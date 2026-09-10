#pragma once

#include "../include/background.hpp"
#include <stdexcept>


background::background(std::string path, float width, float height)
{

    if(!texture.loadFromFile(path))
    {
        throw std::runtime_error("error loading file: " + path + "\n");
    }

    sprite->setTexture(texture);
    sprite->setScale(sf::Vector2f{width / texture.getSize().x, height / texture.getSize().y});

}


void background::draw(sf::RenderWindow& window)
{
    window.draw(*sprite);
}


