#include "Game/GUI/PopMessage.h"

// Init Private Functions
void PopMessage::initWindow(){
    if(!this->window_texture.loadFromFile("assets/GUI/message_window.png")){
        std::cerr << "Failed to load Message Window for Pop Message\n";
        exit(1);
    }

    this->window.setTexture(window_texture);
    this->window.setPosition(0,0);
}
void PopMessage::initText() {
    if(!this->font.loadFromFile("assets/Fonts/courier.ttf")){
        std::cerr << "Failed to load Courier Font for Pop Message\n";
        exit(1);
    }

    // Title
    this->title.setFont(font);
    this->title.setFillColor(sf::Color(196, 129, 42));
    this->title.setCharacterSize(24);

    // Message
    this->message.setFont(font);
    this->message.setFillColor(sf::Color::White);
    this->message.setCharacterSize(18);
}


// Constructor
PopMessage::PopMessage() {
    this->initWindow();
    this->initText();
}

// Destructor
PopMessage::~PopMessage() {

}


// Render
void PopMessage::render(sf::RenderTarget *target) {
    target->draw(this->window);
    target->draw(this->title);
    target->draw(this->message);
}


// Getters and Setters
    // Text - Title
void PopMessage::setMessageTitle(const std::string &s){
    this->title.setString(s);
}

void PopMessage::centerMessageTitle(){
    this->title.setPosition(this->window.getPosition().x + this->window.getGlobalBounds().width / 2 -
                            this->title.getGlobalBounds().width / 2,
                            this->window.getPosition().y + 50);
}

    // Text - Message
void PopMessage::setMessage(const std::string &s){
    this->message.setString(s);
}

void PopMessage::centerMessage() {
    this->message.setPosition(this->window.getPosition().x + this->window.getGlobalBounds().width / 2 -
                              this->title.getGlobalBounds().width / 2 - 20,
                              this->window.getPosition().y + 170);
}
    // Window
void PopMessage::setWindowPosition(const float& x, const float& y){
    this->window.setPosition(x, y);
}

sf::Vector2f PopMessage::getWindowPosition(){
    return this->window.getPosition();
}

sf::FloatRect PopMessage::getWindowSize(){
    return this->window.getGlobalBounds();
}