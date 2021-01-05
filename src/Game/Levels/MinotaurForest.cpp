#include "Game/Levels/MinotaurForest.h"

// Constructor
MinotaurForest::MinotaurForest(const sf::Window *window,
                               std::map<std::string, sf::Texture>& textures,
                               std::map<std::string, sf::Font>& fonts)
                               : Level(window, textures, fonts) {

    // Variables
    this->progress = 0;
    this->current_enemies = 0;
    this->total_enemies = 5;

    // Text
    this->title.setString("Minotaur Forest");
    // Repositioning
    this->title.setPosition(300, 30);
    // Added half of the text width to x_pos to center it horizontally
    this->title.setPosition(this->title.getPosition().x - this->title.getGlobalBounds().width/2,
                            this->title.getPosition().y);

    // Background

    background.setTexture(textures["MinotaurForest"]);
    background.setPosition(0, 0);
}

// Destructor
MinotaurForest::~MinotaurForest() {

}

// Update
void MinotaurForest::update(const float &dt) {
    Level::update(dt);

    this->updateProgress();
    this->updateText();
    this->run();

}

void MinotaurForest::updateProgress(){
    this->current_enemies = this->enemy_spawner.getEnemiesKilledCount();
    this->progress = current_enemies;
}


// Functions
void MinotaurForest::run() {
    if(!this->enemy_spawner.isEnemySpawned() &&
    this->current_enemies < this->total_enemies){
        switch(current_enemies){
            case 0:
            case 1:
            case 2:
                this->enemy_spawner.spawn(5, Mob::MINOTAUR); break;
            case 3:
                this->enemy_spawner.spawn(5, Mob::MINOTAUR2); break;
            case 4:
                this->enemy_spawner.spawn(5, Mob::MINOTAUR3); break;
            case 5:
            default: std::cout << "[Level] Something's wrong in run()\n";
        }
    }
}

void MinotaurForest::updateText() {
    std::ostringstream int2string;
    int2string << this->current_enemies;

    std::string string2print(int2string.str());

    this->enemies_killed_count.setString(string2print);

    // Repositioning
        // Upper half of the screen ( 600x800 resolution )
        this->enemies_killed_count.setPosition(300, 200);
        // Added half of the text width to x_pos to center it horizontally
        this->enemies_killed_count.setPosition(
                this->enemies_killed_count.getPosition().x - this->enemies_killed_count.getGlobalBounds().width/2,
                this->enemies_killed_count.getPosition().y);
}