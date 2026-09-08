#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "wall.hpp"

class Player {
public:

Player(std::string playerName, sf::Color playerColor):
playerName{playerName}, playerColor{playerColor}{};


void playerMovement();
void playerGrow();
void playerShrink();
void buildPlayer();
void resize(float f);

void wallBlock(wall w);

void draw(sf::RenderWindow& window);


sf::CircleShape& getPlayer();


private:
sf::Color playerColor;
std::string playerName;;

sf::CircleShape player;


};
