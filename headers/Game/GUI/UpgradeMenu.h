#pragma once

#include <Game/GUI/Button.h>

class UpgradeMenu {
public:
    enum State {closed = 0, opened = 1};
    enum UpgradeButton {NoButtonPressed = 0, UpgradeClickDamage, Open, Close};
    // Constructor/Destructor
    UpgradeMenu(std::map<std::string, sf::Texture>& textures,
                std::map<std::string, sf::Font>& fonts);
    ~UpgradeMenu();

    // Update
    void update(const float& damage);

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    void open();
    void close();
    short isButtonPressed(const sf::Vector2i& mousePos) const;

private:
    // Texture
    sf::Sprite window;
    sf::Text click_damage_text;

    // State
    short state;

    // Buttons
    Button upgrade_open_button;
    Button upgrade_close_button;
    Button upgrade_click_damage_button;
};