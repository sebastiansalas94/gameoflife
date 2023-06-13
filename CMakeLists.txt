cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(lib GameOfLife/Lib)
add_subdirectory(tests GameOfLife/Tests)
add_subdirectory(app GameOfLife/App)