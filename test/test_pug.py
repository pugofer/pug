import unittest
import sys
import os
import re
from typing import Callable, Union, Dict, Any

# Platform-specific imports for pexpect functionality
if sys.platform == "win32":
    import wexpect as pexpect  # type: ignore
    # wexpect uses the same exception names directly in the module
    pexpect_exceptions = pexpect
    PexpectSpawn = pexpect.spawn
else:
    import pexpect
    import pexpect.exceptions as pexpect_exceptions
    PexpectSpawn = pexpect.spawn

# --- Configuration ---
PUG_PROMPT = r"\? " # The prompt is a literal '?' followed by a space.
MANIFEST_FILE = os.path.join(os.path.dirname(__file__), 'test_manifest.txt')

# --- transforming command with absolute path
def transform_command(command):
    prefix = command[:2] 
    script_path = f"scripts/{command[2:].strip()}"
    path = os.path.join(os.path.dirname(__file__),script_path)
    return f"{prefix} {path}"

# --- Generic Test Runner Function ---

def run_cmd_test_from_file(test_case: unittest.TestCase, process: Any, filename: str):
    """
    A generic, data-driven test runner that reads a file of commands and expected outputs.

    Args:
        test_case: The unittest.TestCase instance (i.e., 'self').
        process: The pexpect process running the pug interpreter.
        filename: The path to the test data file.
    """
    if not os.path.exists(filename):
        test_case.fail(f"Test data file not found at {filename}")

    with open(filename, 'r') as f:
        lines = f.readlines()

    # Simple parser for the test file
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        if not line or line.startswith('#'): # Ignore empty lines and comments
            i += 1
            continue

        if line.startswith('? '):
            command = line[2:]
            if line.startswith('? :'):
                command = transform_command(command)
                
            i += 1
            is_regex = False 

            if i < len(lines) and lines[i].strip() == '-- REGEX MATCH':
                is_regex = True
                i+=1

            if i < len(lines):
                expected_output = lines[i].strip()

                with test_case.subTest(command=command, expected=expected_output):
                    process.sendline(command)
                    # Match against the expected output or the next prompt
                    if is_regex:
                        index = process.expect([expected_output, PUG_PROMPT, pexpect.EOF, pexpect.TIMEOUT], timeout=2)
                        test_case.assertEqual(index, 0,
                                            f"Regex pattern did not match.\nPattern:\n'{expected_output}'\nGot:\n'{process.before}'")
                    else:
                        index = process.expect_exact([expected_output, PUG_PROMPT, pexpect.EOF, pexpect.TIMEOUT], timeout=1)
                        before_output = str(process.before).strip() if process.before else ""
                        test_case.assertEqual(index, 0,
                                            f"Command '{command}' did not produce expected output '{expected_output}'. "
                                            f"Got: '{before_output}'")

                    # Ensure we see the next prompt before continuing
                    process.expect(PUG_PROMPT)
            else:
                test_case.fail(f"Test file format error in {filename}: Command '{command}' has no expected output.")
        i += 1


# --- Test Suite Class ---

class TestPugInterpreter(unittest.TestCase):
    """
    Test suite for the Pug interpreter using pexpect.
    Test methods for data files are generated dynamically.
    """
    process: Union[Any, None] = None
    current_langlevel = None  # Stores the langlevel for the current test

    def setUp(self):
        """Sets up a new pug interpreter process before each test method."""
        script_dir = os.path.dirname(os.path.abspath(__file__))
        src_dir = os.path.join(script_dir, '../src/')

        # Calculate absolute path to langlevels directory
        test_dir = os.path.dirname(os.path.abspath(__file__))
        project_root = os.path.dirname(test_dir)
        langlevels_dir = os.path.join(project_root, 'langlevels')

        # Handle platform-specific executable names
        if sys.platform == "win32":
            pug_executable = os.path.join(src_dir, 'pug.exe')
        else:
            pug_executable = os.path.join(src_dir, 'pug')

        if not os.path.exists(pug_executable):
            self.fail(f"Pug executable not found at {pug_executable}. "
                      f"Please build it by running 'make' in the 'src' directory.")

        # Get the current test method name and check if it has a langlevel attribute
        test_method_name = self._testMethodName
        test_method = getattr(self, test_method_name)
        langlevel = getattr(test_method, 'langlevel', 'pug')  # default to 'pug'

        # Set up environment with absolute path to langlevel file
        langlevel_file = os.path.join(langlevels_dir, f'{langlevel}.pre')

        # Verify the langlevel file exists
        if not os.path.exists(langlevel_file):
            self.fail(f"Language level file not found: {langlevel_file}")

        env: Dict[str, str] = {'PUG': langlevel_file}

        self.process = pexpect.spawn(pug_executable, encoding='utf-8', cwd=src_dir, env=env)  # type: ignore
        self.process.expect(PUG_PROMPT)  # type: ignore

    def tearDown(self):
        """Terminates the pug process after each test method."""
        if self.process and self.process.isalive():
            self.process.terminate(force=True)

    def test_01_startup_and_exit(self):
        """Tests if the interpreter starts up and exits cleanly."""
        if self.process:
            self.process.sendline(":q")
            self.process.expect(pexpect.EOF)
            self.assertFalse(self.process.isalive(), "Process did not terminate after ':q' command.")

# --- Dynamic Test Generation Logic ---

def generate_tests():
    """
    Reads the manifest file and dynamically creates a test method for each
    entry, attaching it to the TestPugInterpreter class.
    """
    def create_test_method(filename: str, langlevel: str) -> Callable[['TestPugInterpreter'], None]:
        """
        This is a 'function factory'. It creates and returns a new function
        that will serve as our test method. This closure captures the filename and langlevel.
        """
        def test_template(self: 'TestPugInterpreter') -> None:
            if self.process:
                run_cmd_test_from_file(self, self.process, filename)
            else:
                self.fail("Process not initialized")
        # Set the langlevel as an attribute on the test method
        test_template.langlevel = langlevel  # type: ignore
        return test_template

    print("MANIFEST FILE:", MANIFEST_FILE)

    # Read the manifest file
    with open(MANIFEST_FILE, 'r') as f:
        for test_file_path in f:
            test_file_path = test_file_path.strip()
            print(f"Processing test file: {test_file_path}")
            if not test_file_path or test_file_path.startswith('#'):
                continue

            # Extract langlevel from filename
            basename = os.path.basename(test_file_path)
            langlevel_candidate = basename.split('_')[0]

            # Check if it matches known langlevels, otherwise default to 'pug'
            if langlevel_candidate in ['pup', 'pug', 'kit']:
                langlevel = langlevel_candidate
            else:
                langlevel = 'pug'  # default

            print(f"Test file: {test_file_path} -> langlevel: {langlevel}")

            # Create a valid Python method name from the filename
            # e.g., "test/arithmetic_test.txt" -> "test_from_file_arithmetic_test_txt"
            test_name = "test_cmd_" + re.sub(r'[^a-zA-Z0-9]', '_', os.path.basename(test_file_path))

            # Create the actual test method function
            test_method = create_test_method(test_file_path, langlevel)

            # Attach the new method to the TestPugInterpreter class
            setattr(TestPugInterpreter, test_name, test_method)

# --- Main Execution Block ---
# Call the generator at the module level.
# This ensures it runs when 'unittest discover' imports this file.
# Dynamically generate the tests before running them
generate_tests()

if __name__ == '__main__':
    unittest.main()
