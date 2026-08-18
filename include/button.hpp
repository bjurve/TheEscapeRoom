#pragma once

#include <SFML/Graphics.hpp>

enum class ButtonSize{
    small,
    medium,
    large
};



class Button{

    public:
    // input => (ButtonSize::(s,m,l),sf::Color, sf::vector2f)
    // s=small, m=medium, l=large
    Button(ButtonSize size, sf::Color color, sf::Vector2f coordinates):buttonSize{size},buttonColor{color}, buttonCoordinates{coordinates}{};

    void buildButton();
    void draw(sf::RenderWindow& window);



    sf::RectangleShape getButton()const;


    private:
    sf::RectangleShape button;
    sf::Color buttonColor;
    ButtonSize buttonSize;
    sf::Vector2f buttonCoordinates;


};