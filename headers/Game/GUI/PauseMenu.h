#pragma once

#include "Game/GUI/Button.h"

class PauseMenu {
public:
    // Constructor/Destructor
    PauseMenu(std::map<std::string, sf::Texture>& textures, std::map<std::string, sf::Font>& fonts);
    virtual ~PauseMenu();

    // Render
    void render(sf::RenderTarget *target);


    Button return_button;
    Button quit_button;

private:
    sf::Sprite window;
    sf::Text title;
};
