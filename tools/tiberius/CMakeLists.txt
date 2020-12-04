cmake_minimum_required(VERSION 3.5)

project(tiberius LANGUAGES C CXX)
set(TARGET_NAME tiberiusui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets MultimediaWidgets)

set(HDR_FILES
  application/application.h
  application/settings.h
  dialog/difficultydialog.h
  dialog/displayoptionsdialog.h
  dialog/donationdialog.h
  dialog/festivaldialog.h
  dialog/giftdialog.h
  dialog/missiondialog.h
  dialog/newcareerdialog.h
  dialog/pricesdialog.h
  dialog/prioritydialog.h
  dialog/resourcetradedialog.h
  dialog/salarydialog.h
  dialog/soundoptionsdialog.h
  dialog/speedoptionsdialog.h
  widget/advisorwidget.h
  widget/chiefadvisorwidget.h
  widget/educationadvisorwidget.h
  widget/entertainmentadvisorwidget.h
  widget/financeadvisorwidget.h
  widget/healthadvisorwidget.h
  widget/imperialadvisorwidget.h
  widget/laboradvisorwidget.h
  widget/legionadvisorwidget.h
  widget/populationadvisorwidget.h
  widget/prioritylabel.h
  widget/ratingsadvisorwidget.h
  widget/religionadvisorwidget.h
  widget/sidebarwidget.h
  widget/tradeadvisorwidget.h
  window/advisorswindow.h
  window/cityconstructionwindow.h
  window/empirewindow.h
  window/gamewindow.h
  window/mainwindow.h
  window/menuwindow.h
  window/missionwindow.h
  window/titlewindow.h
  window/videowindow.h
)

set(SRC_FILES
  main.cpp
  application/application.cpp
  application/settings.cpp
  dialog/difficultydialog.cpp
  dialog/displayoptionsdialog.cpp
  dialog/donationdialog.cpp
  dialog/festivaldialog.cpp
  dialog/giftdialog.cpp
  dialog/missiondialog.cpp
  dialog/newcareerdialog.cpp
  dialog/pricesdialog.cpp
  dialog/prioritydialog.cpp
  dialog/resourcetradedialog.cpp
  dialog/salarydialog.cpp
  dialog/soundoptionsdialog.cpp
  dialog/speedoptionsdialog.cpp
  widget/advisorwidget.cpp
  widget/chiefadvisorwidget.cpp
  widget/educationadvisorwidget.cpp
  widget/entertainmentadvisorwidget.cpp
  widget/financeadvisorwidget.cpp
  widget/healthadvisorwidget.cpp
  widget/imperialadvisorwidget.cpp
  widget/laboradvisorwidget.cpp
  widget/legionadvisorwidget.cpp
  widget/populationadvisorwidget.cpp
  widget/prioritylabel.cpp
  widget/ratingsadvisorwidget.cpp
  widget/religionadvisorwidget.cpp
  widget/sidebarwidget.cpp
  widget/tradeadvisorwidget.cpp
  window/advisorswindow.cpp
  window/cityconstructionwindow.cpp
  window/empirewindow.cpp
  window/gamewindow.cpp
  window/mainwindow.cpp
  window/menuwindow.cpp
  window/missionwindow.cpp
  window/titlewindow.cpp
  window/videowindow.cpp
)

set(UI_FILES
  dialog/difficultydialog.ui
  dialog/displayoptionsdialog.ui
  dialog/donationdialog.ui
  dialog/festivaldialog.ui
  dialog/giftdialog.ui
  dialog/missiondialog.ui
  dialog/newcareerdialog.ui
  dialog/pricesdialog.ui
  dialog/prioritydialog.ui
  dialog/resourcetradedialog.ui
  dialog/salarydialog.ui
  dialog/soundoptionsdialog.ui
  dialog/speedoptionsdialog.ui
  widget/chiefadvisorwidget.ui
  widget/educationadvisorwidget.ui
  widget/entertainmentadvisorwidget.ui
  widget/financeadvisorwidget.ui
  widget/healthadvisorwidget.ui
  widget/imperialadvisorwidget.ui
  widget/laboradvisorwidget.ui
  widget/legionadvisorwidget.ui
  widget/populationadvisorwidget.ui
  widget/ratingsadvisorwidget.ui
  widget/religionadvisorwidget.ui
  widget/sidebarwidget.ui
  widget/tradeadvisorwidget.ui
  window/advisorswindow.ui
  window/cityconstructionwindow.ui
  window/empirewindow.ui
  window/gamewindow.ui
  window/mainwindow.ui
  window/menuwindow.ui
  window/missionwindow.ui
  window/titlewindow.ui
  window/videowindow.ui
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

set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME tiberius)
