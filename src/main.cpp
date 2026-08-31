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


	

	
	
	


	//Game-states og variable for current state
	enum class gameState{Menu, Playing, GameOver};
	gameState currentGameState = gameState::Menu;

	//Score count
	int count = 0;

	
	//Nedtelling til Game Over
	sf::Clock countDown;
	float countDownDuration = 10.0f;

	

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



        //-----------------Tegning av neste frame--------------------------------

        //Tegning av Game Menu-------------------------------------------------------------------------------------------------
		if(currentGameState == gameState::Menu)
		{
			countDown.reset();


			//StartGame knapp
			Button startGame(ButtonSize::medium, sf::Color::White,{750.0f,200.0f});
			startGame.buildButton();
			screenText startGameText(font, "START GAME", sf::Color::Red, 30);
			startGameText.buildText();

			startGame.draw(window);
			mergeTextButton(startGameText, startGame);
			startGameText.draw(window);



			//Input boks for spillernavn
			Button inputBox(ButtonSize::medium, sf::Color::White, {750.0f, 280.0f});
			inputBox.buildButton();
			inputBox.draw(window);
			



			//startGame Logikk
			//sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//sf::Vector2f mousdPosF(mousePos);
			//sf::Mouse::Button mousButton = sf::Mouse::Button::Left;

			//if(startGame.getButton().getGlobalBounds().contains(mousdPosF) && sf::Mouse::isButtonPressed(mousButton))
			//{
			//	currentGameState = gameState::Playing;
			//};
			if(buttonClicked(window, startGame)){currentGameState = gameState::Playing;}
			
			
		
		

		}
        //Tegning av selve Spillet--------------------------------------------------------------------------------------------
		else if(currentGameState == gameState::Playing)
		{

			//Nedtelling sjekk og tekst
			sf::Time timeElapsed = countDown.getElapsedTime();
			float time = timeElapsed.asSeconds();

			sf::Text CountDownText(font);
			float timeleft = countDownDuration - time;
			int timeleftINT = static_cast<int>(std::round(timeleft));
		
			CountDownText.setString("Time Left: " + std::to_string(timeleftINT));
			sf::FloatRect timeBound = CountDownText.getGlobalBounds();
			CountDownText.setOrigin({timeBound.position.x + timeBound.size.x / 2 , timeBound.position.y + timeBound.size.y / 2});
			CountDownText.setPosition({750.0f, 20.0f});
			CountDownText.setCharacterSize(50);


			countDown.start();
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




            // sjekker om nedtelling har gått ut og sender spiller til Game Over om den har
			if(time >= countDownDuration)
			{
				currentGameState = gameState::GameOver; 
			}


			//Tegning av Nedtelling

            //tegner
			window.draw(sprite);
			bob.draw(window);
			window.draw(SunBurnCount);
			window.draw(CountDownText);
	


		}
		//Tegning av Game Over----------------------------------------------------------------------------------------------------
		else if(currentGameState == gameState::GameOver)
		{

			sf::Text GameOverText(font);
			GameOverText.setString("GAME OVER!!!!");
			GameOverText.setFillColor(sf::Color::White);
			GameOverText.setCharacterSize(100);
			sf::FloatRect gotBound = GameOverText.getGlobalBounds();
			GameOverText.setOrigin({gotBound.position.x + gotBound.size.x / 2, gotBound.position.y + gotBound.size.y / 2});
			GameOverText.setPosition({750.0f, 200.0f});

			sf::Text FinalScore(font);
			FinalScore.setString("Youre Score: " + std::to_string(count));
			FinalScore.setFillColor(sf::Color::White);
			FinalScore.setCharacterSize(70);
			sf::FloatRect scoreBound = FinalScore.getGlobalBounds();
			FinalScore.setOrigin({scoreBound.position.x + scoreBound.size.x / 2, scoreBound.position.y + scoreBound.size.y / 2});
			FinalScore.setPosition({750.0f, 400.0f});

			//restart Game Logikk
			sf::RectangleShape tryAgainButton;
			tryAgainButton.setSize({600.0f,50.0f});
			tryAgainButton.setOrigin({300.0f,25.0f});
			tryAgainButton.setPosition({750.0f,600.0f});
			

			sf::Text tryAgainText(font);
			tryAgainText.setString("Try Again Noob");
			tryAgainText.setCharacterSize(30);
		    tryAgainText.setFillColor(sf::Color::Red);

			sf::FloatRect tATBound = tryAgainText.getGlobalBounds();
			tryAgainText.setOrigin({tATBound.position.x + tATBound.size.x / 2, tATBound.position.y + tATBound.size.y / 2});
			tryAgainText.setPosition(tryAgainButton.getPosition());


			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2f mousdPosF(mousePos);
			sf::Mouse::Button mousButton = sf::Mouse::Button::Left;

			if(tryAgainButton.getGlobalBounds().contains(mousdPosF) && sf::Mouse::isButtonPressed(mousButton))
			{
				currentGameState = gameState::Playing;
				countDown.reset();
				count = 0;
			};

			
			


			window.draw(GameOverText);
			window.draw(FinalScore);
			window.draw(tryAgainButton);
			window.draw(tryAgainText);

		}
	





		//Render ny frame------------------------------
		window.display();
	}
}
