project(sudokuShared)
project(sudokuEntry)

set (SOURCE_FILES move.cpp gameboard.cpp ../include/board-initializer.h board-initializer.cpp tobi-solver.cpp flo-solver.cpp)
set (ENTRY main.cpp ../include/solver.h ../include/tobi-solver.h ../include/flo-solver.h ../include/kp.h ../include/exception/no-such-move-exception.h)

include_directories(../include)
add_library(sudokuShared ${SOURCE_FILES} util.cpp)
add_executable(sudokuEntry ${ENTRY} util.cpp)
target_link_libraries(sudokuEntry sudokuShared)

