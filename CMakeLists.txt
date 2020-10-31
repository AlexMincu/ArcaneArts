cmake_minimum_required(VERSION 3.17)
project(ArcaneArts)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArcaneArts main.cpp evoker_subclasses.cpp evoker_subclasses.h Ash_user.h I_Print.h Evoker.cpp Evoker.h Wizzard.cpp Wizzard.h I_Menu.h)