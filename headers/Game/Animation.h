#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Animation {
public:
    Animation(sf::Sprite &sprite, sf::Texture &texture_sheet,
              float animation_timer,
              int start_frame_x, int start_frame_y,
              int frames_x, int frames_y,
              int width, int height);
    virtual ~Animation();

    void play(const float &dt);
    void reset();
private:
    sf::Sprite &sprite;
    sf::Texture &texture_sheet;
    float animation_timer;
    float timer;
    int width;
    int height;
    sf::IntRect start_rect;
    sf::IntRect current_rect;
    sf::IntRect end_rect;
};
