#!/bin/bash

# Set the build directory
BUILD_DIR="tests/build"
VALGRIND=false

# Set color codes
RED='\033[0;31m'
BRIGHT_RED='\033[1;31m'
GREEN='\033[0;32m'
BRIGHT_GREEN='\033[1;32m'
WHITE='\033[0;37m'
BRIGHT_WHITE='\033[1;37m'
MAGENTA='\033[0;35m'
BRIGHT_MAGENTA='\033[1;35m'
BLUE='\033[0;34m'
BRIGHT_BLUE='\033[1;34m'
NC='\033[0m' # No Color

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

# Function to clone Google Test locally
clone_gtest() {
    if [ -d "external/googletest" ]; then
        echo "Google Test already exists in external/googletest. Skipping clone."
    else
        echo "Cloning Google Test into external/googletest..."
        git clone https://github.com/google/googletest.git external/googletest
        if [ $? -ne 0 ]; then
            echo "Failed to clone Google Test."
            exit 1
        fi
        echo "Cloning complete."
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
        --local)
        USE_LOCAL_GTEST=true
        shift # Remove --local from processing
        ;;
    esac
done

# Clone Google Test locally if --local flag is set
if [ "$USE_LOCAL_GTEST" = true ]; then
    clone_gtest
fi

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
    echo -e "CMake configuration ${BRIGHT_RED}failed${NC}. Try running this script with ${BRIGHT_GREEN}--local${NC} flag"
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
    ctest --output-on-failure --verbose
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