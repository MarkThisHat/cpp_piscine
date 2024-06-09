# tests/CMakeLists.txt

set(CMAKE_CXX_STANDARD 98)

# Include directories for project sources
include_directories(
    ../ex00
    ../ex01
    ${gtest_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}/include
)

# Source files
set(EX00_SOURCES
    ../ex00/Zombie.cpp
    ../ex00/newZombie.cpp
    ../ex00/randomChump.cpp
)

set(EX01_SOURCES
   ../ex01/Zombie.cpp
   ../ex01/zombieHorde.cpp
)

# Exercise ex02 only has a main function, no sources added

# Create test executables for ex00
add_executable(runTests_ex00 test_ex00_zombie.cpp ${EX00_SOURCES})
if (GTest_FOUND)
    target_link_libraries(runTests_ex00 GTest::gtest GTest::gtest_main pthread)
else()
    target_link_libraries(runTests_ex00 gtest gtest_main pthread)
endif()
add_test(NAME runTests_ex00 COMMAND runTests_ex00)

# Create test executables for ex01
add_executable(runTests_ex01 test_ex01_zombieHorde.cpp ${EX01_SOURCES})
if (GTest_FOUND)
    target_link_libraries(runTests_ex01 GTest::gtest GTest::gtest_main pthread)
else()
    target_link_libraries(runTests_ex01 gtest gtest_main pthread)
endif()
add_test(NAME runTests_ex01 COMMAND runTests_ex01)

# Create test executables for ex01
add_executable(runTests_ex02 test_ex02_brain.cpp)
if (GTest_FOUND)
    target_link_libraries(runTests_ex02 GTest::gtest GTest::gtest_main pthread)
else()
    target_link_libraries(runTests_ex02 gtest gtest_main pthread)
endif()
add_test(NAME runTests_ex02 COMMAND runTests_ex02)
