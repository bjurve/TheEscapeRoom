
#include "../../include/rooms/gameMeny.hpp"


void gameMeny::drawBackground()
{
    background menyBAckground("Assets/PNG/pikselBackground.png",static_cast<float>(window->getSize().x),static_cast<float>(window->getSize().y));
    menyBAckground.draw(*window);
}

void gameMeny::drawClouds()
{
    character cloud1("Assets/PNG/cloud.png", {100.0,200.0}, {0.2,0.2});
	cloud1.buildCharacter();
    cloud1.draw(*window);


}

void gameMeny::drawButtons()
{
    Button startGame(ButtonSize::medium, sf::Color::White,{750.0f,400.0f});
	startGame.buildButton();
	startGame.draw(*window);
		
    screenText startGameText(font, "START GAME", sf::Color::Red, 50);
	startGameText.buildText();
	mergeTextButton(startGameText, startGame);
	startGameText.draw(*window);


    if(buttonClicked(*window, startGame))
    {
        roomFinished = true;

    }

};


void gameMeny::run()
{
    drawBackground();
    drawClouds();
    drawButtons();

    if(roomFinished)
    {
        *currentState = gameState::room1;
    }

};