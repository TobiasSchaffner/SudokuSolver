project(sudokuShared)
project(sudokuEntry)

set (SOURCE_FILES move.cpp gameboard.cpp ../include/board-initializer.h board-initializer.cpp ../include/solver.h solver.cpp)
set (ENTRY main.cpp)

include_directories(../include)
add_library(sudokuShared ${SOURCE_FILES} util.cpp)
add_executable(sudokuEntry ${ENTRY} util.cpp)
target_link_libraries(sudokuEntry sudokuShared)

