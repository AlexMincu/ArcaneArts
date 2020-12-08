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

    const bool & play(const std::string &key, const float &dt, float* hp = nullptr, const float &damage = 0);

    // Getters and Setters
    const bool &isDone(const std::string &key);
    void manual_reset(const std::string &key);

private:
    // Variables
    sf::Sprite &sprite;
    sf::Texture &texture_sheet;
    std::map<std::string, Animation*> animations;
};