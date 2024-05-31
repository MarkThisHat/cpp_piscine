cmake_minimum_required(VERSION 3.10)

project(cpp01)

set(CMAKE_CXX_STANDARD 98)

include(CTest)

enable_testing()

# Add subdirectory for tests
add_subdirectory(tests)
