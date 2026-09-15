#include "../../include/characters/player.hpp"
#include "../../include/helpFunctions/helpFunctions.hpp"


//Bygger spiller med div. egenskaper
void Player::buildPlayer()
{
    playerBoi.setPosition(pos);
    playerBoi.setScale(scale);

}



//PlayerMovement by arrows 
void Player::playerMovement()
{
    arrowMovementControl(playerBoi);

    //stopper bevegelse hvis karakter bryter vindugrenser
	sf::FloatRect bounds = playerBoi.getGlobalBounds();		
	if(bounds.position.x < 0){playerBoi.move({5.0f,0.0f});}                          
	if(bounds.position.x + bounds.size.x > 1500.0f){playerBoi.move({-5.0f,0.0f});}
	if(bounds.position.y < 0){playerBoi.move({0.0f,5.0f});}
	if(bounds.position.y + bounds.size.y > 800.0f){playerBoi.move({0.0f,-5.0f});}
}

void Player::wallBlock(wall w)
{
    if(objectIntersect(playerBoi, w.getWall()))
    {
        playerBoi.move({0.0,0.0});
    }

}



void Player::draw(sf::RenderWindow& window)
{
    window.draw(playerBoi);
}


sf::Sprite& Player::getPlayer()
{
    return playerBoi;
}