#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <random>

//inneholder alle klassene og funksjonen som er laget
#include "../include/header.hpp"



int main()
{
 //========================= CONFIGS =========================================================
 //-------- General Game Config -------------------------------------------------
	//Konstruererfor Spillvindu
	unsigned int width = 1500;
	unsigned int height = 800;	
	sf::RenderWindow window( sf::VideoMode( sf::Vector2u(width, height)), "Lets Build Some Shit!", sf::Style::Default);
	window.setFramerateLimit(120);

	//Font for tekst
	sf::Font font;
	if(!font.openFromFile("Assets/FONT/Super_Bouncer.ttf"))
	{
		std::cerr << "Failed to load Font!!!" << std::endl;
		return -1;
	}
 
 	//Game-states og variable for current state
	enum class gameState{Menu, room1, room2, room3, room4, GameOver, Victory};
	gameState currentGameState = gameState::room4;

	//initierer og starter klokke
	countDown countDown(10.0f);


 //-------- Game Meny Config -----------------------------------------------------
	sf::Texture logoSkin("Assets/PNG/logo.png");
	sf::Sprite logo(logoSkin);
	logo.setOrigin(getOriginCenterSprite(logo));
	logo.setPosition({750.0, 400.0});
	logo.setScale({0.8,0.8});

 //-------- Room 1 Config --------------------------------------------------------
	//Score count
	int count = 0;

	//Sirkel Objekt
	Player bob("bob",sf::Color::Red);
	bob.buildPlayer();

	//Sol - room1
	sf::Texture texture("Assets/PNG/sun.png");
	sf::Sprite sprite(texture);
	sprite.setPosition({800.f,400.f});
	sprite.setScale({0.06f,0.06f});

 //-------- Room 2 Config --------------------------------------------------------
	//zombie - room2
	zombie zombie(bob);
	zombie.buildZombie();

		// //Zombielyd til rom 2
	// sf::SoundBuffer buffer;
	// if(!font.openFromFile("Assets/SOUND/zombieSound.wav"))
	// {
	// 	std::cerr << "Failed to load Sound!!!" << std::endl;
	// 	return -1;
	// }

 //-------- Room 3 Config --------------------------------------------------------
	//Answer A
 	Button answerA(ButtonSize::small,sf::Color::Red, {300.0, 550.0});
	answerA.buildButton();
	sf::Vector2f speedA{5.0, 3.0};
	//Answer B
	Button answerB(ButtonSize::small,sf::Color::Yellow, {750.0, 450.0});
	answerB.buildButton();
	sf::Vector2f speedB{5.0, 3.0};
	//Answer C
	Button answerC(ButtonSize::small,sf::Color::Red, {1200.0, 550.0});
	answerC.buildButton();
	sf::Vector2f speedC{5.0, 3.0};

 //-------- Room 4 Config --------------------------------------------------------
	std::vector<wall> wallCollection;

	wall wall1({750.0, 400.0},{400.0,10.0}, sf::Color::Green);
	wallCollection.push_back(wall1);

	wall wall2({650.0, 400.0},{10.0,400.0}, sf::Color::Green);
	wallCollection.push_back(wall2);

	wall wall3({150.0, 400.0},{400.0,10.0}, sf::Color::Green);
	wallCollection.push_back(wall3);





 //-------- Game Over Config --------------------------------------------------------
 
 //================================================================================================


 //========================= The Game ===========================================================
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
			window.draw(logo);

			//countDown.reset();
			countDown.reset();

			//StartGame knapp
			Button startGame(ButtonSize::medium, sf::Color::White,{750.0f,400.0f});
			startGame.buildButton();
			startGame.draw(window);

			screenText startGameText(font, "START GAME", sf::Color::Red, 50);
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
			countDown.setCountdown(15.0f);
			countDown.start();
			std::string timeLeft = countDown.printCountDown();


			screenText countDownText(font, timeLeft, sf::Color::Cyan, 120);
			countDownText.buildText();
			countDownText.setPosition({1200.0f,400.0f});
			countDownText.draw(window);
			countDownText.updateText(timeLeft);

			screenText room1(font, "ROOM 1", sf::Color::Red, 80);
			room1.buildText();
			room1.setPosition({750.0f, 50.0f});
			room1.draw(window);

			screenText infoRoom1(font, "Collect 5 Suns before time runs out!!!!! \n HURRY!", sf::Color::Red, 50);
			infoRoom1.buildText();
			infoRoom1.setPosition({500.0, 300.0});
			infoRoom1.draw(window);


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
			countDown.setCountdown(15.0f);
			countDown.start();

			// sf::Sound zombieSound(buffer);
			// zombieSound.play();

			screenText r2CountDown(font, "You Must Survive For " + countDown.printCountDown() + " seconds!!!", sf::Color::Green, 50);
			r2CountDown.buildText();
			r2CountDown.setPosition({400.0, 200.0});
			r2CountDown.draw(window);


			screenText room2(font, "ROOM 2", sf::Color::Green, 80);
			room2.buildText();
			room2.setPosition({750.0f, 50.0f});
			room2.draw(window);

			screenText infoRoom2(font, "DO NOT get hit by the pac boi!!", sf::Color::Yellow, 80);
			infoRoom2.buildText();
			infoRoom2.setPosition({750.0f, 600.0f});
			infoRoom2.draw(window);

			
			
			zombie.moveLeft();
			zombie.borderCheck();
			zombie.draw(window);

			bob.draw(window);
			bob.playerMovement();


			if(countDown.isTimerOver())
			{
				currentGameState = gameState::room3;
				countDown.reset();
			}

			if(objectIntersect(zombie.getZombie().getCharacter(), bob.getPlayer()))
			{
				currentGameState = gameState::GameOver;
				countDown.reset();
				zombie.getZombie().getSpeedX() = 5.0;
			}

		}
		//ROOM 3 ---------------------------------------------------------------------------------
		else if(currentGameState == gameState::room3)
		{
			//nedtelling
			countDown.setCountdown(8.0f);
			countDown.start();
			screenText r2CountDown(font,countDown.printCountDown(), sf::Color::Magenta, 100);
			r2CountDown.buildText();
			r2CountDown.setPosition({750.0, 650.0});
			r2CountDown.draw(window);

			screenText room3(font, "ROOM 3", sf::Color::Magenta, 80);
			room3.buildText();
			room3.setPosition({750.0f, 50.0f});
			room3.draw(window);

			screenText infoRoom3(font, "CLICK the corrct answer", sf::Color::Red, 80);
			infoRoom3.buildText();
			infoRoom3.setPosition({750.0f, 520.0f});
			infoRoom3.draw(window);

			//Mattespørsmål som MÅ besvares riktig for å komme videre
			screenText math(font, "What is 7*7+8+10!!??", sf::Color::Magenta, 70);
			math.buildText();
			math.setPosition({750.0,200.0});
			math.draw(window);

			//Svaralternativ A
			if(objectTouchWindowBorder(answerA.getButton())){speedA = randomFloats(5.0);}
			answerA.getButton().move(speedA);
			answerA.draw(window);

			screenText answerAText(font, "72", sf::Color::White, 30);
			answerAText.buildText();
			mergeTextButton(answerAText, answerA);
			answerAText.draw(window);

			//Svaralternativ B
			if(objectTouchWindowBorder(answerB.getButton())){speedB = randomFloats(5.0);}
			answerB.getButton().move(speedB);
			answerB.draw(window);

			screenText answerBText(font, "67", sf::Color::Black, 70);
			answerBText.buildText();
			mergeTextButton(answerBText, answerB);
			answerBText.draw(window);

			//Svaralternativ C
			if(objectTouchWindowBorder(answerC.getButton())){speedC = randomFloats(5.0);}
			answerC.getButton().move(speedC);
			answerC.draw(window);

			screenText answerCText(font, "82", sf::Color::White, 30);
			answerCText.buildText();
			mergeTextButton(answerCText, answerC);
			answerCText.draw(window);




			if(countDown.isTimerOver())
			{
				currentGameState = gameState::GameOver;
				countDown.reset();
			}

			if(buttonClicked(window, answerB) || textClicked(window, answerBText)){currentGameState = gameState::Victory;}

			if(
				buttonClicked(window, answerA) || textClicked(window, answerAText) ||
			 	buttonClicked(window, answerC) || textClicked(window, answerCText)) 
			{currentGameState = gameState::GameOver;}




		}
		// Room 4 --------------------------------------------------------------------------------
		else if(currentGameState == gameState::room4)
		{
			for(auto it : wallCollection)
			{
				it.buildWall();
				it.draw(window);
			}

			bob.playerMovement();
			bob.draw(window);
			
			
			
		

		}

		//Game Over----------------------------------------------------------------------------------------------------
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
		//Victory -------------------------------------------------------------------------	
		else if(currentGameState == gameState::Victory)
		{

			screenText victoryText(font, "CONGRATS \n You Escaped Every Room!!!!", sf::Color::Magenta, 100);
			victoryText.buildText();
			victoryText.setPosition({750.0, 400.0});
			victoryText.draw(window);

		}
		
	
		//Render ny frame------------------------------
		window.display();
	}
}
