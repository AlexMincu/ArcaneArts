#include "Game/Characters/EnemySpawner.h"


// Init Private Functions
void EnemySpawner::initTextures() {
    if(!this->textures["MINOTAUR_SHEET1"].loadFromFile("assets/enemies/minotaur_sheet1.png")) {
        std::cerr << "Failed to load Minotaur1 Sheet\n";
        exit(1);
    }

    if(!this->textures["MINOTAUR_SHEET2"].loadFromFile("assets/enemies/minotaur_sheet2.png")) {
        std::cerr << "Failed to load Minotaur2 Sheet\n";
        exit(1);
    }

    if(!this->textures["HP_BAR_TEXTURE"].loadFromFile("assets/hp_bar.png")) {
        std::cerr << "Failed to load ProgressBar Texture\n";
        exit(1);
    }
}


// Constructor
EnemySpawner::EnemySpawner(const float &spawn_pos_x, const float &spawn_pos_y,
                           const std::map<std::string, sf::Texture>& textures)
                           : spawn_pos_x{spawn_pos_x}, spawn_pos_y{spawn_pos_y},
                           enemies_killed_count{0} {

    this->textures = textures;
    this->initTextures();
}

// Destructor
EnemySpawner::~EnemySpawner() {

}


// Update
void EnemySpawner::update(const float &dt) {
    if(!enemies.empty())
        enemies.at(0)->update(dt);

    this->deleteKilledEnemies();
}

void EnemySpawner::deleteKilledEnemies(){
    // Deleting
    if(!enemies.empty()) {

        if (enemies.at(0)->getCurrentHealth() <= 0) {
            if (enemies.at(0)->getEnemyState() == E_IDLE) {
                delete this->enemies.at(0);
                this->enemies.erase(this->enemies.begin());

                // Killed enemies Text
                enemies_killed_count++;
            }
        }

    }
}


// Render
void EnemySpawner::render(sf::RenderTarget *target){
    // Mobs
    for (auto *enemy : this->enemies)
    {
        enemy->render(target);
    }
}


// Functions
void EnemySpawner::spawn_minotaur1() {
    std::cout << "Spawning minotaru1\n";
    if(this->enemies.empty()){  // Recheck for safety
        this->enemies.push_back(new Enemy (50, this->spawn_pos_x, this->spawn_pos_y,
                                           this->textures["MINOTAUR_SHEET1"],
                                           this->textures["HP_BAR_TEXTURE"]));
    }
}

void EnemySpawner::spawn_minotaur2() {
    std::cout << "Spawning minotaru2\n";
    if(this->enemies.empty()){  // Recheck for safety
        this->enemies.push_back(new Enemy (100, this->spawn_pos_x, this->spawn_pos_y,
                                           this->textures["MINOTAUR_SHEET2"],
                                           this->textures["HP_BAR_TEXTURE"]));
    }
}


// Getters and Setters
int EnemySpawner::getEnemiesKilledCount() const {
    return enemies_killed_count;
}

bool EnemySpawner::isEnemySpawned() const {
    return !(enemies.empty());
}