#include "Game/Game.h"

// Init Private Functions
void Game::initWindow() {
    // Settings
    std::string title = "Arcane Arts";
    uint16_t framerate_limit = 5000;
    bool vert_sync = false;
    sf::VideoMode window_bounds(600, 800);

    // Create the window w/ the settings
    this->window = new sf::RenderWindow(window_bounds,title, sf::Style::Close);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vert_sync);
}

void Game::initKeybinds() {
    this->keybinds ["ATTACK"] = sf::Keyboard::Key::Space;
    this->keybinds ["EXIT"] = sf::Keyboard::Key::Escape;
}

void Game::initTextures() {

}

void Game::initText() {
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

void Game::initPausePop(){
    // Pop Window
    this->pause_pop = new PopMessage();

    this->pause_pop->setWindowPosition( static_cast<float>(this->window->getSize().x) / 2 -
                                        this->pause_pop->getWindowSize().width / 2,
                                        static_cast<float>(this->window->getSize().y) / 2 -
                                        this->pause_pop->getWindowSize().height / 2 );

    this->pause_pop->setMessageTitle("GAME PAUSED");
    this->pause_pop->centerMessageTitle();

    // Return Button
    this->return_button = new Button(Button::Type::Default);
    this->return_button->setSize(160, 80);
    this->return_button->setTextSize(18);
    this->return_button->setText("Return");
    this->return_button->setPosition(this->pause_pop->getWindowPosition().x + this->pause_pop->getWindowSize().width/2 - this->return_button->getSize().width/2,
                                     this->pause_pop->getWindowPosition().y + this->pause_pop->getWindowSize().height/2 - 60);
    this->return_button->centerText();

    // Quit Button
    this->quit_button = new Button(Button::Type::Default);
    this->quit_button->setSize(160, 80);
    this->quit_button->setTextSize(18);
    this->quit_button->setText("Quit");
    this->quit_button->setPosition(this->pause_pop->getWindowPosition().x + this->pause_pop->getWindowSize().width/2 - this->return_button->getSize().width/2,
                                   this->pause_pop->getWindowPosition().y + this->pause_pop->getWindowSize().height/2 + 60);
    this->quit_button->centerText();
}

void Game::initLevel(){
    this->current_level = new MinotaurForest(window, textures);
    this->level = minotaur_forest;
}

void Game::initDebug(){
    line[0].setPosition(window->getSize().x / 2.f, 0);
    line[1].setPosition(0, window->getSize().y / 2.f);

    line[0].setSize(sf::Vector2f(1, 2000));
    line[1].setSize(sf::Vector2f(2000, 1));

    line[0].setFillColor(sf::Color::Green);
    line[1].setFillColor(sf::Color::Green);
}

void Game::initGUI() {
    this->upgradeComponent = new UpgradeMenu();
}

// Constructor/Destructor
Game::Game() :  window{nullptr}, event{sf::Event()},
                game_state{running}, focus{true},
                dt{0.f}, dt_frames{0.f}, dt_average{0.f}, fps_render_timing{0.f},
                pause_pop{nullptr}, return_button{nullptr}, quit_button{nullptr},
                current_level{nullptr}, level(1),
                progression{0}, current_level_progression{-1}, last_current_level_progression{-1},
                click_damage{1.f}, idle_damage{0.f},
                upgradeComponent{nullptr} {

    std::cout << "[Game] Starting...\n";
    // Loading previous settings
    this->load();

    // Initiate the game
    this->initWindow();
    this->initKeybinds();
    this->initTextures();
    this->initText();
    this->initPausePop();
    this->initGUI();
    this->initLevel();

    this->initDebug();
}

Game::~Game() {

    // Saving
    this->save();

    // Releasing the memory
    delete this->current_level;
    delete this->return_button;
    delete this->quit_button;
    delete this->pause_pop;
    delete this->upgradeComponent;
    delete this->window;

    std::cout << "[Game] Closed\n";
}

// Update
void Game::update() {
    if(this->game_state == paused) {
        this->updateDt();
        this->updateEvents();
        this->updateFPS();
        this->updateProgression();
        this->updateDamage();
        this->upgradeComponent->update(click_damage);

        if(this->focus) {
            this->mouse_pos = sf::Mouse::getPosition(*this->window);
        }
    }

    else if(this->game_state == running || this->game_state == upgrading) {
        this->updateDt();
        this->updateEvents();
        this->updateFPS();
        this->updateProgression();
        this->updateDamage();
        this->upgradeComponent->update(click_damage);

        this->current_level->update(dt);

        if(this->focus) {
            this->mouse_pos = sf::Mouse::getPosition(*this->window);
        }
    }

}

void Game::updateDt() {
    // Updating the time it takes to update and render a frame - Delta Time
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateEvents() {
    // Handling events
    while(this->window->pollEvent(this->event)){
        switch(this->event.type){

            ////////// Closing the window //////////
            case sf::Event::EventType::Closed:
                this->close();
                break;


            ////////// Gain Focus when playing //////////
            case sf::Event::EventType::GainedFocus:
                this->focus = true;
                std::cout << "[GameEvent] Gained Focus\n";
                break;


            ////////// Lose Focus on minimize //////////
            case sf::Event::EventType::LostFocus:
                this->focus = false;
                std::cout << "[GameEvent] Lost Focus\n";
                break;


            ////////// Keyboard Key Release //////////
            case sf::Event::EventType::KeyReleased:

                    // -----> EXIT KEY <-----
                if (this->event.key.code == sf::Keyboard::Key(this->keybinds.at("EXIT"))) {
                    if(this->game_state == running) {
                        this->game_state = paused;
                        std::cout << "[Game] Paused\n";
                        }
                    else if(this->game_state == paused) {
                        this->game_state = running;
                        std::cout << "[Game] Unpaused\n";
                    }
                    else if(this->game_state == upgrading) {
                        this->upgradeComponent->close();
                        this->game_state = running;
                    }
                }

                    // ----> ATTACK KEY <-----
                else if (this->event.key.code == sf::Keyboard::Key(this->keybinds.at("ATTACK"))) {
                    if(this->game_state == running){
                        this->current_level->UseEnemySpawnerAttack(damage);
                        std::cout << "[Enemy] ATTACK used by Attack Keybind Key\n";
                    }
                }
                break;


            ////////// Mouse Buttons Release //////////
            case sf::Event::EventType::MouseButtonReleased:

                    // ----> MLEFT BUTTON <-----
                if (this->event.mouseButton.button == sf::Mouse::Left) {
                    if(this->game_state == running) {

                        // Hitting an Enemy
                        if (this->current_level->EnemyHitboxPressed(this->mouse_pos)) {
                            this->current_level->UseEnemySpawnerAttack(damage);
                            std::cout << "[Enemy] ATTACK used by MLEFT Button\n";
                        }

                        // Upgrade Icon
                        if (this->upgradeComponent->upgrade_button->isPressed(this->mouse_pos)) {
                            this->upgradeComponent->open();
                            this->game_state = upgrading;
                        }
                    }
                    else if(this->game_state == paused) {
                        if (this->return_button->isPressed(this->mouse_pos)) {
                            this->game_state = running;
                            std::cout << "[Game] Unpaused\n";
                        }
                        if (this->quit_button->isPressed(this->mouse_pos)) {
                            this->close();
                        }
                    }
                    else if(this->game_state == upgrading) {
                        if(this->upgradeComponent->quit_upgrade_button->isPressed(this->mouse_pos)) {
                            this->upgradeComponent->close();
                            this->game_state = running;
                        }
                    }

                }
                break;
        }
    }
}

void Game::updateFPS() {
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

void Game::updateProgression() {
    this->current_level_progression = this->current_level->getProgress();

    if(last_current_level_progression != current_level_progression) {
        progression++;
        last_current_level_progression = current_level_progression;

        // Debug
        std::cout << "[Game] Progression is at " << this->progression << "\n";
    }
}

void Game::updateDamage() {
    this->damage = this->click_damage + idle_damage;
}

// Render
void Game::render() {
    // Refresh window
    this->window->clear(sf::Color::Black);


    // Level
    this->current_level->render(this->window, game_state);

    // FPS
    this->window->draw(fps);

    // GUI
        // Pause Pop
        if(this->game_state == paused) {
            this->pause_pop->render(this->window);
            this->return_button->render(this->window);
            this->quit_button->render(this->window);
        }

        // Upgrade Component
        this->upgradeComponent->render(this->window);

    // Debug
    this->renderDebug();


    // Display everything
    this->window->display();
}

void Game::renderDebug(){
    this->window->draw(line[0]);
    this->window->draw(line[1]);
}


// Functions
void Game::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Game::close() {
    std::cout << "[Game] Closing...\n";
    this->window->close();
}

void Game::load(){      // work in progress
    //Debug
    std::cout << "[Game] Loading previous savings...\n";

    std::fstream fin;

    fin.open("save.txt");
    if(fin.is_open()){

        //Debug
        std::cout << "[Game] Done loading previous savings\n";
        fin.close();
    }
    else
        //Debug
        std::cout << "[Game] No previous savings exist, loading a new game!\n";
}

void Game::save(){      // work in progress
    //Debug
    std::cout << "[Game] Saving...\n";

    std::fstream fout;

    fout.open("save.txt", std::fstream::out);
    fout.close();

    fout.open("save.txt", std::fstream::app);
    if(fout.is_open()){
        fout << "current_level = " << this->level << "\n\n";
        fout.close();
    }

    //Debug
    std::cout << "[Game] Saving done\n";
}


