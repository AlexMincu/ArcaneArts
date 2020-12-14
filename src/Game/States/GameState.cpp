#include "Game/States/GameState.h"

// Init Private Functions

void GameState::initKeybinds() {
    this->keybinds ["ATTACK"] = this->supportedKeys->at("Space");
    this->keybinds ["EXIT"] = this->supportedKeys->at("Escape");

    this->keybinds ["UP"] = this->supportedKeys->at("Up");
    this->keybinds ["DOWN"] = this->supportedKeys->at("Down");
    this->keybinds ["LEFT"] = this->supportedKeys->at("Left");
    this->keybinds ["RIGHT"] = this->supportedKeys->at("Right");
}

void GameState::initTextures() {

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

void GameState::initPausePop(){
    this->pause_pop = new PopMessage();

    this->pause_pop->setWindowPosition( static_cast<float>(this->window->getSize().x) / 2 -
                                        this->pause_pop->getWindowSize().width / 2,
                                        static_cast<float>(this->window->getSize().y) / 2 -
                                        this->pause_pop->getWindowSize().height / 2 );

    this->pause_pop->setMessageTitle("GAME PAUSED");
}

// Constructor/Destructor
GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
                     : State(window, supportedKeys),
    fps_render_timing{0.f}, dt_frames{0.f}, dt_average{0.f},
    paused{false}, pause_pop{nullptr} {

    this->load();

    this->initKeybinds();
    this->initTextures();
    this->initText();

    this->current_level = new MinotaurForest(window, textures);
    this->level = minotaur_forest;

    this->initPausePop();
}

GameState::~GameState() {
    this->save();
    delete this->current_level;
    delete this->pause_pop;
}

// Update
void GameState::updateInput(const float &dt) {
    // Mouse
    this->updateMousePosition();

    // Keyboard
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("EXIT")))){
        this->paused = true;
    }


    if(this->paused) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("UP")))) {

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("DOWN")))) {

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("LEFT")))) {

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("RIGHT")))) {

        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("EXIT")))){
            this->endState();
        }
    }
}

void GameState::updateFPS(const float &dt) {
   fps_render_timing += dt;
   dt_average += dt;
   dt_frames++;

   if(fps_render_timing >= 0.2) {
        float a = dt_frames / dt_average;

       if(a < 500)
           fps.setFillColor(sf::Color::Red);
       else
           fps.setFillColor(sf::Color::Green);

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

    this->current_level->update(dt);
}


// Render
void GameState::render(sf::RenderTarget *target) {
    if(!target)
        target = this->window;

    // Level
    this->current_level->render(target);

    // FPS
    this->window->draw(fps);

    // Pause Pop
    this->pause_pop->render(target);
}


// Functions
void GameState::load(){
    //Debug
    std::cout << "Loading savings...\n";

    std::fstream fin;

    fin.open("save.txt");
    if(fin.is_open()){

        //Debug
        std::cout << "Done loading previous savings\n";
        fin.close();
    }
    else
        //Debug
        std::cout << "No previous savings exist, loading a new game!\n";
}


void GameState::save(){
    //Debug
    std::cout << "Saving the game...\n";

    std::fstream fout;

    fout.open("save.txt", std::fstream::out);
    fout.close();

    fout.open("save.txt", std::fstream::app);
    if(fout.is_open()){
        fout << "current_level = " << this->level << "\n\n";
        fout.close();
    }

    //Debug
    std::cout << "Saving the game done\n";
}
