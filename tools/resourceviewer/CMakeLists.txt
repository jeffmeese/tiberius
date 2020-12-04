cmake_minimum_required(VERSION 3.5)

project(resourceviewer LANGUAGES CXX)

set(TARGET_NAME resourceviewer)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets)

set(HDR_FILES
  application/mainwindow.h
  graphics/imageindexgroup.h
  languages/stringtablemodel.h
  model/gameitem.h
  model/graphicsitem.h
  model/imageitem.h
  model/languageitem.h
  model/mapitem.h
  model/messagedataitem.h
  model/messageitem.h
  model/resourceitem.h
  model/textdataitem.h
  model/savedgamesitem.h
  model/smkitem.h
  properties/property.h
  properties/propertiesmodel.h
)

set(SRC_FILES
  main.cpp
  application/mainwindow.cpp
  graphics/imageindexgroup.cpp
  languages/stringtablemodel.cpp
  model/gameitem.cpp
  model/graphicsitem.cpp
  model/imageitem.cpp
  model/languageitem.cpp
  model/mapitem.cpp
  model/messagedataitem.cpp
  model/messageitem.cpp
  model/resourceitem.cpp
  model/textdataitem.cpp
  model/savedgamesitem.cpp
  model/smkitem.cpp
  properties/property.cpp
  properties/propertiesmodel.cpp
)

set(UI_FILES
  application/mainwindow.ui
  videos/smkwidget.ui
)

if (WIN32)
  add_executable(${TARGET_NAME} WIN32 ${HDR_FILES} ${SRC_FILES} ${UI_FILES})
else()
  add_executable(${TARGET_NAME} ${HDR_FILES} ${SRC_FILES} ${UI_FILES})
endif()

if (MSVC)
  target_compile_definitions(${TARGET_NAME} PRIVATE -D_CRT_SECURE_NO_WARNINGS)
  target_compile_definitions(${TARGET_NAME} PRIVATE -DTIBERIUS_IMPORT)
endif()

target_link_libraries(${TARGET_NAME} tiberius)
