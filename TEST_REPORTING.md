# Test Reporting for Pug Interpreter

This document describes the test reporting functionality added to the Pug interpreter project.

## Overview

The project now includes enhanced test reporting capabilities that generate XML reports compatible with GitHub Actions and other CI/CD systems.

## Files Added

- `requirements-test.txt` - Python dependencies for test reporting
- `run_tests_with_reports.py` - Test runner script that generates XML reports
- `TEST_REPORTING.md` - This documentation file

## Running Tests Locally

### Basic Tests (Original)
```bash
make -C src test
```

### Tests with XML Reports
```bash
make -C src test-reports
```

### CI Tests (Used by GitHub Actions)
```bash
make -C src test-ci
```

## Test Reports Generated

### XML Reports
- Location: `test-reports/` directory
- Format: JUnit XML format
- Compatible with GitHub Actions test reporting

### GitHub Actions Integration

The CI workflow now:
1. Runs tests with XML reporting
2. Displays test results in the GitHub Actions UI
3. Shows test results in PR checks
4. Uploads detailed reports as artifacts

## Viewing Test Results

### In GitHub UI
- **Actions Tab**: View test summaries and results
- **PR Checks**: See test status directly in pull requests
- **Artifacts**: Download detailed HTML reports

### Locally
- XML reports: `test-reports/*.xml`
- Console output with detailed test information

## Timeout Protection

Tests are configured with timeouts to prevent hanging:
- Local tests: 180 seconds (3 minutes)
- GitHub Actions: 15 minutes total job timeout

## Dependencies

The test reporting requires:
- `unittest-xml-reporting` - Generates JUnit XML reports
- `pexpect` (Linux/Mac) or `wexpect` (Windows) - Process interaction

Install with:
```bash
pip install -r requirements-test.txt
```

## Troubleshooting

### Tests Hanging
- Check that the pug executable is built: `make -C src pug`
- Verify test data files exist in the `test/` directory
- Check timeout settings if tests run longer than expected

### Missing Reports
- Ensure `test-reports/` directory is created
- Check that `unittest-xml-reporting` is installed
- Verify the test runner script has execute permissions

## Integration with Other CI Systems

The JUnit XML format is compatible with most CI/CD systems including:
- Jenkins
- GitLab CI
- Azure DevOps
- CircleCI
- Travis CI

Simply point your CI system to the `test-reports/*.xml` files.
