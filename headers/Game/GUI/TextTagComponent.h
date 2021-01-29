#pragma once

#include "Game/GUI/TextTag.h"

class TextTagComponent {
public:
    enum Type {Default = 0, Damage};
    // Constructor/Destructor
    TextTagComponent(std::map<std::string, sf::Font>& fonts);
    virtual ~TextTagComponent();

    // Update
    void update(const float& dt);

    // Render
    void render(sf::RenderTarget *target);

    // Functions
    void addTag(const std::string &text,
                const float& x, const float& y,
                const short &type);

private:
    std::vector<TextTag*> tags;
    std::map<std::string, sf::Font>* fonts;
};