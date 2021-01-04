#include "Game/GUI/Button.h"

// Constructor
Button::Button(const short& type) {

    if (type == Type::Default) {
        //Init Window(texture)
        if (!this->window_texture.loadFromFile("assets/GUI/button.png")) {
            std::cerr << "Failed to load Button Texture\n";
            exit(1);
        }

        this->window.setTexture(window_texture);


        // Init Text
        if (!this->font.loadFromFile("assets/Fonts/courier.ttf")) {
            std::cerr << "Failed to load Courier Font for Button\n";
            exit(1);
        }

        this->text.setFont(font);
        this->text.setFillColor(sf::Color::White);
        this->text.setCharacterSize(16);
        this->text.setPosition(this->window.getPosition().x + this->window.getGlobalBounds().width / 2 -
                               this->text.getGlobalBounds().width / 2,
                               this->window.getPosition().y + this->window.getGlobalBounds().height / 2 -
                               this->text.getGlobalBounds().width / 2);

    }

    else if(type == Type::Upgrade) {
        if (!this->window_texture.loadFromFile("assets/GUI/upgrade_button.png")) {
            std::cerr << "Failed to load Upgrade Button Texture\n";
            exit(1);
        }

        this->window.setTexture(window_texture);
    }

    else if(type == Type::Quit_upgrade) {
        if (!this->window_texture.loadFromFile("assets/GUI/quit_upgrade_button.png")) {
            std::cerr << "Failed to load Quit Upgrade Button Texture\n";
            exit(1);
        }

        this->window.setTexture(window_texture);
    }

    else if(type == Type::Upgrade_click_damage) {
        if (!this->window_texture.loadFromFile("assets/GUI/upgrade_click_damage_button.png")) {
            std::cerr << "Failed to load Quit Upgrade Button Texture\n";
            exit(1);
        }

        this->window.setTexture(window_texture);
    }
}

// Destructor
Button::~Button() {

}


// Update
bool Button::isPressed(const sf::Vector2i& mousePos){
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