#include "Game/Levels/MinotaurForest.h"

// Init Private Functions
void MinotaurForest::initSettings() {
    this->progression = 0;
    this->total_enemies = 4;
}


// Constructor
MinotaurForest::MinotaurForest(const sf::Window &window, const std::map<std::string, sf::Texture>& textures)
: Level(window, textures){
    this->initSettings();
}

// Destructor
MinotaurForest::~MinotaurForest() {

}

// Update
void MinotaurForest::update(const float &dt) {
    Level::update(dt);
}


// Render
void MinotaurForest::render(sf::RenderTarget *target) {
    Level::render(target);
}


// Functions
void MinotaurForest::run() {
    Level::run();

    if(this->enemy_spawner->getLastKilled() == 1) {
        this->enemy_spawner->spawn_minotaur2();
    }
    else if(this->enemy_spawner->getLastKilled() == 2) {
        this->enemy_spawner->spawn_minotaur1();
    }
    else {
        this->enemy_spawner->spawn_minotaur1();
    }

}


// Getters and Setters
