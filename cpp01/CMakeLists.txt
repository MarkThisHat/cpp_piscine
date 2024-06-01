cmake_minimum_required(VERSION 3.10)

project(cpp01)

set(CMAKE_CXX_STANDARD 98)

include(CTest)

enable_testing()

# Check if Google Test is installed
find_package(GTest)

# If GTest is not found, download and build it
if (NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(googletest)
endif()

# Add subdirectory for tests
add_subdirectory(tests)
