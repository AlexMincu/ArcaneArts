#pragma once

#include "State.h"

class GameState : public State {
public:
    // Constructor/Destructor
    GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);
    ~GameState() override;

    // Update
    void updateInput(const float &dt) override;
    void update(const float &dt) override;

    // Render
    void render(sf::RenderTarget *target) override;

private:
    // Init Private Functions
    void initKeybinds() override;
    void initTextures();
    void initEnemy();

    // Variables
    Minotaur *enemy;
    sf::Texture texture;
};
