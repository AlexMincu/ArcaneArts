#include "Game/GUI/Menu.h"

void Menu::initDirectDamageSection(std::map<std::string, sf::Texture>& textures, std::map<std::string, sf::Font> &fonts) {
    // Main Button
    this->direct_damage_button.setPosition(this->slots.at(0).x, this->slots.at(0).y);

    // Upgrade Direct Damage Button
    this->upgrade_direct_damage_button.setPosition(this->slots.at(4).x, this->slots.at(4).y);
    this->upgrade_direct_damage_button.setSize(139, 139);

    // Upgrade Direct Damage Text
    this->direct_damage_text.setFont(fonts["Langar"]);
    this->direct_damage_text.setFillColor(sf::Color::White);
    this->direct_damage_text.setCharacterSize(25);
    this->direct_damage_text.setPosition(this->slots.at(4).x + 139.f, this->slots.at(4).y);
    this->direct_damage_text.setString("N/A Direct Damage");
}

void Menu::initIdleDamageSection(std::map<std::string, sf::Texture>& textures, std::map<std::string, sf::Font> &fonts) {
    // Main Button
    this->idle_damage_button.setPosition(this->slots.at(1).x, this->slots.at(1).y);
}

void Menu::initSpellsSection(std::map<std::string, sf::Texture>& textures, std::map<std::string, sf::Font> &fonts) {
    // Main Button
    this->spells_button.setPosition(this->slots.at(2).x, this->slots.at(2).y);
}

void Menu::initSettingsSection(std::map<std::string, sf::Texture>& textures, std::map<std::string, sf::Font> &fonts) {
    // Main Button
    this->settings_button.setPosition(this->slots.at(3).x, this->slots.at(3).y);
}



// Constructor
Menu::Menu(std::map<std::string, sf::Texture>& textures,
           std::map<std::string, sf::Font>& fonts)
                         : state{State::closed}, section{Section::None},
                           animation_current_time{0.f},
                           opening_time{0.25}, closing_time{0.15},

                           direct_damage_button(Button::Type::DirectDamageMenu, textures, fonts),
                           upgrade_direct_damage_button(Button::Type::UpgradeDirectDamage, textures, fonts),

                           idle_damage_button(Button::Type::IdleDamageMenu, textures, fonts),

                           spells_button(Button::Type::SpellsMenu, textures, fonts),

                           settings_button(Button::Type::SettingsMenu, textures, fonts) {

    // Main Menu
    this->window.setTexture(textures["MenuGUI"]);
    this->window.setPosition(0, 700);

    // Init Slots
        // Top Slot Size 139 x 100
        // Slot0 (+19, +11)   | Slot1 (+158, +11)  | Slot3 (+298, +11)  | Slot4 (+437, +11)

        // Slot Size 278 x 100
        // Slot5 (+19, +116)  | Slot6 (+298, +116)
        // Slot7 (+19, +221)  | Slot8 (+298, +221)

    this->slots.emplace_back(this->window.getPosition().x + 19, this->window.getPosition().y + 11);
    this->slots.emplace_back(this->window.getPosition().x + 158, this->window.getPosition().y + 11);
    this->slots.emplace_back(this->window.getPosition().x + 298, this->window.getPosition().y + 11);
    this->slots.emplace_back(this->window.getPosition().x + 437, this->window.getPosition().y + 11);

    this->slots.emplace_back(this->window.getPosition().x + 19, this->window.getPosition().y + 116);
    this->slots.emplace_back(this->window.getPosition().x + 298, this->window.getPosition().y + 116);
    this->slots.emplace_back(this->window.getPosition().x + 19, this->window.getPosition().y + 221);
    this->slots.emplace_back(this->window.getPosition().x + 298, this->window.getPosition().y + 221);

    this->initDirectDamageSection(textures, fonts);
    this->initIdleDamageSection(textures, fonts);
    this->initSpellsSection(textures, fonts);
    this->initSettingsSection(textures, fonts);
}

// Destructor
Menu::~Menu() {
}


// Update
void Menu::update(const float& dt, const float& damage) {

    this->updateSlots();
    this->updateAnimation(dt);
    this->updateDirectDamageSection(damage);
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
    // Top Slot Size 139 x 100
    // Slot0 (+19, +11)   | Slot1 (+158, +11)  | Slot2 (+298, +11)  | Slot3 (+437, +11)

    // Slot Size 278 x 100
    // Slot4 (+19, +116)  | Slot5 (+298, +116)
    // Slot6 (+19, +221)  | Slot7 (+298, +221)
    this->slots.at(0).x = this->window.getPosition().x + 19; this->slots.at(0).y = this->window.getPosition().y + 11;
    this->slots.at(1).x = this->window.getPosition().x + 158; this->slots.at(1).y = this->window.getPosition().y + 11;
    this->slots.at(2).x = this->window.getPosition().x + 298; this->slots.at(2).y = this->window.getPosition().y + 11;
    this->slots.at(3).x = this->window.getPosition().x + 437; this->slots.at(3).y = this->window.getPosition().y + 11;
    this->slots.at(4).x = this->window.getPosition().x + 19; this->slots.at(4).y = this->window.getPosition().y + 116;
    this->slots.at(5).x = this->window.getPosition().x + 298; this->slots.at(5).y = this->window.getPosition().y + 116;
    this->slots.at(6).x = this->window.getPosition().x + 19; this->slots.at(6).y = this->window.getPosition().y + 221;
    this->slots.at(7).x = this->window.getPosition().x + 298; this->slots.at(7).y = this->window.getPosition().y + 221;

    // ----> Direct Damage Section <----
    this->direct_damage_button.setPosition(this->slots.at(0).x, this->slots.at(0).y);
    this->upgrade_direct_damage_button.setPosition(this->slots.at(4).x, this->slots.at(4).y);
    this->direct_damage_text.setPosition(this->slots.at(4).x + 139.f, this->slots.at(4).y);

    // ----> Idle Damage Section <----
    this->idle_damage_button.setPosition(this->slots.at(1).x, this->slots.at(1).y);

    // ----> Spells Section <----
    this->spells_button.setPosition(this->slots.at(2).x, this->slots.at(2).y);

    // ----> Settings Section <----
    this->settings_button.setPosition(this->slots.at(3).x, this->slots.at(3).y);
}

void Menu::updateDirectDamageSection(const float& damage) {

    // Update Click Damage Text
    std::ostringstream ss;
    ss << damage;
    ss << " Direct Damage";
    std::string to_print(ss.str()); // float -> string conversion
    this->direct_damage_text.setString(to_print);
}

void Menu::updateIdleDamageSection() {

}

void Menu::updateSpellsSection() {

}

void Menu::updateSettingsSection() {

}


// Render
void Menu::render(sf::RenderTarget *target) {

    target->draw(window);

    // ----> Top Menu <----
    this->direct_damage_button.render(target);
    this->idle_damage_button.render(target);
    this->spells_button.render(target);
    this->settings_button.render(target);

    // ----> Direct Damage Section <----
    if (this->section == Section::DirectDamage) {
        this->upgrade_direct_damage_button.render(target);
        target->draw(this->direct_damage_text);
    }

    // ----> Idle Damage Section <----
    else if (this->section == Section::IdleDamage) {

    }

    // ----> Spells Section <----
    else if (this->section == Section::Spells) {

    }

    // ----> Settings Section <----
    else if (this->section == Section::Settings) {

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
    if(this->section == Section::DirectDamage) {
        std::cout << "[Menu] Open Direct Damage Menu\n";
    }
    else if(this->section == Section::IdleDamage) {
        std::cout << "[Menu] Open Idle Damage Menu\n";
    }
    else if(this->section == Section::Spells) {
        std::cout << "[Menu] Open Spells Menu\n";
    }
    else if(this->section == Section::Settings) {
        std::cout << "[Menu] Open Settings Menu\n";
    }
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
    if(this->section == Section::DirectDamage)
        std::cout << "[Menu] Close Direct Damage Menu\n";
    else if(this->section == Section::IdleDamage)
        std::cout << "[Menu] Close Idle Damage Menu\n";
    else if(this->section == Section::Spells)
        std::cout << "[Menu] Close Spells Menu\n";
    else if(this->section == Section::Settings)
        std::cout << "[Menu] Close Settings Menu\n";
}


short Menu::isButtonPressed(const sf::Vector2i& mousePos) const {

    // ----> Direct Damage Section <----
    if(this->direct_damage_button.isPressed(mousePos)) {
        if(this->state == State::closed) {
            return MenuButton::OpenDirectDamage;
        }
        else if(this->state == State::opened) {
            if(this->section == Section::DirectDamage) {
                return MenuButton::Close;
            }
            else {
                return MenuButton::OpenDirectDamage;
            }
        }
    }

    if(this->upgrade_direct_damage_button.isPressed(mousePos)) {
        return MenuButton::UpgradeDirectDamage;
    }

    // ----> Idle Damage Section <----
    if(this->idle_damage_button.isPressed(mousePos)) {
        if(this->state == State::closed) {
            return MenuButton::OpenIdleDamage;
        }
        else if(this->state == State::opened) {
            if(this->section == Section::IdleDamage) {
                return MenuButton::Close;
            }
            else {
                return MenuButton::OpenIdleDamage;
            }
        }
    }

    // ----> Spells Section <----
    if(this->spells_button.isPressed(mousePos)) {
        if(this->state == State::closed) {
            return MenuButton::OpenSpells;
        }
        else if(this->state == State::opened) {
            if(this->section == Section::Spells) {
                return MenuButton::Close;
            }
            else {
                return MenuButton::OpenSpells;
            }
        }
    }

    // ----> Settings Section <----
    if(this->settings_button.isPressed(mousePos)) {
        if(this->state == State::closed) {
            return MenuButton::OpenSettings;
        }
        else if(this->state == State::opened) {
            if(this->section == Section::Settings) {
                return MenuButton::Close;
            }
            else {
                return MenuButton::OpenSettings;
            }
        }
    }


    return -1;
}

