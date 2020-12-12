#pragma once

#include "Game/Characters/EnemySpawner.h"

class Level {
public:
    // Constructor/ Destructor
    Level(const sf::Window &window, const std::map<std::string, sf::Texture>& textures);
    virtual ~Level();

    // Update
    virtual void update(const float &dt);

    // Render
    virtual void render(sf::RenderTarget *target);

    // Functions
    virtual void run();

protected:
    // Variables
    float progression;
    int total_enemies;
    int current_enemies;

    // Components
    EnemySpawner* enemy_spawner;
    //Background

private:
    // Init functions
    void initEnemySpawner(const sf::Window &window, const std::map<std::string, sf::Texture>& textures);
};