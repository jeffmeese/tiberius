cmake_minimum_required(VERSION 3.5)

project(tinyfd LANGUAGES C)
set(TARGET_NAME tinyfd)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${TARGET_NAME} STATIC tinyfiledialogs.h tinyfiledialogs.c)
