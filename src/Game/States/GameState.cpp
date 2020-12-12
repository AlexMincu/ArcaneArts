#include "Game/States/GameState.h"

// Init Private Functions

void GameState::initKeybinds() {
    this->keybinds ["ATTACK"] = this->supportedKeys->at("Space");
    this->keybinds ["EXIT"] = this->supportedKeys->at("Escape");
}

void GameState::initTextures() {
    if(!background_texture.loadFromFile("assets/backgrounds/stage1_background.png")) {
        std::cerr << "Failed to load Background1 for Game State\n";
        exit(1);
    }
}

void GameState::initEnemySpawner() {
    // Find the position to set the enemy in the middle of the window
    float enemy_pos_x = this->window->getSize().x/2.f - 180.f;       // Enemy image asset:
    float enemy_pos_y = this->window->getSize().y/2.f - 90.f;      // 360 x 245

    this->enemy_spawner = new EnemySpawner(enemy_pos_x, enemy_pos_y, this->textures);
}

void GameState::initText() {
    if(!this->font.loadFromFile("assets/Fonts/courier.ttf")) {
        std::cerr << "Failed to load Courier Font for Game State\n";
        exit(1);
    }

    // FPS
    this->fps.setFont(font);
    this->fps.setCharacterSize(20);
    this->fps.setFillColor(sf::Color::Green);
    this->fps.setPosition(5.f, 5.f);
}

void GameState::initBackground(){
    background.setTexture(this->background_texture);
    background.setPosition(0, 0);
}


// Constructor/Destructor
GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
    : State(window, supportedKeys),
    fps_render_timing{0.f}, dt_frames{0.f}, dt_average{0.f},
    enemy_spawner{nullptr} {

    this->load();

    this->initKeybinds();
    this->initTextures();
    this->initText();
    this->initEnemySpawner();
    this->initBackground();
}

GameState::~GameState() {
    this->save();
    delete this->enemy_spawner;
}

// Update
void GameState::updateInput(const float &dt) {
    // Mouse
    this->updateMousePosition();

    // Keyboard
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("EXIT"))))
        this->endState();
}

void GameState::updateFPS(const float &dt) {
   fps_render_timing += dt;
   dt_average += dt;
   dt_frames++;

   if(fps_render_timing >= 0.2) {
        float a = dt_frames / dt_average;
        std::ostringstream ss;
        ss << a;
        ss << " FPS\n";

        a = dt_average / dt_frames;
        ss << a;
        ss << " DT";

        std::string de_afisat(ss.str()); // float -> string conversion

        this->fps.setString(de_afisat);

        //Reset
        fps_render_timing = 0.f;
        dt_average = 0.f;
        dt_frames = 0.f;
   }
}

void GameState::update(const float &dt) {
    this->updateFPS(dt);
    this->updateInput(dt);
    this->enemy_spawner->update(dt);
}


// Render
void GameState::render(sf::RenderTarget *target) {
    if(!target)
        target = this->window;

    target->draw(background);

    // Enemy spawner
    this->enemy_spawner->render(target);

    // FPS
    this->window->draw(fps);
}


// Functions
void GameState::load(){
    std::cout << "Loading savings...\n";
    std::fstream fin;
    fin.open("save.txt");
    if(fin.is_open()){


        std::cout << "Done loading previous savings\n";
        fin.close();
    }
    else
        std::cout << "No previous savings exist, loading a new game!\n";
}


void GameState::save(){
    std::cout << "Saving the game...\n";
    std::fstream fout;
    fout.open("save.txt", std::ios::out);
    if(fout.is_open()){
        fout << "===Some character information===" << "\n";
        fout << "===Some items information===" << "\n";
//        fout << "===Overall progression: how many mobs killed===" << "\n";
        fout << enemy_spawner->getEnemiesKilledCount() << "\n";
        fout << "===Current Level===" << "\n";
        fout << "===Level progression: last mob alive===" << "\n";

        std::cout << "Saving done\n";
        fout.close();
    }
}
