#include "../include/player.hpp"
#include "../include/helpFunctions.hpp"


//Bygger spiller med div. egenskaper
void Player::buildPlayer()
{
    player.setFillColor(this->playerColor);

    player.setOrigin(getOriginCenterObject(player));
    player.setPosition({1300.0f,600.0f});
    player.setRadius(30.0f);

}


//PlayerMovement by arrows 
void Player::playerMovement()
{
    arrowMovementControl(player);

    //stopper bevegelse hvis karakter bryter vindugrenser
	sf::FloatRect bounds = player.getGlobalBounds();		
	if(bounds.position.x < 0){player.move({5.0f,0.0f});}                          
	if(bounds.position.x + bounds.size.x > 1500.0f){player.move({-5.0f,0.0f});}
	if(bounds.position.y < 0){player.move({0.0f,5.0f});}
	if(bounds.position.y + bounds.size.y > 800.0f){player.move({0.0f,-5.0f});}
}

void Player::wallBlock(wall w)
{
    if(objectIntersect(player, w.getWall()))
    {
        player.move({0.0,0.0});
    }

}

void Player::resize(float f)
{
    player.setRadius(f);
}


void Player::draw(sf::RenderWindow& window)
{
    window.draw(player);
}


sf::CircleShape& Player::getPlayer()
{
    return player;
}