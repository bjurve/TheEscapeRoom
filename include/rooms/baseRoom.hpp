#pragma once

#include <SFML/Graphics.hpp>
#include "game/gamestate.hpp"
#include <iostream>



class baseRoom
{
    public:
        baseRoom(sf::RenderWindow* w, gameState gs)
        :window{w},currentState{gs}
        {
            if(!font.openFromFile("Assets/FONT/escape_game_font.ttf"))
		    {
			    std::cerr << "Failed to load Font!!!" << std::endl;
			    return;
		    }
        }; 




    protected:


        sf::RenderWindow* window;
        gameState currentState;

        sf::Font font;

        bool roomFinished = false;
};



