#pragma once

#include "State.h"
#include "Game/GUI/PopMessage.h"
#include "Game/GUI/Button.h"

enum Levels {minotaur_forest = 1};
enum GameStates {paused = 0, running = 1};

class GameState : public State {
public:
    // Constructor/Destructor
    GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);
    ~GameState() override;

    // Update
    void updateInput(const float &dt) override;
    void updateFPS(const float &dt);
    void update(const float &dt) override;

    // Render
    void render(sf::RenderTarget *target) override;

    // Functions
    void load();
    void save();

private:
    // Variables
    Level *current_level;
    unsigned short level;

    // FPS
    sf::Font font;
    sf::Text fps;
    float fps_render_timing;
    float dt_average;
    float dt_frames;

    // Pause
    unsigned int state;
    PopMessage *pause_pop;
    Button *return_button;
    Button *quit_button;

    // Init Private Functions
    void initKeybinds();
    void initTextures();
    void initText();
    void initPausePop();
};
