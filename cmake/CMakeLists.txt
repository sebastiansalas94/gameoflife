# TODO 1: Set the minimum required version of CMake to be 3.10
cmake_minimum_required(VERSION 3.10)

# TODO 2: Create a project named Tutorial
project(GameOfLife)

# TODO 7: Set the project version number as 1.0 in the above project command

# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h

# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx
#add_executable(GameOfLife ../app/source/main.cpp)

# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}
#get_filename_component(source_root "app/source/" REALPATH)
#set(include_dirs ${source_root})
#include_directories(${include_dirs})

get_filename_component(abs_include_dir "../app/source/" REALPATH)
set(include_dirs ${abs_include_dir})
include_directories(${include_dirs})

file(GLOB_RECURSE source_files "../app/source/*.cpp" "../app/source/*.h")

include("filtersMacro.txt")

setupVsFilters()

add_library(GameOfLife SHARED ${source_files})
#add_executable(GameOfLife source_files)
#add_subdirectory(OVERLOGGER_DLL OVERLOGGER_ALL/DLL)