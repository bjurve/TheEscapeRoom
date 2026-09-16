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
	try
	{	//Konstruererfor Spillvindu
		unsigned int width = 1500;
		unsigned int height = 800;	
		sf::RenderWindow window( sf::VideoMode( sf::Vector2u(width, height)), "Lets Build Some Shit!", sf::Style::Default);
		window.setFramerateLimit(120);
		std::cout << "Spillvindu Generert" << std::endl;

		//Font for tekst
		sf::Font font;
		if(!font.openFromFile("Assets/FONT/escape_game_font.ttf"))
		{
			std::cerr << "Failed to load Font!!!" << std::endl;
			return -1;
		}


		gameState currentGameState = gameState::room1;

		//initierer og starter klokke
		countDown countDown(10.0f);


	//-------- Game Meny Config -----------------------------------------------------
		
		gameMeny meny(&window, &currentGameState);

	//-------- Room 1 Config  (SunCollect) --------------------------------------------------------
		
		room1 room1(&window, &currentGameState);
		room1.config();


	//-------- Room 2 Config --------------------------------------------------------
		//zombie - room2
		// enemy zombieR2("Assets/PNG/skully.png",bob,{0.0,400.0});
		// zombieR2.buildEnemy();

		background R2Background("Assets/PNG/lava.png", width, height);

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
		// std::vector<wall> wallCollection;

		// wall wall1({750.0, 400.0},{400.0,10.0}, sf::Color::Green);
		// wallCollection.push_back(wall1);

		// wall wall2({650.0, 400.0},{10.0,400.0}, sf::Color::Green);
		// wallCollection.push_back(wall2);

		// wall wall3({150.0, 400.0},{400.0,10.0}, sf::Color::Green);
		// wallCollection.push_back(wall3);

		// wall wall4({150.0, 100.0},{400.0,10.0}, sf::Color::Green);
		// wallCollection.push_back(wall4);

		// wall wall5({400.0, 100.0},{10.0,200.0}, sf::Color::Green);
		// wallCollection.push_back(wall5);

		// wall wall6({550.0, 300.0},{400.0,10.0}, sf::Color::Green);
		// wallCollection.push_back(wall6);

		// wall wall7({150.0, 400.0},{400.0,10.0}, sf::Color::Green);
		// wallCollection.push_back(wall7);

		// //bygger zombie for rom 4
		// enemy zombieR4("Assets/PNG/skully.png",bob,{0.0,400.0});
		// zombieR4.buildEnemy();


	//-------- Game Over Config --------------------------------------------------------

		background GMBackground("Assets/PNG/gameoverBackground.png", width, height);
	
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
				meny.run();	
			}
			//ROOM 1--------------------------------------------------------------------------------------------
			else if(currentGameState == gameState::room1)
			{
			

				room1.run();

				// countDown.setCountdown(15.0f);
				// countDown.start();
				// std::string timeLeft = countDown.printCountDown();


				// screenText countDownText(font, timeLeft, sf::Color::Cyan, 120);
				// countDownText.buildText();
				// countDownText.setPosition({1200.0f,400.0f});
				// countDownText.draw(window);
				// countDownText.updateText(timeLeft);



				// if(countDown.isTimerOver())
				// {
				// 	currentGameState = gameState::GameOver;
				// 	countDown.reset();
				// }

				// if(count >= 5)
				// {
				// 	currentGameState = gameState::room2;
				// 	countDown.reset();
				// }



				//SunBurnCount Tekst 
				// sf::Text SunBurnCount(font);
				// SunBurnCount.setString("Count: " + std::to_string(count));

			
		
		
				// //KarakterBorder + SpriteBorder-logikk
				// if(sprite.getGlobalBounds().findIntersection(bob.getPlayer().getGlobalBounds()))
				// {	
				// 	count = count + 1;
				// 	bob.getPlayer().setPosition({width / 4.0f, height / 2.0f});
				// 	sprite.setPosition(randomCoordinates(1500.0f, 800.0f));
				// }			


				

				//tegner
				//window.draw(sprite);
				
				//window.draw(SunBurnCount);
			}
		
			// //ROOM 2 ---------------------------------------------------------------------------------------------------------------
			else if(currentGameState == gameState::room2)
			{
				// R2Background.draw(window);
				// countDown.setCountdown(15.0f);
				// countDown.start();

				// // sf::Sound zombieSound(buffer);
				// // zombieSound.play();

				// screenText r2CountDown(font, "You Must Survive For " + countDown.printCountDown() + " seconds!!!", sf::Color::Green, 20);
				// r2CountDown.buildText();
				// r2CountDown.setPosition({400.0, 200.0});
				// r2CountDown.draw(window);


				// screenText room2(font, "ROOM 2", sf::Color::Green, 30);
				// room2.buildText();
				// room2.setPosition({750.0f, 50.0f});
				// room2.draw(window);

				// screenText infoRoom2(font, "OOHH NOO, watch out for Skully (you're swore enemy)!!", sf::Color::Yellow, 30);
				// infoRoom2.buildText();
				// infoRoom2.setPosition({750.0f, 600.0f});
				// infoRoom2.draw(window);

				
				
				// zombieR2.moveRight();
				// zombieR2.borderCheck();
				// zombieR2.draw(window);

				// bob.draw(window);
				// bob.playerMovement();


				// if(countDown.isTimerOver())
				// {
				// 	currentGameState = gameState::room3;
				// 	countDown.reset();
				// }

				// if(objectIntersect(zombieR2.getEnemy(), bob.getPlayer()))
				// {
				// 	currentGameState = gameState::GameOver;
				// 	countDown.reset();
				// 	zombieR2.getSpeed() = 2.0;
				// }

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

				if(buttonClicked(window, answerB) || textClicked(window, answerBText)){currentGameState = gameState::room4;}

				if(
					buttonClicked(window, answerA) || textClicked(window, answerAText) ||
					buttonClicked(window, answerC) || textClicked(window, answerCText)) 
				{currentGameState = gameState::GameOver;}

			}
			// Room 4 --------------------------------------------------------------------------------
			else if(currentGameState == gameState::room4)
			{
				
				// //Tegner alle veggene
				// for(wall& it : wallCollection)
				// {
				// 	it.buildWall();
				// 	it.draw(window);
				// }

				// // Tegner spiller og spiller/vegg-logikk
				// bob.playerMovement();
				// stopWhenTouchingWall(bob, wallCollection);
				// bob.draw(window);
				
				// // tegner Zombie og logikk
				// zombieR4.followPlayer(bob, 2.0);
				// zombieR4.draw(window);


				// if(objectIntersect(bob.getPlayer(), zombieR4.getEnemy()))
				// {
				// 	currentGameState = gameState::GameOver;
				// }


			}

			//Game Over----------------------------------------------------------------------------------------------------
			else if(currentGameState == gameState::GameOver)
			{
				// GMBackground.draw(window);
			
				// //Restart game Knapp,Tekst og logikk
				// Button tryAgainButton(ButtonSize::medium, sf::Color::White, {750.0f, 600.0f});
				// tryAgainButton.buildButton();
				// tryAgainButton.draw(window);

				// screenText tryAgainText(font, "Try Again", sf::Color::Red, 30);
				// tryAgainText.buildText();
				// mergeTextButton(tryAgainText,tryAgainButton);
				// tryAgainText.draw(window);

				// if(buttonClicked(window, tryAgainButton))
				// {
				// 	currentGameState = gameState::room1;
				// 	//countDown.reset();
				// 	count = 0;
				// }

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
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: "<< e.what() << std::endl;
		return 1;
	}	
}
