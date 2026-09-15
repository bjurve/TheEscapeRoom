#pragma once 

#include <SFML/Graphics.hpp>
#include "../helpFunctions/helpFunctions.hpp"




class character
{
    public:

    character(std::string path, sf::Vector2f pos = {750.0f, 400.0f}, sf::Vector2f scale = {0.06f,0.06f})
    :skin{path}, sprite{skin}, speedX{3}, speedY{3}, pos{pos}, scale{scale}{};

    void buildCharacter();
    void draw(sf::RenderWindow& window);


    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void speedUp();

   // void loopLeft(sf::Vector2f coord);
    //void loopRight();

    
    sf::Sprite& getCharacter();
    float& getSpeedX();
    float& getSpeedY();

    private:
    sf::Texture skin;
    sf::Sprite sprite;

    sf::Vector2f pos;
    sf::Vector2f scale;

    float speedX;
    float speedY;

};