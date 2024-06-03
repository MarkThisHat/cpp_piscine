# tests/CMakeLists.txt

set(CMAKE_CXX_STANDARD 98)

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
    ../ex00/newZombie.cpp
    ../ex00/randomChump.cpp
)

# set(EX01_SOURCES
#    ../ex01/something.cpp
#)

# Create the test executable
add_executable(runTests ${TEST_SOURCES} 
                        ${EX00_SOURCES}
                        #${EX01_SOURCES}
)

# Link libraries, including gtest and gtest_main
if (GTest_FOUND)
    target_link_libraries(runTests GTest::gtest GTest::gtest_main pthread)
else()
    target_link_libraries(runTests gtest gtest_main pthread)
endif()

# Add tests
add_test(NAME runTests COMMAND runTests)
