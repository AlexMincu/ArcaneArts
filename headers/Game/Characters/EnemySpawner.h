#pragma once

#include "Enemy.h"

class EnemySpawner {
public:
    // Constructor/Destructor
    EnemySpawner(const float &spawn_pos_x, const float &spawn_pos_y,
                 const std::map<std::string, sf::Texture>& textures);
    virtual ~EnemySpawner();

    // Update
    void update(const float &dt);

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    void spawn_minotaur();

private:
    // Init Private Functions
    void initTextures();

    // Variables
    std::vector<Enemy*> enemies;
    float spawn_pos_x;
    float spawn_pos_y;

    std::map<std::string, sf::Texture> textures;
};