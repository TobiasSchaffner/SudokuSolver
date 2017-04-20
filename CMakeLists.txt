cmake_minimum_required(VERSION 3.6)
project(sudoku)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp gameboard.h gameboard.cpp cmake-build-debug/step.h)
add_executable(sudoku ${SOURCE_FILES})