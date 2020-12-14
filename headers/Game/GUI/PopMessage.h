#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class PopMessage {
public:
    // Constructor/Destructor
    PopMessage();
    virtual ~PopMessage();

    // Update
    void update(const float &dt);

    // Render
    virtual void render(sf::RenderTarget *target);

    // Functions
    void setMessageTitle(const std::string &s);
    void setMessage(const std::string &s);
    void setWindowPosition(const float& x, const float& y);
    sf::FloatRect getWindowSize();

private:
    // Variables

    // Texture
    sf::Sprite window;
    sf::Texture window_texture;

    // Text
    sf::Font font;
    sf::Text title;
    sf::Text message;

    // Init Private Functions
    void initWindow();
    void initText();
};