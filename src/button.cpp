
#include <SFML/Graphics.hpp>
#include "../include/helpFunctions.hpp"
#include "../include/button.hpp"

//bygger knapp med div. egenskaper
void Button::buildButton()
{

    switch (buttonSize)
    {
    case ButtonSize::small:
        button.setSize({200.0f, 50.0f});
        break;

    case ButtonSize::medium:
        button.setSize({400.0f, 50.0f});
        break;

    case ButtonSize::large:
        button.setSize({600.0f, 50.0f});
        break;

    default:
        button.setSize({400.0f, 50.0f});
        break;
    }

    button.setFillColor(buttonColor);
    button.setOrigin(getOriginCenterButton(*this));
    button.setPosition({buttonCoordinates});

}

void Button::draw(sf::RenderWindow& window)
{   
    window.draw(button);
};


sf::RectangleShape& Button::getButton(){return button;}
const sf::RectangleShape& Button::getButtonConst()const{return button;}




