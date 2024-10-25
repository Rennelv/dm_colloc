cmake_minimum_required(VERSION 3.22)
project(dm_math_tests LANGUAGES CXX)

# Set the output directory for the compiled binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Set the project directory
set(PROJECT_DIR ${PROJECT_SOURCE_DIR}/..)

# Include directories
include_directories(${PROJECT_DIR}/include)

# Recursively find all test source files in the test directory
file(GLOB_RECURSE TEST_SOURCES
    "${PROJECT_SOURCE_DIR}/N/*.cpp"
    "${PROJECT_SOURCE_DIR}/P/*.cpp"
    "${PROJECT_SOURCE_DIR}/Z/*.cpp"
    "${PROJECT_SOURCE_DIR}/Q/*.cpp"
    "${PROJECT_SOURCE_DIR}/tests.cpp"

)

# Recursively find all source files in the source directory
file(GLOB_RECURSE SOURCES
    "${PROJECT_DIR}/src/N/*.cpp"
    "${PROJECT_DIR}/src/P/*.cpp"
    "${PROJECT_DIR}/src/Z/*.cpp"
    "${PROJECT_DIR}/src/Q/*.cpp"
)

# Add the test executable target
add_executable(dm_math_tests ${TEST_SOURCES} ${SOURCES})

# Link the Google Test libraries and the main project library
target_link_libraries(dm_math_tests ${GTEST_LIBRARIES} pthread)
