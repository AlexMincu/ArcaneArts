cmake_minimum_required(VERSION 3.17)
project(ArcaneArts)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArcaneArts src/main.cpp headers/Ash_user.h headers/I_Print.h headers/Evoker.h headers/Wizzard.h headers/Spellbook.h headers/Fire_user.h headers/Earth_user.h headers/Air_user.h)

