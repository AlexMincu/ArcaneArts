#include "Game/Game.h"


// Init Private Functions
void Game::initWindow() {
    std::string title = "Arcane Arts";
    uint16_t framerate_limit = 30;
    bool vert_sync = false;
    sf::VideoMode window_bounds(600, 800);

    this->window = new sf::RenderWindow(window_bounds,title, sf::Style::Close);
//    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vert_sync);
}

void Game::initKeys() {
    this->supportedKeys["Space"] = sf::Keyboard::Key::Space;
    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
}

void Game::initStates() {
    this->states.push(new GameState(this->window, &supportedKeys));
}

void Game::initDebug(){
    line[0].setPosition(window->getSize().x / 2.f, 0);
    line[1].setPosition(0, window->getSize().y / 2.f);

    line[0].setSize(sf::Vector2f(1, 2000));
    line[1].setSize(sf::Vector2f(2000, 1));

    line[0].setFillColor(sf::Color::Green);
    line[1].setFillColor(sf::Color::Green);
}

// Constructor
Game::Game()
: window{nullptr}, dt{0.f} {
    this->initWindow();
    this->initKeys();
    this->initStates();

    this->initDebug();
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
void Game::renderDebug(){
    this->window->draw(line[0]);
    this->window->draw(line[1]);
}
void Game::render() {
    this->window->clear(sf::Color::Black);

    // Display the state
    if(!this->states.empty())
            this->states.top()->render(this->window);

    this->renderDebug();

    this->window->display();

}


// Functions
void Game::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

