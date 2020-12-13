#pragma once

#include "Game/Levels/Level.h"

class MinotaurForest : public Level{
public:
    // Constructor/ Destructor
    MinotaurForest(const sf::Window *window,
                   const std::map<std::string, sf::Texture>& textures);
    ~MinotaurForest() override;

    // Update
    void update(const float &dt) override;
    void updateProgress() override;
    void updateText() override;

    // Render

    // Functions
    void run() override;

protected:

private:
    // Init functions
    void initSettings();

    // Variables
        //    float progression;        from Level
        //    int total_enemies;        from Level
        //    int current_enemies;      from Level

    // Components
        //    EnemySpawner* enemy_spawner;  from Level
 //to-do >>>>       //Background                        from Level
};