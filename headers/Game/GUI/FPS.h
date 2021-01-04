#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

class FPS {
public:
    FPS(std::map<std::string, sf::Font>& fonts);
    ~FPS();
    void update(const float& dt);
    void render(sf::RenderTarget *target);
private:
    sf::Text fps;
    float fps_render_timing;
    float dt_average;
    float dt_frames;
};
