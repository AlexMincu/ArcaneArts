#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class Button {
public:
    // Constructor/Destructor
    Button(const short& type);
    virtual ~Button();

    // Update
    bool isPressed(const sf::Vector2i& mousePos);

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

    enum Type {Default = 0, Upgrade = 1, Quit_upgrade = 2, Upgrade_click_damage = 3, Pause_menu = 4};

private:
    // Variables

    // Texture
    sf::Sprite window;
    sf::Texture window_texture;

    // Text
    sf::Font font;
    sf::Text text;
};