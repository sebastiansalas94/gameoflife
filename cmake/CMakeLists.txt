cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

get_filename_component(abs_include_dir "../app/source/" REALPATH)
set(include_dirs ${abs_include_dir})
include_directories(${include_dirs})

file(GLOB_RECURSE source_files "../app/source/*.cpp" "../app/source/*.h")

include("filtersMacro.txt")
setupVsFilters()

include("testMacro.txt")
enableGoogleTest(source_files)

#add_library(GameOfLife SHARED ${source_files})
add_executable(GameOfLife ${source_files})
#add_subdirectory(OVERLOGGER_DLL OVERLOGGER_ALL/DLL)