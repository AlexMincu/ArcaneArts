#pragma once

#include "Game/Animations/AnimationComponent.h"

class Enemy {
public:
    enum State {IDLE = 0, ATTACKED, DYING};

    // Constructor/Destructor
    Enemy(const float &hp,
          const float &x, const float &y,
          sf::Texture &enemy_texture_sheet);
    virtual ~Enemy();

    // Update
    void update(const float &dt);
    void updateAnimation(const float &dt);

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    void attack(const float& damage);

    // Getters & Setters
    bool HitboxPressed(const sf::Vector2i& mousePos) const;
    unsigned short getEnemyState() const;
    float getCurrentHealth() const;
    float getCurrentHealthPercentage() const;

private:
    // Stats
    short unsigned enemy_state;
    float base_health;
    float current_health;

    // Texture
    sf::Sprite sprite;
    AnimationComponent animationComponent;


    // Init Private Functions
    void initAnimationComponent(sf::Texture &enemy_texture_sheet);
};
