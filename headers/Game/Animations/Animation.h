#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum AnimState {NONE = -1, STARTING = 0, RUNNING = 1, FINISHING = 2};

class Animation {
public:
    // Constructor/Destructor
    Animation(sf::Sprite &sprite, sf::Texture &texture_sheet,
              float animation_timer,
              int start_frame_x, int start_frame_y,
              int frames_x, int frames_y,
              int width, int height);
    virtual ~Animation();

    // Functions
    const short& play(const std::string &key, const float &dt);
    void manual_reset();

private:
    // Variables
        // Texture
    sf::Sprite &sprite;
    sf::Texture &texture_sheet;
        // Positioning inside the sheet
    sf::IntRect start_rect;
    sf::IntRect current_rect;
    sf::IntRect end_rect;
        // Size of a single image
    int width;
    int height;
        // Timers for the animation
    float animation_timer;
    float timer;
        // Others
    short state;
};
