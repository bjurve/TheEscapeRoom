#pragma once 


#include <SFML/Graphics.hpp>
#include "baseRoom.hpp"
#include "header.hpp"




class gameMeny : public baseRoom
{

    public:

        gameMeny(sf::RenderWindow* w, gameState gs)
        : baseRoom(w, gs){};

        void drawBackground();
        void drawClouds();
        void drawButtons();
        bool isRoomFinished();

        void run();

       


    private:

    

    


};