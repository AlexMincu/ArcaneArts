#pragma once

#include "Animation.h"

class AnimationComponent {
public:
    // Constructor/ Destructor
    AnimationComponent(sf::Sprite &sprite, sf::Texture &texture_sheet);
    virtual ~AnimationComponent();

    // Functions
    void addAnimation(const std::string& key,
                      float animation_timer,
                      int start_frame_x, int start_frame_y,
                      int frames_x, int frames_y,
                      int width, int height);

    const short& play(const std::string &key, const float &dt);

    // Getters and Setters
    void manual_reset(const std::string &key);

private:
    // Variables
    sf::Sprite &sprite;
    sf::Texture &texture_sheet;
    std::map<std::string, Animation*> animations;
};