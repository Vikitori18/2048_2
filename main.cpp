#include <iostream>
#include <SFML/Graphics.hpp>
#include "GamePole.h"
#include "selectlvl.h"
#include "Gamemenu.h"


int main()
{
	int Choose = 1;
	int WhidthAndHeight;
	int NandM;
	int whichlvl = 1;


	sf::RenderWindow windowmenu(sf::VideoMode(248, 248), "Game");

	Choose = GameMenu(windowmenu);
	whichlvl = svitchlvl(windowmenu);

	windowmenu.close();

	WhidthAndHeight = 0;
	switch (whichlvl) {
	case 1: {WhidthAndHeight = 248; break; }
	case 2: {WhidthAndHeight = 310; break; }
	case 3: {WhidthAndHeight = 372; break; }
	}

	if (Choose == 1)
	{
		sf::RenderWindow windowgame(sf::VideoMode(WhidthAndHeight, WhidthAndHeight), "Game");

		GamePole* pole = NULL;
		switch (whichlvl)
		{
		case 1: { pole = new GamePole(4); break; }
		case 2: { pole = new GamePole(5);  break; }
		case 3: { pole = new GamePole(6);  break; }
		}

		if (pole != NULL) pole->Game(windowgame);
	}

	return 0;
}
