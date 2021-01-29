cmake_minimum_required(VERSION 3.17)
project(ArcaneArts)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArcaneArts
        src/main.cpp
        src/Game/Characters/Enemy.cpp headers/Game/Characters/Enemy.h
        src/Game/Game.cpp headers/Game/Game.h
        src/Game/Animations/AnimationComponent.cpp headers/Game/Animations/AnimationComponent.h
        src/Game/Animations/Animation.cpp headers/Game/Animations/Animation.h
        src/Game/GUI/HealthBar.cpp headers/Game/GUI/HealthBar.h src/Game/Levels/Level.cpp headers/Game/Levels/Level.h src/Game/Levels/MinotaurForest.cpp headers/Game/Levels/MinotaurForest.h src/Game/GUI/Button.cpp headers/Game/GUI/Button.h src/Game/GUI/Menu.cpp headers/Game/GUI/Menu.h src/Game/GUI/FPS.cpp headers/Game/GUI/FPS.h src/Game/GUI/PauseMenu.cpp headers/Game/GUI/PauseMenu.h src/Game/GUI/TextTagComponent.cpp headers/Game/GUI/TextTagComponent.h headers/Game/GUI/TextTag.cpp headers/Game/GUI/TextTag.h)

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