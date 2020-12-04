#pragma once

#include "GameState.h"


class Game {
public:
    Game();
    virtual ~Game();

    void endApplication();

    void updateDt();
    void updateSFMLEvents();
    void update();

    void render();

    void run();

private:
    void initVariables();
    void initWindow();
    void initKeys();
    void initStates();

    sf::RenderWindow *window;
    sf::Event event;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    std::map<std::string, int> supportedKeys;
};
