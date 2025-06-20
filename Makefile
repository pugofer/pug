# Root Makefile for the Pug project
# Provides convenience targets for building and testing.

.PHONY: all build setup-tests test-all test-all-reports test-all-ci clean-test-env clean

# Default target: build the project
all: build

# Target to build the main project (delegates to src/Makefile)
# Assumes 'make' in 'src/' builds the necessary executables.
build:
	@echo "Building Pug project in src/..."
	$(MAKE) -C src

# Test environment and execution targets (delegate to test/Makefile)
setup-tests:
	@echo "Setting up test environment..."
	$(MAKE) -C test setup

test-all: build
	@echo "Running all tests..."
	$(MAKE) -C test run

test-all-reports: build
	@echo "Running all tests and generating reports..."
	$(MAKE) -C test reports

test-all-ci:
	@echo "Running all tests for CI (with XML reports)..."
	$(MAKE) -C test ci

clean-test-env:
	@echo "Cleaning test environment..."
	$(MAKE) -C test clean

# General clean target (delegates to src/Makefile and test/Makefile for cleaning)
clean:
	@echo "Cleaning build artifacts in src/..."
	$(MAKE) -C src clean
	@echo "Cleaning test environment and artifacts..."
	$(MAKE) -C test clean
	@echo "Full cleanup complete."
