#!/bin/bash

# Set the build directory
BUILD_DIR="tests/build"
VALGRIND=false

# Function to clean up the build directory
cleanup() {
    if [ -d "$BUILD_DIR" ]; then
        echo "Cleaning up..."
        rm -rf "$BUILD_DIR" 2> cleanup_error.log
        if [ $? -ne 0 ]; then
            echo "Failed to remove the build directory. Check cleanup_error.log for details."
        else
            rm cleanup_error.log
            echo "Cleanup complete."
        fi
    else
        rm -rf "$BUILD_DIR" 2> cleanup_error.log
        if [ $? -ne 0 ]; then
            echo "Failed to remove the build directory. Check cleanup_error.log for details."
        else
            rm cleanup_error.log
        fi
    fi
}

# Parse command-line arguments
KEEP_BUILD_DIR=false
for arg in "$@"
do
    case $arg in
        --keep)
        KEEP_BUILD_DIR=true
        shift # Remove --keep from processing
        ;;
        --valgrind)
        VALGRIND=true
        shift # Remove --valgrind from processing
        ;;
    esac
done

# Always clean up the build directory before starting
cleanup

# Create the build directory
mkdir -p "$BUILD_DIR"

# Navigate to the build directory
cd "$BUILD_DIR"

# Run CMake to configure the project
cmake ../.. -D CTEST_USE_LAUNCHERS=ON

# Check if CMake succeeded
if [ $? -ne 0 ]; then
    echo "CMake configuration failed."
    cd ../..
    exit 1
fi

# Build the project
make

# Check if make succeeded
if [ $? -ne 0 ]; then
    echo "Build failed."
    cd ../..
    exit 1
fi

# Run the tests
if [ "$VALGRIND" = true ]; then
    echo "Running tests with valgrind..."
    ctest --output-on-failure -T memcheck
else
    ctest --output-on-failure
fi

# Check if tests succeeded
if [ $? -ne 0 ]; then
    echo "Tests failed."
    cd ../..
    exit 1
fi

# Navigate back to the parent directory before cleanup
cd ../..

# Optionally clean up the build directory after testing
if [ "$KEEP_BUILD_DIR" = false ]; then
    cleanup
else
    echo "Build directory retained."
fi

echo "Build and test process complete."