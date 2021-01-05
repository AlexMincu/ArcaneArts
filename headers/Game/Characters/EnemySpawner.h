#pragma once

#include "Enemy.h"

enum Mob {MINOTAUR = 0, MINOTAUR2, MINOTAUR3};

class EnemySpawner {
public:
    // Constructor/Destructor
    EnemySpawner(const float &spawn_pos_x, const float &spawn_pos_y,
                 std::map<std::string, sf::Texture>& textures);
    virtual ~EnemySpawner();

    // Update
    void update(const float &dt);
    void deleteKilledEnemies();

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    void spawn(const float& hp, const unsigned short& mob);
    void attackEnemy(const float& damage);

    // Getters and Setters
    int getEnemiesKilledCount() const;
    bool isEnemySpawned() const;
    bool EnemyHitboxPressed(const sf::Vector2i& mousePos) const;
    float getCurrentHealthPercentage() const;

private:
    // Variables
    std::vector<Enemy*> enemies;
    float spawn_pos_x;
    float spawn_pos_y;
    int enemies_killed_count;

    std::map<std::string, sf::Texture> *textures;
};