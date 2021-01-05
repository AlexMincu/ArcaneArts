#pragma once

#include <Game/GUI/Button.h>

class UpgradeMenu {
public:
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

    // Getters and Setters

    enum State {closed = 0, opened = 1};

    // Buttons
    Button open_upgrade_button;
    Button quit_upgrade_button;
    Button upgrade_click_damage_button;

private:
    // Texture
    sf::Sprite window;
    sf::Texture window_texture;

    sf::Font font;
    sf::Text click_damage_text;

    // State
    short state;
};