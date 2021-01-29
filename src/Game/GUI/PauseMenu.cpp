#include "Game/GUI/PauseMenu.h"

// Constructor
PauseMenu::PauseMenu(std::map<std::string, sf::Texture>& textures,
                     std::map<std::string, sf::Font>& fonts)
                     : return_button(Button::Type::Pause, textures, fonts),
                       close_button(Button::Type::Pause, textures, fonts) {

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
    this->close_button.setSize(160, 80);
    this->close_button.setPosition(300 - this->close_button.getSize().width / 2,
                                    400 + 20);
    this->close_button.setTextSize(18);
    this->close_button.setText("Quit");
    this->close_button.centerText();
}

// Destructor
PauseMenu::~PauseMenu() {
}


// Render
void PauseMenu::render(sf::RenderTarget *target) {
    target->draw(this->window);
    target->draw(this->title);
    this->return_button.render(target);
    this->close_button.render(target);
}

// Functions
short PauseMenu::isButtonPressed(const sf::Vector2i& mousePos) const {
    if(this->return_button.isPressed(mousePos)) {
        return PauseButton::Return;
    }

    else if(this->close_button.isPressed(mousePos)) {
        return PauseButton::Close;
    }

    return PauseButton::NoButtonPressed;
}