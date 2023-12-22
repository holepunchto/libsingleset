cmake_minimum_required(VERSION 3.22)

project(singleset C)

add_library(singleset INTERFACE)
target_include_directories(singleset INTERFACE include)

if(PROJECT_IS_TOP_LEVEL)
  add_subdirectory(examples)
endif()
