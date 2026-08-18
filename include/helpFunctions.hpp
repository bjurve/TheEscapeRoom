#pragma once 

#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "button.hpp"

//Produserer sentrumspunktetkoordinater til diverse objekter
sf::Vector2f getOriginCenterPlayer(const Player& p);
sf::Vector2f getOriginCenterButton(const Button& b);