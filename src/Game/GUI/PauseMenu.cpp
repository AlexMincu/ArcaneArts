#include "Game/GUI/PauseMenu.h"

// Constructor
PauseMenu::PauseMenu(std::map<std::string, sf::Texture>& textures,
                     std::map<std::string, sf::Font>& fonts)
                     :  return_button(Button::Type::Pause, textures, fonts),
                        quit_button(Button::Type::Pause, textures, fonts) {

    // Window
    this->window.setTexture(textures["MessageWindow"]);
    float width_multiplier = 400 / this->window.getGlobalBounds().width;
    float height_multiplier = 600 / this->window.getGlobalBounds().height;
    this->window.setScale(width_multiplier, height_multiplier);
    this->window.setPosition(100, 100);

    // Title
    this->title.setFont(fonts["Langar"]);
    this->title.setFillColor(sf::Color::White);
    this->title.setCharacterSize(30);
    this->title.setString("PAUSE");
    this->title.setPosition(300 - this->title.getGlobalBounds().width/2,
                            this->window.getPosition().y + 20);

    // Return Button
    this->return_button.setSize(160, 80);
    this->return_button.setPosition(300 - this->return_button.getSize().width/2,
                                    400 - 20 - this->return_button.getSize().height);
    this->return_button.setTextSize(18);
    this->return_button.setText("Return");
    this->return_button.centerText();

    // Quit Button
    this->quit_button.setSize(160, 80);
    this->quit_button.setPosition(300 - this->quit_button.getSize().width/2,
                                    400 + 20);
    this->quit_button.setTextSize(18);
    this->quit_button.setText("Quit");
    this->quit_button.centerText();
}

// Destructor
PauseMenu::~PauseMenu() {
}


// Render
void PauseMenu::render(sf::RenderTarget *target) {
    target->draw(this->window);
    target->draw(this->title);
    this->return_button.render(target);
    this->quit_button.render(target);
}