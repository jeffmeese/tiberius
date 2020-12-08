cmake_minimum_required(VERSION 3.5)

project(gamedump LANGUAGES CXX)

set(TARGET_NAME ${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core)

set(SRC_FILES
  main.cpp
)

add_executable(${TARGET_NAME} ${HDR_FILES} ${SRC_FILES} ${UI_FILES})

if (MSVC)
  target_compile_definitions(${TARGET_NAME} PRIVATE -D_CRT_SECURE_NO_WARNINGS)
  target_compile_definitions(${TARGET_NAME} PRIVATE -DTIBERIUS_IMPORT)
endif()

target_link_libraries(${TARGET_NAME} tiberius)
