#include "Game/Game.h"


// Init Private Functions
void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800,600),"Arcane Arts");
    this->window->setFramerateLimit(60);
}

void Game::initKeys() {
    this->supportedKeys["Space"] = sf::Keyboard::Key::Space;
    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
}

void Game::initStates() {
    this->states.push(new GameState(this->window, &supportedKeys));
}


// Constructor
Game::Game()
: window{nullptr}, dt{0.f} {
    this->initWindow();
    this->initKeys();
    this->initStates();
}


// Destructor
Game::~Game() {
    delete this->window;

    while(!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
}


// Updating
void Game::updateDt() {
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

void Game::updateStates() {
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


void Game::update() {
    this->updateDt();
    this->updateSFMLEvents();
    this->updateStates();
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
void Game::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

