#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "character.hpp"
#include "helpFunctions.hpp"



class enemy{
    public:

    enemy(Player p):enemyBoi{"Assets/PNG/skully.png"},target{p}, mvspeed{1}{};

    void buildEnemy();
    void draw(sf::RenderWindow& window);
    void incSpeed();
    void decSpeed();

    void moveLeft();
    void borderCheck();
    void changeDirWhenTouchWindow();

    void followPlayer(Player& p, float speed);

    character& getEnemy();

    private:
    
    character enemyBoi;
    Player target;
    int mvspeed;
};