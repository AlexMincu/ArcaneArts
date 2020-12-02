#include <vector>
#include <memory>
#include <Characters/Character.h>
#include <SFML/Graphics.hpp>
#include <iostream>


int main(){
    sf::err().rdbuf(NULL);

    sf::RenderWindow window(sf::VideoMode(1000,1000),"Arcane Arts");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("assets/enemies/minotaur/idle.png");

    sf::Sprite enemy_sprite;
    enemy_sprite.setTexture(texture);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(enemy_sprite);
        window.display();
    }

    return 0;
}



