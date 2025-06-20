# Testing Environment Setup for Pug

This document outlines the steps to set up a consistent Python testing environment for the Pug project using `uv` and Python 3.12.

## Prerequisites

1.  **Python 3.12**: Ensure you have Python 3.12 installed. You can download it from [python.org](https://www.python.org/downloads/) or install it using a version manager like `pyenv`.
2.  **`uv`**: This project uses `uv` for Python package management and virtual environments. `uv` is a fast Python package installer and resolver, written in Rust.

    *   **Installation (Linux/macOS):**
        ```bash
        curl -LsSf https://astral.sh/uv/install.sh | sh
        ```
    *   **Installation (Windows PowerShell):**
        ```powershell
        irm https://astral.sh/uv/install.ps1 | iex
        ```
    *   For other installation methods or more details, refer to the [official `uv` documentation](https://astral.sh/uv).

## Setup Steps

All commands below should be run from the **project root directory**.

1.  **Create Virtual Environment:**
    Create a virtual environment named `.venv` in the project root, specifically using Python 3.12:
    ```bash
    uv venv .venv --python 3.12
    ```

2.  **Activate Virtual Environment:**
    *   **Linux/macOS (bash/zsh):**
        ```bash
        source .venv/bin/activate
        ```
    *   **Windows (Command Prompt):**
        ```cmd
        .venv\Scripts\activate
        ```
    *   **Windows (PowerShell):**
        ```powershell
        .venv\Scripts\Activate.ps1
        ```
    Your shell prompt should change to indicate that the virtual environment is active (e.g., `(.venv) user@host:...$`).

3.  **Install Test Dependencies:**
    With the virtual environment active, install the required test dependencies from `requirements-test.txt`:
    ```bash
    uv pip install -r requirements-test.txt
    ```

## Running Tests using Makefile

This project provides Makefiles to simplify setting up the test environment and running tests.

*   **`test/Makefile`**: Contains the detailed logic for test setup and execution.
*   **Root `Makefile`**: Provides convenience targets that delegate to `test/Makefile`.

**Available `make` targets (run from project root):**

*   **`make setup-tests`**:
    *   Checks for `uv`.
    *   Creates the `.venv` virtual environment (Python 3.12).
    *   Installs test dependencies into `.venv`.
    *   This is the recommended first step.

*   **`make test-all`**:
    *   Runs the main test suite using `unittest discover`.
    *   Uses Python from `.venv` if `setup-tests` has been run.

*   **`make test-all-reports`**:
    *   Runs tests using `run_tests_with_reports.py` to generate reports.
    *   Uses Python from `.venv`.

*   **`make test-all-ci`**:
    *   Runs tests with CI-specific options (e.g., XML output for test reports).
    *   Uses Python from `.venv`.

*   **`make clean-test-env`**:
    *   Removes the `.venv` directory, `__pycache__` folders, and other test-generated artifacts.

**Usage:**

1.  First, set up the environment:
    ```bash
    make setup-tests
    ```
2.  Then, activate the environment (as guided by `make setup-tests` output):
    ```bash
    source .venv/bin/activate
    ```
3.  Now you can run tests:
    ```bash
    make test-all
    # or
    make test-all-reports
    ```
    Alternatively, after `make setup-tests`, you can run `make` targets from within the `test/` directory (e.g., `cd test && make run`).

## Optional: Automatic Virtual Environment Activation with `direnv`

`direnv` is a tool that automatically loads and unloads environment variables (including activating/deactivating virtual environments) when you `cd` into or out of a directory.

1.  **Install `direnv`**: Follow the [official `direnv` installation guide](https://direnv.net/docs/installation.html).
2.  **Hook `direnv` into your shell**: This step is crucial and specific to your shell (bash, zsh, fish, etc.). See `direnv` documentation.
3.  **Create `.envrc` file**: In the project root directory, create a file named `.envrc` with the following content:
    ```sh
    # .envrc
    source_env .venv/bin/activate
    ```
    This command instructs `direnv` to source the `.venv/bin/activate` script. The path `.venv/bin/activate` is relative to the location of the `.envrc` file (i.e., your project root).
    *   **Important**: The `.venv` directory and the `activate` script within it must already exist (e.g., created by running `make setup-tests`).
    *   If `~/p/pug/.venv/bin/activate` exists, `direnv` will source it, activating the virtual environment.
    *   If the `activate` script does not exist, `direnv` will report an error (e.g., "path .venv/bin/activate is not a file"). This serves as a reminder to run `make setup-tests`.

4.  **Allow `direnv`**: The first time you `cd` into the project directory (or if `.envrc` changes), `direnv` will require you to allow its execution:
    ```bash
    direnv allow
    ```
Now, whenever you navigate into the project directory, `direnv` will automatically activate the `.venv` virtual environment. When you navigate out, it will be deactivated.

Remember to add `.direnv/` (direnv's cache directory) to your root `.gitignore` file.
