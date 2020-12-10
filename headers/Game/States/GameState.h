#pragma once

#include "State.h"

class GameState : public State {
public:
    // Constructor/Destructor
    GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);
    ~GameState() override;

    // Update
    void updateInput(const float &dt) override;
    void updateEntities(const float &dt);
    void updateFPS(const float &dt);
    void update(const float &dt) override;

    // Render
    void render(sf::RenderTarget *target) override;

private:
    // Init Private Functions
    void initKeybinds();
    void initTextures();
    void initEnemySpawner();
    void initText();

    // Variables
    EnemySpawner* enemy_spawner;
    Enemy* enemy;
    sf::Texture texture;

    // FPS
    sf::Font font;
    sf::Text fps;
    float fps_render_timing;
    float dt_average;
    float dt_frames;

};
