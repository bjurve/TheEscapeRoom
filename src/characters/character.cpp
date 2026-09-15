#pragma once 

#include "../../include/characters/character.hpp"

void character::buildCharacter()
{
    sprite.setTexture(skin);
    sprite.setPosition(pos);
    sprite.setScale(scale);
}

void character::draw(sf::RenderWindow& window){ window.draw(sprite);}

void character::moveLeft(){sprite.move({-speedX,0.0f});};
void character::moveRight(){sprite.move({speedX,0.0f});};

// void character::loopLeft(sf::Vector2f coord)
// {
//     sprite.move({-speedX,0.0f});
//     if(objectTouchWindowBorder(sprite))
//     {
//         sprite.setPosition{coord};
//     }


// }



void character::speedUp(){speedX++;};


sf::Sprite& character::getCharacter(){return sprite;}

float& character::getSpeedX(){return speedX;}
float& character::getSpeedY(){return speedY;}