#pragma once

#include "Game/Levels/MinotaurForest.h"
#include "Game/GUI/PopMessage.h"
#include "Game/GUI/Button.h"

enum Levels {minotaur_forest = 1};
enum GameStates {paused = 0, running = 1, closing = 2};

class Game {
public:
    // Constructor/Destructor
    Game();
    ~Game();

    // Update
    void update();
    void updateDt();
    void updateSFMLEvents();
    void updateInput();
    void updateFPS();

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
    unsigned int game_state;

    // Delta Time
    sf::Clock dtClock;
    float dt;

    // Textures
    std::map<std::string, sf::Texture> textures;

    // Inputs
        // Mouse
    sf::Vector2i mouse_pos_screen;
    sf::Vector2i mouse_pos_window;
        // Keyboard
    std::map<std::string, int> keybinds;

    // Level Component
    Level *current_level;
    unsigned short level;

    // FPS on-screen Component
    sf::Font font;
    sf::Text fps;
    float fps_render_timing;
    float dt_average;
    float dt_frames;

    // Pause Pop-Up Component
    PopMessage *pause_pop;
    Button *return_button;
    Button *quit_button;

    // Init Private Functions
    void initWindow();
    void initKeybinds();
    void initTextures();
    void initText();
    void initLevel();
    void initPausePop();

    // Debug
    void initDebug();
    void renderDebug();
    sf::RectangleShape line[2];
};
