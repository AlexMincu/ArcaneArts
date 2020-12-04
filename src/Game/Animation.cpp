#include "Game/Animation.h"

Animation::Animation(sf::Sprite &sprite, sf::Texture &texture_sheet,
                     float animation_timer,
                     int start_frame_x, int start_frame_y,
                     int frames_x, int frames_y,
                     int width, int height)
        : sprite(sprite), texture_sheet(texture_sheet),
          animation_timer(animation_timer),
          width(width), height(height) {
    this->timer = 0.f;
    this->start_rect = sf::IntRect (start_frame_x * width, start_frame_y * height, width, height);
    this->current_rect = this->start_rect;
    this->end_rect = sf::IntRect (frames_x * width, frames_y * height, width, height);

    this->sprite.setTexture(this->texture_sheet, true);
    this->sprite.setTextureRect(this->start_rect);
}

Animation::~Animation() {

}

void Animation::play(const float &dt) {
    this->timer += 150.f * dt;
    if(this->timer >= this->animation_timer){
        // reset timer
        this->timer = 0.f;

        // animate
        if(this->current_rect != this->end_rect)
            this->current_rect.left += this->width;
        else    // reset
            this->current_rect.left = this->start_rect.left;

        this->sprite.setTextureRect(this->current_rect);
    }
}

void Animation::reset() {
    this->timer = 0.f;
    this->current_rect = this->start_rect;
}
