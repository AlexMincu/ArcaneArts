#include "Game/GUI/UpgradeMenu.h"


// Init Private Functions
void UpgradeMenu::initWindow() {
    if (!this->window_texture.loadFromFile("assets/GUI/upgrade_window.png")) {
        std::cerr << "Failed to load Upgrade Window Texture\n";
        exit(1);
    }

    this->window.setTexture(window_texture);

    float width_multiplier = 400 / this->window.getGlobalBounds().width;
    float height_multiplier = 600 / this->window.getGlobalBounds().height;
    this->window.setScale(width_multiplier, height_multiplier);

    this->window.setPosition(100, 100);
}

void UpgradeMenu::initButtons() {
    // Upgrade Button
    this->upgrade_button = new Button(Button::Type::Upgrade);
    this->upgrade_button->setPosition(20, 680);
    this->upgrade_button->setSize(100, 100);

    // Quit Upgrade Button
    this->quit_upgrade_button = new Button(Button::Type::Quit_upgrade);
    this->quit_upgrade_button->setPosition(470, 88);
    this->quit_upgrade_button->setSize(50, 50);

    // Upgrade Click Damage Button
    this->upgrade_click_damage_button = new Button(Button::Type::Upgrade_click_damage);
    this->upgrade_click_damage_button->setPosition(150, 135);
    this->upgrade_click_damage_button->setSize(100, 100);

    // Upgrade Click Damage Text
    if (!this->font.loadFromFile("assets/Fonts/langar.ttf")) {
        std::cerr << "Failed to load Font for Upgrade click damage text\n";
        exit(1);
    }
    this->click_damage_text.setFont(font);
    this->click_damage_text.setFillColor(sf::Color::White);
    this->click_damage_text.setCharacterSize(30);
    this->click_damage_text.setPosition(275, 165);
    this->click_damage_text.setString("1 Damage");
}


// Constructor
UpgradeMenu::UpgradeMenu() : upgrade_button{nullptr}, state{State::closed} {
    this->initButtons();
    this->initWindow();
}

// Destructor
UpgradeMenu::~UpgradeMenu() {
    delete this->upgrade_button;
}


// Update
void UpgradeMenu::update(const float& damage) {

    // Update Damage Text
    std::ostringstream ss;
    ss << damage;
    ss << " Damage";
    std::string de_afisat(ss.str()); // float -> string conversion
    this->click_damage_text.setString(de_afisat);
}


// Render
void UpgradeMenu::render(sf::RenderTarget *target) {
    this->upgrade_button->render(target);
    if(state == State::opened) {
        target->draw(window);
        this->quit_upgrade_button->render(target);
        this->upgrade_click_damage_button->render(target);
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


// Getters and Setters
