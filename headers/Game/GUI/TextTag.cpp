#include "TextTag.h"

// Constructor
TextTag::TextTag(const std::string &text,
                 const sf::Vector2i& position,
                 sf::Font &font,
                 const int& size,
                 const sf::Color& text_color,
                 const float& life_time)
                 :  pos{position},
                    life{0.f}, life_time{life_time},
                    fade{false}, outline{false},
                    movement{false}, movement_pos(0, 0), movement_distance(0, 0) {

    // Init Text
    this->tag.setString(text);
    this->tag.setFont(font);
    this->tag.setCharacterSize(size);
    this->tag.setFillColor(text_color);

    this->pos.x -= this->tag.getGlobalBounds().width/2;
    this->pos.y -= this->tag.getGlobalBounds().height/2;
    this->tag.setPosition(this->pos.x, this->pos.y);
}

// Destructor
TextTag::~TextTag() {

}


// Update
void TextTag::update(const float &dt) {
    this->life += dt;

    if(fade) {
        float lifetime_percentage = this->life / this->life_time * 255;
        this->tag.setFillColor(sf::Color(this->tag.getFillColor().r,
                                         this->tag.getFillColor().g,
                                         this->tag.getFillColor().b,
                                         255 - lifetime_percentage));
        if(outline){
            this->tag.setOutlineColor(sf::Color(this->tag.getOutlineColor().r,
                                                this->tag.getOutlineColor().g,
                                                this->tag.getOutlineColor().b,
                                                255 - lifetime_percentage));
        }
    }

    if(movement) {
        float lifetime_percentage = this->life / this->life_time;
        this->tag.setPosition(this->pos.x - this->movement_distance.x * lifetime_percentage,
                              this->pos.y - this->movement_distance.y * lifetime_percentage);
    }

}


// Render
void TextTag::render(sf::RenderTarget *target) {
    target->draw(this->tag);
}


// Getters and Setters
void TextTag::addOutline(const float &thickness, const sf::Color &color) {
    this->outline = true;
    this->tag.setOutlineThickness(thickness);
    this->tag.setOutlineColor(color);
}

void TextTag::addFade() {
    this->fade = true;
}

void TextTag::addMovement(const sf::Vector2i& new_position) {
    this->movement = true;
    this->movement_pos.x = new_position.x;
    this->movement_pos.y = new_position.y;
    this->movement_distance.x = this->pos.x - new_position.x;
    this->movement_distance.y = this->pos.y - new_position.y;
}

bool TextTag::isDead() const {
    if(this->life >= life_time)
        return true;
    return false;
}

