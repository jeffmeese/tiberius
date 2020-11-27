cmake_minimum_required(VERSION 3.5)

project(tiberius LANGUAGES CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory(src)
add_subdirectory(tiberius)
add_subdirectory(resourceviewer)
#add_subdirectory(decompress)
