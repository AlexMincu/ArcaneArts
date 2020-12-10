#include "Game/Characters/Enemy.h"


// Init Private Functions
void Enemy::initAnimationComponent(sf::Texture &char_texture_sheet) {
    this->createAnimationComponent(char_texture_sheet);
    this->animationComponent->addAnimation("IDLE", 0.6f, 0, 0, 11, 0, 360, 245);
    this->animationComponent->addAnimation("ATTACK", 0.4f, 0, 1, 11, 1, 360, 245);
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
: enemy_state{E_IDLE} {
    this->initAnimationComponent(char_texture_sheet);
    this->setPosition(x, y);

    this->initHealthBar(health_bar_texture_sheet);

    this->base_health = hp;
    this->current_health = this->base_health;
}

Enemy::~Enemy() {
    delete this->hp_bar;
};


// Update
void Enemy::updateInput() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->animationComponent->manual_reset("ATTACK");
        setEnemyState(E_ATTACKED);

        //debug
//        std::cout << "MLEFT pressed\n";
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this->animationComponent->manual_reset("ATTACK");
        setEnemyState(E_ATTACKED);

        //debug
//        std::cout << "SPACE pressed\n";
    }
}

void Enemy::updateAnimation(const float &dt) {
    if(this->enemy_state == E_ATTACKED) {
        if (this->animationComponent->play("ATTACK", dt, &current_health, 10))
            this->enemy_state = E_IDLE;
    }
    if(this->enemy_state == E_IDLE){
        this->animationComponent->play("IDLE", dt);
    }
}

void Enemy::update(const float &dt) {
    this->updateInput();
    this->updateAnimation(dt);

    // Progress Bars
    this->hp_bar->update(this->getCurrentHealthPercentage(), dt);
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




