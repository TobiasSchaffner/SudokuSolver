cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)


include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "C:/Users/confix/Desktop/blatt-2-sudoku07-1/cmake-build-debug/test/googletest-src"
  BINARY_DIR        "C:/Users/confix/Desktop/blatt-2-sudoku07-1/cmake-build-debug/test/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
