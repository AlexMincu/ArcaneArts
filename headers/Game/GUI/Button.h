#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class Button {
public:
    // Constructor/Destructor
    Button();
    virtual ~Button();

    // Update
    void update(const float &dt);

    // Render
    virtual void render(sf::RenderTarget *target);

    // Functions
        // Text
    void setText(const std::string &s);
    void setTextSize(const unsigned int& size);
    void centerText();
        // Window
    void setPosition(const float& x, const float& y);
    void setSize(const float& width, const float& height);
    sf::Vector2f getPosition();
    sf::FloatRect getSize();

private:
    // Variables

    // Texture
    sf::Sprite window;
    sf::Texture window_texture;

    // Text
    sf::Font font;
    sf::Text text;

    // Init Private Functions
    void initWindow();
    void initText();
};