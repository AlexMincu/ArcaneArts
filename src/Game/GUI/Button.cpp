#include "Game/GUI/Button.h"

// Constructor
Button::Button(const short& type,
               std::map<std::string, sf::Texture>& textures,
               std::map<std::string, sf::Font>& fonts) {

    switch(type){
        case Type::Pause: {
            this->window.setTexture(textures["Pause"]);

            this->text.setFont(fonts["Langar"]);
            this->text.setFillColor(sf::Color::White);
            this->text.setCharacterSize(16);
            this->text.setPosition(this->window.getPosition().x + this->window.getGlobalBounds().width / 2 -
                                   this->text.getGlobalBounds().width / 2,
                                   this->window.getPosition().y + this->window.getGlobalBounds().height / 2 -
                                   this->text.getGlobalBounds().width / 2);
            break;
        }

        case Type::DirectDamageMenu: {
            this->window.setTexture(textures["DirectDamageButton"]);
            break;
        }

        case Type::UpgradeDirectDamage: {
            this->window.setTexture(textures["UpgradeDirectDamage"]);
            break;
        }

        case Type::IdleDamageMenu: {
            this->window.setTexture(textures["IdleDamageButton"]);
            break;
        }

        case Type::SpellsMenu: {
            this->window.setTexture(textures["SpellsButton"]);
            break;
        }

        case Type::SettingsMenu: {
            this->window.setTexture(textures["SettingsButton"]);
            break;
        }

        default: {
            this->window.setTexture(textures["Button"]);

            // Init Text
            this->text.setFont(fonts["Courier"]);
            this->text.setFillColor(sf::Color::White);
            this->text.setCharacterSize(16);
            this->text.setPosition(this->window.getPosition().x + this->window.getGlobalBounds().width / 2 -
                                   this->text.getGlobalBounds().width / 2,
                                   this->window.getPosition().y + this->window.getGlobalBounds().height / 2 -
                                   this->text.getGlobalBounds().width / 2);
        }
    }
}

// Destructor
Button::~Button() {

}


// Update
bool Button::isPressed(const sf::Vector2i& mousePos) const{
    if(this->window.getGlobalBounds().contains(mousePos.x, mousePos.y))
            return true;

    return false;
}


// Render
void Button::render(sf::RenderTarget *target) {
    target->draw(this->window);
    target->draw(this->text);
}


// Getters and Setters
    // Text
void Button::setText(const std::string &s) {
    this->text.setString(s);
}

void Button::setTextSize(const unsigned int& size){
    this->text.setCharacterSize(size);
}

void Button::centerText(){
    this->text.setPosition(this->window.getPosition().x + this->window.getGlobalBounds().width/2 - this->text.getGlobalBounds().width/2,
                           this->window.getPosition().y + this->window.getGlobalBounds().height/2 - this->text.getGlobalBounds().height);
}
    // Window
void Button::setPosition(const float &x, const float &y) {
    this->window.setPosition(x, y);
}

void Button::setSize(const float &width, const float &height) {
    float width_multiplier = width / this->window.getGlobalBounds().width;
    float height_multiplier = height / this->window.getGlobalBounds().height;

    this->window.setScale(width_multiplier, height_multiplier);
}

sf::Vector2f Button::getPosition() {
    return this->window.getPosition();
}

sf::FloatRect Button::getSize() {
    return this->window.getGlobalBounds();
}