#pragma once 

#include "../include/character.hpp"

void character::buildCharacter()
{
    sprite.setTexture(skin);
    sprite.setPosition({750.0f, 400.0f});
    sprite.setScale({0.06f,0.06f});
}

void character::draw(sf::RenderWindow& window){ window.draw(sprite);}

void character::moveLeft(){sprite.move({speedX,0.0f});};

void character::speedUp(){speedX++;};


sf::Sprite& character::getCharacter(){return sprite;}

float& character::getSpeedX(){return speedX;}
float& character::getSpeedY(){return speedY;}