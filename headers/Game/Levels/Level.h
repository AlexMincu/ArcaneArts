#pragma once

#include "Game/Characters/EnemySpawner.h"

class Level {
public:
    // Constructor/ Destructor
    Level(const sf::Window *window,
          std::map<std::string, sf::Texture>& textures,
          std::map<std::string, sf::Font>& fonts);
    virtual ~Level();

    // Update
    virtual void update(const float &dt);
    virtual void updateProgress() = 0;
    virtual void updateText() = 0;

    // Render
    virtual void render(sf::RenderTarget *target, const unsigned short& state);

    // Functions
    virtual void run() = 0;
    void UseEnemySpawnerAttack(const float& damage);
    void save();

    // Getters and Setters
    bool EnemyHitboxPressed(const sf::Vector2i& mousePos);
    float getCurrentHealthPercentage() const;
    std::string getTitle();
    const int& getProgress() const;

protected:
    // Variables
    int progress;
    int total_enemies;
    int current_enemies;

    // Components
    EnemySpawner enemy_spawner;
        // Text
    sf::Text title;
    sf::Text enemies_killed;
    sf::Text enemies_killed_count;
        // Background
    sf::Sprite background;

private:
};