
cmake_minimum_required(VERSION 3.25)

project(
    cpp_cross_platform_ci
    VERSION 1.0.0
    DESCRIPTION "Cross-platform C++ CI/CD training project"
    LANGUAGES CXX
)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(BUILD_TESTING "Build unit tests" ON)
option(ENABLE_WARNINGS "Enable compiler warnings" ON)

# Library
add_library(tinycore
    src/calculator.cpp
)

target_include_directories(tinycore
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Compiler warnings
if(ENABLE_WARNINGS)
    if(MSVC)
        target_compile_options(tinycore PRIVATE /W4 /WX)
    else()
        target_compile_options(tinycore PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
        )
    endif()
endif()

# Application
add_executable(tinycalc
    src/main.cpp
)

target_link_libraries(tinycalc
    PRIVATE tinycore
)

if(ENABLE_WARNINGS)
    if(MSVC)
        target_compile_options(tinycalc PRIVATE /W4 /WX)
    else()
        target_compile_options(tinycalc PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
        )
    endif()
endif()

# Tests
if(BUILD_TESTING)
    include(CTest)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    )

    # Avoid overriding parent project compiler/linker settings on Windows.
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(tinycore_tests
        tests/test_calculator.cpp
    )

    target_link_libraries(tinycore_tests
        PRIVATE
            tinycore
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(tinycore_tests)
endif()
