cmake_minimum_required(VERSION 3.17)
project(ArcaneArts)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArcaneArts
        src/main.cpp
        src/Game/Characters/Character.cpp headers/Game/Characters/Character.h
        src/Game/Items/Item.cpp headers/Game/Items/Item.h
        src/Game/Items/Weapon.cpp headers/Game/Items/Weapon.h
        src/Game/Items/Sword.cpp headers/Game/Items/Sword.h
        src/Game/Characters/Enemy.cpp headers/Game/Characters/Enemy.h
        src/Game/Game.cpp headers/Game/Game.h
        src/Game/States/State.cpp headers/Game/States/State.h
        src/Game/States/GameState.cpp headers/Game/States/GameState.h
        src/Game/Animations/AnimationComponent.cpp headers/Game/Animations/AnimationComponent.h
        src/Game/Animations/Animation.cpp headers/Game/Animations/Animation.h
        src/Game/GUI/ProgressBar.cpp headers/Game/GUI/ProgressBar.h src/Game/Characters/EnemySpawner.cpp headers/Game/Characters/EnemySpawner.h src/Game/Levels/Level.cpp headers/Game/Levels/Level.h src/Game/Levels/MinotaurForest.cpp headers/Game/Levels/MinotaurForest.h src/Game/GUI/PopMessage.cpp headers/Game/GUI/PopMessage.h src/Game/GUI/Button.cpp headers/Game/GUI/Button.h)

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