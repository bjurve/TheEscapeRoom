#include <SFML/Graphics.hpp>

int main()
{
    //Konstruktor for Spillvindu
	sf::RenderWindow window( sf::VideoMode( { 1500, 800 } ), "Lets Build Some Shit!");

	//SpillKarakter (objekt)
	sf::Texture texture("C:/Users/sondr/OneDrive/Desktop/Git_Projects/Game_1/Assets/PNG/sun.png");
	sf::Sprite sprite(texture);
	sprite.setScale({0.06f,0.06f});
	

	//Spilltekst
	sf::Font font("C:/Users/sondr/OneDrive/Desktop/Git_Projects/Game_1/Assets/FONT/Doug-Regular.ttf.otf");
	sf::Text text(font);


	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}
         
	    //Rydder vinduet fra forrige frame
		window.clear(sf::Color::Black);



        //tegner på neste frame
 		window.draw( sprite );


		text.setString("Kjøøøøh!");
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);




		//Displayer nytt frame
		window.display();
	}
}
