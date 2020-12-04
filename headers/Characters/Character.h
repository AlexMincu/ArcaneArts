#pragma once

#include "../Game/AnimationComponent.h"

class Character {
public:
    Character();
    virtual ~Character();

    void setTexture (sf::Texture &texture);
    void createAnimationComponent(sf::Texture &texture_sheet);

    virtual void setPosition(const float x, const float y);

    virtual void update(const float &dt);
    virtual void render(sf::RenderTarget *target);

protected:
    sf::Sprite sprite;

    AnimationComponent *animationComponent;
private:
    void initVariables();
};
