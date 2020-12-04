#include "Characters/Enemy.h"

void Enemy::initVariables() {

}

void Enemy::initComponents() {

}

Enemy::Enemy(float x, float y, sf::Texture &texture_sheet) {
    this->initVariables();
    this->initComponents();

    this->createAnimationComponent(texture_sheet);
    this->setPosition(x, y);

    this->animationComponent->addAnimation("ENEMY_IDLE", 10.f, 0, 0, 11, 0, 360, 245);
}

Enemy::~Enemy() {

}

void Enemy::update(const float &dt) {
    this->animationComponent->play("ENEMY_IDLE", dt);
}



