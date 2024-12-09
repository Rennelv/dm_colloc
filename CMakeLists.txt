cmake_minimum_required(VERSION 3.22)
project(dm_math LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
# Ensure that the standard is required and doesn't fall back to a lower version
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Use only standard C++ features

message(STATUS "CMake Generator: ${CMAKE_GENERATOR}")

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building in Debug mode")
else()
    message(STATUS "Building in Release mode")
endif()

# Set output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Ensure static linking for GCC/MinGW
if(MINGW)
    message(STATUS "Building in MinGW environment")
    # Force static linking
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    set(BUILD_SHARED_LIBS OFF)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static")
endif()
    
# Set compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
include(FetchContent)
    
set(ENABLE_DOXYGEN ON CACHE BOOL "Enable Doxygen")

if (ENABLE_DOXYGEN)
    FetchContent_Declare(
        doxygen-awesome-css
        GIT_REPOSITORY https://github.com/jothepro/doxygen-awesome-css.git
        GIT_TAG v2.3.4
    )
    FetchContent_MakeAvailable(doxygen-awesome-css)

    # Save the location the files were cloned into
    # This allows us to get the path to doxygen-awesome.css
    FetchContent_GetProperties(doxygen-awesome-css SOURCE_DIR AWESOME_CSS_DIR)

    # Generate the Doxyfile
    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYFILE_OUT ${PROJECT_SOURCE_DIR}/Doxyfile)
    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)
endif()

# Check if GLFW is already installed
find_package(glfw3 QUIET)

if ((NOT glfw3_FOUND) AND MINGW)
    message(WARNING "GLFW not found. Fetching and building GLFW locally. Its better to install GLFW system-wide first.")
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
    )
    FetchContent_MakeAvailable(glfw)
else()
    message(STATUS "GLFW found.")
endif()

# Conditionally add ImGui
FetchContent_Declare(
    imgui_external
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.91.4
    EXCLUDE_FROM_ALL
)

FetchContent_MakeAvailable(imgui_external)

add_library(imgui
${imgui_external_SOURCE_DIR}/imgui.cpp
${imgui_external_SOURCE_DIR}/imgui_draw.cpp
${imgui_external_SOURCE_DIR}/imgui_tables.cpp
${imgui_external_SOURCE_DIR}/imgui_widgets.cpp
${imgui_external_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
${imgui_external_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)
if (glfw3_FOUND)
    target_include_directories(imgui PUBLIC ${imgui_external_SOURCE_DIR})
else()
    target_include_directories(imgui PUBLIC ${imgui_external_SOURCE_DIR} ${glfw_SOURCE_DIR}/include)
endif()
include(FetchContent)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Recursively find all source files in the src directory
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

message(STATUS "Compiler flags: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")

# Add the executable target
if (MINGW AND (EXISTS "${PROJECT_SOURCE_DIR}/app.rc"))
    add_executable(dm_math ${SOURCES} ${PROJECT_SOURCE_DIR}/app.rc)
else()
    add_executable(dm_math ${SOURCES})
endif()

# Link libraries
find_package(OpenGL REQUIRED)
# find_package(glfw3 REQUIRED)
target_link_libraries(dm_math OpenGL::GL glfw imgui)

# Enable Unity Builds option
option(ENABLE_UNITY "Enable Unity Builds for faster compile times" OFF)
if(ENABLE_UNITY)
    set_target_properties(dm_math PROPERTIES UNITY_BUILD ON)
    message(STATUS "Unity Build enabled for faster compile times")
endif()

# Define a custom option to generate tests
option(COMPILE_TESTS "Generate tests" OFF)

# Add tests only if requested
if (COMPILE_TESTS)
    # Recursively find all source files for test dependencies
    file(GLOB_RECURSE SOURCES_FOR_TESTS
        "${PROJECT_SOURCE_DIR}/src/N/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/P/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Q/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Z/*.cpp"
    )

    # Find and link the GTest library
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # Enable testing
    enable_testing()

    # Recursively find all test files
    file(GLOB_RECURSE TEST_SOURCES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

    # Create executable for tests
    add_executable(dm_tests ${TEST_SOURCES} ${SOURCES_FOR_TESTS} )
    
    # Set Unity Build for tests if enabled
    if(ENABLE_UNITY)
        set_target_properties(dm_tests PROPERTIES UNITY_BUILD ON)
    endif()

    # Link tests with the main library and GTest
    target_link_libraries(dm_tests ${GTEST_LIBRARIES} pthread)

    # Add tests to CTest
    add_test(NAME dm_tests COMMAND dm_tests)

    include(GoogleTest)
    gtest_discover_tests(dm_tests)
endif()
