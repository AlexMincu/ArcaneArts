#include "Game/Characters/Enemy.h"


// Init Private Functions
void Enemy::initAnimationComponent(sf::Texture &enemy_texture_sheet) {

    this->animationComponent.addAnimation("IDLE", 0.6f,
                                           1, 1,
                                           12, 1,
                                           360, 245);

    this->animationComponent.addAnimation("ATTACK", 0.3f,
                                           1, 2,
                                           12, 1,
                                           360, 245);

    this->animationComponent.addAnimation("DYING", 0.4f,
                                           1, 3,
                                           15, 1,
                                           360, 245);
}


// Constructor/Destructor
Enemy::Enemy(const float &hp,
             const float &x, const float &y,
             sf::Texture &enemy_texture_sheet)
             :  base_health{hp}, current_health{hp},
                enemy_state{State::IDLE},
                animationComponent(this->sprite, enemy_texture_sheet) {

    this->initAnimationComponent(enemy_texture_sheet);
    this->sprite.setPosition(x, y);
}

Enemy::~Enemy() {

}


// Update
void Enemy::update(const float &dt) {

    this->updateAnimation(dt);
}

void Enemy::updateAnimation(const float &dt) {

    if(this->enemy_state == State::ATTACKED) {

        short anim_state = this->animationComponent.play("ATTACK", dt);

        // When the attack animation is finished check
        //  what animation should be played next
        if (anim_state == AnimState::FINISHING){
            if (this->current_health <= 0)
                this->enemy_state = State::DYING;
            else
                this->enemy_state = State::IDLE;
        }
    }

    if(this->enemy_state == State::IDLE){
        this->animationComponent.play("IDLE", dt);
    }


    if(this->enemy_state == State::DYING){
        // Put it back in IDLE so we know when the anim is finished
        if(this->animationComponent.play("DYING", dt) == AnimState::FINISHING) {
            this->enemy_state = State::IDLE;
        }
    }

}


// Render
void Enemy::render(sf::RenderTarget *target) {
    // Enemy
    target->draw(this->sprite);
}


// Functions
void Enemy::attack(const float& damage) {

    if(this->getCurrentHealth() > 0) {
        this->current_health -= damage;

        this->animationComponent.manual_reset("ATTACK");
        this->enemy_state = State::ATTACKED;
    }
}


// Getters
bool Enemy::HitboxPressed(const sf::Vector2i& mousePos) const {
    return this->sprite.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

float Enemy::getCurrentHealth() const {
    return this->current_health;
}

float Enemy::getCurrentHealthPercentage() const {
    return (this->current_health / this->base_health) * 100.f;
}

unsigned short Enemy::getEnemyState() const {
    return this->enemy_state;
}






