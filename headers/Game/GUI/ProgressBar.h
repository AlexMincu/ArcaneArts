#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class ProgressBar {
public:
    // Constructor/Destructor
    ProgressBar(const float& x, const float& y, sf::Texture &texture_sheet);
    virtual ~ProgressBar();

    // Update
    void update(const float & hp, const float &dt);
    void updateHealthBar(const float &hp_procent);
    void updateText(const float& hp_procent);

    // Render
    virtual void render(sf::RenderTarget *target);

    // Functions

    // Getters and Setters

private:
    // Init Private Functions
    void initHealthBar(const float& x, const float & y);
    void initText();

    // Variables
        // Texture
    sf::Sprite sprite;
    sf::Texture &texture_sheet;
    sf::RectangleShape progress;

    sf::Vector2f progress_size;

    sf::Font font;
    sf::Text health;



};
