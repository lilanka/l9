cmake_minimum_required(VERSION 3.23)
project(cc)

add_executable(cc
  main.c
  compiler.c
  scanner.c
  debug.c
)
