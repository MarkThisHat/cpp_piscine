# tests/CMakeLists.txt

set(CMAKE_CXX_STANDARD 98)

# Include directories for project sources
include_directories(
    ${gtest_SOURCE_DIR}/include
    ${gmock_SOURCE_DIR}/include
)

# Source files
set(EX00_SOURCES
  ../ex00/src/Animal.cpp
  ../ex00/src/Cat.cpp
  ../ex00/src/Dog.cpp
  ../ex00/src/WrongAnimal.cpp
  ../ex00/src/WrongCat.cpp
)

set(EX01_SOURCES
  ../ex01/src/Animal.cpp
  ../ex01/src/Cat.cpp
  ../ex01/src/Dog.cpp
  ../ex01/src/Brain.cpp
)

set(EX02_SOURCES

)

set(EX03_SOURCES

)

# Create test executables for ex00
add_executable(runTests_ex00 test_ex00.cpp ${EX00_SOURCES})
if (GTest_FOUND)
    target_link_libraries(runTests_ex00 GTest::gtest GTest::gtest_main pthread)
else()
    target_link_libraries(runTests_ex00 gtest gtest_main pthread)
endif()
add_test(NAME runTests_ex00 COMMAND runTests_ex00)

# Create test executables for ex01
add_executable(runTests_ex01 test_ex01.cpp ${EX01_SOURCES})
if (GTest_FOUND)
    target_link_libraries(runTests_ex01 GTest::gtest GTest::gtest_main pthread)
else()
    target_link_libraries(runTests_ex01 gtest gtest_main pthread)
endif()
add_test(NAME runTests_ex01 COMMAND runTests_ex01)

# Create test executables for ex02
#add_executable(runTests_ex02 test_ex02.cpp ${EX01_SOURCES} ${EX02_SOURCES})
#if (GTest_FOUND)
#    target_link_libraries(runTests_ex02 GTest::gtest GTest::gtest_main pthread)
#else()
#    target_link_libraries(runTests_ex02 gtest gtest_main pthread)
#endif()
#add_test(NAME runTests_ex02 COMMAND runTests_ex02)

# Create test executables for ex03
#add_executable(runTests_ex03 test_ex03.cpp ${EX01_SOURCES} ${EX02_SOURCES} ${EX03_SOURCES})
#if (GTest_FOUND)
#    target_link_libraries(runTests_ex03 GTest::gtest GTest::gtest_main pthread)
#else()
#    target_link_libraries(runTests_ex03 gtest gtest_main pthread)
#endif()
#add_test(NAME runTests_ex03 COMMAND runTests_ex03)