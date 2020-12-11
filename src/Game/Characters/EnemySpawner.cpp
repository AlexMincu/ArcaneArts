#include "Game/Characters/EnemySpawner.h"


// Init Private Functions
void EnemySpawner::initTextures() {
    if(!this->textures["MINOTAUR_SHEET"].loadFromFile("assets/enemies/minotaur_sheet.png")) {
        std::cerr << "Failed to load Minotaur Sheet\n";
        exit(1);
    }
    if(!this->textures["HP_BAR_TEXTURE"].loadFromFile("assets/hp_bar.png")) {
        std::cerr << "Failed to load ProgressBar Texture\n";
        exit(1);
    }
}

// Constructor
EnemySpawner::EnemySpawner(const float &spawn_pos_x, const float &spawn_pos_y, const std::map<std::string, sf::Texture>& textures)
                           : spawn_pos_x{spawn_pos_x}, spawn_pos_y{spawn_pos_y} {

    this->textures = textures;
    this->initTextures();
}

// Destructor
EnemySpawner::~EnemySpawner() {

}


// Update
void EnemySpawner::update(const float &dt) {

    // Spawning
    spawn_minotaur();

    // Updating
    enemies.at(0)->update(dt);

    // Deleting
    if(enemies.at(0)->getCurrentHealth() <= 0) {
        delete this->enemies.at(0);
        this->enemies.erase(this->enemies.begin());
    }
}


// Render
void EnemySpawner::render(sf::RenderTarget *target){
    for (auto *enemy : this->enemies)
    {
        enemy->render(target);
    }
}


// Functions
void EnemySpawner::spawn_minotaur() {
    if(this->enemies.empty()){
        this->enemies.push_back(new Enemy (30, this->spawn_pos_x, this->spawn_pos_y,
                                           this->textures["MINOTAUR_SHEET"],
                                           this->textures["HP_BAR_TEXTURE"]));
    }
}
