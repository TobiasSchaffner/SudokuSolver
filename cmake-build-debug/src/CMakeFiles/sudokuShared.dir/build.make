# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\confix\Desktop\blatt-2-sudoku07-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/sudokuShared.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/sudokuShared.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/sudokuShared.dir/flags.make

src/CMakeFiles/sudokuShared.dir/move.cpp.obj: src/CMakeFiles/sudokuShared.dir/flags.make
src/CMakeFiles/sudokuShared.dir/move.cpp.obj: src/CMakeFiles/sudokuShared.dir/includes_CXX.rsp
src/CMakeFiles/sudokuShared.dir/move.cpp.obj: ../src/move.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/sudokuShared.dir/move.cpp.obj"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sudokuShared.dir\move.cpp.obj -c C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\move.cpp

src/CMakeFiles/sudokuShared.dir/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudokuShared.dir/move.cpp.i"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\move.cpp > CMakeFiles\sudokuShared.dir\move.cpp.i

src/CMakeFiles/sudokuShared.dir/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudokuShared.dir/move.cpp.s"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\move.cpp -o CMakeFiles\sudokuShared.dir\move.cpp.s

src/CMakeFiles/sudokuShared.dir/move.cpp.obj.requires:

.PHONY : src/CMakeFiles/sudokuShared.dir/move.cpp.obj.requires

src/CMakeFiles/sudokuShared.dir/move.cpp.obj.provides: src/CMakeFiles/sudokuShared.dir/move.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\sudokuShared.dir\build.make src/CMakeFiles/sudokuShared.dir/move.cpp.obj.provides.build
.PHONY : src/CMakeFiles/sudokuShared.dir/move.cpp.obj.provides

src/CMakeFiles/sudokuShared.dir/move.cpp.obj.provides.build: src/CMakeFiles/sudokuShared.dir/move.cpp.obj


src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj: src/CMakeFiles/sudokuShared.dir/flags.make
src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj: src/CMakeFiles/sudokuShared.dir/includes_CXX.rsp
src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj: ../src/gameboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sudokuShared.dir\gameboard.cpp.obj -c C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\gameboard.cpp

src/CMakeFiles/sudokuShared.dir/gameboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudokuShared.dir/gameboard.cpp.i"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\gameboard.cpp > CMakeFiles\sudokuShared.dir\gameboard.cpp.i

src/CMakeFiles/sudokuShared.dir/gameboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudokuShared.dir/gameboard.cpp.s"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\gameboard.cpp -o CMakeFiles\sudokuShared.dir\gameboard.cpp.s

src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj.requires:

.PHONY : src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj.requires

src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj.provides: src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\sudokuShared.dir\build.make src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj.provides.build
.PHONY : src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj.provides

src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj.provides.build: src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj


src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj: src/CMakeFiles/sudokuShared.dir/flags.make
src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj: src/CMakeFiles/sudokuShared.dir/includes_CXX.rsp
src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj: ../src/board-initializer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sudokuShared.dir\board-initializer.cpp.obj -c C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\board-initializer.cpp

src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudokuShared.dir/board-initializer.cpp.i"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\board-initializer.cpp > CMakeFiles\sudokuShared.dir\board-initializer.cpp.i

src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudokuShared.dir/board-initializer.cpp.s"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\board-initializer.cpp -o CMakeFiles\sudokuShared.dir\board-initializer.cpp.s

src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj.requires:

.PHONY : src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj.requires

src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj.provides: src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\sudokuShared.dir\build.make src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj.provides.build
.PHONY : src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj.provides

src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj.provides.build: src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj


src/CMakeFiles/sudokuShared.dir/solver.cpp.obj: src/CMakeFiles/sudokuShared.dir/flags.make
src/CMakeFiles/sudokuShared.dir/solver.cpp.obj: src/CMakeFiles/sudokuShared.dir/includes_CXX.rsp
src/CMakeFiles/sudokuShared.dir/solver.cpp.obj: ../src/solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/sudokuShared.dir/solver.cpp.obj"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sudokuShared.dir\solver.cpp.obj -c C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\solver.cpp

src/CMakeFiles/sudokuShared.dir/solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudokuShared.dir/solver.cpp.i"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\solver.cpp > CMakeFiles\sudokuShared.dir\solver.cpp.i

src/CMakeFiles/sudokuShared.dir/solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudokuShared.dir/solver.cpp.s"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\solver.cpp -o CMakeFiles\sudokuShared.dir\solver.cpp.s

src/CMakeFiles/sudokuShared.dir/solver.cpp.obj.requires:

.PHONY : src/CMakeFiles/sudokuShared.dir/solver.cpp.obj.requires

src/CMakeFiles/sudokuShared.dir/solver.cpp.obj.provides: src/CMakeFiles/sudokuShared.dir/solver.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\sudokuShared.dir\build.make src/CMakeFiles/sudokuShared.dir/solver.cpp.obj.provides.build
.PHONY : src/CMakeFiles/sudokuShared.dir/solver.cpp.obj.provides

src/CMakeFiles/sudokuShared.dir/solver.cpp.obj.provides.build: src/CMakeFiles/sudokuShared.dir/solver.cpp.obj


src/CMakeFiles/sudokuShared.dir/generator.cpp.obj: src/CMakeFiles/sudokuShared.dir/flags.make
src/CMakeFiles/sudokuShared.dir/generator.cpp.obj: src/CMakeFiles/sudokuShared.dir/includes_CXX.rsp
src/CMakeFiles/sudokuShared.dir/generator.cpp.obj: ../src/generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/sudokuShared.dir/generator.cpp.obj"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sudokuShared.dir\generator.cpp.obj -c C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\generator.cpp

src/CMakeFiles/sudokuShared.dir/generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudokuShared.dir/generator.cpp.i"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\generator.cpp > CMakeFiles\sudokuShared.dir\generator.cpp.i

src/CMakeFiles/sudokuShared.dir/generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudokuShared.dir/generator.cpp.s"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\generator.cpp -o CMakeFiles\sudokuShared.dir\generator.cpp.s

src/CMakeFiles/sudokuShared.dir/generator.cpp.obj.requires:

.PHONY : src/CMakeFiles/sudokuShared.dir/generator.cpp.obj.requires

src/CMakeFiles/sudokuShared.dir/generator.cpp.obj.provides: src/CMakeFiles/sudokuShared.dir/generator.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\sudokuShared.dir\build.make src/CMakeFiles/sudokuShared.dir/generator.cpp.obj.provides.build
.PHONY : src/CMakeFiles/sudokuShared.dir/generator.cpp.obj.provides

src/CMakeFiles/sudokuShared.dir/generator.cpp.obj.provides.build: src/CMakeFiles/sudokuShared.dir/generator.cpp.obj


src/CMakeFiles/sudokuShared.dir/util.cpp.obj: src/CMakeFiles/sudokuShared.dir/flags.make
src/CMakeFiles/sudokuShared.dir/util.cpp.obj: src/CMakeFiles/sudokuShared.dir/includes_CXX.rsp
src/CMakeFiles/sudokuShared.dir/util.cpp.obj: ../src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/sudokuShared.dir/util.cpp.obj"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sudokuShared.dir\util.cpp.obj -c C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\util.cpp

src/CMakeFiles/sudokuShared.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sudokuShared.dir/util.cpp.i"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\util.cpp > CMakeFiles\sudokuShared.dir\util.cpp.i

src/CMakeFiles/sudokuShared.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sudokuShared.dir/util.cpp.s"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\confix\Desktop\blatt-2-sudoku07-1\src\util.cpp -o CMakeFiles\sudokuShared.dir\util.cpp.s

src/CMakeFiles/sudokuShared.dir/util.cpp.obj.requires:

.PHONY : src/CMakeFiles/sudokuShared.dir/util.cpp.obj.requires

src/CMakeFiles/sudokuShared.dir/util.cpp.obj.provides: src/CMakeFiles/sudokuShared.dir/util.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\sudokuShared.dir\build.make src/CMakeFiles/sudokuShared.dir/util.cpp.obj.provides.build
.PHONY : src/CMakeFiles/sudokuShared.dir/util.cpp.obj.provides

src/CMakeFiles/sudokuShared.dir/util.cpp.obj.provides.build: src/CMakeFiles/sudokuShared.dir/util.cpp.obj


# Object files for target sudokuShared
sudokuShared_OBJECTS = \
"CMakeFiles/sudokuShared.dir/move.cpp.obj" \
"CMakeFiles/sudokuShared.dir/gameboard.cpp.obj" \
"CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj" \
"CMakeFiles/sudokuShared.dir/solver.cpp.obj" \
"CMakeFiles/sudokuShared.dir/generator.cpp.obj" \
"CMakeFiles/sudokuShared.dir/util.cpp.obj"

# External object files for target sudokuShared
sudokuShared_EXTERNAL_OBJECTS =

src/libsudokuShared.a: src/CMakeFiles/sudokuShared.dir/move.cpp.obj
src/libsudokuShared.a: src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj
src/libsudokuShared.a: src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj
src/libsudokuShared.a: src/CMakeFiles/sudokuShared.dir/solver.cpp.obj
src/libsudokuShared.a: src/CMakeFiles/sudokuShared.dir/generator.cpp.obj
src/libsudokuShared.a: src/CMakeFiles/sudokuShared.dir/util.cpp.obj
src/libsudokuShared.a: src/CMakeFiles/sudokuShared.dir/build.make
src/libsudokuShared.a: src/CMakeFiles/sudokuShared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libsudokuShared.a"
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\sudokuShared.dir\cmake_clean_target.cmake
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sudokuShared.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/sudokuShared.dir/build: src/libsudokuShared.a

.PHONY : src/CMakeFiles/sudokuShared.dir/build

src/CMakeFiles/sudokuShared.dir/requires: src/CMakeFiles/sudokuShared.dir/move.cpp.obj.requires
src/CMakeFiles/sudokuShared.dir/requires: src/CMakeFiles/sudokuShared.dir/gameboard.cpp.obj.requires
src/CMakeFiles/sudokuShared.dir/requires: src/CMakeFiles/sudokuShared.dir/board-initializer.cpp.obj.requires
src/CMakeFiles/sudokuShared.dir/requires: src/CMakeFiles/sudokuShared.dir/solver.cpp.obj.requires
src/CMakeFiles/sudokuShared.dir/requires: src/CMakeFiles/sudokuShared.dir/generator.cpp.obj.requires
src/CMakeFiles/sudokuShared.dir/requires: src/CMakeFiles/sudokuShared.dir/util.cpp.obj.requires

.PHONY : src/CMakeFiles/sudokuShared.dir/requires

src/CMakeFiles/sudokuShared.dir/clean:
	cd /d C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\sudokuShared.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/sudokuShared.dir/clean

src/CMakeFiles/sudokuShared.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\confix\Desktop\blatt-2-sudoku07-1 C:\Users\confix\Desktop\blatt-2-sudoku07-1\src C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src C:\Users\confix\Desktop\blatt-2-sudoku07-1\cmake-build-debug\src\CMakeFiles\sudokuShared.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/sudokuShared.dir/depend

