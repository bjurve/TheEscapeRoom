#pragma once
#include "SFML/Graphics.hpp"
#include <string>


class Player {
public:

Player(std::string playerName, sf::Color playerColor):
playerName{playerName}, playerColor{playerColor}{};


void playerMovement();
void playerGrow(Player player);
void playerShrink(Player player);
void buildPlayer();

void draw(sf::RenderWindow& window);


sf::CircleShape getPlayer()const;


private:
sf::Color playerColor;
std::string playerName;;

sf::CircleShape player;


};
