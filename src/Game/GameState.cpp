#include "Game/GameState.h"


void GameState::initKeybinds() {
    this->keybinds ["PRESS_Q"] = this->supportedKeys->at("Q");
    this->keybinds ["PRESS_W"] = this->supportedKeys->at("W");
    this->keybinds ["PRESS_A"] = this->supportedKeys->at("A");
    this->keybinds ["PRESS_S"] = this->supportedKeys->at("S");
    this->keybinds ["PRESS_D"] = this->supportedKeys->at("D");
    this->keybinds ["ATTACK"] = this->supportedKeys->at("Space");
    this->keybinds ["EXIT"] = this->supportedKeys->at("Escape");
}

void GameState::initTextures() {
    if(!this->textures["ENEMY_IDLE"].loadFromFile("assets/enemies/minotaur/idle_sheet.png"))
        throw "ERROR::GAME_STATE::MINOTAUR_IDLE_TEXTURE_FAILED_TO_LOAD";
}

void GameState::initEnemy() {
    this->enemy = new Enemy(0, 0, this->textures["ENEMY_IDLE"]);
}


GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
    : State(window, supportedKeys) {
    this->initKeybinds();
    this->initTextures();
    this->initEnemy();
}

GameState::~GameState() {
    delete this->enemy;
}


void GameState::updateInput(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ATTACK"))))
        std::cout << "Space was pressed! \n";

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("EXIT")))) {
        this->endState();
    }
}

void GameState::update(const float &dt) {
    this->updateInput(dt);
    this->enemy->update(dt);
}

void GameState::render(sf::RenderTarget *target) {
    if(!target)
        target = this->window;

    this->enemy->render(target);
}

