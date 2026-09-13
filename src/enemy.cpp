#pragma once 

#include "../include/enemy.hpp"

void enemy::buildEnemy()
{
    enemyBoi.setScale({scale});
    enemyBoi.setPosition({pos});
}

void enemy::incSpeed(){speed++;}
void enemy::decSpeed(){speed--;}

void enemy::draw(sf::RenderWindow& window){ window.draw(enemyBoi);}



void enemy::moveRight(){enemyBoi.move({speed,0.0});}

void enemy::borderCheck()
{
    if(objectTouchWindowBorder(enemyBoi))
    {
        enemyBoi.setPosition({0.0,randomCoordinateY(800.0)});
        speed++;
    }
}

void enemy::followPlayer(Player& p, float speedf)
{
    // Få posisjonene
    sf::Vector2f enemyPos = enemyBoi.getPosition();
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
        enemyBoi.move(direction * speedf);
    }
}

sf::Sprite& enemy::getEnemy(){return enemyBoi;}

float& enemy::getSpeed(){return speed;}
