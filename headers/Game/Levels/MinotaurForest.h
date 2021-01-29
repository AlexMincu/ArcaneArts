#pragma once

#include "Game/Levels/Level.h"

class MinotaurForest : public Level{
public:
    // Constructor/ Destructor
    MinotaurForest(sf::Vector2i pos,
                   std::map<std::string, sf::Texture>& textures,
                   std::map<std::string, sf::Font>& fonts);
    ~MinotaurForest() override;

    // Update
    void update(const float &dt) override;
    void updateProgress() override;
    void updateText() override;

    // Functions
    void run() override;

private:
    void initLevel() override;
};