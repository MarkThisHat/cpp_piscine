# tests/CMakeLists.txt

set(CMAKE_CXX_STANDARD 98)

# Google Test
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

# Include directories for project sources
include_directories(
    ../ex00
    # ../ex01
)

# Test sources
set(TEST_SOURCES
    test_ex00_zombie.cpp
    # test_ex01_something.cpp
)

# Source files
set(EX00_SOURCES
    ../ex00/Zombie.cpp
)

# set(EX01_SOURCES
#    ../ex01/something.cpp
#)

# Create the test executable
add_executable(runTests ${TEST_SOURCES} ${EX00_SOURCES} # ${EX01_SOURCES}
)

# Link libraries, including gtest_main
target_link_libraries(runTests gtest gtest_main pthread)
#target_link_libraries(runTests ${GTEST_LIBRARIES} gtest_main pthread)

# Add tests
add_test(NAME runTests COMMAND runTests)
