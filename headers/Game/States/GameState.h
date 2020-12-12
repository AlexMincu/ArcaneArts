#pragma once

#include "State.h"

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
    // Init Private Functions
    void initKeybinds();
    void initTextures();
    void initEnemySpawner();
    void initText();
    void initBackground();

    // Variables
    EnemySpawner* enemy_spawner;

    // Background
    sf::Sprite background;
    sf::Texture background_texture;

    // FPS
    sf::Font font;
    sf::Text fps;
    float fps_render_timing;
    float dt_average;
    float dt_frames;

};
