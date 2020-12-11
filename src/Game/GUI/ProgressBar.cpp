#include "Game/GUI/ProgressBar.h"

// Init Private Functions
void ProgressBar::initHealthBar(const float& x, const float & y){
    // Create the rectangle that shows % health remaining on the screen
    sf::Color color (240, 39, 39);
    this->progress.setFillColor(color);
    this->progress.setPosition(x+53, y+23);
    this->progress_size.x = 204;
    this->progress_size.y = 17;
    this->progress.setSize(progress_size);
}

void ProgressBar::initText(){
    if(!this->font.loadFromFile("assets/Fonts/courier.ttf")){
        std::cerr << "Failed to load Courier Font for Progress Bar\n";
        exit(1);
    }


    this->health.setFont(font);
    this->health.setFillColor(sf::Color::White);
    this->health.setCharacterSize(20);
    this->health.setOutlineColor(sf::Color::Black);
    this->health.setOutlineThickness(1);

    this->health.setString("100%");

    sf::Rect<float> text_pos = this->progress.getGlobalBounds();
    std::cout << text_pos.left << " " << text_pos.top << "\n";

    text_pos.left += text_pos.width/2;
    text_pos.top += text_pos.height/2;
    std::cout << text_pos.left << " " << text_pos.top << "\n";

    sf::Rect<float> temp = this->health.getGlobalBounds();
    std::cout << "temp  " << temp.width << " " << temp.height << "\n";

    text_pos.left -= temp.width;
    text_pos.top -= temp.height;
    std::cout << text_pos.left << " " << text_pos.top << "\n";

    this->health.setPosition(text_pos.left + 10, text_pos.top+2);

}


// Constructor
ProgressBar::ProgressBar(const float& x, const float & y, sf::Texture &texture_sheet)
: texture_sheet{texture_sheet} {

    this->sprite.setTexture(this->texture_sheet, true);
    this->sprite.setPosition(x, y);

    this->initHealthBar(x, y);
    this->initText();
}

//Destructor
ProgressBar::~ProgressBar() {

}


// Update
void ProgressBar::update(const float& hp_procent, const float &dt) {
    this->updateHealthBar(hp_procent);
    this->updateText(hp_procent);
}

void ProgressBar::updateHealthBar(const float& hp_procent){
    // Update the rectangle that shows % health remaining on the screen
    // It shrinks based on the health percentage that enemy has
    if(hp_procent >= 0)
        this->progress_size.x = 2.04 * hp_procent;
    this->progress.setSize(progress_size);
}

void ProgressBar::updateText(const float& hp_procent){
    std::ostringstream int2string;
    int2string << static_cast<int>(hp_procent);
    int2string << "%";

    std::string string2print(int2string.str());

    this->health.setString(string2print);
}




// Render
void ProgressBar::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
    target->draw(this->progress);
    target->draw(this->health);
}


// Functions

// Getter and Setters
