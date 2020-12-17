#include <Game/Animations/Animation.h>



// Constructor/Destructor
Animation::Animation(sf::Sprite &sprite, sf::Texture &texture_sheet,
                     float animation_timer,
                     int start_frame_x, int start_frame_y,
                     int frames_x, int frames_y,
                     int width, int height)
                : sprite(sprite), texture_sheet(texture_sheet),
                  animation_timer(animation_timer), timer{0.f}, state{NONE},
                  width(width), height(height) {

    // Set the texture for the animation
        // Animated texture positioning inside the sheet
    this->start_rect = sf::IntRect ((start_frame_x - 1) * width, (start_frame_y - 1) * height, width, height);
    this->current_rect = this->start_rect;
    this->end_rect = sf::IntRect (start_rect.left + ((frames_x - 1)* width), start_rect.top + ((frames_y - 1) * height), width, height);
        // Set the texture to the sprite
    this->sprite.setTexture(this->texture_sheet, true);
    this->sprite.setTextureRect(this->start_rect);
}

Animation::~Animation() {

}


// Functions
const short& Animation::play(const std::string &key, const float &dt) {
    /*  this->timer = this->timer + x * dt;
     *      x - number of images inside the sheet
     *      dt - the times is take to update and render a frame
     *
     *      animation_timer - How much time in seconds will an animation render
     */
    this->state = NONE;
    this->timer += 12.f * dt;   // 12 image animation sheet

    if(this->timer >= this->animation_timer)
    {
        // Reset timer
        this->timer = 0.f;

        // Deal damage
        if (this->current_rect == this->start_rect){
            this->state = STARTING;

            this->current_rect.left += this->width;
        }

        // Animate
        else if (this->current_rect != this->end_rect) {
            this->state = RUNNING;

            this->current_rect.left += this->width;
        }
        // Reset the position of the rect to the beginning
        else {
            this->state = FINISHING;

            this->current_rect.left = this->start_rect.left;

        }

        // Set current frame of animation
        this->sprite.setTextureRect(this->current_rect);
    }
    return this->state;
}



// Setters and Getters
void Animation::manual_reset() {
    this->timer = 0.f;
    this->current_rect = this->start_rect;
}