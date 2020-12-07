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
}


// Functions
void State::endState() {
    this->quit = true;
}


// Getters and Setters
const bool &State::getQuit() const {
    return this->quit;
}
