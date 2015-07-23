cmake_minimum_required(VERSION 2.8)
project(lineup CXX)

add_subdirectory(src)
include_directories(include/lineup)
include_directories(opt/catch/include)

add_library(
  lineup
  STATIC
  ${lineupSourceFiles}
)

ADD_DEFINITIONS(-std=c++11)
SET(CMAKE_EXE_LINKER_FLAGS "-pthread")

add_executable(lineupApp src/main.cc)
target_link_libraries(lineupApp lineup)

add_subdirectory(test)
enable_testing()
add_test(NAME lineupTest COMMAND lineupTest)

