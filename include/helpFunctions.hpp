#pragma once 

#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "button.hpp"
#include "screenText.hpp"
#include <cmath>
#include <random>


sf::Vector2f randomCoordinates(float maxX, float maxY);

float randomCoordinateX(float maxX);
float randomCoordinateY(float maxY);

float randomNumber(float n);





//Produserer sentrumspunktetkoordinater til diverse objekter
sf::Vector2f getOriginCenterPlayer(const Player& p);
sf::Vector2f getOriginCenterButton(const Button& b);
sf::Vector2f getOriginCenterText(screenText& t);


//kombinerer text-objekt med button-objekt
void mergeTextButton(screenText& text, Button button);

//returnerer true hvis knapp er trykket
bool buttonClicked(sf::Window& window, Button button);
bool textClicked(sf::Window& window, screenText text);

float randomPlusOrMinus(float n);

sf::Vector2f randomFloats(float n);

//----------------Templates -------------------

//returnerer True hvis objekt a og b krysser hverandre
template<typename T, typename U>
bool objectIntersect(T a,U b)
{

	if(a.getGlobalBounds().findIntersection(b.getGlobalBounds()))
	{
		return true;
	}

	return false;
};

//returnerer True hvis objekt krysser spillvindu
template<typename T>
bool objectTouchWindowBorder(T& t)
{
    sf::FloatRect bounds = t.getGlobalBounds();		
	if(bounds.position.x < 0){t.move({5.0f,0.0f}); return true;}                          
	if(bounds.position.x + bounds.size.x > 1500.0f){t.move({-5.0f,0.0f}); return true;}
	if(bounds.position.y < 0){t.move({0.0f,5.0f}); return true;}
	if(bounds.position.y + bounds.size.y > 800.0f){t.move({0.0f,-5.0f}); return true;}
	return false;
}






