cmake_minimum_required(VERSION 3.5)

project(gridview LANGUAGES CXX)

set(TARGET_NAME ${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets)

set(HDR_FILES
  application/application.h
  application/gridview.h
  application/mainwindow.h
)

set(SRC_FILES
  main.cpp
  application/application.cpp
  application/gridview.cpp
  application/mainwindow.cpp
)

set(UI_FILES
  application/mainwindow.ui
)

if (WIN32)
  add_executable(${TARGET_NAME} WIN32 ${HDR_FILES} ${SRC_FILES} ${UI_FILES})
else()
  add_executable(${TARGET_NAME} ${HDR_FILES} ${SRC_FILES} ${UI_FILES})
endif()

if (MSVC)
  target_compile_definitions(${TARGET_NAME} PRIVATE -D_CRT_SECURE_NO_WARNINGS)
  target_compile_definitions(${TARGET_NAME} PUBLIC -DTIBERIUS_IMPORT)
endif()

target_link_libraries(${TARGET_NAME} tiberius)
