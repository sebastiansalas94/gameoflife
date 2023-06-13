cmake_minimum_required(VERSION 3.10)

project(GameOfLifeApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(source_dirs "../source")

include("../../cmake/testMacro.txt")

file(GLOB_RECURSE src_files "${source_dirs}/*.cpp" "${source_dirs}/*.h")

enableGoogleTest(header_files src_files)