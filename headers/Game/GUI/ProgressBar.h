#pragma once

#include <iostream>
#include <map>

#include <SFML/Graphics.hpp>

class ProgressBar {
public:
    // Constructor/Destructor
    ProgressBar(float x, float y, sf::Texture &texture_sheet);
    virtual ~ProgressBar();

    // Update
    void update(float hp, const float &dt);

    // Render
    virtual void render(sf::RenderTarget *target);

    // Functions

    // Getters and Setters

private:
    // Variables
        // Texture
    sf::Sprite sprite;
    sf::Texture &texture_sheet;
    sf::RectangleShape progress;

    sf::Vector2f progress_size;

    // Init Private Functions
    void initTexture();
};
