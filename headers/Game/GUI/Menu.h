#pragma once

#include <Game/GUI/Button.h>

class Menu {
public:
    enum State {closed = 0, opened = 1};
    enum Section {None = 0, Upgrades = 1};
    enum UpgradeButton {NoButtonPressed = 0, UpgradeClickDamage, Open, Close};
    // Constructor/Destructor
    Menu(std::map<std::string, sf::Texture>& textures,
         std::map<std::string, sf::Font>& fonts);
    ~Menu();

    // Update
    void update(const float& dt, const float& damage);
    void updateAnimation(const float& dt);
    void updateSlots();
    void updateUpdatesSection(const float &damage);

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    void open(const short& Section);
    void close();
    short isButtonPressed(const sf::Vector2i& mousePos) const;

private:
    // Menu Window
    sf::Sprite window;
    std::vector<sf::Vector2i> slots;

    // State
    short state;
    short section;
    float animation_current_time;
    float opening_time;
    float closing_time;
    sf::Vector2f current_pos;
    sf::Vector2f distance;

    // Buttons
        // Upgrades Menu
    Button upgrades_button;
        // Upgrades Menu - Buttons
    Button upgrade_click_damage_button;
    sf::Text click_damage_text;

    void initUpgradesSection(std::map<std::string, sf::Font> &fonts);
};