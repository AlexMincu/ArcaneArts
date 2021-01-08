#pragma once

#include <Game/GUI/FPS.h>
#include <Game/GUI/PauseMenu.h>
#include "Game/Levels/MinotaurForest.h"
#include "Game/GUI/UpgradeMenu.h"
#include "Game/GUI/HealthBar.h"
#include "Game/GUI/TextTagComponent.h"

class Game {
public:
    // Constructor/Destructor
    Game();
    ~Game();

    // Update
    void update();
    void updateDt();
    void updateEvents();
    void updatePlayerInfo();

    // Render
    void render();

    // Functions
    void run();
    void close();
    void load();
    void save();


    enum Levels {minotaur_forest = 1};
    enum State {paused = 0, running = 1, closing = 2, upgrading = 3};

private:
    sf::RenderWindow *window;
    sf::Event event;
    unsigned int state;
    bool focus;

    // Delta Time
    sf::Clock dtClock;
    float dt;

    // Fonts & Textures
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;

    // Inputs
        // Mouse
    sf::Vector2i mouse_pos;
        // Keyboard
    std::map<std::string, int> keybinds;

    // Level Component
    Level *current_level;
    unsigned short level;

    //GUI
    FPS *fps;
    UpgradeMenu *upgradeComponent;
    PauseMenu *pauseComponent;
    HealthBar *hp_bar;
    sf::Sprite *bottom_gui;
    TextTagComponent *tags;

    // Player Info
        // Progression
        int progression;
        int current_level_progression;
        int last_current_level_progression;
        // Damage
        float damage;
        float click_damage;
        float idle_damage;

    // Init Private Functions
    void initWindow();
    void initKeybinds();
    void initTextures();
    void initLevel();
    void initGUI();

    // Debug
    void initDebug();
    void renderDebug();
    sf::RectangleShape line[2];
};
