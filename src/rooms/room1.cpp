#include "../../include/rooms/room1.hpp"

void room1::drawBackground()
{
    background background("Assets/PNG/blueSky.png",static_cast<float>(window->getSize().x),static_cast<float>(window->getSize().y));
    background.draw(*window);
}


void room1::drawPlayer()
{
	bob.playerMovement();
    bob.draw(*window);
}


void room1::drawSun()
{
    character sun("Assets/PNG/sun.png");
	sun.buildCharacter();
    sun.draw(*window);
}

void room1::drawTexts()
{
    screenText room1(font, "ROOM 1", sf::Color::Yellow, 60);
    room1.buildText();
    room1.setPosition({750.0f, 50.0f});
    room1.draw(*window);

    screenText infoRoom1(font, "Collect 5 Suns before time runs out!!!!! \n HURRY!", sf::Color::Yellow, 30);
    infoRoom1.buildText();
    infoRoom1.setPosition({560.0, 300.0});
    infoRoom1.draw(*window);
}



void room1::drawCountDown()
{
    countDown countDown(10.0f);
    countDown.setCountdown(15.0f);
    countDown.start();
    std::string timeLeft = countDown.printCountDown();


    screenText countDownText(font, timeLeft, sf::Color::Cyan, 120);
    countDownText.buildText();
    countDownText.setPosition({1200.0f,400.0f});
    countDownText.draw(*window);
    countDownText.updateText(timeLeft);

}



void room1::config()
{
    bob.buildPlayer();
}

void room1::run()
{
    drawBackground();
    drawTexts();
    drawPlayer();
    drawSun();
    drawCountDown();


    if(roomFinished)
    {
        *currentState = gameState::room2;
    }

}