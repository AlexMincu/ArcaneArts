cmake_minimum_required(VERSION 3.17)
project(ArcaneArts)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArcaneArts src/main.cpp headers/Ash_user.h headers/I_Print.h headers/Evoker.h headers/Wizzard.h headers/Spellbook.h headers/Fire_user.h headers/Earth_user.h headers/Air_user.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
include_directories(headers /usr/include C:/SFML/include)

#SFML Library
    find_package(SFML REQUIRED system window graphics)
    if (SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
    endif()
    file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
    # Copy dlls to build
    if(WIN32)
        file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
        file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    endif()