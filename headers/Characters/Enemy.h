#pragma once

#include "Character.h"

class Enemy : public Character{
public:
    Enemy(float x, float y, sf::Texture &texture_sheet);
    virtual ~Enemy();

    void update(const float &dt) override;
protected:
private:
    void initVariables();
    void initComponents();
};
