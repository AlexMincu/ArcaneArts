#pragma once

#include "Game/Levels/MinotaurForest.h"
#include "Game/GUI/PopMessage.h"
#include "Game/GUI/UpgradeMenu.h"

enum Levels {minotaur_forest = 1};
enum GameStates {paused = 0, running = 1, closing = 2, upgrading = 3};

class Game {
public:
    // Constructor/Destructor
    Game();
    ~Game();

    // Update
    void update();
    void updateDt();
    void updateEvents();
    void updateFPS();
    void updateDamage();
    void updateProgression();

    // Render
    void render();

    // Functions
    void run();
    void close();
    void load();
    void save();

private:
    sf::RenderWindow *window;
    sf::Event event;

    // Running Information
        unsigned int game_state;
        bool focus;
        // Game Progression
        int progression;
        int current_level_progression;
        int last_current_level_progression;
        // Player Damage
        float damage;
        float click_damage;
        float idle_damage;

    // Delta Time
    sf::Clock dtClock;
    float dt;

    // Textures
    std::map<std::string, sf::Texture> textures;

    // Inputs
        // Mouse
    sf::Vector2i mouse_pos;
        // Keyboard
    std::map<std::string, int> keybinds;

    // Level Component
    Level *current_level;
    unsigned short level;

    //GUI - FPS on-screen Component
    sf::Font font;
    sf::Text fps;
    float fps_render_timing;
    float dt_average;
    float dt_frames;

    // GUI - Pause Pop-Up Component
    PopMessage *pause_pop;
    Button *return_button;
    Button *quit_button;

    // GUI - Upgrade Function
    UpgradeMenu *upgradeComponent;

    // Init Private Functions
    void initWindow();
    void initKeybinds();
    void initTextures();
    void initText();
    void initLevel();
    void initPausePop();
    void initGUI();

    // Debug
    void initDebug();
    void renderDebug();
    sf::RectangleShape line[2];

};
