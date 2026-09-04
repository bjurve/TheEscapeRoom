#pragma once

#include "../include/helpFunctions.hpp"


//returerer Random X og Y koordinater basert på 0 til max for x og y
sf::Vector2f randomCoordinates(float maxX, float maxY)
{
	static std::random_device rd;
	static std::mt19937 engine(rd());
    
	std::uniform_real_distribution<float> distX(0.0f, maxX - 200.0f);
	std::uniform_real_distribution<float> distY(0.0f, maxY - 50.0f);
	
	return sf::Vector2f(distX(engine), distY(engine));
}

float randomCoordinateX(float maxX)
{
	static std::random_device rd;
	static std::mt19937 engine(rd());
    
	std::uniform_real_distribution<float> distX(0.0f, maxX);
	
	return distX(engine);
}

float randomCoordinateY(float maxY)
{
	static std::random_device rd;
	static std::mt19937 engine(rd());
    
	std::uniform_real_distribution<float> distX(0.0f, maxY);
	
	return distX(engine);
}

float randomNumber(float n)
{
    static std::random_device rd;
	static std::mt19937 engine(rd());
    
	std::uniform_real_distribution<float> distX(0.0f,n);

    return distX(engine);
};





//Produserer sentrumspunktkoordinater til objekt
sf::Vector2f getOriginCenterPlayer(const Player& p)
{
    sf::FloatRect bound = p.getPlayer().getGlobalBounds();
    return {bound.position.x + bound.size.x / 2 , bound.position.y + bound.size.y / 2};
}

sf::Vector2f getOriginCenterButton(const Button& b)
{
    sf::FloatRect bound = b.getButtonConst().getGlobalBounds();
    return {bound.position.x + bound.size.x / 2 , bound.position.y + bound.size.y / 2};
}

sf::Vector2f getOriginCenterText(screenText& t)
{
    sf::FloatRect bound = t.getText().getGlobalBounds();
    return {bound.position.x + bound.size.x / 2 , bound.position.y + bound.size.y / 2};
}

sf::Vector2f getOriginCenterSprite(sf::Sprite& s)
{
    sf::FloatRect bound = s.getGlobalBounds();
    return {bound.position.x + bound.size.x / 2 , bound.position.y + bound.size.y / 2};
}



//kombinerer text-objekt med button-objekt
void mergeTextButton(screenText& text, Button button)
{
    text.getText().setPosition(button.getButton().getPosition());
}

//Returnerer True hvis knapp trykkes
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

bool textClicked(sf::Window& window, screenText text)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousdPosF(mousePos);
    sf::Mouse::Button mousButton = sf::Mouse::Button::Left;    

    if(text.getText().getGlobalBounds().contains(mousdPosF) && sf::Mouse::isButtonPressed(mousButton))
    {
	    return true;
    }

    return false;
}

float randomPlusOrMinus(float n)
{
    if(randomNumber(10) < 5){return n;}

    return 0 - n;
};

sf::Vector2f randomFloats(float n)
{
	float x{randomPlusOrMinus(randomNumber(n))};
	float y{randomPlusOrMinus(randomPlusOrMinus(n))};
	return {x,y};
};








