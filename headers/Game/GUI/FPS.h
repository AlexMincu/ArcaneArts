#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class FPS {
public:
    // Constructor/Destructor
    FPS(std::map<std::string, sf::Font>& fonts);
    ~FPS();

    // Update
    void update(const float& dt);

    // Render
    void render(sf::RenderTarget *target);

private:
    sf::Text fps;
    float fps_render_timing;
    float dt_average;
    float dt_frames;
};
