#pragma once

#include "Game/Characters/EnemySpawner.h"

class Level {
public:
    // Constructor/ Destructor
    Level(const sf::Window *window,
          const std::map<std::string, sf::Texture>& textures);
    virtual ~Level();

    // Update
    virtual void update(const float &dt);
    virtual void updateProgress() = 0;
    virtual void updateText() = 0;

    // Render
    virtual void render(sf::RenderTarget *target, const unsigned short& state);

    // Functions
    virtual void run() = 0;
    void save();

    // Getters and Setters
    std::string getTitle();

protected:
    // Variables
    float progress;
    int total_enemies;
    int current_enemies;

    // Components
    EnemySpawner* enemy_spawner;
        // Text
    sf::Font font;
    sf::Text title;
    sf::Text enemies_killed;
    sf::Text enemies_killed_count;
        // Background
    sf::Sprite background;
    sf::Texture background_texture;

private:
    // Init functions
    void initEnemySpawner(const sf::Window *window,
                          const std::map<std::string, sf::Texture>& textures);
    void initText();
};