#!/usr/bin/env python3
"""
Test runner script that generates XML reports for the Pug interpreter tests.
"""

import os
import sys
import unittest
import argparse
import signal
from pathlib import Path

# Import the XML test runner
try:
    import xmlrunner
except ImportError:
    print("Error: unittest-xml-reporting not installed. Run: pip install unittest-xml-reporting")
    sys.exit(1)

def timeout_handler(signum, frame):
    """Handle timeout signal"""
    print("\nTest execution timed out!")
    sys.exit(1)

def main():
    parser = argparse.ArgumentParser(description='Run Pug interpreter tests with reporting')
    parser.add_argument('--xml-output', default='test-reports',
                       help='Directory for XML test reports (default: test-reports)')
    parser.add_argument('--verbose', '-v', action='store_true',
                       help='Verbose output')
    parser.add_argument('--timeout', type=int, default=300,
                       help='Test timeout in seconds (default: 300)')

    args = parser.parse_args()

    # Ensure output directories exist
    os.makedirs(args.xml_output, exist_ok=True)

    # Set up the test discovery
    test_dir = Path(__file__).parent / 'test'

    # Set up timeout (Unix-like systems only)
    if hasattr(signal, 'SIGALRM'):
        signal.signal(signal.SIGALRM, timeout_handler)
        signal.alarm(args.timeout)

    # Discover and run tests
    loader = unittest.TestLoader()
    suite = loader.discover(str(test_dir), pattern='test_*.py')

    # Configure the XML test runner
    runner = xmlrunner.XMLTestRunner(
        output=args.xml_output,
        verbosity=2 if args.verbose else 1,
        stream=sys.stdout
    )

    print(f"Running tests with XML output to: {args.xml_output}")
    print(f"Test timeout set to: {args.timeout} seconds")

    try:
        result = runner.run(suite)

        # Cancel timeout if tests complete
        if hasattr(signal, 'SIGALRM'):
            signal.alarm(0)

        print(f"\nTest execution completed successfully!")
        print(f"Tests run: {result.testsRun}")
        print(f"Failures: {len(result.failures)}")
        print(f"Errors: {len(result.errors)}")

        # Return appropriate exit code
        return 0 if result.wasSuccessful() else 1

    except Exception as e:
        print(f"Error during test execution: {e}")
        return 1

if __name__ == '__main__':
    sys.exit(main())
