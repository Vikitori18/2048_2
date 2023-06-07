#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <vector>

#pragma once
class GamePole
{
public:
	const int TILESIZE = 64;
	enum Direction
	{
		Left,
		Right,
		Up,
		Down,
	};
protected:
	int poleSize = 4;
private:
	bool win = false;
	std::vector<std::vector<int>> map;
public:
	GamePole(int size);
	int getPoleAbsSize() { return poleSize * TILESIZE; }
	int getPoleSize() { return poleSize; }
	sf::Vector2i genPos();
	void countMap();
	int genNewTile();
	void placeNewTitle();
	void Shift(Direction d);
	void Game(sf::RenderWindow& window);
	bool checkPosition(int x, int y);
	int checkChoose(int whichlvl);
};

