#pragma once 

#include "../include/enemy.hpp"

void enemy::buildEnemy()
{
    enemyBoi.getCharacter().setScale({0.10f, 0.10f});
    enemyBoi.getCharacter().setPosition({0.0, 400.0});
}

void enemy::draw(sf::RenderWindow& window){ window.draw(enemyBoi.getCharacter());}



void enemy::moveLeft(){enemyBoi.moveLeft();}

void enemy::borderCheck()
{
    if(objectTouchWindowBorder(enemyBoi.getCharacter()))
    {
        enemyBoi.getCharacter().setPosition({0.0,randomCoordinateY(800.0)});
        enemyBoi.speedUp();
    }
}

void enemy::followPlayer(Player& p, float speed)
{
    // Få posisjonene
    sf::Vector2f enemyPos = enemyBoi.getCharacter().getPosition();
    sf::Vector2f playerPos = p.getPlayer().getPosition();
    
    // Beregn retningsvektor
    sf::Vector2f direction = playerPos - enemyPos;
    
    // Beregn lengden (distansen)
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    

    if (distance > 0.1f)
    {
        // Normaliser vektoren 
        direction /= distance;
        
        // Beveg zombien mot spilleren
        enemyBoi.getCharacter().move(direction * speed);
    }
}

character& enemy::getEnemy(){return enemyBoi;}