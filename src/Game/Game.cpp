#include "Game/Game.h"

bool Game::debug = false;

// Init Private Functions
void Game::initVariables() {
    this->window = nullptr;
    this->dt = 0.f;
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"Arcane Arts");
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


// Constructor/Destructor
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


// Updating
void Game::updateDt() {
    if(isDebug()) {
//        std::cout << "dt: " << this->dt << "\n";
        std::cout << "fps: " << (1.0f / dt) << "\n";
    }

    // Updating the time it takes to update and render a frame - Delta Time
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {
    // Pulls out an event
    while(this->window->pollEvent(this->event)){
        // Closing the window event
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update() {
    this->updateSFMLEvents();

    // If there is a state available
    if (!this->states.empty()) {
        this->states.top()->update(dt);

        // Ending state
        if(this->states.top()->getQuit()){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    // If states stack is empty close the game
    else{
        std::cout << "Closing the Game\n";
        this->window->close();
    }
}


// Rendering
void Game::render() {
    this->window->clear();

    // Display the state
    if(!this->states.empty())
            this->states.top()->render(this->window);

    this->window->display();
}


// Functions
void Game::run(const bool &Debug) {
    // Debug option
    if(Debug) {
        Game::debug = true;
    }

    while (this->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}


// Getters and Setters
bool Game::isDebug() {
    return debug;
}



