#!/bin/bash

# Set the build directory
BUILD_DIR="tests/build"
VALGRIND=false
RERUN_TESTS=false

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
			echo -e "${BRIGHT_RED}Failed ${NC}to remove the build directory. Check cleanup_error.log for details."
		else
			rm cleanup_error.log
			echo -e "Cleanup ${GREEN}complete${NC}."
		fi
	else
		rm -rf "$BUILD_DIR" 2> cleanup_error.log
		if [ $? -ne 0 ]; then
			echo "${BRIGHT_RED}Failed ${NC}to remove the build directory. Check cleanup_error.log for details."
		else
			rm cleanup_error.log
		fi
	fi
}

# Function to clean up external directory
clean_external() {
	if [ -d "external/googletest" ]; then
		echo -e "Cleaning external directory..."
		rm -rf "external"
		if [ $? -ne 0 ]; then
			echo -e "${BRIGHT_RED}Failed ${NC}to remove the external directory."
		else
			echo -e "External directory cleanup ${GREEN}complete${NC}."
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
			echo -e "${BRIGHT_RED}Failed {$NC}to clone Google Test."
			exit 1
		fi
		echo -e "Cloning ${GREEN}complete${NC}."
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
		--clean)
		CLEAN_BUILDS=true
		shift # Remove --clean from processing
		;;
		--rerun)
		KEEP_BUILD_DIR=true
		RERUN_TESTS=true
		shift # Remove --rerun from processing
		;;
		-h)
		INFO_SCRIPT=true
		shift # Remove --h from processing
		;;
		--options)
		INFO_SCRIPT=true
		shift # Remove --options from processing
		;;
		--help)
		INFO_SCRIPT=true
		shift # Remove --help from processing
		;;
		--info)
		INFO_SCRIPT=true
		shift # Remove --info from processing
		;;
		*)
		echo -e "Unknown option: ${BRIGHT_RED}${arg}${NC}"
		exit 1
		;;
	esac
done

if [ "$INFO_SCRIPT" = true ]; then
	echo -e "Options:\n\t--keep\t\tbuild directory will persist\n\t--rerun\t\tuses a previous build\n\t--local\t\tcreates google test folder locally\n\t--valgrind\tcheck for memory leaks\n\t--clean\t\tremoves build and gtest directories\n"
	exit 0
fi

# If --clean is set, perform clean up and exit
if [ "$CLEAN_BUILDS" = true ]; then
	cleanup
	clean_external
	exit 0
fi

# Check if rebuild flag is set and the build directory exists
if [ "$RERUN_TESTS" = true ] && [ ! -d "$BUILD_DIR" ]; then
    echo -e "Build directory inexistant. Please run with --keep and without --rerun${NC}"
    exit 1
fi


# Clone Google Test locally if --local flag is set
if [ "$USE_LOCAL_GTEST" = true ]; then
	clone_gtest
fi

if [ "$RERUN_TESTS" = false ]; then
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
		echo -e "CMake configuration ${BRIGHT_RED}failed${NC}. Try running this script with ${BRIGHT_GREEN}--local ${NC}flag"
		cd ../..
		exit 1
	fi
else
	cd "$BUILD_DIR"
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