#pragma once

#include <SFML/Graphics.hpp>
#include "game/gamestate.hpp"



class baseRoom
{
    public:
        baseRoom(sf::RenderWindow* w, gameState* gs)
        :window{w},gameState{gs}{}; 



    protected:


        sf::RenderWindow* window;
        gameState* gameState;
};



