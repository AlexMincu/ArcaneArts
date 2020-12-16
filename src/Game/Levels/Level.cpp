#include "Game/Levels/Level.h"

// Init Private Functions
void Level::initEnemySpawner(const sf::Window *window,
                             const std::map<std::string, sf::Texture>& textures) {
    // Find the position to set the enemy in the middle of the window
    float enemy_pos_x = window->getSize().x/2.f - 180.f;       // Enemy image asset:
    float enemy_pos_y = window->getSize().y/2.f - 90.f;      // 360 x 245

    this->enemy_spawner = new EnemySpawner(enemy_pos_x, enemy_pos_y, textures);
}

void Level::initText() {
    if(!this->font.loadFromFile("assets/Fonts/langar.ttf")){
        std::cerr << "Failed to load Langar Font for Enemy Spawner\n";
        exit(1);
    }

    // Title
    this->title.setFont(font);
    this->title.setFillColor(sf::Color::White);
    this->title.setCharacterSize(32);
    this->title.setOutlineColor(sf::Color::Black);
    this->title.setOutlineThickness(2);
    this->title.setString("Title");
    this->title.setPosition(300, 30);
        // Added half of the text width to x_pos to center it horizontally
    this->title.setPosition(this->title.getPosition().x - this->title.getGlobalBounds().width/2,
                            this->title.getPosition().y);


    // Enemies Killed
    this->enemies_killed.setFont(font);
    this->enemies_killed.setFillColor(sf::Color::White);
    this->enemies_killed.setCharacterSize(32);
    this->enemies_killed.setOutlineColor(sf::Color::Black);
    this->enemies_killed.setOutlineThickness(2);
    this->enemies_killed.setString("Enemies Killed");

        // Upper half of the screen ( 600x800 resolution )
    this->enemies_killed.setPosition(300, 250);
        // Added half of the text width to x_pos to center it horizontally
    this->enemies_killed.setPosition(this->enemies_killed.getPosition().x - this->enemies_killed.getGlobalBounds().width/2,
                                     this->enemies_killed.getPosition().y);


    // Enemies killed count (no of enemies killed)
    this->enemies_killed_count.setFont(font);
    this->enemies_killed_count.setFillColor(sf::Color::White);
    this->enemies_killed_count.setCharacterSize(32);
    this->enemies_killed_count.setOutlineColor(sf::Color::Black);
    this->enemies_killed_count.setOutlineThickness(2);
    this->enemies_killed_count.setString("None");

    // Upper half of the screen ( 600x800 resolution )
    this->enemies_killed_count.setPosition(300, 200);
        // Added half of the text width to x_pos to center it horizontally
    this->enemies_killed_count.setPosition(this->enemies_killed_count.getPosition().x - this->enemies_killed_count.getGlobalBounds().width/2,
                                           this->enemies_killed_count.getPosition().y);

}

// Constructor
Level::Level(const sf::Window *window,
             const std::map<std::string, sf::Texture>& textures) {

    this->initEnemySpawner(window, textures);
    this->initText();
}

// Destructor
Level::~Level() {
    this->save();
    delete this->enemy_spawner;
}


// Update
void Level::update(const float &dt){
    this->enemy_spawner->update(dt);
}

// Render
void Level::render(sf::RenderTarget *target, const unsigned short& state) {

    if(state == 1) {    // If the game is running
        // Background
        target->draw(this->background);

        // Mobs
        this->enemy_spawner->render(target);

        // Texts
        target->draw(title);
        target->draw(enemies_killed);
        target->draw(enemies_killed_count);
    }

    if(state == 0) {    // If the game is paused
        // Background
        target->draw(this->background);

        // Texts
        target->draw(title);
    }
}


// Functions
void Level::UseEnemySpawnerAttack() {
    this->enemy_spawner->attackEnemy();
}
void Level::save() {
    // Debug
    std::cout << "[Level] Saving...\n";

    std::fstream fout;
    fout.open("save.txt", std::fstream::app);
    if(fout.is_open()){
        fout << "progress = " << progress << "\n";
        fout << "current_enemies = " << current_enemies << "\n\n";
        fout.close();
    }

    // Debug
    std::cout << "[Level] Saving done\n";
}


// Getters and Setters
bool Level::EnemyHitboxPressed (const sf::Vector2i& mousePos) {
    return this->enemy_spawner->EnemyHitboxPressed(mousePos);
}
std::string Level::getTitle(){
    return this->title.getString();
}