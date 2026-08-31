#include "../include/player.hpp"
#include "../include/helpFunctions.hpp"


//Bygger spiller med div. egenskaper
void Player::buildPlayer()
{
    this->player.setFillColor(this->playerColor);

    this->player.setOrigin(getOriginCenterPlayer(*this));
    this->player.setPosition({400.0f, 400.0f});
    this->player.setRadius(50.0f);

}


//PlayerMovement by arrows 
void Player::playerMovement()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {player.move({-5.0f,0.0f});}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){player.move({5.0f,0.0f});}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))   {player.move({0.0f,-5.0f});}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {player.move({0.0f,5.0f});}

    //stopper bevegelse hvis karakter bryter vindugrenser
	sf::FloatRect bounds = player.getGlobalBounds();		
	if(bounds.position.x < 0){player.move({5.0f,0.0f});}                          
	if(bounds.position.x + bounds.size.x > 1500.0f){player.move({-5.0f,0.0f});}
	if(bounds.position.y < 0){player.move({0.0f,5.0f});}
	if(bounds.position.y + bounds.size.y > 800.0f){player.move({0.0f,-5.0f});}
}


void Player::draw(sf::RenderWindow& window)
{
    window.draw(this->player);
}


sf::CircleShape Player::getPlayer()const
{
    return this->player;
}