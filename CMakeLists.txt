cmake_minimum_required(VERSION 3.14)
project(leetcode-solutions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB PROBLEM_FILES "problems/*.cpp")

foreach(PROBLEM_FILE ${PROBLEM_FILES})
    get_filename_component(PROBLEM_NAME ${PROBLEM_FILE} NAME_WE)
    add_executable(${PROBLEM_NAME} ${PROBLEM_FILE})
    target_link_libraries(${PROBLEM_NAME} gtest_main)
    add_test(NAME ${PROBLEM_NAME} COMMAND ${PROBLEM_NAME})
endforeach()