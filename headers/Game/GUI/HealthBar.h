#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class HealthBar {
public:
    // Constructor/Destructor
    HealthBar(const float& x, const float & y,
              std::map<std::string, sf::Texture>& textures,
              std::map<std::string, sf::Font>& fonts);
    virtual ~HealthBar();

    // Update
    void update(const float & hp, const float &dt);

    // Render
    virtual void render(sf::RenderTarget *target);

private:
     // Variables
        // Texture
    sf::Sprite sprite;
    sf::RectangleShape progress;
        // Dynamic component (a resizeable rectangle)
    sf::Vector2f progress_size;
        // Text
    sf::Font font;
    sf::Text health;

};
