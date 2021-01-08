#include "Game/GUI/TextTagComponent.h"

// Constructor
TextTagComponent::TextTagComponent(std::map<std::string, sf::Font>& fonts)
                : fonts{&fonts} {
}

// Destructor
TextTagComponent::~TextTagComponent() {

}


// Update
void TextTagComponent::update(const float &dt) {

    for(auto i = 0; i < this->tags.size(); i++) {
        this->tags.at(i)->update(dt);

        // If tag life is over
        if(this->tags.at(i)->isDead()){
            this->tags.erase(this->tags.begin() + i);
        }
    }
}


// Render
void TextTagComponent::render(sf::RenderTarget *target) {
    for(auto tag : this->tags) {
        tag->render(target);
    }
}


// Functions
void TextTagComponent::addTag(const std::string& text,
                              const float& x, const float& y,
                              const short& type) {
    switch(type){
        case Type::Default: {
            this->tags.push_back(new TextTag(text,
                                             sf::Vector2i(x, y),
                                             ((*this->fonts)["Courier"]),
                                             20,
                                             sf::Color::White,
                                             2.f));
            break;
        }
        case Type::Damage: {
            this->tags.push_back(new TextTag(text,
                                             sf::Vector2i(x, y),
                                             ((*this->fonts)["Langar"]),
                                             34,
                                             sf::Color::Red,
                                             1.f));
            this->tags.back()->addOutline(2.f, sf::Color::Black);
            this->tags.back()->addFade();
            this->tags.back()->addMovement(sf::Vector2i(x, y - 150));
            break;
        }
        default: {
            std::cout << "[TextTagComponent] ERR::Unknown TextTagComponent Type\n";
        }
    }

}