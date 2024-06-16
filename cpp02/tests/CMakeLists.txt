# tests/CMakeLists.txt

set(CMAKE_CXX_STANDARD 98)

# Include directories for project sources
include_directories(
    ../ex00
    ${gtest_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}/include
)

# Source files
set(EX00_SOURCES
    ../ex00/Fixed.cpp
)

# Create test executables for ex00
add_executable(runTests_ex00 test_ex00.cpp ${EX00_SOURCES})
if (GTest_FOUND)
    target_link_libraries(runTests_ex00 GTest::gtest GTest::gtest_main pthread)
else()
    target_link_libraries(runTests_ex00 gtest gtest_main pthread)
endif()
add_test(NAME runTests_ex00 COMMAND runTests_ex00)
