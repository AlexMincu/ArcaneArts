#pragma once

#include <Game/GUI/Button.h>

class Menu {
public:
    enum State {closed = 0, opened = 1};
    enum Section {None = 0, DirectDamage, IdleDamage, Spells, Settings};
    enum MenuButton {UpgradeDirectDamage, Close, OpenDirectDamage, OpenIdleDamage, OpenSpells, OpenSettings};
    // Constructor/Destructor
    Menu(std::map<std::string, sf::Texture>& textures,
         std::map<std::string, sf::Font>& fonts);
    ~Menu();

    // Update
    void update(const float& dt, const float& damage);
    void updateAnimation(const float& dt);
    void updateSlots();
    void updateDirectDamageSection(const float &damage);
    void updateIdleDamageSection();
    void updateSpellsSection();
    void updateSettingsSection();

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

    // Direct Damage Section
    Button direct_damage_button;
    Button upgrade_direct_damage_button;
    sf::Text direct_damage_text;

    // Idle Damage Section
    Button idle_damage_button;

    // Spells Section
    Button spells_button;

    // Settings Section
    Button settings_button;

    void initDirectDamageSection(std::map<std::string, sf::Texture>& textures, std::map<std::string, sf::Font> &fonts);
    void initIdleDamageSection(std::map<std::string, sf::Texture> &textures, std::map<std::string, sf::Font> &fonts);
    void initSpellsSection(std::map<std::string, sf::Texture> &textures, std::map<std::string, sf::Font> &fonts);
    void initSettingsSection(std::map<std::string, sf::Texture> &textures, std::map<std::string, sf::Font> &fonts);
};