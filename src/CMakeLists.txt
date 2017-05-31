project(sudokuShared)
project(sudokuEntry)

set (SOURCE_FILES move.cpp gameboard.cpp ../include/board-initializer.h board-initializer.cpp solver.cpp generator.cpp ../include/generator.h)
set (ENTRY main.cpp ../include/solvers.h ../include/solver.h ../include/kp.h ../include/exception/no-such-move-exception.h)

include_directories(../include)
add_library(sudokuShared ${SOURCE_FILES} util.cpp generator.cpp ../include/generator.h)
add_executable(sudokuEntry ${ENTRY} util.cpp generator.cpp ../include/generator.h)
target_link_libraries(sudokuEntry sudokuShared)

