cmake_minimum_required(VERSION 3.12)
project(pug VERSION 0.3 LANGUAGES C)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Platform-specific configuration
if(WIN32)
    # Windows-specific settings
    set(CMAKE_EXECUTABLE_SUFFIX ".exe")
endif()

# Compiler configuration
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Build output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add source directory
add_subdirectory(src)

# Copy langlevels directory to build directory for runtime
file(COPY ${CMAKE_SOURCE_DIR}/langlevels 
     DESTINATION ${CMAKE_BINARY_DIR}/bin)

# Platform-specific installation settings
install(TARGETS pug 
        RUNTIME DESTINATION bin)
install(DIRECTORY langlevels/ DESTINATION share/pug/langlevels)

# CPack configuration for future installer creation
set(CPACK_PACKAGE_NAME "pug")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION "Pug functional programming language interpreter")
set(CPACK_PACKAGE_CONTACT "pug-dev@example.com")

if(WIN32)
    set(CPACK_GENERATOR "ZIP")
elseif(APPLE)
    set(CPACK_GENERATOR "ZIP")
else()
    set(CPACK_GENERATOR "TGZ")
endif()

include(CPack)
