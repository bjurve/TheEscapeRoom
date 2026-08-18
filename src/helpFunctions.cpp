#pragma once

#include "SFML/Graphics.hpp"
#include "../include/player.hpp"
#include "../include/button.hpp"


//Produserer sentrumspunktetkoordinater til objekt
sf::Vector2f getOriginCenterPlayer(const Player& p)
{
    sf::FloatRect bound = p.getPlayer().getGlobalBounds();
    return {bound.position.x + bound.size.x / 2 , bound.position.y + bound.size.y / 2};

};

sf::Vector2f getOriginCenterButton(const Button& b)
{
    sf::FloatRect bound = b.getButton().getGlobalBounds();
    return {bound.position.x + bound.size.x / 2 , bound.position.y + bound.size.y / 2};

};