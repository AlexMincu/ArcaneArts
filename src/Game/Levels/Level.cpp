#include "Game/Levels/Level.h"

// Constructor
Level::Level(sf::Vector2i pos, std::map<std::string, sf::Texture>& textures,
             std::map<std::string, sf::Font>& fonts)
             :  textures{&textures},
                spawn_pos{pos.x, pos.y},
                progress{0}, total_enemies{0}, enemies_killed_count{0} {

    // Title
    this->title.setFont(fonts["Langar"]);
    this->title.setFillColor(sf::Color::White);
    this->title.setCharacterSize(32);
    this->title.setOutlineColor(sf::Color::Black);
    this->title.setOutlineThickness(2);
    this->title.setString("Title");


    // Enemies Killed
    this->enemies_killed_text.setFont(fonts["Langar"]);
    this->enemies_killed_text.setFillColor(sf::Color::White);
    this->enemies_killed_text.setCharacterSize(32);
    this->enemies_killed_text.setOutlineColor(sf::Color::Black);
    this->enemies_killed_text.setOutlineThickness(2);
    this->enemies_killed_text.setString("Enemies Killed");

    // Upper half of the screen ( 600x800 resolution )
    this->enemies_killed_text.setPosition(300, 250);
    // Added half of the text width to x_pos to center it horizontally
    this->enemies_killed_text.setPosition(this->enemies_killed_text.getPosition().x - this->enemies_killed_text.getGlobalBounds().width/2,
                                     this->enemies_killed_text.getPosition().y);


    // Enemies killed count (no of enemies killed)
    this->enemies_killed_count_text.setFont(fonts["Langar"]);
    this->enemies_killed_count_text.setFillColor(sf::Color::White);
    this->enemies_killed_count_text.setCharacterSize(32);
    this->enemies_killed_count_text.setOutlineColor(sf::Color::Black);
    this->enemies_killed_count_text.setOutlineThickness(2);
    this->enemies_killed_count_text.setString("None");

    // Upper half of the screen ( 600x800 resolution )
    this->enemies_killed_count_text.setPosition(300, 200);
    // Added half of the text width to x_pos to center it horizontally
    this->enemies_killed_count_text.setPosition(this->enemies_killed_count_text.getPosition().x - this->enemies_killed_count_text.getGlobalBounds().width/2,
                                           this->enemies_killed_count_text.getPosition().y);

}

// Destructor
Level::~Level() {
    this->save();
}


// Update
void Level::update(const float &dt){
    if(!enemies.empty()) {
        this->updateEnemy(dt);
    }
}

void Level::updateEnemy(const float &dt) {
    enemies.at(0)->update(dt);

    // If enemy is killed, delete it
    if (enemies.at(0)->getCurrentHealth() <= 0) {
        if (enemies.at(0)->getEnemyState() == Enemy::State::IDLE) {
            delete this->enemies.at(0);
            this->enemies.erase(this->enemies.begin());

            // Killed enemies Text
            enemies_killed_count++;
        }
    }
}


// Render
void Level::render(sf::RenderTarget *target, const unsigned short& state) {

    // Background
    target->draw(this->background);

    if(state == 1) {    // If the game is running
        // Mobs
        if(!this->enemies.empty())
            this->enemies.at(0)->render(target);

        // Texts
        target->draw(title);
        target->draw(enemies_killed_text);
        target->draw(enemies_killed_count_text);
    }

}


// Functions
void Level::save() {
    // Debug
    std::cout << "[Level] Saving...\n";

    std::fstream fout;
    fout.open("save.txt", std::fstream::app);
    if(fout.is_open()){
        fout << "progress = " << progress << "\n";
        fout.close();
    }

    // Debug
    std::cout << "[Level] Saving done\n";
}


// Getters and Setters
std::string Level::getTitle() const{
    return this->title.getString();
}

int Level::getProgress() const {
    return this->progress;
}

int Level::getEnemiesKilledCount() const {
    return enemies_killed_count;
}




// Enemy Spawner Component
void Level::spawn(const float& hp, const unsigned short& mob) {
    if(this->enemies.empty()){

        if(mob == Mob::MINOTAUR) {

            //DEBUG
            std::cout << "[Enemy Spawner] Spawning minotaru1\n";

            this->enemies.push_back(new Enemy(hp, this->spawn_pos.x, this->spawn_pos.y,
                                              (*this->textures)["Minotaur1"]));
        }
        else if(mob == Mob::MINOTAUR2) {

            //DEBUG
            std::cout << "[Enemy Spawner] Spawning minotaru2\n";

            this->enemies.push_back(new Enemy(hp, this->spawn_pos.x, this->spawn_pos.y,
                                              (*this->textures)["Minotaur2"]));
        }
        else if(mob == Mob::MINOTAUR3) {

            //DEBUG
            std::cout << "[Enemy Spawner] Spawning minotaru3\n";

            this->enemies.push_back(new Enemy(hp, this->spawn_pos.x, this->spawn_pos.y,
                                              (*this->textures)["Minotaur3"]));
        }
    }

}

void Level::attackEnemy(const float& damage) {
    if(!this->enemies.empty())
        this->enemies[0]->attack(damage);
}


bool Level::isEnemySpawned() const {
    return !(enemies.empty());
}

bool Level::EnemyHitboxPressed (const sf::Vector2i& mousePos) const {
    if(!this->enemies.empty())
        return this->enemies[0]->HitboxPressed(mousePos);

    return false;
}

float Level::getCurrentHealthPercentage() const {
    return this->enemies[0]->getCurrentHealthPercentage();
}