cmake_minimum_required(VERSION 3.22)
project(dm_math LANGUAGES CXX)

# # Check for Ninja and set it as the default generator if available
# find_program(NINJA_EXECUTABLE ninja)
# if ((NOT (CMAKE_GENERATOR STREQUAL "Ninja")) AND NINJA_EXECUTABLE AND (CMAKE_GENERATOR STREQUAL "Unix Makefiles"))
#     set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "Default generator")
#     message(STATUS "Ninja build system found. Using Ninja as the default generator")
# endif()


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building in Debug mode")
    # Export compile_commands.json
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
else()
    message(STATUS "Building in Release mode")
endif()

# Set the output directory for the compiled binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Ensure static linking for GCC/MinGW
if(MINGW)
    message(STATUS "Building in MinGW environment")
    # Force static linking
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    set(BUILD_SHARED_LIBS OFF)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static")
endif()

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Recursively find all source files in the src directory
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Add the executable target
add_executable(dm_math ${SOURCES})

# Set compiler flags for debugging
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic")

# Optionally, you can add more configurations, such as release flags
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Создаем тесты только в режиме отладки 
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Recursively find all source files in the src directory
    file(GLOB_RECURSE SOURCES_FOR_TESTS
        "${PROJECT_SOURCE_DIR}/src/N/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/P/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Q/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Z/*.cpp"
    )

    # Найти и подключить библиотеку GTest
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # Включить тестирование
    enable_testing()

    # Рекурсивно найти все тестовые файлы в папке tests и добавить их в список TEST_SOURCES
    file(GLOB_RECURSE TEST_SOURCES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

    # Создать исполняемый файл для всех тестов
    add_executable(dm_tests ${TEST_SOURCES} ${SOURCES_FOR_TESTS} )

    # Слинковать тесты с основной библиотекой и GTest
    target_link_libraries(dm_tests ${GTEST_LIBRARIES} pthread)

    # Добавить тесты в CTest
    add_test(NAME dm_tests COMMAND dm_tests)

    include(GoogleTest)
    gtest_discover_tests(dm_tests)
endif()