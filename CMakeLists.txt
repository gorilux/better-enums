cmake_minimum_required(VERSION 3.18)

project(better-enums)

add_library(better-enums INTERFACE)

target_include_directories ( better-enums INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} )


