#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "../objects/wall.hpp"

class Player {
public:

    Player(std::string path,sf::Vector2f pos = {750.0f, 400.0f}, sf::Vector2f scale = {0.06f,0.06f}):
    playerSkin{path}, playerBoi{playerSkin}, pos{pos}, scale{scale}{};


    void playerMovement();
    void playerGrow();
    void playerShrink();
    void buildPlayer();

    void wallBlock(wall w);

    void draw(sf::RenderWindow& window);


    sf::Sprite& getPlayer();


private:

    sf::Texture playerSkin;
    sf::Sprite playerBoi;

    sf::Vector2f pos;
    sf::Vector2f scale;

};
