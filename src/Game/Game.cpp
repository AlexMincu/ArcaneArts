#include "Game/Game.h"

void Game::initVariables() {
    this->window = nullptr;
    this->dt = 0.f;
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"Arcane Arts");
    this->window->setFramerateLimit(120);
}

void Game::initKeys() {
    this->supportedKeys["Q"] = sf::Keyboard::Key::Q;
    this->supportedKeys["W"] = sf::Keyboard::Key::W;
    this->supportedKeys["A"] = sf::Keyboard::Key::A;
    this->supportedKeys["S"] = sf::Keyboard::Key::S;
    this->supportedKeys["D"] = sf::Keyboard::Key::D;
    this->supportedKeys["Space"] = sf::Keyboard::Key::Space;
    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
}

void Game::initStates() {
    this->states.push(new GameState(this->window, &supportedKeys));
}


Game::Game() {
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game() {
    delete this->window;

    while(!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
}

void Game::endApplication() {
    std::cout << "Ending Game window\n";
}

void Game::updateDt() {
    /* Updating the time it takes to update and render a frame
     */
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {
    while(this->window->pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update() {
    this->updateSFMLEvents();

    if (!this->states.empty()) {
        this->states.top()->update(dt);

        if(this->states.top()->getQuit()){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else{
        this->endApplication();
        this->window->close();
    }
}

void Game::render() {
    this->window->clear();

    if(!this->states.empty())
            this->states.top()->render(this->window);

    this->window->display();
}

void Game::run() {
    while (this->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}





