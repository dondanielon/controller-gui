cmake_minimum_required(VERSION 3.31.3)
project(controller-gui VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES
  main.cpp
  Controller.cpp
  Gui.cpp
)

set(HEADERS
  Controller.h
  Gui.h
)

add_executable(controller-gui ${SOURCES} ${HEADERS})

target_link_libraries(controller-gui ${SDL2_LIBRARIES})

set_property(TARGET controller-gui PROPERTY CXX_STANDARD 17)