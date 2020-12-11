#include "Game/States/State.h"

// Constructor/Destructor
State::State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
    : window{window}, supportedKeys{supportedKeys}, quit{false} {

}

State::~State() = default;


// Update
void State::updateMousePosition() {
    this->mouse_pos_screen = sf::Mouse::getPosition();
    this->mouse_pos_window = sf::Mouse::getPosition(*this->window);
//    std::cout << sf::Mouse::getPosition(*this->window).x << "  " << sf::Mouse::getPosition(*this->window).y << "\n";

}


// Functions
void State::endState() {
    this->quit = true;
}


// Getters and Setters
const bool &State::getQuit() const {
    return this->quit;
}
