#pragma once

#include "Animation.h"

class AnimationComponent {
public:
    AnimationComponent(sf::Sprite &sprite, sf::Texture &texture_sheet);
    virtual ~AnimationComponent();

    void addAnimation(const std::string key,
                      float animation_timer,
                      int start_frame_x, int start_frame_y,
                      int frames_x, int frames_y,
                      int width, int height);
    void play(const std::string key, const float &dt);
private:
    sf::Sprite &sprite;
    sf::Texture &texture_sheet;
    std::map<std::string, Animation*> animations;
};