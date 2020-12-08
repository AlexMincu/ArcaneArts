#pragma once

#include "Game/Animations/AnimationComponent.h"
#include <Game/GUI/ProgressBar.h>

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
    void setPosition(const float &x, const float &y);
    const sf::Vector2f &getPosition() const;
    sf::Rect<float> getSize() const;
    float getCurrentHealth() const;
    float getCurrentHealthPercentage() const;

protected:
    // Variables
    sf::Sprite sprite;
    AnimationComponent *animationComponent;
    float base_health;
    float current_health;

private:

};
