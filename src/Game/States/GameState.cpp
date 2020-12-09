#include "Game/States/GameState.h"

// Init Private Functions

void GameState::initKeybinds() {
    this->keybinds ["ATTACK"] = this->supportedKeys->at("Space");
    this->keybinds ["EXIT"] = this->supportedKeys->at("Escape");
}

void GameState::initTextures() {
    if(!this->textures["MINOTAUR_SHEET"].loadFromFile("assets/enemies/minotaur_sheet.png")) {
        std::cerr << "Failed to load Minotaur Sheet\n";
        exit(1);
    }
    if(!this->textures["HP_BAR_TEXTURE"].loadFromFile("assets/hp_bar.png")) {
        std::cerr << "Failed to load ProgressBar Texture\n";
        exit(1);
    }
}

void GameState::initEnemy() {
    std::cout << "Find enemy pos\n";
    // Find the position to set the enemy in the middle of the window
    float enemy_pos_x = this->window->getSize().x/2.f - 180.f;       // Enemy image asset:
    float enemy_pos_y = this->window->getSize().y/2.f - 122.5f;      // 360 x 245

    std::cout << "Creating enemy\n";
    this->enemy = new Enemy(100, enemy_pos_x, enemy_pos_y, this->textures["MINOTAUR_SHEET"], this->textures["HP_BAR_TEXTURE"]);
}

void GameState::initText() {
    if(!this->font.loadFromFile("assets/Fonts/courier.ttf")) {
        std::cerr << "Failed to load Courier Font\n";
        exit(1);
    }

    // FPS
    this->fps.setFont(font);
    this->fps.setCharacterSize(20);
    this->fps.setFillColor(sf::Color::Green);
    this->fps.setPosition(5.f, 5.f);
}


// Constructor/Destructor
GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
    : State(window, supportedKeys), fps_render_timing{0.f}, dt_frames{0.f}, dt_average{0.f} {
    this->initKeybinds();
    this->initTextures();
    this->initEnemy();
    this->initText();
}

GameState::~GameState() {
    delete this->enemy;
}

// Update
void GameState::updateInput(const float &dt) {
    // Mouse
    this->updateMousePosition();

    // Keyboard
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("EXIT"))))
        this->endState();
}

void GameState::updateEntities(const float &dt) {
    // Enemies
    this->enemy->update(dt);
}

void GameState::updateFPS(const float &dt) {
   fps_render_timing += dt;
   dt_average += dt;
   dt_frames++;

   if(fps_render_timing >= 0.2) {
        float a = dt_frames / dt_average;
        std::ostringstream ss;
        ss << a;
        ss << " FPS\n";

        a = dt_average / dt_frames;
        ss << a;
        ss << " DT";

        std::string de_afisat(ss.str()); // float -> string conversion

        this->fps.setString(de_afisat);

        //Reset
        fps_render_timing = 0.f;
        dt_average = 0.f;
        dt_frames = 0.f;
   }
}

void GameState::update(const float &dt) {
    this->updateInput(dt);
    this->updateEntities(dt);
    this->updateFPS(dt);
}


// Render
void GameState::render(sf::RenderTarget *target) {
    if(!target)
        target = this->window;

    // Entities
    this->enemy->render(target);

    // FPS
    this->window->draw(fps);
}

