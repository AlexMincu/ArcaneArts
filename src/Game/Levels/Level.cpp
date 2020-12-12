#include "Game/Levels/Level.h"

// Init Private Functions
void Level::initEnemySpawner(const sf::Window &window, const std::map<std::string, sf::Texture>& textures) {
    // Find the position to set the enemy in the middle of the window
    float enemy_pos_x = window.getSize().x/2.f - 180.f;       // Enemy image asset:
    float enemy_pos_y = window.getSize().y/2.f - 90.f;      // 360 x 245

    this->enemy_spawner = new EnemySpawner(enemy_pos_x, enemy_pos_y, textures);
}


// Constructor
Level::Level(const sf::Window &window, const std::map<std::string, sf::Texture>& textures) {
    this->initEnemySpawner(window, textures);
}

// Destructor
Level::~Level() {
    delete this->enemy_spawner;
}


// Update
void Level::update(const float &dt){
    this->enemy_spawner->update(dt);
}

// Render
void Level::render(sf::RenderTarget *target) {
    this->enemy_spawner->render(target);
}


// Functions
void Level::run() {

}


// Getters and Setters