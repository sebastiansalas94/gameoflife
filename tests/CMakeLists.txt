cmake_minimum_required(VERSION 3.10)

project(GameOfLifeTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(source_dirs "../lib/include")

include("../cmake/testMacro.txt")

file(GLOB_RECURSE src_files "${source_dirs}/*.cpp" "${source_dirs}/*.h")

#message(APP_SOURCE_FILES="${src_files}")
#message(PROJECT_NAME="${PROJECT_NAME}")

enableGoogleTest(${PROJECT_NAME} src_files)