#include "Characters/Enemy.h"

// Init Private Functions
void Enemy::initVariables() {
    this->enemy_state = E_IDLE;
}

void Enemy::initAnimationComponent(const float &x, const float &y, sf::Texture &texture_sheet) {
    this->createAnimationComponent(texture_sheet);
    this->setPosition(x, y);
}


// Constructor/Destructor
Enemy::Enemy(const float &x, const float &y, sf::Texture &texture_sheet) {
    this->initVariables();
    this->initAnimationComponent(x, y, texture_sheet);
}

Enemy::~Enemy() = default;


// Update
void Enemy::update(const float &dt) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        this->isAttacked();
}


// Render


// Functions


// Getters and Setters
void Enemy::isAttacked(){
    this->enemy_state = E_ATTACKED;
}

unsigned short Enemy::getEnemyState() const {
    return enemy_state;
}
