#pragma once 

#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "button.hpp"
#include "screenText.hpp"

//Produserer sentrumspunktetkoordinater til diverse objekter
sf::Vector2f getOriginCenterPlayer(const Player& p);
sf::Vector2f getOriginCenterButton(const Button& b);
sf::Vector2f getOriginCenterText(screenText& t);


//kombinerer text-objekt med button-objekt
void mergeTextButton(screenText& text, Button button);

//returnerer true hvis knapp er trykket
bool buttonClicked(sf::Window& window, Button button);




