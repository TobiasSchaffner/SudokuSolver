cmake_minimum_required(VERSION 2.8.7)

set(CMAKE_CXX_STANDARD 14)

project(sudoku)

add_subdirectory(src)
add_subdirectory(test)

include_directories(include)

enable_testing()
add_test(NAME SudokuTest COMMAND sudokuTest)
