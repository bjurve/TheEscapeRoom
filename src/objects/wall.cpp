#pragma once

#include "../../include/objects/wall.hpp" 

void wall::buildWall()
{
   // wallBoi.setOrigin(getOriginCenterObject(wallBoi));
    wallBoi.setPosition(coord);
    wallBoi.setSize(size);
    wallBoi.setFillColor(color);
}


void wall::draw(sf::RenderWindow& w)
{
    w.draw(wallBoi);
};

sf::RectangleShape& wall::getWall(){return wallBoi;}