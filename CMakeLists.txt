cmake_minimum_required(VERSION 2.8)
project(lineup CXX)

add_subdirectory(Source)
include_directories(Include/lineup)

add_library(
  lineup
  STATIC
  ${lineupSourceFiles}
)

ADD_DEFINITIONS(-std=c++11)
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")

add_subdirectory(Tests)
enable_testing()
add_test(NAME Test COMMAND Test)

