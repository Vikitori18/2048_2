#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


int svitchlvl(sf::RenderWindow& window) {



	using namespace sf;


	sf::Texture Level4x4, Level5x5, Level6x6;
	Level4x4.loadFromFile("Sprites\\4x4.png");
	Level5x5.loadFromFile("Sprites\\5x5.png");
	Level6x6.loadFromFile("Sprites\\6x6.png");


	sf::Sprite Level1(Level4x4), Level2(Level5x5), Level3(Level6x6);
	bool isLevel = 1;
	int choosLevel = 0;

	Level1.setPosition(80, 20);
	Level2.setPosition(80, 100);
	Level3.setPosition(80, 180);

	while (isLevel)
	{
		window.clear(Color::Black);
	if (IntRect(80, 20, 100, 50).contains(Mouse::getPosition(window))) { Level4x4.loadFromFile("Sprites\\4x4.png"); choosLevel = 1; }
	else { Level4x4.loadFromFile("Sprites\\4x4.png"); }
	if (IntRect(80, 100, 100, 50).contains(Mouse::getPosition(window))) { Level5x5.loadFromFile("Sprites\\5x5.png"); choosLevel = 2; }
	else { Level5x5.loadFromFile("5x5.png"); }
	if (IntRect(80, 180, 100, 50).contains(Mouse::getPosition(window))) { Level6x6.loadFromFile("Sprites\\6x6.png"); choosLevel = 3; }
	else { Level6x6.loadFromFile("Sprites\\6x6.png"); }


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (choosLevel == 1) { isLevel = false; }

			if (choosLevel == 2) { isLevel = false; }

			if (choosLevel == 3) { isLevel = false; }
		}


		window.draw(Level1);
		window.draw(Level2);
		window.draw(Level3);

		window.display();
	}

	



	return choosLevel;
}

