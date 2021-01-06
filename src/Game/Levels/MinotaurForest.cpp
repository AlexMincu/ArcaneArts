#include "Game/Levels/MinotaurForest.h"

void MinotaurForest::initLevel() {
    // Variables
        this->progress = 0;
        this->enemies_killed_count = 0;
        this->total_enemies = 5;

    // Title
    this->title.setString("Minotaur Forest");
        // Recenter the title
    this->title.setPosition(this->title.getPosition().x - this->title.getGlobalBounds().width/2,
                            this->title.getPosition().y);

    // Background
    background.setTexture((*this->textures)["MinotaurForest"]);
}


// Constructor
MinotaurForest::MinotaurForest(sf::Vector2i pos,
                               std::map<std::string, sf::Texture>& textures,
                               std::map<std::string, sf::Font>& fonts)
                               : Level(pos, textures, fonts) {
    this->initLevel();
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
    this->enemies_killed_count = this->getEnemiesKilledCount();
    this->progress = enemies_killed_count;
}


// Functions
void MinotaurForest::run() {
    if(!this->isEnemySpawned() && this->enemies_killed_count < this->total_enemies){
        switch(enemies_killed_count){
            case 0:
            case 1:
            case 2:
                this->spawn(5, Mob::MINOTAUR); break;
            case 3:
                this->spawn(5, Mob::MINOTAUR2); break;
            case 4:
                this->spawn(5, Mob::MINOTAUR3); break;
            case 5:
            default: std::cout << "[Level] Something's wrong in run() from " << this->getTitle() << "\n";
        }
    }
}

void MinotaurForest::updateText() {
    std::ostringstream int2string;
    int2string << this->enemies_killed_count;

    std::string string2print(int2string.str());

    this->enemies_killed_count_text.setString(string2print);

    // Repositioning
        // Upper half of the screen ( 600x800 resolution )
        this->enemies_killed_count_text.setPosition(300, 200);
        // Added half of the text width to x_pos to center it horizontally
        this->enemies_killed_count_text.setPosition(this->enemies_killed_count_text.getPosition().x -
                                                    this->enemies_killed_count_text.getGlobalBounds().width/2,
                                                    this->enemies_killed_count_text.getPosition().y);
}

