#include "player.hpp"

sf::Color Player::getPlayerColor(std::string color)
{
    if(color == "red"){return sf::Color::Red;}
    else if(color == "black"){return sf::Color::Black;}
    else if(color == "blue"){return sf::Color::Blue;}
    else if(color == "white"){return sf::Color::White;}
    else if(color == "green"){return sf::Color::Green;}
    else{return sf::Color::Magenta;}
};

void Player::buildPlayer()
{
    player.setFillColor(getPlayerColor(playerColor));
};


//PlayerMovement by arrows
void Player::playerMovement()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {player.move({-5.0f,0.0f});}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){player.move({5.0f,0.0f});}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))   {player.move({0.0f,-5.0f});}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {player.move({0.0f,5.0f});}
};