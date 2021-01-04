#pragma once

#include "Game/Animations/AnimationComponent.h"
#include <Game/GUI/ProgressBar.h>

enum enemy_states {E_IDLE = 0, E_ATTACKED, E_DYING};

class Enemy {
public:
    // Constructor/Destructor
    Enemy(const float &hp, const float &x, const float &y,
            sf::Texture &texture_sheet,
            sf::Texture &health_bar_texture_sheet);
    virtual ~Enemy();

    // Update
    void update(const float &dt);
    void updateAnimation(const float &dt);

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    void attack(const float& damage);

    // Getters
    bool HitboxPressed(const sf::Vector2i& mousePos) const;
    unsigned short getEnemyState() const;
    const sf::Vector2f &getPosition() const;
    sf::Rect<float> getSize() const;
    float getCurrentHealth() const;
    float getCurrentHealthPercentage() const;

    // Setters
    void setEnemyState(enemy_states);
    void setTexture (sf::Texture &texture);
    void setPosition(const float &x, const float &y);

private:
    // Stats
    short unsigned enemy_state;
    float base_health;
    float current_health;

    // Texture
    sf::Sprite sprite;
    AnimationComponent *animationComponent;

    // HP Bar
    ProgressBar *hp_bar;

    float received_damage;

    // Init Private Functions
    void initAnimationComponent(sf::Texture &enemy_texture_sheet);
    void initHealthBar(sf::Texture &health_bar_texture_sheet);
};
