#pragma once

#include "../include/screenText.hpp"
#include "../include/helpFunctions.hpp"




void screenText::buildText()
{


    text.setString(theText);
    text.setFillColor(colorText);
    text.setCharacterSize(textSize);
    text.setOrigin(getOriginCenterText(*this));
    text.setFont(font);
}




sf::Text& screenText::getText(){return text;}


void screenText::draw(sf::RenderWindow& window)
{   
    window.draw(this->text);
}

