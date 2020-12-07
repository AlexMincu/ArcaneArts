#pragma once

#include "Game/States/GameState.h"

class Game {
public:
    // Constructor/Destructor
    Game();
    virtual ~Game();

    // Update
    void updateDt();
    void updateSFMLEvents();
    void updateStates();
    void update();

    // Render
    void render();

    // Functions
    void run();

private:
    // Variables
    sf::RenderWindow *window;
    sf::Event event;
    std::stack<State*> states;
        // Delta Time
    sf::Clock dtClock;
    float dt;
        // Inputs
    std::map<std::string, int> supportedKeys;

    // Init Private Functions
    void initWindow();
    void initKeys();
    void initStates();

protected:

};
