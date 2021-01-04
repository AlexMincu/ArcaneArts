#include "Game/Characters/EnemySpawner.h"


// Init Private Functions
void EnemySpawner::initTextures() {
    if(!this->textures["MINOTAUR1_SHEET"].loadFromFile("assets/enemies/minotaur1_sheet.png")) {
        std::cerr << "Failed to load Minotaur1 Sheet\n";
        exit(1);
    }

    if(!this->textures["MINOTAUR2_SHEET"].loadFromFile("assets/enemies/minotaur2_sheet.png")) {
        std::cerr << "Failed to load Minotaur2 Sheet\n";
        exit(1);
    }

    if(!this->textures["MINOTAUR3_SHEET"].loadFromFile("assets/enemies/minotaur3_sheet.png")) {
        std::cerr << "Failed to load Minotaur3 Sheet\n";
        exit(1);
    }

    if(!this->textures["HP_BAR_TEXTURE"].loadFromFile("assets/GUI/hp_bar.png")) {
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
    if(!this->enemies.empty())
        this->enemies.at(0)->render(target);
}


// Functions
void EnemySpawner::spawn(const float& hp, const unsigned short& mob) {
    if(this->enemies.empty()){

        if(mob == Mob::MINOTAUR) {

            //DEBUG
            std::cout << "[Enemy Spawner] Spawning minotaru1\n";

            this->enemies.push_back(new Enemy(hp, this->spawn_pos_x, this->spawn_pos_y,
                                              this->textures["MINOTAUR1_SHEET"],
                                              this->textures["HP_BAR_TEXTURE"]));
        }
        else if(mob == Mob::MINOTAUR2) {

            //DEBUG
            std::cout << "[Enemy Spawner] Spawning minotaru2\n";

            this->enemies.push_back(new Enemy(hp, this->spawn_pos_x, this->spawn_pos_y,
                                              this->textures["MINOTAUR2_SHEET"],
                                              this->textures["HP_BAR_TEXTURE"]));
        }
        else if(mob == Mob::MINOTAUR3) {

            //DEBUG
            std::cout << "[Enemy Spawner] Spawning minotaru3\n";

            this->enemies.push_back(new Enemy(hp, this->spawn_pos_x, this->spawn_pos_y,
                                              this->textures["MINOTAUR3_SHEET"],
                                              this->textures["HP_BAR_TEXTURE"]));
        }
    }

}

void EnemySpawner::attackEnemy(const float& damage) {
    if(!this->enemies.empty())
        this->enemies[0]->attack(damage);
}

bool EnemySpawner::EnemyHitboxPressed(const sf::Vector2i& mousePos) const {
    if(!this->enemies.empty())
        return this->enemies[0]->HitboxPressed(mousePos);

    return false;
}


// Getters and Setters
int EnemySpawner::getEnemiesKilledCount() const {
    return enemies_killed_count;
}

bool EnemySpawner::isEnemySpawned() const {
    return !(enemies.empty());
}