#pragma once

#include "Character.h"

enum enemy_states {E_IDLE = 0, E_ATTACKED};

class Enemy : public Character{
public:
    // Constructor/Destructor
    Enemy(const float &x, const float &y, sf::Texture &texture_sheet);
    virtual ~Enemy();

    // Update
    void update(const float &dt) override;

    // Render
        //Use render(sf::RenderTarget *target);                         from Character

    // Functions
        //Use createAnimationComponent(sf::Texture &texture_sheet);     from Character

    // Getters and Setters
        //Use setTexture (sf::Texture &texture);                        from Character
        //Use setPosition(const float &x, const float &y);              from Character
    void isAttacked();
    unsigned short getEnemyState() const;

private:
    // Init Private Functions
    void initVariables();
    void initAnimationComponent(const float &x, const float &y, sf::Texture &texture_sheet);

    // Variables
    short unsigned enemy_state;
};
