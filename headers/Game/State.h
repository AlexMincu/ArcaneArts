#pragma once

#include "../Characters/Enemy.h"

class State {
public:
    explicit State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);
    virtual ~State();

    virtual void updateInput(const float &dt) = 0;
    virtual void update(const float &dt) = 0;
    virtual void render(sf::RenderTarget *target) = 0;

    const bool &getQuit() const;
    void endState();

protected:
    virtual void initKeybinds() = 0;

    sf::RenderWindow *window;
    std::map<std::string, int> *supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;
    std::map<std::string, sf::Texture> textures;
};
