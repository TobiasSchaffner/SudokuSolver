project(sudokuShared)
project(sudokuEntry)
set (SOURCE_FILES move.cpp gameboard.cpp ../include/board-initializer.h board-initializer.cpp)
set (ENTRY main.cpp)

include_directories(../include)
add_library(sudokuShared ${SOURCE_FILES})
add_executable(sudokuEntry ${ENTRY})
target_link_libraries(sudokuEntry sudokuShared)

