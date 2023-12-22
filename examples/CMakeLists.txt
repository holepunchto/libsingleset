cmake_minimum_required(VERSION 3.25)

project(example)
add_executable(example example.c)

target_link_libraries(
  example
  PUBLIC
    singleset
)
