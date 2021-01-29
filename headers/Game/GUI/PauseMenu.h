#pragma once

#include "Game/GUI/Button.h"

class PauseMenu {
public:
    enum PauseButton {NoButtonPressed = 0, Return, Close};
    // Constructor/Destructor
    PauseMenu(std::map<std::string, sf::Texture>& textures, std::map<std::string, sf::Font>& fonts);
    virtual ~PauseMenu();

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    short isButtonPressed(const sf::Vector2i& mousePos) const;

private:
    sf::Sprite window;
    sf::Text title;

    // Buttons
    Button return_button;
    Button close_button;
};
