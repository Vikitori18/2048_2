#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


int GameMenu(sf::RenderWindow& window) {



	using namespace sf;

		
		sf::Texture StartTexture, ExitTexture;
		StartTexture.loadFromFile("Sprites\\start.png");
		ExitTexture.loadFromFile("Sprites\\exit.png");
	

		sf::Sprite Start(StartTexture),  Exit(ExitTexture);
		bool isMenu = 1;
		int menuNum = 0;

		Start.setPosition(80, 50);
		Exit.setPosition(80, 150);

		while (isMenu)
		{
			window.clear(Color::Black);
			if (IntRect(80, 50, 100, 50).contains(Mouse::getPosition(window))) { StartTexture.loadFromFile("Sprites\\start.png"); menuNum = 1; }
			else { StartTexture.loadFromFile("Sprites\\start.png"); }
			if (IntRect(80, 150, 100, 50).contains(Mouse::getPosition(window))) { ExitTexture.loadFromFile("Sprites\\exit.png"); menuNum = 2; }
			else { ExitTexture.loadFromFile("Sprites\\exit.png"); }

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) { isMenu = false; }

				if (menuNum == 2) { window.close(); isMenu = false; }
			}


			window.draw(Start);
			window.draw(Exit);

			window.display();
		}
		
	
	



	return menuNum;
}
