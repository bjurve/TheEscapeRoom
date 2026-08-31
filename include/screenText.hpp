#pragma once 

#include "SFML/Graphics.hpp"


class screenText
{
    public:

    screenText(const sf::Font& font, std::string text, sf::Color color, int size): font{font}, text{font}, theText{text}, colorText{color}, textSize{size}
    {this->text.setFont(this->font);}
    
    void buildText();
    void draw(sf::RenderWindow& window);
    
    sf::Text& getText();

    private:

    sf::Font font;
    sf::Text text;
    std::string theText;
    sf::Color colorText;

    int textSize;

};