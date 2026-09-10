#pragma once

#include <SFML/Graphics.hpp>





class background
{
    public:
    background(std::string path, float width, float height);

    void draw(sf::RenderWindow& window);


    private:

    sf::Texture texture;
    sf::Sprite* sprite;



};