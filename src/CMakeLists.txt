cmake_minimum_required(VERSION 3.5)

project(tiberius LANGUAGES C CXX)
set(TARGET_NAME tiberius)

# Define options
option(TIBERIUS_BUILD_SHARED "Set to ON to build as a shared library" ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)

add_subdirectory(3rdparty/libsmacker)
add_subdirectory(3rdparty/tinyfiledialogs)

set(HDR_FILES
  tiberius.h
  application/tiberiusapplication.h
  advisor/advisor.h
  building/building.h
  city/buildingdata.h
  city/camera.h
  city/city.h
  city/data.h
  city/datamodel.h
  city/datavector.h
  city/educationdata.h
  city/empiredata.h
  city/entertainmentdata.h
  city/financedata.h
  city/healthdata.h
  city/imperialdata.h
  city/labordata.h
  city/militarydata.h
  city/populationdata.h
  city/ratingsdata.h
  city/resourcedata.h
  city/religiondata.h
  city/routedata.h
  city/scenariodata.h
  city/scribemessage.h
  city/scribemessagedata.h
  city/tradedata.h
  city/walkerdata.h
  core/abstractfactory.h
  core/painter.h
  core/streamio.h
  dialog/dialog.h
  dialog/filedialog.h
  dialog/messagedialog.h
  entertainment/festival.h
  empire/city.h
  event/demandchange.h
  event/earthquake.h
  event/emperorchange.h
  event/emperorrequest.h
  event/empireexpansion.h
  event/event.h
  event/gladiatorrevolt.h
  event/pricechange.h
  figure/figure.h
  game/difficulty.h
  game/direction.h
  game/game.h
  game/player.h
  graphics/font.h
  graphics/imagedata.h
  graphics/imagegroups.h
  graphics/imageset.h
  graphics/sgimagedata.h
  graphics/sgimagegroup.h
  graphics/sgimagerecord.h
  graphics/sgpixeldata.h
  graphics/stitchedimage.h
  imperial/gift.h
  imperial/request.h
  language/language.h
  language/message.h
  language/messagedata.h
  language/stringdata.h
  language/stringdatagroup.h
  map/bookmark.h
  map/grid.h
  map/location.h
  map/map.h
  media/sound.h
  media/sounddata.h
  media/sounds.h
  media/video.h
  media/videos.h
  media/videodata.h
  military/invasion.h
  military/legion.h
  military/soldier.h
  religion/god.h
  resource/resource.h
  route/route.h
  scenario/goal.h
  scenario//scenario.h
  widget/buildmenu.h
  widget/buildmenuitem.h
  widget/button.h
  widget/citywidget.h
  widget/label.h
  widget/lineedit.h
  widget/listwidget.h
  widget/mapwidget.h
  widget/menu.h
  widget/menubar.h
  widget/messagewidget.h
  widget/panel.h
  widget/scrollbar.h
  widget/scrollwidget.h
  widget/textedit.h
  widget/tiberiuswidget.h
  zip/pkzipdata.h
)

set(SRC_FILES
  application/tiberiusapplication.cpp
  advisor/advisor.cpp
  building/building.cpp
  city/buildingdata.cpp
  city/camera.cpp
  city/city.cpp
  city/data.cpp
  city/datamodel.cpp
  city/educationdata.cpp
  city/empiredata.cpp
  city/entertainmentdata.cpp
  city/financedata.cpp
  city/healthdata.cpp
  city/imperialdata.cpp
  city/labordata.cpp
  city/militarydata.cpp
  city/populationdata.cpp
  city/ratingsdata.cpp
  city/religiondata.cpp
  city/resourcedata.cpp
  city/routedata.cpp
  city/scenariodata.cpp
  city/scribemessage.cpp
  city/scribemessagedata.cpp
  city/tradedata.cpp
  city/walkerdata.cpp
  core/painter.cpp
  core/streamio.cpp
  dialog/dialog.cpp
  dialog/filedialog.cpp
  dialog/messagedialog.cpp
  empire/city.cpp
  entertainment/festival.cpp
  event/demandchange.cpp
  event/earthquake.cpp
  event/emperorchange.cpp
  event/emperorrequest.cpp
  event/empireexpansion.cpp
  event/event.cpp
  event/gladiatorrevolt.cpp
  event/pricechange.cpp
  figure/figure.cpp
  game/difficulty.cpp
  game/game.cpp
  game/player.cpp
  graphics/font.cpp
  graphics/imagedata.cpp
  graphics/imageset.cpp
  graphics/sgimagedata.cpp
  graphics/sgimagegroup.cpp
  graphics/sgimagerecord.cpp
  graphics/sgpixeldata.cpp
  graphics/stitchedimage.cpp
  imperial/gift.cpp
  imperial/request.cpp
  language/language.cpp
  language/message.cpp
  language/messagedata.cpp
  language/stringdata.cpp
  language/stringdatagroup.cpp
  map/bookmark.cpp
  map/location.cpp
  map/map.cpp
  media/sound.cpp
  media/sounddata.cpp
  media/sounds.cpp
  media/video.cpp
  media/videos.cpp
  media/videodata.cpp
  military/invasion.cpp
  military/legion.cpp
  military/soldier.cpp
  religion/god.cpp
  resource/resource.cpp
  route/route.cpp
  scenario/goal.cpp
  scenario/scenario.cpp
  widget/buildmenu.cpp
  widget/buildmenuitem.cpp
  widget/button.cpp
  widget/citywidget.cpp
  widget/label.cpp
  widget/lineedit.cpp
  widget/listwidget.cpp
  widget/mapwidget.cpp
  widget/menu.cpp
  widget/menubar.cpp
  widget/messagewidget.cpp
  widget/panel.cpp
  widget/scrollbar.cpp
  widget/scrollwidget.cpp
  widget/textedit.cpp
  widget/tiberiuswidget.cpp
  zip/pkzipdata.cpp
)

set(UI_FILES
  dialog/filedialog.ui
  dialog/messagedialog.ui
)

set(BUILD_TYPE STATIC)
if (TIBERIUS_BUILD_SHARED)
  set(BUILD_TYPE SHARED)
endif()

add_library(${TARGET_NAME} ${BUILD_TYPE} ${HDR_FILES} ${SRC_FILES} ${UI_FILES} ${LIBSMACKER_FILES} ${TINYFD_FILES})

if (MSVC)
  target_compile_definitions(${TARGET_NAME} PUBLIC -D_CRT_SECURE_NO_WARNINGS)
  if (TIBERIUS_BUILD_SHARED)
    target_compile_definitions(${TARGET_NAME} PRIVATE -DTIBERIUS_EXPORT)
  endif()
endif()

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

target_link_libraries(${TARGET_NAME} PUBLIC smacker)
target_link_libraries(${TARGET_NAME} PUBLIC tinyfd)
target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Widgets)
target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Multimedia)
target_link_libraries(${TARGET_NAME} PUBLIC Qt5::MultimediaWidgets)
