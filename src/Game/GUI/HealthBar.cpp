#include "Game/GUI/HealthBar.h"


// Constructor
HealthBar::HealthBar(const float& x, const float & y,
                     std::map<std::string, sf::Texture>& textures,
                     std::map<std::string, sf::Font>& fonts) {

    // Init the texture of the health bar
    this->sprite.setTexture(textures["HealthBar"], true);
    this->sprite.setPosition(x, y);


    // The resizing part of the bar
    // Create the rectangle that shows % health remaining on the screen
    sf::Color color (240, 39, 39);
    this->progress.setFillColor(color);
    this->progress.setPosition(x+53, y+23);
    this->progress_size.x = 204;
    this->progress_size.y = 17;
    this->progress.setSize(progress_size);


    // Init Text
    this->health.setFont(fonts["Langar"]);
    this->health.setFillColor(sf::Color::White);
    this->health.setCharacterSize(20);
    this->health.setOutlineColor(sf::Color::Black);
    this->health.setOutlineThickness(1);
    this->health.setString("100%");

    sf::Vector2 text_pos = this->progress.getPosition();
    text_pos.x += this->progress_size.x/2;
    text_pos.y += this->progress_size.y/2;
    text_pos.x -= health.getGlobalBounds().width;
    text_pos.y -= health.getGlobalBounds().height;

    /*      Text of health:
     *    (Position of the Health Bar) + (Half the size of the Health Bar) -
     *          - (Text Size) +- (some variables to center the text in a correct way)
     */
    this->health.setPosition(text_pos.x + 10, text_pos.y + 5);
}

//Destructor
HealthBar::~HealthBar() {

}


// Update
void HealthBar::update(float hp_procent, const float &dt) {
    // Update the rectangle that shows % health remaining on the screen
    // It shrinks based on the health percentage that enemy has
    if(hp_procent < 0)
        hp_procent = 0;

    this->progress_size.x = 2.04 * hp_procent;
    this->progress.setSize(progress_size);


    // Update the text inside the health bar
    std::ostringstream int2string;
    int2string << static_cast<int>(hp_procent);
    int2string << "%";

    std::string string2print(int2string.str());

    this->health.setString(string2print);
}


// Render
void HealthBar::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
    target->draw(this->progress);
    target->draw(this->health);
}