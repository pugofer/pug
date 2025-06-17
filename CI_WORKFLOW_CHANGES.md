# CI Workflow Changes for Windows Testing

## Overview
Modified the GitHub Actions CI workflow to support Windows testing while building Windows binaries on Linux using cross-compilation.

## Changes Made

### 1. Restructured CI Jobs
- **Before**: Single job `build-and-test` running only on Ubuntu
- **After**: Three separate jobs:
  - `build-and-test-linux`: Build and test on Linux (unchanged functionality)
  - `build-windows`: Cross-compile Windows binary on Linux
  - `test-windows`: Run tests on Windows using the cross-compiled binary

### 2. Cross-Compilation Setup
- Uses `gcc-mingw-w64-x86-64-ucrt` for cross-compilation
- Builds `pug.exe` on Linux using: `CC=x86_64-w64-mingw32-gcc-ucrt LDFLAGS="-lm -static" make -C src pug`
- Static linking ensures the binary runs on Windows without additional dependencies

### 3. Artifact Management
- Windows binary (`pug.exe`) and `langlevels/` folder are uploaded as artifacts from the Linux build job
- Windows test job downloads these artifacts before running tests
- Both Linux and Windows test reports are uploaded separately

### 4. Test Infrastructure
- Existing test infrastructure already supports Windows via `wexpect` (Windows version of `pexpect`)
- No changes needed to test files or test runner
- Tests run using the same Python test framework on both platforms

## Benefits

1. **Consistent Build Environment**: All binaries built on Linux ensures reproducible builds
2. **Faster CI**: Cross-compilation is typically faster than native Windows builds
3. **Better Control**: We control the exact MinGW-w64 version and configuration
4. **Maintains Compatibility**: Linux build and test process remains unchanged
5. **No New Dependencies**: Uses existing Makefile targets with environment variables

## Workflow Structure

```
build-and-test-linux (Ubuntu)
├── Build pug binary
├── Run tests on Linux
└── Upload Linux test reports

build-windows (Ubuntu)
├── Install MinGW-w64 UCRT
├── Cross-compile pug.exe
└── Upload Windows artifacts (pug.exe + langlevels/)

test-windows (Windows)
├── Download Windows artifacts
├── Run tests using pug.exe
└── Upload Windows test reports
```

## Testing
- Both Linux and Windows test results appear separately in GitHub Actions
- Test reports are uploaded as artifacts for both platforms
- Failures on either platform will be reported independently

## Usage
The workflow triggers on:
- Pushes to `main` and `tests` branches
- Pull requests to `devel` branch
- Manual workflow dispatch

No changes needed for developers - the existing build process (`make -C src`) continues to work for local development.
