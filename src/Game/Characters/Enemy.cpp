#include "Game/Characters/Enemy.h"


// Init Private Functions
void Enemy::initAnimationComponent(sf::Texture &enemy_texture_sheet) {

    this->animationComponent = new AnimationComponent(this->sprite, enemy_texture_sheet);

    this->animationComponent->addAnimation("IDLE", 0.6f,
                                           1, 1,
                                           12, 1,
                                           360, 245);

    this->animationComponent->addAnimation("ATTACK", 0.3f,
                                           1, 2,
                                           12, 1,
                                           360, 245);

    this->animationComponent->addAnimation("DYING", 0.4f,
                                           1, 3,
                                           15, 1,
                                           360, 245);
}

void Enemy::initHealthBar(sf::Texture &health_bar_texture_sheet){
    // HP BAR
        // Find the position to set the HP Bar under the enemy
    float x_spacer = 45.f;
    float y_spacer = this->getSize().height;

    float hp_bar_pos_x = this->getPosition().x + x_spacer;
    float hp_bar_pos_y = this->getPosition().y + y_spacer;

    this->hp_bar = new ProgressBar(hp_bar_pos_x, hp_bar_pos_y, health_bar_texture_sheet);
}


// Constructor/Destructor
Enemy::Enemy(const float &hp, const float &x, const float &y,
             sf::Texture &char_texture_sheet, sf::Texture &health_bar_texture_sheet)
             :  base_health{0.f}, current_health{0.f},
                enemy_state{E_IDLE},
                animationComponent{nullptr}, hp_bar(nullptr){

    this->initAnimationComponent(char_texture_sheet);
    this->setPosition(x, y);

    this->initHealthBar(health_bar_texture_sheet);

    this->base_health = hp;
    this->current_health = this->base_health;
}

Enemy::~Enemy() {
    delete this->hp_bar;
    delete this->animationComponent;
}


// Update
void Enemy::update(const float &dt) {
    // Enemy Animation
    this->updateAnimation(dt);

    // Progress Bars
    this->hp_bar->update(this->getCurrentHealthPercentage(), dt);
}

void Enemy::updateAnimation(const float &dt) {

    if(this->enemy_state == E_ATTACKED) {

        short anim_state = this->animationComponent->play("ATTACK", dt);

        if (anim_state == AnimState::STARTING) {
            if(this->current_health > 0) {
                this->current_health -= this->received_damage;
            }
        }
        else if (anim_state == AnimState::FINISHING){
            if (this->current_health <= 0)
                this->enemy_state = E_DYING;
            else
                this->enemy_state = E_IDLE;
        }
    }

    if(this->enemy_state == E_IDLE){
        this->animationComponent->play("IDLE", dt);
    }


    if(this->enemy_state == E_DYING){
        if(this->animationComponent->play("DYING", dt) == AnimState::FINISHING)
            this->enemy_state = E_IDLE;
    }

}


// Render
void Enemy::render(sf::RenderTarget *target) {
    // Enemy
    target->draw(this->sprite);

    // Progress Bars
    this->hp_bar->render(target);
}


// Functions
void Enemy::attack(const float& damage) {
    this->received_damage = damage;
    if(this->getCurrentHealth() > 0) {
        this->animationComponent->manual_reset("ATTACK");
        setEnemyState(E_ATTACKED);
    }
}


// Getters
bool Enemy::HitboxPressed(const sf::Vector2i& mousePos) const {
    return this->sprite.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

unsigned short Enemy::getEnemyState() const {
    return enemy_state;
}

const sf::Vector2f &Enemy::getPosition() const {
    return this->sprite.getPosition();
}

sf::Rect<float> Enemy::getSize() const {
    return this->sprite.getGlobalBounds();
}

float Enemy::getCurrentHealth() const {
    return this->current_health;
}

float Enemy::getCurrentHealthPercentage() const {
    return (this->current_health / this->base_health) * 100.f;
}


// Setters
void Enemy::setEnemyState(enemy_states state) {
    this->enemy_state = state;
}

void Enemy::setTexture(sf::Texture &texture) {
    this->sprite.setTexture(texture);
}

void Enemy::setPosition(const float &x, const float &y) {
    this->sprite.setPosition(x, y);
}







