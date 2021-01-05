#pragma once

#include "Game/Levels/Level.h"

class MinotaurForest : public Level{
public:
    // Constructor/ Destructor
    MinotaurForest(const sf::Window *window,
                   std::map<std::string, sf::Texture>& textures,
                   std::map<std::string, sf::Font>& fonts);
    ~MinotaurForest() override;

    // Update
    void update(const float &dt) override;
    void updateProgress() override;
    void updateText() override;

    // Functions
    void run() override;

protected:

private:
    // Inherited from Level
    /*
        float progress;
        int total_enemies;
        int current_enemies;

        EnemySpawner* enemy_spawner;

        sf::Text title;
        sf::Text enemies_killed;
        sf::Text enemies_killed_count;

        sf::Sprite background;
    */
};