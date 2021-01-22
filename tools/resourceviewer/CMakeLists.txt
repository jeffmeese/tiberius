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
  model/aqueductgriditem.h
  model/buildinggriditem.h
  model/damagegriditem.h
  model/desirabilitygriditem.h
  model/demandchangegroup.h
  model/demandchangeitem.h
  model/edgegriditem.h
  model/elevationgriditem.h
  model/empirecitygroup.h
  model/empirecityitem.h
  model/fishingpointgroup.h
  model/fishingpointitem.h
  model/herdpointgroup.h
  model/herdpointitem.h
  model/gamegridgroup.h
  model/gameitem.h
  model/goalsitem.h
  model/graphicgriditem.h
  model/graphicsitem.h
  model/gridgroup.h
  model/imageitem.h
  model/invasiongroup.h
  model/invasionitem.h
  model/invasionpointsgroup.h
  model/invasionpointsitem.h
  model/languageitem.h
  model/mapitem.h
  model/merginggriditem.h
  model/messagedataitem.h
  model/messageitem.h
  model/pricechangegroup.h
  model/pricechangeitem.h
  model/randomeventsitem.h
  model/requestgroup.h
  model/requestitem.h
  model/resourceitem.h
  model/savedgamesitem.h
  model/smkitem.h
  model/terraingriditem.h
  model/textdataitem.h
  model/walkergriditem.h
  properties/property.h
  properties/propertiesmodel.h
  views/gridview.h
  widgets/smkwidget.h
)

set(SRC_FILES
  main.cpp
  application/mainwindow.cpp
  graphics/imageindexgroup.cpp
  languages/stringtablemodel.cpp
  model/aqueductgriditem.cpp
  model/buildinggriditem.cpp
  model/damagegriditem.cpp
  model/desirabilitygriditem.cpp
  model/demandchangegroup.cpp
  model/demandchangeitem.cpp
  model/edgegriditem.cpp
  model/elevationgriditem.cpp
  model/empirecitygroup.cpp
  model/empirecityitem.cpp
  model/fishingpointgroup.cpp
  model/fishingpointitem.cpp
  model/herdpointgroup.cpp
  model/herdpointitem.cpp
  model/gamegridgroup.cpp
  model/gameitem.cpp
  model/goalsitem.cpp
  model/gridgroup.cpp
  model/graphicgriditem.cpp
  model/graphicsitem.cpp
  model/imageitem.cpp
  model/invasiongroup.cpp
  model/invasionitem.cpp
  model/invasionpointsgroup.cpp
  model/invasionpointsitem.cpp
  model/languageitem.cpp
  model/mapitem.cpp
  model/messagedataitem.cpp
  model/messageitem.cpp
  model/merginggriditem.cpp
  model/pricechangegroup.cpp
  model/pricechangeitem.cpp
  model/randomeventsitem.cpp
  model/requestgroup.cpp
  model/requestitem.cpp
  model/resourceitem.cpp
  model/terraingriditem.cpp
  model/savedgamesitem.cpp
  model/smkitem.cpp
  model/textdataitem.cpp
  model/walkergriditem.cpp
  properties/property.cpp
  properties/propertiesmodel.cpp
  views/gridview.cpp
  widgets/smkwidget.cpp
)

set(UI_FILES
  application/mainwindow.ui
  widgets/smkwidget.ui
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
