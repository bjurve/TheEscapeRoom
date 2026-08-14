#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

int main()
{
    //Konstruktor for Spillvindu
	unsigned int width = 1500;
	unsigned int height = 800;	
	sf::RenderWindow window( sf::VideoMode( sf::Vector2u(width, height)), "Lets Build Some Shit!");

	//Objekt (Sprite)
	sf::Texture texture("C:/Users/sondr/OneDrive/Desktop/Git_Projects/Game_1/Assets/PNG/sun.png");
	sf::Sprite sprite(texture);
	sprite.setPosition({800.f,400.f});
	sprite.setScale({0.06f,0.06f});

	//Objekt (Sirkel)
	sf::CircleShape circle(50.f);
	circle.setOrigin(circle.getGeometricCenter());
	circle.setPosition({width / 4.0f, height / 2.0f} );
	


	
	

	//Spilltekst
	sf::Font font("C:/Users/sondr/OneDrive/Desktop/Git_Projects/Game_1/Assets/FONT/Doug-Regular.ttf.otf");
	sf::Text text(font);
	text.setPosition({10.f,50.f});

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

		




	    //Rydder og fjerner forrige frame
		window.clear(sf::Color::Black);



        //tegner på neste frame
 		//window.draw( sprite );
		window.draw(circle);
		circle.move({5.f,0.f});


		text.setString("Kjøøøøh!");
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);




		//Render ny frame
		window.display();
	}
}
