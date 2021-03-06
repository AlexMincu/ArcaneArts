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
//    this->keybinds ["ATTACK"] = sf::Keyboard::Key::Space;
    this->keybinds ["EXIT"] = sf::Keyboard::Key::Escape;
}

void Game::initTextures() {

    // Textures

        // GUI
    if(!this->textures["MenuGUI"].loadFromFile("assets/GUI/menu_gui.png")){
        std::cerr << "Failed to load MenuGUI Texture\n";
        exit(1);
    }

    if(!this->textures["MessageWindow"].loadFromFile("assets/GUI/message_window.png")){
        std::cerr << "Failed to load MessageWindow Texture\n";
        exit(1);
    }

    if (!this->textures["UpgradeWindow"].loadFromFile("assets/GUI/upgrade_window.png")) {
        std::cerr << "Failed to load UpgradeWindow Texture\n";
        exit(1);
    }

    if(!this->textures["HealthBar"].loadFromFile("assets/GUI/hp_bar.png")) {
        std::cerr << "Failed to load HealthBar Texture\n";
        exit(1);
    }


        // GUI - Bottons - Menu
    if (!this->textures["Button"].loadFromFile("assets/GUI/buttons/button.png")) {
        std::cerr << "Failed to load Button Texture\n";
        exit(1);
    }

    if (!this->textures["DirectDamageButton"].loadFromFile("assets/GUI/buttons/direct_damage.png")) {
        std::cerr << "Failed to load DirectDamageButton Texture\n";
        exit(1);
    }

    if (!this->textures["IdleDamageButton"].loadFromFile("assets/GUI/buttons/idle_damage.png")) {
        std::cerr << "Failed to load IdleDamageButton Texture\n";
        exit(1);
    }
    if (!this->textures["SpellsButton"].loadFromFile("assets/GUI/buttons/spells.png")) {
        std::cerr << "Failed to load SpellsButton Texture\n";
        exit(1);
    }
    if (!this->textures["SettingsButton"].loadFromFile("assets/GUI/buttons/settings.png")) {
        std::cerr << "Failed to load Settings Texture\n";
        exit(1);
    }

    // GUI - Menu - Direct Damage Section
    if (!this->textures["UpgradeDirectDamage"].loadFromFile("assets/GUI/buttons/upgrade_click_damage.png")) {
        std::cerr << "Failed to load UpgradeClickDamage Texture\n";
        exit(1);
    }


        // GUI - Bottons - Menu
    if (!this->textures["Pause"].loadFromFile("assets/GUI/buttons/pause_menu.png")) {
        std::cerr << "Failed to load Pause Button Texture\n";
        exit(1);
    }


        // MinotaurForest Level

            // Background
    if (!this->textures["MinotaurForest"].loadFromFile("assets/backgrounds/minotaur_forest.png")) {
        std::cerr << "Failed to load MinotaurForest Texture\n";
        exit(1);
    }

            // Enemies
    if(!this->textures["Minotaur1"].loadFromFile("assets/enemies/minotaur1_sheet.png")) {
        std::cerr << "Failed to load Minotaur1 Texture \n";
        exit(1);
    }

    if(!this->textures["Minotaur2"].loadFromFile("assets/enemies/minotaur2_sheet.png")) {
        std::cerr << "Failed to load Minotaur2 Texture\n";
        exit(1);
    }

    if(!this->textures["Minotaur3"].loadFromFile("assets/enemies/minotaur3_sheet.png")) {
        std::cerr << "Failed to load Minotaur3 Texture\n";
        exit(1);
    }



    // Fonts
    if(!this->fonts["Courier"].loadFromFile("assets/Fonts/courier.ttf")) {
        std::cerr << "Failed to load Courier Font\n";
        exit(1);
    }

    if(!this->fonts["Langar"].loadFromFile("assets/Fonts/langar.ttf")) {
        std::cerr << "Failed to load Langar Font\n";
        exit(1);
    }
}

void Game::initLevel(){
    this->current_level = new MinotaurForest(
            sf::Vector2i(window->getSize().x/2.f - 180.f,
                            window->getSize().y/2.f - 90.f),
            textures,
            fonts);
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
    this->fps = new FPS(fonts);

    this->menuComponent = new Menu(textures, fonts);

    this->pauseComponent = new PauseMenu(textures, fonts);

    this->hp_bar = new HealthBar(300.f - 140, 400.f + 160, textures, fonts);

    this->tags = new TextTagComponent(fonts);
}

// Constructor/Destructor
Game::Game() : window{nullptr}, event{sf::Event()},
               state{Game::State::running}, focus{true}, dt{0.f},
               current_level{nullptr}, level(1),
               progression{0}, current_level_progression{-1}, last_current_level_progression{-1},
               click_damage{1.f}, idle_damage{0.f}, damage{0.f},
               menuComponent{nullptr}, pauseComponent{nullptr},
               hp_bar{nullptr}, tags{nullptr}, fps{nullptr}{

    std::cout << "[Game] Starting...\n";
    // Loading previous settings
    this->load();

    // Initiate the game
    this->initWindow();
    this->initKeybinds();
    this->initTextures();
    this->initLevel();
    this->initGUI();

    this->initDebug();
}

Game::~Game() {

    // Saving
    this->save();

    // Releasing the memory
    delete this->current_level;
    delete this->menuComponent;
    delete this->pauseComponent;
    delete this->window;
    delete this->fps;
    delete this->hp_bar;
    delete this->tags;

    std::cout << "[Game] Closed\n";
}

// Update
void Game::update() {
    this->updateDt();
    this->updateEvents();
    this->menuComponent->update(dt, click_damage);
    this->fps->update(dt);
    this->updatePlayerInfo();
    this->tags->update(dt);

    if (this->state == Game::State::running ||
        this->state == Game::State::menuing) {

        this->current_level->update(dt);
        this->hp_bar->update(this->current_level->getCurrentHealthPercentage(), dt);
    }

    if(this->focus) {
        this->mouse_pos = sf::Mouse::getPosition(*this->window);
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

                    // ====> RUNNING GAME STATE <====
                    if(this->state == Game::State::running) {
                        this->state = Game::State::paused;
                        std::cout << "[Game] Paused\n";
                        }

                    // ====> PAUSED GAME STATE <====
                    else if(this->state == Game::State::paused) {
                        this->state = Game::State::running;
                        std::cout << "[Game] Unpaused\n";
                    }

                    // ====> UPGRADING GAME STATE <====
                    else if(this->state == Game::State::menuing) {
                        this->menuComponent->close();
                        this->state = Game::State::running;
                    }
                }

                break;


            ////////// Mouse Buttons Release //////////
            case sf::Event::EventType::MouseButtonReleased:

                    // ----> MLEFT BUTTON <-----
                if (this->event.mouseButton.button == sf::Mouse::Left) {

                    // ====> RUNNING GAME STATE <====
                    if(this->state == Game::State::running) {

                        // Hitting an Enemy
                        if (this->current_level->EnemyHitboxPressed(this->mouse_pos)) {
                            this->current_level->attackEnemy(damage);

                            std::ostringstream damage_text;
                            damage_text << click_damage;
                            std::string to_print(damage_text.str());

                            this->tags->addTag(to_print, this->mouse_pos.x, this->mouse_pos.y, TextTagComponent::Type::Damage);

                            std::cout << "[Enemy] ATTACK used by MLEFT Button\n";
                        }

                        // Menu State when Game Running
                        if (this->menuComponent->isButtonPressed(this->mouse_pos) == Menu::MenuButton::OpenDirectDamage) {
                            this->menuComponent->open(Menu::Section::DirectDamage);
                            this->state = Game::State::menuing;
                        }
                        else if (this->menuComponent->isButtonPressed(this->mouse_pos) == Menu::MenuButton::OpenIdleDamage) {
                            this->menuComponent->open(Menu::Section::IdleDamage);
                            this->state = Game::State::menuing;
                        }
                        else if (this->menuComponent->isButtonPressed(this->mouse_pos) == Menu::MenuButton::OpenSpells) {
                            this->menuComponent->open(Menu::Section::Spells);
                            this->state = Game::State::menuing;
                        }
                        else if (this->menuComponent->isButtonPressed(this->mouse_pos) == Menu::MenuButton::OpenSettings) {
                            this->menuComponent->open(Menu::Section::Settings);
                            this->state = Game::State::menuing;
                        }
                    }

                    // ====> PAUSED GAME STATE <====
                    else if(this->state == Game::State::paused) {
                        if (this->pauseComponent->isButtonPressed(this->mouse_pos) == PauseMenu::PauseButton::Return) {
                            this->state = Game::State::running;
                            std::cout << "[Game] Unpaused\n";
                        }
                        if (this->pauseComponent->isButtonPressed(this->mouse_pos) == PauseMenu::PauseButton::Close) {
                            this->close();
                        }
                    }

                    // ====> MENU STATE <====
                    else if(this->state == Game::State::menuing) {
                        // Menu State when Game Menu is opened
                        short but = this->menuComponent->isButtonPressed(this->mouse_pos);
                        switch(but) {
                            case Menu::MenuButton::OpenDirectDamage: {
                                this->menuComponent->open(Menu::Section::DirectDamage);
                                break;
                            }
                            case Menu::MenuButton::OpenIdleDamage: {
                                this->menuComponent->open(Menu::Section::IdleDamage);
                                break;
                            }
                            case Menu::MenuButton::OpenSpells: {
                                this->menuComponent->open(Menu::Section::Spells);
                                break;
                            }
                            case Menu::MenuButton::OpenSettings: {
                                this->menuComponent->open(Menu::Section::Settings);
                                break;
                            }
                            case Menu::MenuButton::Close: {
                                this->menuComponent->close();
                                this->state = Game::State::running;
                                break;
                            }
                            case Menu::MenuButton::UpgradeDirectDamage: {
                                this->click_damage++;
                                std::cout << "[Game] UpgradeClickDamage to " << this->click_damage << "\n";
                                break;
                            }
                        }

                    }

                }
                break;
        }
    }
}

void Game::updatePlayerInfo() {
    // Update the player progression
    this->current_level_progression = this->current_level->getProgress();

    if(last_current_level_progression != current_level_progression) {
        progression++;
        last_current_level_progression = current_level_progression;

        // Debug
        std::cout << "[Game] Progression is at " << this->progression << "\n";
    }

    // Update the player damage
    this->damage = this->click_damage + idle_damage;
}

// Render
void Game::render() {
    // Refresh window
    this->window->clear(sf::Color::Black);


    if (this->state == Game::State::running ||
        this->state == Game::State::menuing) {
        // Level
        this->current_level->render(this->window, state);
        // FPS
        this->fps->render(this->window);
        // GUI - HP Bar
        this->hp_bar->render(this->window);
        // GUI - Upgrade Component
        this->menuComponent->render(this->window);
        // GUI - TextTags
        this->tags->render(this->window);
    }



    if (this->state == Game::State::paused) {
        // Level
        this->current_level->render(this->window, state);
        // FPS
        this->fps->render(this->window);
        // GUI - Menu
        this->menuComponent->render(this->window);
        // GUI - TextTags
        this->tags->render(this->window);
        // GUI - Pause Component
        this->pauseComponent->render(this->window);
    }


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


