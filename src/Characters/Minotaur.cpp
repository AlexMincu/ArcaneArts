#include "Characters/Minotaur.h"

// Init Private Functions
void Minotaur::initAnimations() {
    this->animationComponent->addAnimation("MINOTAUR_IDLE", 3.35, 0, 0, 11, 0, 360, 245);
    this->animationComponent->addAnimation("MINOTAUR_ATTACKED", 3.0, 0, 1, 11, 1, 360, 245);
}


// Constructor/Destructor
Minotaur::Minotaur(const float &x, const float &y, sf::Texture &texture_sheet)
: Enemy(x, y, texture_sheet) {
    this->initAnimations();
}

Minotaur::~Minotaur() {

}


// Update
void Minotaur::update(const float &dt) {
    Enemy::update(dt);
    if(getEnemyState() == E_IDLE)
        this->animationComponent->play("MINOTAUR_IDLE", dt);

    if(getEnemyState() == E_ATTACKED)
        this->animationComponent->play("MINOTAUR_ATTACKED", dt);
}

