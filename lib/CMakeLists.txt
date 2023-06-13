cmake_minimum_required(VERSION 3.10)

project(GameOfLifeLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

get_filename_component(abs_include_dir "include/" REALPATH)
set(include_dirs ${abs_include_dir})
include_directories(${include_dirs})

file(GLOB_RECURSE source_files "source/*.cpp" "include/*.h")

include("../cmake/filtersMacro.txt")
setupVsFilters()

add_library(GameOfLifeLib ${source_files})