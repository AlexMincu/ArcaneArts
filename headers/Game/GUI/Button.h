#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class Button {
public:
    // Constructor/Destructor
    Button(const short& type,
           std::map<std::string, sf::Texture>& textures,
           std::map<std::string, sf::Font>& fonts);
    virtual ~Button();

    // Render
    virtual void render(sf::RenderTarget *target);

    // Getters and Setters
    void setText(const std::string &s);
    void setTextSize(const unsigned int& size);
    void centerText();

    bool isPressed(const sf::Vector2i& mousePos);
    void setPosition(const float& x, const float& y);
    void setSize(const float& width, const float& height);
    sf::Vector2f getPosition();
    sf::FloatRect getSize();


    enum Type {Default = 0, Upgrade_Open = 1, Upgrade_Close = 2, Upgrade_Click_Damage = 3, Pause = 4};

private:
    sf::Sprite window;
    sf::Text text;
};