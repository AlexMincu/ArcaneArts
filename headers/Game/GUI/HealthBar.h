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
    void update(float hp_procent, const float &dt);

    // Render
    virtual void render(sf::RenderTarget *target);

private:
    sf::Sprite sprite;
    sf::Text health;

    // Dynamic component (a resizeable rectangle)
    sf::RectangleShape progress;
    sf::Vector2f progress_size;
};
