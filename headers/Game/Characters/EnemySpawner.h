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
    void deleteKilledEnemies();

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    void spawn_minotaur1();
    void spawn_minotaur2();

    // Getters and Setters
    int getEnemiesKilledCount() const;
    bool isEnemySpawned() const;

private:
    // Variables
    std::vector<Enemy*> enemies;
    float spawn_pos_x;
    float spawn_pos_y;
    int enemies_killed_count;

    std::map<std::string, sf::Texture> textures;

    // Init Private Functions
    void initTextures();
};