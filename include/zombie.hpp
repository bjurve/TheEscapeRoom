#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "character.hpp"
#include "helpFunctions.hpp"



class zombie{
    public:

    zombie(Player p):zombieBoi{"Assets/PNG/zombie2.png"},target{p}, mvspeed{1}{};

    void buildZombie();
    void draw(sf::RenderWindow& window);
    void incSpeed();
    void decSpeed();

    void moveLeft();
    void borderCheck();
    void changeDirWhenTouchWindow();

    character& getZombie();

    private:
    
    character zombieBoi;
    Player target;
    int mvspeed;
};