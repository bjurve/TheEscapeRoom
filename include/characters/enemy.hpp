#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "character.hpp"
#include "../helpFunctions/helpFunctions.hpp"



class enemy{
    public:

    enemy(std::string path, Player p, sf::Vector2f pos = {750.0f, 400.0f}, sf::Vector2f scale = {0.06f,0.06f}):
    enemySkin{path},enemyBoi{enemySkin},pos{pos}, scale{scale},target{p}, speed{5.0}{};

    void buildEnemy();
    void draw(sf::RenderWindow& window);
    void incSpeed();
    void decSpeed();

    void moveRight();
    void borderCheck();
    void changeDirWhenTouchWindow();

    void followPlayer(Player& p, float speed);

    sf::Sprite& getEnemy();

    float& getSpeed();

    private:
    
    sf::Texture enemySkin;
    sf::Sprite enemyBoi;

    sf::Vector2f pos;
    sf::Vector2f scale;
    
    Player target;             
    float speed;
};