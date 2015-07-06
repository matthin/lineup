set(TestSourceFiles
  ${CMAKE_CURRENT_SOURCE_DIR}/Compiler.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/Tokenizer.cc
)

include_directories(.)

add_executable(Test ${TestSourceFiles})
target_link_libraries(
  Test
  lineup
)

