#include "Game/GUI/Menu.h"

void Menu::initUpgradesSection(std::map<std::string, sf::Font>& fonts) {
    // Main Button
    this->upgrades_button.setPosition(this->slots.at(0).x, this->slots.at(0).y);
    this->upgrades_button.setSize(100, 100);

    // Upgrade Click Damage Button
    this->upgrade_click_damage_button.setPosition(this->slots.at(4).x, this->slots.at(4).y);
    this->upgrade_click_damage_button.setSize(100, 100);

    // Upgrade Click Damage Text
    this->click_damage_text.setFont(fonts["Langar"]);
    this->click_damage_text.setFillColor(sf::Color::White);
    this->click_damage_text.setCharacterSize(25);
    this->click_damage_text.setPosition(this->slots.at(5).x, this->slots.at(5).y);
    this->click_damage_text.setString("N/A Click Damage");
}

// Constructor
Menu::Menu(std::map<std::string, sf::Texture>& textures,
           std::map<std::string, sf::Font>& fonts)
                         : state{State::closed},
                           animation_current_time{0.f},
                           opening_time{0.25}, closing_time{0.15},

                           upgrades_button(Button::Type::Upgrade_Open, textures, fonts),
                           upgrade_click_damage_button(Button::Type::Upgrade_Click_Damage, textures, fonts) {

    // Main Menu
    this->window.setTexture(textures["BottomGUI"]);
    this->window.setPosition(0, 700);

    // Init Slots
        // Slot Size 100 x 100
        // Slot0 (+39, +26)  | Slot1 (+178, +26)  | Slot2 (+317, +26)   | Slot3 (+456, +26)
        // Slot4 (+39, +131) | Slot5 (+178, +131) | Slot6 (+317, +131)  | Slot7 (+456, +131)
        // Slot8 (+39, +236) | Slot9 (+178, +236) | Slot10 (+317, +236) | Slot11 (+456, +236)
    this->slots.emplace_back(this->window.getPosition().x + 39, this->window.getPosition().y + 26);
    this->slots.emplace_back(this->window.getPosition().x + 178, this->window.getPosition().y + 26);
    this->slots.emplace_back(this->window.getPosition().x + 317, this->window.getPosition().y + 26);
    this->slots.emplace_back(this->window.getPosition().x + 456, this->window.getPosition().y + 26);

    this->slots.emplace_back(this->window.getPosition().x + 39, this->window.getPosition().y + 131);
    this->slots.emplace_back(this->window.getPosition().x + 178, this->window.getPosition().y + 131);
    this->slots.emplace_back(this->window.getPosition().x + 317, this->window.getPosition().y + 131);
    this->slots.emplace_back(this->window.getPosition().x + 456, this->window.getPosition().y + 131);

    this->slots.emplace_back(this->window.getPosition().x + 39, this->window.getPosition().y + 236);
    this->slots.emplace_back(this->window.getPosition().x + 178, this->window.getPosition().y + 236);
    this->slots.emplace_back(this->window.getPosition().x + 317, this->window.getPosition().y + 236);
    this->slots.emplace_back(this->window.getPosition().x + 456, this->window.getPosition().y + 236);

    this->initUpgradesSection(fonts);
}

// Destructor
Menu::~Menu() {
}


// Update
void Menu::update(const float& dt, const float& damage) {

    this->updateSlots();
    this->updateAnimation(dt);
    this->updateUpdatesSection(damage);
}

void Menu::updateAnimation(const float &dt) {
    // Closed pos = 0 x 700
    // Opened pos = 0 x 460

    if( (this->state == State::opened && this->window.getPosition() != sf::Vector2f(0, 460)) ||
        (this->state == State::closed && this->window.getPosition() != sf::Vector2f(0, 700)) ) {

        this->animation_current_time += dt;
        float animation_done_multipler = this->animation_current_time / this->opening_time;
        if(animation_done_multipler > 1) animation_done_multipler = 1;

        this->window.setPosition(this->current_pos.x - animation_done_multipler * this->distance.x,
                                 this->current_pos.y - animation_done_multipler * this->distance.y);
    }
}

void Menu::updateSlots() {

    this->slots.at(0).x = this->window.getPosition().x + 39; this->slots.at(0).y = this->window.getPosition().y + 26;
    this->slots.at(1).x = this->window.getPosition().x + 178; this->slots.at(1).y = this->window.getPosition().y + 26;
    this->slots.at(2).x = this->window.getPosition().x + 317; this->slots.at(2).y = this->window.getPosition().y + 26;
    this->slots.at(3).x = this->window.getPosition().x + 456; this->slots.at(3).y = this->window.getPosition().y + 26;
    this->slots.at(4).x = this->window.getPosition().x + 39; this->slots.at(4).y = this->window.getPosition().y + 131;
    this->slots.at(5).x = this->window.getPosition().x + 178; this->slots.at(5).y = this->window.getPosition().y + 131;
    this->slots.at(6).x = this->window.getPosition().x + 317; this->slots.at(6).y = this->window.getPosition().y + 131;
    this->slots.at(7).x = this->window.getPosition().x + 456; this->slots.at(7).y = this->window.getPosition().y + 131;
    this->slots.at(8).x = this->window.getPosition().x + 39; this->slots.at(8).y = this->window.getPosition().y + 236;
    this->slots.at(9).x = this->window.getPosition().x + 178; this->slots.at(9).y = this->window.getPosition().y + 236;
    this->slots.at(10).x = this->window.getPosition().x + 317; this->slots.at(10).y = this->window.getPosition().y + 236;
    this->slots.at(11).x = this->window.getPosition().x + 456; this->slots.at(11).y = this->window.getPosition().y + 236;

    // Upgrades Section
    this->upgrades_button.setPosition(this->slots.at(0).x, this->slots.at(0).y);
    this->upgrade_click_damage_button.setPosition(this->slots.at(4).x, this->slots.at(4).y);
    this->click_damage_text.setPosition(this->slots.at(5).x, this->slots.at(5).y);
}

void Menu::updateUpdatesSection(const float& damage) {

    // Update Click Damage Text
    std::ostringstream ss;
    ss << damage;
    ss << " Click Damage";
    std::string to_print(ss.str()); // float -> string conversion
    this->click_damage_text.setString(to_print);
}

// Render
void Menu::render(sf::RenderTarget *target) {

    target->draw(window);

    // ----> Top Menu <----
    this->upgrades_button.render(target);

    // ----> Upgrades Section <----
    if(this->section == Section::Upgrades) {
        this->upgrade_click_damage_button.render(target);
        target->draw(this->click_damage_text);
    }
}


// Functions
void Menu::open(const short& Section) {
    this->state = State::opened;
    // Closed pos = 0 x 700
    // Opened pos = 0 x 460

    // Reset Animation
    this->animation_current_time = 0.f;
    // Recalculate the distance and the current position
    this->distance.x = this->window.getPosition().x;
    this->distance.y = this->window.getPosition().y - 460;
    this->current_pos = this->window.getPosition();

    this->section = Section;


    // Debug
    if(this->section == Section::Upgrades)
        std::cout << "[Menu] Open Upgrades Menu\n";
}

void Menu::close() {
    this->state = State::closed;
    // Closed pos = 0 x 700
    // Opened pos = 0 x 460

    // Reset Animation
    this->animation_current_time = 0.f;
    // Recalculate the distance and the current position
    this->distance.x = this->window.getPosition().x;
    this->distance.y = this->window.getPosition().y - 700;
    this->current_pos = this->window.getPosition();

    // Debug
    if(this->section == Section::Upgrades)
        std::cout << "[Menu] Close Upgrades Menu Window\n";
}


short Menu::isButtonPressed(const sf::Vector2i& mousePos) const {

    // ----> Upgrades Section <----
    if(this->upgrades_button.isPressed(mousePos)) {
        if(this->state == State::closed) {
            return UpgradeButton::Open;
        }
        else if(this->state == State::opened) {
            return UpgradeButton::Close;
        }
    }

    if(this->upgrade_click_damage_button.isPressed(mousePos)) {
        return UpgradeButton::UpgradeClickDamage;
    }


    return UpgradeButton::NoButtonPressed;
}

