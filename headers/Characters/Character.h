#pragma once

#include "../Game/AnimationComponent.h"

class Character {
public:
    // Constructor/Destructor
    Character();
    virtual ~Character();

    // Update
    virtual void update(const float &dt) = 0;

    // Render
    virtual void render(sf::RenderTarget *target);

    // Functions
    void createAnimationComponent(sf::Texture &texture_sheet);

    // Getters and Setters
    void setTexture (sf::Texture &texture);
    virtual void setPosition(const float &x, const float &y);

protected:
    // Variables
    sf::Sprite sprite;
    AnimationComponent *animationComponent;

private:

};
