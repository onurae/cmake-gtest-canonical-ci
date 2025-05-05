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
target_include_directories(Calculator
    PUBLIC ${PROJECT_SOURCE_DIR}
)

# Google test
include(FetchContent)
message(STATUS "Fetching googletest library...")
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG 6910c9d9165801d8827d628cb72eb7ea9dd538c5 # release-1.16.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing in CMake
enable_testing()

# Unit test project
file(GLOB TEST_SOURCES ${PROJECT_NAME}/*.test.cpp)
add_executable(CalculatorTest ${TEST_SOURCES})
target_link_libraries(CalculatorTest
    PRIVATE Calculator
    PRIVATE GTest::gtest_main
)

# Enable CMake’s test runner to discover the tests
include(GoogleTest)
gtest_discover_tests(CalculatorTest)
