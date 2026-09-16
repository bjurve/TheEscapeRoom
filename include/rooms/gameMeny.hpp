#pragma once 


#include <SFML/Graphics.hpp>
#include "header.hpp"




class gameMeny : public baseRoom
{

    public:

        gameMeny(sf::RenderWindow* w, gameState* gs)
        : baseRoom(w, gs){};

        void drawBackground();
        void drawClouds();
        void drawButtons();

        void run();

       


    private:

    

    


};