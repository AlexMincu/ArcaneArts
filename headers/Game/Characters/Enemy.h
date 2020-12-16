#pragma once

#include "Character.h"

enum enemy_states {E_IDLE = 0, E_ATTACKED, E_DYING};

class Enemy : public Character{
public:
    // Constructor/Destructor
    Enemy(const float &hp, const float &x, const float &y,
            sf::Texture &texture_sheet, sf::Texture &health_bar_texture_sheet);
    virtual ~Enemy();

    // Update
    void update(const float &dt) override;
    void updateAnimation(const float &dt);

    // Functions
    void attack();

    // Getters and Setters
    unsigned short getEnemyState() const;
    void setEnemyState(enemy_states);
    bool HitboxPressed(const sf::Vector2i& mousePos) const;

private:
    // Variables
    sf::Event event;
    short unsigned enemy_state;

    // Init Private Functions
    void initAnimationComponent(sf::Texture &char_texture_sheet);
    void initHealthBar(sf::Texture &health_bar_texture_sheet);
};
