#include "Characters/Character.h"


// Constructor/Destructor
Character::Character() {

}

Character::~Character() {
    delete this->animationComponent;
}


// Update


// Render
void Character::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
}


// Functions
void Character::createAnimationComponent(sf::Texture &texture_sheet) {
    this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}


// Getters and Setters
void Character::setTexture(sf::Texture &texture) {
    this->sprite.setTexture(texture);
}
void Character::setPosition(const float &x, const float &y) {
    this->sprite.setPosition(x, y);
}




