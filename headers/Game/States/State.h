#pragma once

#include "Game/Characters/Enemy.h"

class State {
public:
    // Constructor/Destructor
    State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);
    virtual ~State();

    // Update
    virtual void updateMousePosition();
    virtual void updateInput(const float &dt) = 0;
    virtual void update(const float &dt) = 0;

    // Render
    virtual void render(sf::RenderTarget *target) = 0;

    // Functions
    void endState();

    // Getters and Setters
    const bool &getQuit() const;

private:

protected:
    // Variables
    sf::RenderWindow *window;
    std::map<std::string, sf::Texture> textures;
        // Inputs
    sf::Vector2i mouse_pos_screen;
    sf::Vector2i mouse_pos_window;
    std::map<std::string, int> *supportedKeys;
    std::map<std::string, int> keybinds;
        // Others
    bool quit;
};
