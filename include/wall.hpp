#pragma once

#include <SFML/Graphics.hpp>




class wall
{   
    public:
    wall(sf::Vector2f coord, sf::Vector2f size, sf::Color color): coord{coord}, size{size}, color{color}{};

    void buildWall();
    void draw(sf::RenderWindow& w);

    sf::RectangleShape& getWall();


    private:
    sf::RectangleShape wallBoi;
    sf::Vector2f coord;
    sf::Vector2f size;
    sf::Color color;
    
};