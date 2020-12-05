#pragma once

#include "Enemy.h"

class Minotaur : public Enemy {
public:
    // Constructor/Destructor
    Minotaur(const float &x, const float &y, sf::Texture &texture_sheet);
    ~Minotaur() override;

    // Update
    void update(const float &dt) override;

    // Render
        //Use Character render function

    // Functions
        //Use createAnimationComponent(sf::Texture &texture_sheet);     from Character

    // Getters and Setters
        //Use setTexture (sf::Texture &texture);                        from Character
        //Use setPosition(const float &x, const float &y);              from Character
        //Use isAttacked();                                             from Enemy
        //Use getEnemyState() const;                                    from Enemy
private:
    // Init Private Functions
    void initAnimations();
};
