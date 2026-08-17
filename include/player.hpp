#pragma once
#include "SFML/Graphics.hpp"
#include <string>


class Player {
public:

Player(std::string playerName, std::string playerColor):playerName{playerName}, playerColor{playerColor}, player(50.0f){};

sf::Color getPlayerColor(std::string color);

void playerMovement();
void playerGrow();
void playerShrink();
void buildPlayer();


private:
std::string playerColor;
std::string playerName;
sf::CircleShape player;


};
