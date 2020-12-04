cmake_minimum_required(VERSION 3.17)
project(ArcaneArts)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArcaneArts src/main.cpp src/Characters/Character.cpp headers/Characters/Character.h src/Items/Item.cpp headers/Items/Item.h src/Characters/Human.cpp headers/Characters/Human.h src/Items/Weapon.cpp headers/Items/Weapon.h src/Items/Sword.cpp headers/Items/Sword.h src/Characters/Elf.cpp headers/Characters/Elf.h src/Characters/Enemy.cpp headers/Characters/Enemy.h src/Characters/Slime.cpp headers/Characters/Slime.h src/Game/Game.cpp headers/Game/Game.h src/Game/State.cpp headers/Game/State.h src/Game/GameState.cpp headers/Game/GameState.h src/Characters/Hero.cpp headers/Characters/Hero.h src/Game/AnimationComponent.cpp headers/Game/AnimationComponent.h src/Game/Animation.cpp headers/Game/Animation.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
include_directories(headers assets /usr/include c:/SFML/include)

#SFML Library
    find_package(SFML REQUIRED system window graphics audio)
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