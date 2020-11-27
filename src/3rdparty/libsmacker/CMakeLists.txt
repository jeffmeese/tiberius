cmake_minimum_required(VERSION 3.5)

project(smacker LANGUAGES C)
set(TARGET_NAME smacker)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HDR_FILES
  smacker.h
  smk_bitstream.h
  smk_hufftree.h
  smk_malloc.h
)

set(SRC_FILES 
  smacker.c
  smk_bitstream.c
  smk_hufftree.c
)

add_library(${TARGET_NAME} STATIC ${HDR_FILES} ${SRC_FILES})

if (MSVC)
  target_compile_definitions(${TARGET_NAME} PUBLIC -D_CRT_SECURE_NO_WARNINGS)
  target_compile_options(${TARGET_NAME} PRIVATE /wd4028)
endif()
