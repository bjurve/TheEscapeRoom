
#include <SFML/Graphics.hpp>
#include "../include/helpFunctions.hpp"
#include "../include/button.hpp"


void Button::buildButton()
{

    switch (this->buttonSize)
    {
    case ButtonSize::small:
        this->button.setSize({200.0f, 50.0f});
        break;

    case ButtonSize::medium:
        this->button.setSize({400.0f, 50.0f});
        break;

    case ButtonSize::large:
        this->button.setSize({600.0f, 50.0f});
        break;

    default:
        this->button.setSize({400.0f, 50.0f});
        break;
    }

    this->button.setFillColor(buttonColor);
    this->button.setOrigin(getOriginCenterButton(*this));
    this->button.setPosition({buttonCoordinates});
}

void Button::draw(sf::RenderWindow& window)
{   
    window.draw(this->button);
};


sf::RectangleShape Button::getButton()const{return button;}



