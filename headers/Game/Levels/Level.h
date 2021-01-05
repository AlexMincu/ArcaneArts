#pragma once

#include "Game/Characters/Enemy.h"
enum Mob {MINOTAUR = 0, MINOTAUR2 = 1, MINOTAUR3 = 3};

class Level {
public:
    // Constructor/ Destructor
    Level(sf::Vector2i pos,
          std::map<std::string, sf::Texture>& textures,
          std::map<std::string, sf::Font>& fonts);
    virtual ~Level();

    // Update
    virtual void update(const float &dt);
    virtual void updateProgress() = 0;
    virtual void updateText() = 0;
    virtual void updateEnemy(const float &dt);

    // Render
    virtual void render(sf::RenderTarget *target, const unsigned short& state);

    // Functions
    virtual void run() = 0;
    void save();

    // Getters and Setters
    std::string getTitle() const;
    int getProgress() const;
    int getEnemiesKilledCount() const;


    // Enemy Spawner Component
    void spawn(const float& hp, const unsigned short& mob);
    void attackEnemy(const float& damage);

    bool isEnemySpawned() const;
    bool EnemyHitboxPressed(const sf::Vector2i& mousePos) const;
    float getCurrentHealthPercentage() const;

protected:
        // Text
    sf::Text title;
    sf::Text enemies_killed_text;
    sf::Text enemies_killed_count_text;
        // Background
    sf::Sprite background;

    virtual void initLevel() = 0;


    // Enemy Spawner Component
    std::vector<Enemy*> enemies;
    sf::Vector2i spawn_pos;

    int progress;
    int total_enemies;
    int enemies_killed_count;

    std::map<std::string, sf::Texture> *textures;
};