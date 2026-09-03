#pragma once 

#include "../include/zombie.hpp"


void zombie::buildZombie()
{
    zombieBoi.getCharacter().setScale({0.30f, 0.30f});
}

void zombie::draw(sf::RenderWindow& window){ window.draw(zombieBoi.getCharacter());}



void zombie::moveLeft(){zombieBoi.moveLeft();}

void zombie::borderCheck()
{
    if(objectTouchWindowBorder(zombieBoi.getCharacter()))
    {
        zombieBoi.getCharacter().setPosition({0.0,randomCoordinateY(800.0)});
        zombieBoi.speedUp();
    }
}

character& zombie::getZombie(){return zombieBoi;}