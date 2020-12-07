#include "Game/Characters/Enemy.h"


// Init Private Functions
void Enemy::initAnimationComponent(sf::Texture &texture_sheet) {
    this->createAnimationComponent(texture_sheet);
    this->animationComponent->addAnimation("IDLE", 0.6f, 0, 0, 11, 0, 360, 245);
    this->animationComponent->addAnimation("ATTACK", 0.4f, 0, 1, 11, 1, 360, 245);
}

// Constructor/Destructor
Enemy::Enemy(const float &x, const float &y, sf::Texture &texture_sheet)
: enemy_state{E_IDLE}{

    this->initAnimationComponent(texture_sheet);
    this->setPosition(x, y);
}

Enemy::~Enemy() {

};


// Update
void Enemy::updateInput() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->animationComponent->manual_reset("ATTACK");
        setEnemyState(E_ATTACKED);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this->animationComponent->manual_reset("ATTACK");
        setEnemyState(E_ATTACKED);
    }
}

void Enemy::updateAnimation(const float &dt) {
    if(this->enemy_state == E_ATTACKED) {
        if (this->animationComponent->play("ATTACK", dt))
            this->enemy_state = E_IDLE;
    }
    if(this->enemy_state == E_IDLE){
        this->animationComponent->play("IDLE", dt);
    }
}

void Enemy::update(const float &dt) {
    this->updateInput();
    this->updateAnimation(dt);
}


// Render


// Functions


// Getters and Setters
unsigned short Enemy::getEnemyState() const {
    return enemy_state;
}

void Enemy::setEnemyState(enemy_states state) {
    this->enemy_state = state;
}



