#include "Game/GUI/UpgradeMenu.h"

// Constructor
UpgradeMenu::UpgradeMenu(std::map<std::string, sf::Texture>& textures,
                         std::map<std::string, sf::Font>& fonts)
                         : state{State::closed},
                           upgrade_open_button(Button::Type::Upgrade_Open, textures, fonts),
                           upgrade_close_button(Button::Type::Upgrade_Close, textures, fonts),
                           upgrade_click_damage_button(Button::Type::Upgrade_Click_Damage, textures, fonts) {


    // Window
    this->window.setTexture(textures["UpgradeWindow"]);
    float width_multiplier = 400 / this->window.getGlobalBounds().width;
    float height_multiplier = 600 / this->window.getGlobalBounds().height;
    this->window.setScale(width_multiplier, height_multiplier);
    this->window.setPosition(100, 100);

    // Upgrade Open Button
    this->upgrade_open_button.setPosition(39, 676);    //Bottom-GUI Slot1 39x676
    this->upgrade_open_button.setSize(100, 100);

    // Upgrade Close Button
    this->upgrade_close_button.setPosition(470, 88);
    this->upgrade_close_button.setSize(50, 50);

    // Upgrade Click Damage Button
    this->upgrade_click_damage_button.setPosition(150, 135);
    this->upgrade_click_damage_button.setSize(100, 100);

    // Upgrade Click Damage Text
    this->click_damage_text.setFont(fonts["Langar"]);
    this->click_damage_text.setFillColor(sf::Color::White);
    this->click_damage_text.setCharacterSize(25);
    this->click_damage_text.setPosition(275, 165);
    this->click_damage_text.setString("1 Click Damage");
}

// Destructor
UpgradeMenu::~UpgradeMenu() {
}


// Update
void UpgradeMenu::update(const float& damage) {

    // Update Damage Text
    std::ostringstream ss;
    ss << damage;
    ss << " Click Damage";
    std::string to_print(ss.str()); // float -> string conversion
    this->click_damage_text.setString(to_print);
}


// Render
void UpgradeMenu::render(sf::RenderTarget *target) {
    this->upgrade_open_button.render(target);

    if(state == State::opened) {
        target->draw(window);
        this->upgrade_close_button.render(target);
        this->upgrade_click_damage_button.render(target);
        target->draw(this->click_damage_text);
    }
}


// Functions
void UpgradeMenu::open() {
    this->state = State::opened;

    // Debug
    std::cout << "[UpgradeMenu] Open Upgrade Menu Window\n";
}

void UpgradeMenu::close() {
    this->state = State::closed;

    // Debug
    std::cout << "[UpgradeMenu] Close Upgrade Menu Window\n";
}


short UpgradeMenu::isButtonPressed(const sf::Vector2i& mousePos) const {
    if(this->upgrade_open_button.isPressed(mousePos)) {
        return UpgradeButton::Open;
    }

    else if(this->upgrade_close_button.isPressed(mousePos)) {
        return UpgradeButton::Close;
    }

    else if(this->upgrade_click_damage_button.isPressed(mousePos)) {
        return UpgradeButton::UpgradeClickDamage;
    }

    return UpgradeButton::NoButtonPressed;
}