#pragma once

#include "../include/helpFunctions.hpp"




//Produserer sentrumspunktkoordinater til objekt
sf::Vector2f getOriginCenterPlayer(const Player& p)
{
    sf::FloatRect bound = p.getPlayer().getGlobalBounds();
    return {bound.position.x + bound.size.x / 2 , bound.position.y + bound.size.y / 2};
}

sf::Vector2f getOriginCenterButton(const Button& b)
{
    sf::FloatRect bound = b.getButton().getGlobalBounds();
    return {bound.position.x + bound.size.x / 2 , bound.position.y + bound.size.y / 2};
}

sf::Vector2f getOriginCenterText(screenText& t)
{
    sf::FloatRect bound = t.getText().getGlobalBounds();
    return {bound.position.x + bound.size.x / 2 , bound.position.y + bound.size.y / 2};
}


//kombinerer text-objekt med button-objekt
void mergeTextButton(screenText& text, Button button)
{
    text.getText().setPosition(button.getButton().getPosition());
}

//Returnerer True hvis knapp trykkes på
bool buttonClicked(sf::Window& window, Button button)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousdPosF(mousePos);
    sf::Mouse::Button mousButton = sf::Mouse::Button::Left;    

    if(button.getButton().getGlobalBounds().contains(mousdPosF) && sf::Mouse::isButtonPressed(mousButton))
    {
	    return true;
    }

    return false;
}
