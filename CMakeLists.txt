cmake_minimum_required(VERSION 3.17)
project(driveordie C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(driveordie main.c)
target_link_libraries(driveordie ${SDL2_LIBRARIES} -lmingw32 -lSDL2main -lSDL2 -mwindows)