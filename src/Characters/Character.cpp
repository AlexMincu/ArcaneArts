#include "Characters/Character.h"

void Character::initVariables() {

}

Character::Character() {
    this->initVariables();
}

Character::~Character() {
    delete this->animationComponent;
}

void Character::setTexture(sf::Texture &texture) {
    this->sprite.setTexture(texture);
}

void Character::createAnimationComponent(sf::Texture &texture_sheet) {
    this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}


void Character::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Character::update(const float &dt) {

}

void Character::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
}


