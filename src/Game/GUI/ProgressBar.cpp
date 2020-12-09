#include "Game/GUI/ProgressBar.h"


// Constructor
ProgressBar::ProgressBar(const float& x, const float & y, sf::Texture &texture_sheet)
: texture_sheet{texture_sheet} {
    this->sprite.setTexture(this->texture_sheet, true);
    this->sprite.setPosition(x, y);

    // Create the rectangle that shows % health remaining on the screen
    sf::Color color (240, 39, 39);
    this->progress.setFillColor(color);
    this->progress.setPosition(x+53, y+23);
    this->progress_size.x = 204;
    this->progress_size.y = 17;
    this->progress.setSize(progress_size);

}

//Destructor
ProgressBar::~ProgressBar() {

}


// Update
void ProgressBar::update(const float& hp_procent, const float &dt) {
    // Update the rectangle that shows % health remaining on the screen
        // It shrinks based on the health percentage that enemy has
    if(hp_procent >= 0)
        this->progress_size.x = 2.04 * hp_procent;
    this->progress.setSize(progress_size);
}


// Render
void ProgressBar::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
    target->draw(this->progress);
}


// Functions

// Getter and Setters
