#include <Game/Game.h>
#include "Game/GameState.h"

// Init Private Functions
void GameState::initKeybinds() {
    this->keybinds ["ATTACK"] = this->supportedKeys->at("Space");
    this->keybinds ["EXIT"] = this->supportedKeys->at("Escape");
}

void GameState::initTextures() {
    if(!this->textures["MINOTAUR_SHEET"].loadFromFile("assets/enemies/minotaur/minotaur_sheet.png")) {
        std::cerr << "Failed to load Minotaur Sheet\n";
        exit(1);
    }
}

void GameState::initEnemy() {
    this->enemy = new Minotaur(100, 100, this->textures["MINOTAUR_SHEET"]);
}


// Constructor/Destructor
GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
    : State(window, supportedKeys) {
    this->initKeybinds();                                   // Virtual member in constructor? ################################################
    this->initTextures();
    this->initEnemy();
}

GameState::~GameState() {
    delete this->enemy;
}

// Update
void GameState::updateInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ATTACK")))) {
        if (Game::isDebug())
            std::cout << "ATTACK Button was pressed! \n";
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("EXIT")))) {
        this->endState();
        if (Game::isDebug())
            std::cout << "EXIT Button was pressed! \n";
    }
}

void GameState::update(const float &dt) {
    // Update Mouse Positioning
    this->updateMousePosition();
    if (Game::isDebug()) {
        system("cls");
        std::cout << "Screen: " << this->mouse_pos_screen.x << " " << this->mouse_pos_screen.y << "\n";
        std::cout << "Window: " << this->mouse_pos_window.x << " " << this->mouse_pos_window.y << "\n";
    }

    // Update Keyboard Input
    this->updateInput(dt);

    // Update Entities
    this->enemy->update(dt);
}


// Render
void GameState::render(sf::RenderTarget *target) {
    if(!target)
        target = this->window;

    // Render Entities
    this->enemy->render(target);
}

