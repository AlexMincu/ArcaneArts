#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class PopMessage {
public:
    // Constructor/Destructor
    PopMessage();
    virtual ~PopMessage();

    // Render
    virtual void render(sf::RenderTarget *target);

    // Functions

    // Getters and Setters
        // Title
    void setMessageTitle(const std::string &s);
    void centerMessageTitle();
        // Message
    void setMessage(const std::string &s);
    void centerMessage();
        // Window
    void setWindowPosition(const float& x, const float& y);
    sf::Vector2f getWindowPosition();
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