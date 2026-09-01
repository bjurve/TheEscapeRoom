#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <random>
#include "../include/player.hpp"
#include "../include/helpFunctions.hpp"
#include "../include/button.hpp"
#include "../include/screenText.hpp"
#include "../include/countDown.hpp"




sf::Vector2f randomCoordinates(float maxX, float maxY)
{
	static std::random_device rd;
	static std::mt19937 engine(rd());

	std::uniform_real_distribution<float> distX(0.0f, maxX - 200.0f);
	std::uniform_real_distribution<float> distY(0.0f, maxY - 50.0f);
	
	return sf::Vector2f(distX(engine), distY(engine));

}

int main()
{
    //Konstruktor for Spillvindu
	unsigned int width = 1500;
	unsigned int height = 800;	
	sf::RenderWindow window( sf::VideoMode( sf::Vector2u(width, height)), "Lets Build Some Shit!", sf::Style::Default);
	window.setFramerateLimit(120);

	//Spilltekst
	//sf::Font font("C:/Users/sondr/OneDrive/Desktop/Git_Projects/Game_1/Assets/FONT/Super_Bouncer.ttf");
	sf::Font font;
	if(!font.openFromFile("Assets/FONT/Super_Bouncer.ttf"))
	{
		std::cerr << "Failed to load Font!!!" << std::endl;
		return -1;
	}


	sf::Text text(font);
	text.setPosition({10.f,50.f});
	text.setFillColor(sf::Color::Red);

	//Objekt (Sprite)
	//sf::Texture texture("C:/Users/sondr/OneDrive/Desktop/Git_Projects/Game_1/Assets/PNG/sun.png");
	sf::Texture texture("Assets/PNG/sun.png");
	sf::Sprite sprite(texture);
	sprite.setPosition({800.f,400.f});
	sprite.setScale({0.06f,0.06f});
	

	//Sirkel Objekter
	Player bob("bob",sf::Color::Red);
	bob.buildPlayer();


	
	//initierer og starter klokke
	countDown countDown(10.0f);


	//Game-states og variable for current state
	enum class gameState{Menu, room1, room2, GameOver};
	gameState currentGameState = gameState::Menu;

	//Score count
	int count = 0;


	//Game Loop
	while ( window.isOpen() )
	{
		//Lukker Vindu om bruker trykker X eller Escape
		while(std::optional event = window.pollEvent())
		{
			if(event->is<sf::Event::Closed>()){
				window.close();
			}
			else if(const auto* keypressed = event->getIf<sf::Event::KeyPressed>())
			{
				if(keypressed->scancode == sf::Keyboard::Scancode::Escape){
					window.close();
				}
			}

		}


	    //Rydder og fjerner forrige frame------------------------------------
		window.clear(sf::Color::Black);



        //Tegning av Game Menu-------------------------------------------------------------------------------------------------
		if(currentGameState == gameState::Menu)
		{
			//countDown.reset();
			countDown.restart();

			//StartGame knapp
			Button startGame(ButtonSize::medium, sf::Color::White,{750.0f,200.0f});
			startGame.buildButton();
			startGame.draw(window);

			screenText startGameText(font, "START GAME", sf::Color::Red, 30);
			startGameText.buildText();
			mergeTextButton(startGameText, startGame);
			startGameText.draw(window);

			//starter spill hvis startGame er trykket
			if(buttonClicked(window, startGame)){currentGameState = gameState::room1;}
			
	
		}
        //ROOM 1--------------------------------------------------------------------------------------------
		else if(currentGameState == gameState::room1)
		{
			//Countdown før GameOver
			countDown.start();
			std::string timeLeft = countDown.printCountDown();
			std::cout << timeLeft << "\n";

			screenText countDownText(font, timeLeft, sf::Color::White, 50);
			countDownText.buildText();
			countDownText.setPosition({750.0f,20.0f});
			countDownText.draw(window);
			countDownText.updateText(timeLeft);

			if(countDown.isTimerOver())
			{
				currentGameState = gameState::GameOver;
				countDown.reset();
			}

		    if(count >= 5)
			{
				currentGameState = gameState::room2;
				countDown.reset();
			}



			//SunBurnCount Tekst 
			sf::Text SunBurnCount(font);
			SunBurnCount.setString("Count: " + std::to_string(count));

		
			bob.playerMovement();
      
			//KarakterBorder + SpriteBorder-logikk
			if(sprite.getGlobalBounds().findIntersection(bob.getPlayer().getGlobalBounds()))
			{	
				count = count + 1;
				bob.getPlayer().setPosition({width / 4.0f, height / 2.0f});
				sprite.setPosition(randomCoordinates(1500.0f, 800.0f));
			}			




            //tegner
			window.draw(sprite);
			bob.draw(window);
			window.draw(SunBurnCount);
		}
	

		  
	    

		// //ROOM 2 ---------------------------------------------------------------------------------------------------------------
		else if(currentGameState == gameState::room2)
		{

			screenText room2(font, "ROOM 2", sf::Color::Green, 50);
			room2.buildText();
			room2.setPosition({750.0f, 100.0f});
			room2.draw(window);





			bob.draw(window);
			bob.playerMovement();

		}

		//Tegning av Game Over----------------------------------------------------------------------------------------------------
		else if(currentGameState == gameState::GameOver)
		{

	        //GameOver Tekst
			screenText gameOverText(font, "GAME OVER!!!!", sf::Color::White, 100);
			gameOverText.buildText();
			gameOverText.setPosition({750.0f, 200.0f});
			gameOverText.draw(window);

			//Finale Score Tekst
			screenText finaleScore(font, "Youre Score: " + std::to_string(count), sf::Color::White, 70);
			finaleScore.buildText();
			finaleScore.setPosition({750.0f, 400.0f});
			finaleScore.draw(window);

			//Restart game Knapp,Tekst og logikk
			Button tryAgainButton(ButtonSize::medium, sf::Color::White, {750.0f, 600.0f});
			tryAgainButton.buildButton();
			tryAgainButton.draw(window);

			screenText tryAgainText(font, "Try Again", sf::Color::Red, 30);
			tryAgainText.buildText();
			mergeTextButton(tryAgainText,tryAgainButton);
			tryAgainText.draw(window);

			if(buttonClicked(window, tryAgainButton))
			{
				currentGameState = gameState::room1;
			 	//countDown.reset();
			 	count = 0;
			}
		}
	
		//Render ny frame------------------------------
		window.display();
	}
}
