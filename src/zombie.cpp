#pragma once 

#include "../include/zombie.hpp"


void zombie::buildZombie()
{
    zombieBoi.getCharacter().setScale({0.30f, 0.30f});
    zombieBoi.getCharacter().setPosition({60.0, 400.0});
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

void zombie::followPlayer(Player& p, float speed)
{
    // Få posisjonene
    sf::Vector2f zombiePos = zombieBoi.getCharacter().getPosition();
    sf::Vector2f playerPos = p.getPlayer().getPosition();
    
    // Beregn retningsvektor
    sf::Vector2f direction = playerPos - zombiePos;
    
    // Beregn lengden (distansen)
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    

    if (distance > 0.1f)
    {
        // Normaliser vektoren 
        direction /= distance;
        
        // Beveg zombien mot spilleren
        zombieBoi.getCharacter().move(direction * speed);
    }
}

character& zombie::getZombie(){return zombieBoi;}