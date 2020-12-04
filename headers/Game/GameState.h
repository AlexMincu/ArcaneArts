#pragma once

#include "State.h"

class GameState : public State {
public:
    explicit GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);
    ~GameState() override;

    void updateInput(const float &dt) override;
    void update(const float &dt) override;

    void render(sf::RenderTarget *target) override;
private:
    Enemy *enemy;
    sf::Texture texture;

    void initKeybinds() override;
    void initTextures();
    void initEnemy();
};
