cmake_minimum_required(VERSION 3.10)

project(cpp01)

set(CMAKE_CXX_STANDARD 98)

include(CTest)

enable_testing()

# Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Add subdirectory for tests
add_subdirectory(tests)
