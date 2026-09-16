#pragma once


#include "header.hpp"
#include <SFML/Graphics.hpp>



class room1 : public baseRoom
{
    public:

    room1(sf::RenderWindow* w, gameState* gs): baseRoom(w, gs), bob("Assets/PNG/bob.png"){};

    void drawBackground();
    void drawPlayer();
    void drawSun();
    void drawTexts();
    void drawCountDown();

    void config();
    void run();


    private:

    Player bob;
 



   
    int count = 0;


};