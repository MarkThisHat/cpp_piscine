cmake_minimum_required(VERSION 3.10)

project(cpp02)

set(CMAKE_CXX_STANDARD 98)

include(CTest)

enable_testing()

# Check if Google Test is installed
find_package(GTest)

# If GTest is not found, try to use the local copy or download and build it
if (NOT GTest_FOUND)
    if (EXISTS "${CMAKE_SOURCE_DIR}/external/googletest/CMakeLists.txt")
        message(STATUS "Using local copy of Google Test")
        add_subdirectory(external/googletest)
    else()
        message(STATUS "Downloading Google Test")
        include(FetchContent)
        FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/heads/main.zip
            DOWNLOAD_EXTRACT_TIMESTAMP TRUE
        )
        FetchContent_MakeAvailable(googletest)
    endif()
endif()

# Add subdirectory for tests
add_subdirectory(tests)
