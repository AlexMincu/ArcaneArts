cmake_minimum_required(VERSION 3.17)
project(ArcaneArts)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") # CMAKE_CURRENT_LIST_DIR is the directory holding the CMakeLists.txt we are currently using


add_executable(ArcaneArts main.cpp evoker_subclasses.cpp evoker_subclasses.h Ash_user.h I_Print.h Evoker.cpp Evoker.h Wizzard.cpp Wizzard.h I_Menu.h)


#include(FindPkgConfig)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY})