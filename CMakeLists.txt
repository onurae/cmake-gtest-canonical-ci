# Minimum CMake version
cmake_minimum_required(VERSION 3.14)

# Name of the project
project(cmake-gtest-canonical-ci)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Static library
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/*.?pp)
list(FILTER SOURCES EXCLUDE REGEX ".test.cpp")
add_library(Calculator STATIC ${SOURCES})

# Google test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Unit test project
file(GLOB TEST_SOURCES ${PROJECT_NAME}/*.test.cpp)
add_executable(CalculatorTest ${TEST_SOURCES})
target_link_libraries(CalculatorTest
    PRIVATE Calculator
    PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(CalculatorTest)