# Pug Development Guide

This document provides instructions for building Pug using CMake on different platforms.

## Prerequisites

### All Platforms
- CMake 3.12 or later
- A C compiler supporting C90 standard
- Git (for cloning the repository)

### Linux
- GCC or Clang
- Make or Ninja build system
- For Windows cross-compilation: mingw-w64

### Windows
- Visual Studio 2017 or later, OR
- MinGW-w64, OR
- Clang

### macOS
- Xcode Command Line Tools or full Xcode
- Clang (comes with Xcode)

## Building Pug

### Linux Native Build

```bash
# Create build directory
mkdir build-linux
cd build-linux

# Configure
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build . --parallel

# Test (optional)
ctest

# Install (optional)
sudo cmake --install .
```

### Windows Cross-Compilation from Linux

```bash
# Install mingw-w64 if not already installed
# Ubuntu/Debian:
sudo apt-get install mingw-w64

# Fedora/CentOS:
sudo dnf install mingw64-gcc

# Create build directory
mkdir build-windows
cd build-windows

# Configure for Windows cross-compilation
cmake .. \
  -DCMAKE_TOOLCHAIN_FILE=../cmake/mingw-w64-toolchain.cmake \
  -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build . --parallel

# The Windows executable will be in bin/pug.exe
```

### Windows Native Build

#### Using Visual Studio
```cmd
REM Create build directory
mkdir build-windows
cd build-windows

REM Configure
cmake .. -G "Visual Studio 16 2019" -A x64

REM Build
cmake --build . --config Release

REM Install (optional, run as Administrator)
cmake --install . --config Release
```

#### Using MinGW
```bash
# Create build directory
mkdir build-windows
cd build-windows

# Configure
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build . --parallel
```

### macOS Build

```bash
# Create build directory
mkdir build-macos
cd build-macos

# Configure
cmake .. \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_OSX_DEPLOYMENT_TARGET=10.12

# Build
cmake --build . --parallel

# Create app bundle (optional)
cmake --build . --target package
```

## CMake Configuration Options

### Build Types
- `Release` (default): Optimized build
- `Debug`: Debug build with symbols
- `RelWithDebInfo`: Optimized with debug info
- `MinSizeRel`: Minimal size optimized

### Useful CMake Variables
- `CMAKE_INSTALL_PREFIX`: Installation directory
- `CMAKE_BUILD_TYPE`: Build configuration
- `CMAKE_C_COMPILER`: Specify C compiler
- `CMAKE_TOOLCHAIN_FILE`: Cross-compilation toolchain

### Examples

```bash
# Debug build
cmake .. -DCMAKE_BUILD_TYPE=Debug

# Custom install location
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/pug

# Specify compiler
cmake .. -DCMAKE_C_COMPILER=clang

# Use Ninja instead of Make
cmake .. -G Ninja
```

## Cross-Compilation Toolchain

For Windows cross-compilation from Linux, create `cmake/mingw-w64-toolchain.cmake`:

```cmake
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Specify the cross compiler
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

# Search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Search for libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
```

## Testing

### Running Tests with CMake Build

```bash
# After building, from build directory
cd build-linux  # or appropriate build directory

# Run tests using the CMake-built binary
cd ../test
make PYTHON_TO_USE=python3 PUG_BINARY=../build-linux/bin/pug run
```

### Platform-Specific Test Runs

```bash
# Linux
cd test
make run

# Windows (from Linux cross-compile)
# Copy build-windows/bin/pug.exe and langlevels to Windows machine
# Run tests on Windows machine

# macOS
cd test
make run
```

## Packaging

CMake includes CPack configuration for creating installers:

### Linux
```bash
# Create tarball and DEB package
cmake --build . --target package
```

### Windows
```bash
# Create ZIP and NSIS installer (if NSIS installed)
cmake --build . --target package
```

### macOS
```bash
# Create ZIP and DMG
cmake --build . --target package
```

## Project Structure

```
pug/
├── CMakeLists.txt           # Root CMake configuration
├── src/
│   ├── CMakeLists.txt       # Source CMake configuration
│   └── *.c, *.h             # Source files
├── langlevels/              # Runtime language files
├── test/
│   ├── Makefile            # Updated for CMake builds
│   └── *.py                # Test files
└── build-*/                # Build directories (created)
    ├── bin/
    │   ├── pug[.exe]       # Built executable
    │   └── langlevels/     # Copied runtime files
    └── ...
```

## Troubleshooting

### Common Issues

1. **CMake not found**: Install CMake from https://cmake.org/
2. **Compiler not found**: Install appropriate development tools
3. **Cross-compilation fails**: Ensure mingw-w64 is properly installed
4. **Tests fail**: Check that langlevels directory is properly copied

### Debugging Build Issues

```bash
# Verbose build output
cmake --build . --verbose

# Show all CMake variables
cmake -LAH .

# Reconfigure from scratch
rm -rf build-*
mkdir build-linux && cd build-linux
cmake ..
```

## Legacy Makefile

The original `src/Makefile` is preserved for reference but the CMake build system should be used for new development. The CMake system provides:

- Cross-platform compatibility
- Better dependency management
- Integrated testing support
- Package generation
- IDE integration support

## IDE Integration

### Visual Studio Code
1. Install CMake Tools extension
2. Open project folder
3. Configure CMake kit
4. Build using Ctrl+Shift+P → "CMake: Build"

### CLion
1. Open project folder
2. CLion will automatically detect CMakeLists.txt
3. Configure toolchain in Settings
4. Build using standard CLion commands

### Visual Studio (Windows)
1. Use "Open Folder" to open project
2. Visual Studio will detect CMakeLists.txt
3. Configure in CMake Settings
4. Build using standard Visual Studio commands
