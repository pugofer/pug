# Makefile for Pug testing environment and execution
# Should be run from the 'test' directory, or via 'make -C test <target>' from root.

# Determine the Python executable to use.
# Prefers the one in ../.venv if it exists, otherwise defaults to python3.
# This path is relative to where python commands will be run (project root after 'cd ..')
VENV_PYTHON := .venv/bin/python3
SYSTEM_PYTHON := python3
PYTHON_TO_USE := $(shell if [ -f ../$(VENV_PYTHON) ]; then echo $(VENV_PYTHON); else echo $(SYSTEM_PYTHON); fi)

# CMake build directory
BUILD_DIR := ../build

.PHONY: all setup build-pug run reports ci clean

all: build-pug run

setup:
	@if ! command -v uv > /dev/null; then \
		echo "Error: uv command not found. Please install uv first."; \
		echo "See https://astral.sh/uv for installation instructions."; \
		exit 1; \
	fi
	@echo "Creating Python 3.12 virtual environment in ../.venv using uv..."
	cd .. && uv venv .venv --python 3.12
	@echo "Installing test dependencies from ../requirements-test.txt..."
	cd .. && uv pip install --python .venv/bin/python3 -r requirements-test.txt
	@echo ""
	@echo "Test environment setup complete."
	@echo "To activate the virtual environment (from project root), run: source .venv/bin/activate"

build-pug:
	@echo "Building pug using CMake..."
	@if [ ! -d "$(BUILD_DIR)" ]; then \
		echo "Creating build directory..."; \
		mkdir -p $(BUILD_DIR); \
	fi
	cd $(BUILD_DIR) && cmake .. && make pug
	@echo "Pug built successfully in $(BUILD_DIR)"

run: build-pug
	@echo "Running tests from project root using $(PYTHON_TO_USE)..."
	cd .. && $(PYTHON_TO_USE) -m unittest discover -v

reports: build-pug
	@echo "Running tests with reports from project root using $(PYTHON_TO_USE)..."
	cd .. && $(PYTHON_TO_USE) test/run_tests_with_reports.py --verbose --timeout 180

ci: build-pug
	@echo "Running CI tests with reports from project root using $(PYTHON_TO_USE)..."
	cd .. && $(PYTHON_TO_USE) test/run_tests_with_reports.py --verbose --xml-output test-reports --timeout 180

clean:
	@echo "Removing Python virtual environment and test artifacts from project root..."
	rm -rf ../.venv
	@echo "Removing CMake build directory..."
	rm -rf $(BUILD_DIR)
	@echo "Removing __pycache__ directories..."
	# Remove __pycache__ from project root if it exists
	@if [ -d ../__pycache__ ]; then rm -rf ../__pycache__; fi
	# Remove __pycache__ from test directory if it exists
	@if [ -d ./__pycache__ ]; then rm -rf ./__pycache__; fi
	@echo "Removing coverage and report files/directories..."
	rm -f ../.coverage
	rm -rf ../htmlcov/
	rm -rf ../test-reports/
	@echo "Test environment cleanup complete."
