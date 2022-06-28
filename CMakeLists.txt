cmake_minimum_required(VERSION 3.23)
project(cc)

add_executable(cc
  src/main.cc
  src/code.cc
  src/vm.cc
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
)
