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
    void updateInput();
    void updateAnimation(const float &dt);

    // Render
        //Use render(sf::RenderTarget *target);                         from Character

    // Functions
        //Use createAnimationComponent(sf::Texture &texture_sheet);     from Character

    // Getters and Setters
        //Use setTexture (sf::Texture &texture);                        from Character
        //Use setPosition(const float &x, const float &y);              from Character
    unsigned short getEnemyState() const;
    void setEnemyState(enemy_states);

private:
    // Variables
    short unsigned enemy_state;

    // Init Private Functions
    void initAnimationComponent(sf::Texture &char_texture_sheet);
    void initHealthBar(sf::Texture &health_bar_texture_sheet);


};
