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

void EnemySpawner::initText() {
    if(!this->font.loadFromFile("assets/Fonts/langar.ttf")){
        std::cerr << "Failed to load Langar Font for Enemy Spawner\n";
        exit(1);
    }
    this->enemies_killed.setFont(font);
    this->enemies_killed.setFillColor(sf::Color::White);
    this->enemies_killed.setCharacterSize(32);
    this->enemies_killed.setOutlineColor(sf::Color::Black);
    this->enemies_killed.setOutlineThickness(2);
    this->enemies_killed.setString("0 Enemies Killed");

    sf::Vector2 enemies_killed_pos(300, 200); // Upper half of the screen ( 600x800 resolution )
    enemies_killed_pos.x -= enemies_killed.getGlobalBounds().width / 2; // Add half of the text size to center it

    this->enemies_killed.setPosition(enemies_killed_pos.x, enemies_killed_pos.y);
}


// Constructor
EnemySpawner::EnemySpawner(const float &spawn_pos_x, const float &spawn_pos_y, const std::map<std::string, sf::Texture>& textures)
                           : spawn_pos_x{spawn_pos_x}, spawn_pos_y{spawn_pos_y}, enemies_killed_count{0},
                           last_killed{0}{

    this->textures = textures;
    this->initTextures();
    this->initText();

}

// Destructor
EnemySpawner::~EnemySpawner() {

}


// Update
void EnemySpawner::updateText(){
    std::ostringstream int2string;
    int2string << enemies_killed_count;
    int2string << " Enemies Killed";

    std::string string2print(int2string.str());

    this->enemies_killed.setString(string2print);
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
                this->updateText();
            }
        }

    }
}

void EnemySpawner::update(const float &dt) {
    if(!enemies.empty())
        enemies.at(0)->update(dt);

    this->deleteKilledEnemies();
}


// Render
void EnemySpawner::render(sf::RenderTarget *target){
    // Mobs
    for (auto *enemy : this->enemies)
    {
        enemy->render(target);
    }

    // Text
    target->draw(this->enemies_killed);
}


// Functions
void EnemySpawner::spawn_minotaur1() {

    if(this->enemies.empty()){
        this->enemies.push_back(new Enemy (50, this->spawn_pos_x, this->spawn_pos_y,
                                           this->textures["MINOTAUR_SHEET1"],
                                           this->textures["HP_BAR_TEXTURE"]));
        this->last_killed = 1;
    }
}

void EnemySpawner::spawn_minotaur2() {

    if(this->enemies.empty()){
        this->enemies.push_back(new Enemy (100, this->spawn_pos_x, this->spawn_pos_y,
                                           this->textures["MINOTAUR_SHEET2"],
                                           this->textures["HP_BAR_TEXTURE"]));
        this->last_killed = 2;
    }
}


// Getters and Setters
int EnemySpawner::getEnemiesKilledCount() const {
    return enemies_killed_count;
}

// temp
int EnemySpawner::getLastKilled() const {
    return last_killed;
}
