#include "Game/Animations/AnimationComponent.h"

// Constuctor/Destructor
AnimationComponent::AnimationComponent(sf::Sprite &sprite, sf::Texture &texture_sheet)
: sprite(sprite), texture_sheet(texture_sheet) {

}

AnimationComponent::~AnimationComponent() {
    for (auto &i : this->animations)
        delete i.second;
}


// Functions
void AnimationComponent::addAnimation(const std::string &key,
                                 float animation_timer,
                                 int start_frame_x, int start_frame_y,
                                 int frames_x, int frames_y,
                                 int width, int height) {

    this->animations[key] = new Animation(this->sprite, this->texture_sheet,
                                          animation_timer,
                                          start_frame_x, start_frame_y,
                                          frames_x, frames_y,
                                          width, height);
}

const bool & AnimationComponent::play(const std::string &key, const float &dt) {
    return this->animations[key]->play(key, dt);

}


// Getters and Setters
const bool &AnimationComponent::isDone(const std::string &key){
    return this->animations[key]->isDone();
}

void AnimationComponent::manual_reset(const std::string &key) {
    this->animations[key]->manual_reset();
}
