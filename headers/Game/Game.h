#pragma once

#include "GameState.h"

class Game {
public:
    // Constructor/Destructor
    Game();
    virtual ~Game();

    // Update
    void updateDt();
    void updateSFMLEvents();
    void update();

    // Render
    void render();

    // Functions
    void run(const bool &Debug = false);

    // Getters and Setter
    static bool isDebug();

private:
    // Init Private Functions
    void initVariables();
    void initWindow();
    void initKeys();
    void initStates();

    // Variables
    sf::RenderWindow *window;
    sf::Event event;
        // Delta Time
    sf::Clock dtClock;
    float dt;
        // States
    std::stack<State*> states;
        // Inputs
    std::map<std::string, int> supportedKeys;
protected:
    static bool debug;
};
