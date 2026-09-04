#pragma once 

#include <SFML/Graphics.hpp>




class character
{
    public:

    character(std::string path):skin{path}, sprite{skin}, speedX{3}, speedY{3}{};

    void buildCharacter();
    void draw(sf::RenderWindow& window);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void speedUp();

    
    sf::Sprite& getCharacter();
    float& getSpeedX();
    float& getSpeedY();

    private:
    sf::Texture skin;
    sf::Sprite sprite;

    float speedX;
    float speedY;

};