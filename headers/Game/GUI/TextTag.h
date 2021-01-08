#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class TextTag {
public:
    // Constructor/Destructor
    TextTag(const std::string &text,
            const sf::Vector2i& position,
            sf::Font &font,
            const int &size,
            const sf::Color& text_color,
            const float& lifetime);
    virtual ~TextTag();

    // Update
    void update(const float& dt);

    // Render
    void render(sf::RenderTarget *target);

    // Getters & Setters
    void addOutline(const float& thickness, const sf::Color& color);
    void addFade();
    void addMovement(const sf::Vector2i& new_position);
    bool isDead() const;

private:
    sf::Text tag;
    sf::Vector2i pos;
    float life;
    float life_time;

    bool fade;

    bool outline;

    bool movement;
    sf::Vector2i movement_pos;
    sf::Vector2i movement_distance;
};