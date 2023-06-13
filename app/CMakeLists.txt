cmake_minimum_required(VERSION 3.10)

project(GameOfLifeApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

get_filename_component(abs_include_dir "../lib/include/" REALPATH)
set(include_dirs ${abs_include_dir})
include_directories(${include_dirs})

file(GLOB_RECURSE source_files "source/*.cpp" "source/*.h")

include("../cmake/filtersMacro.txt")
setupVsFilters()

#include("testMacro.txt")
#enableGoogleTest(source_files)

add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries(
        ${PROJECT_NAME}
		GameOfLifeLib
    )