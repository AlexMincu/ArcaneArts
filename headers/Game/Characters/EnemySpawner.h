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
    void updateEnemy(const float &dt);
    void updateText();

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    void spawn_minotaur1();
    void spawn_minotaur2();

private:
    // Init Private Functions
    void initTextures();
    void initText();

    // Variables
    std::vector<Enemy*> enemies;
    float spawn_pos_x;
    float spawn_pos_y;

    std::map<std::string, sf::Texture> textures;

    int enemies_killed_count;
    sf::Font font;
    sf::Text enemies_killed;

    //temp
    int last_killed;
};