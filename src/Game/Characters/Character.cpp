#include "Game/Characters/Character.h"

// Constructor/Destructor
Character::Character()
: base_health{0.f}, current_health{0.f}, hp_bar(nullptr) {

}

Character::~Character() {
    delete this->animationComponent;
}


// Update


// Render
void Character::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
    // Progress Bars
    this->hp_bar->render(target);
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

const sf::Vector2f &Character::getPosition() const {
    return this->sprite.getPosition();
}

sf::Rect<float> Character::getSize() const {
    return this->sprite.getGlobalBounds();
}

float Character::getCurrentHealth() const {
    return this->current_health;
}

float Character::getCurrentHealthPercentage() const {
    return (this->current_health / this->base_health) * 100.f;
}

