#include "GamePole.h"

GamePole::GamePole(int size) {
	poleSize = size;
	map = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}

bool GamePole::checkPosition(int x, int y) {
	if (x <= 0 || y <= 0 || y > getPoleSize() || x > getPoleSize()) return false;
	if (map[x - 1][y - 1] == 0) return true;
	return false;
}



int GamePole::checkChoose(int whichlvl) {
	if (whichlvl == 1) return 248;
	if (whichlvl == 2) return 310;
	if (whichlvl == 3) return 372;
}

sf::Vector2i GamePole::genPos() {
	sf::Vector2i v;
	while (true) {
		v.x = rand() % getPoleSize();
		v.y = rand() % getPoleSize();
		if (map[v.y][v.x] == 0) break;
	}
	return v;
}

void GamePole::countMap() {
	for (int a = 0; a < getPoleSize(); a++)
	{
		for (int b = 0; b < getPoleSize(); b++) {
			std::cout << map[a][b] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int GamePole::genNewTile() {
	int t = rand() % 2;
	return t == 0 ? 2 : 4;
}

void GamePole::placeNewTitle() {
	sf::Vector2i p = genPos();
	map[p.y][p.x] = genNewTile();
}

void GamePole::Shift(Direction d) {

	bool didShift = 0;
	if (d == Direction::Up)
	{
		for (int j = 0; j < getPoleSize(); j++)
		{
			for (int i = 0; i < getPoleSize() - 1; i++)
			{
				if (map[i][j] == 0)
				{
					bool change = 0;
					for (int k = i; k < getPoleSize() - 1; k++)
					{
						map[k][j] = map[k + 1][j];
						if (map[k][j] != 0)
						{
							didShift = 1;
							change = 1;
						}
					}
					map[getPoleSize() - 1][j] = 0;
					if (change) i--;
				}
			}
			for (int i = 0; i < getPoleSize() - 1; i++)
			{
				if (map[i][j] == map[i + 1][j] && map[i][j] != 0)
				{
					didShift = 1;
					for (int k = i; k < getPoleSize() - 1; k++)
					{
						map[k][j] = map[k + 1][j];
					}
					map[getPoleSize() - 1][j] = 0;
					map[i][j] *= 2;

				}
			}
		}
	}
	else if (d == Direction::Left)
	{
		for (int i = 0; i < getPoleSize(); i++)
		{
			for (int j = 0; j < getPoleSize() - 1; j++)
			{
				if (map[i][j] == 0)
				{
					bool change = 0;
					for (int k = j; k < getPoleSize() - 1; k++)
					{
						map[i][k] = map[i][k + 1];
						if (map[i][k] != 0)
						{
							didShift = 1;
							change = 1;
						}

					}
					map[i][getPoleSize() - 1] = 0;
					if (change) j--;
				}
			}
			for (int j = 0; j < getPoleSize() - 1; j++)
			{
				if (map[i][j] == map[i][j + 1] && map[i][j] != 0)
				{
					didShift = 1;
					for (int k = j; k < getPoleSize() - 1; k++) map[i][k] = map[i][k + 1];
					map[i][getPoleSize() - 1] = 0;
					map[i][j] *= 2;
				}
			}
		}
	}
	else if (d == Direction::Down)
	{
		for (int j = 0; j < getPoleSize(); j++)
		{
			for (int i = getPoleSize() - 1; i >= 0; i--)
			{
				if (map[i][j] == 0)
				{
					bool change = 0;
					for (int k = i; k > 0; k--)
					{
						map[k][j] = map[k - 1][j];
						if (map[k][j] != 0)
						{
							didShift = 1;
							change = 1;
						}

					}
					map[0][j] = 0;
					if (change) i++;
				}
			}
			for (int i = getPoleSize() - 1; i > 0; i--)
			{
				if (map[i][j] == map[i - 1][j] && map[i][j] != 0)
				{
					didShift = 1;
					for (int k = i; k > 0; k--) map[k][j] = map[k - 1][j];
					map[0][j] = 0;
					map[i][j] *= 2;
				}
			}
		}

	}
	else if (d == Direction::Right)
	{
		for (int i = 0; i < getPoleSize(); i++)
		{
			for (int j = getPoleSize() - 1; j >= 0; j--)
			{
				if (map[i][j] == 0)
				{
					bool change = 0;
					for (int k = j; k > 0; k--)
					{
						map[i][k] = map[i][k - 1];
						if (map[i][k] != 0)
						{
							didShift = 1;
							change = 1;
						}

					}
					map[i][0] = 0;
					if (change) j++;
				}
			}
			for (int j = getPoleSize() - 1; j > 0; j--)
			{
				if (map[i][j] == map[i][j - 1] && map[i][j] != 0)
				{
					didShift = 1;
					for (int k = j; k > 0; k--) map[i][k] = map[i][k - 1];
					map[i][0] = 0;
					map[i][j] *= 2;
				}
			}
		}
	}
	if (didShift) placeNewTitle();
}

void GamePole::Game(sf::RenderWindow& window) {

	sf::Texture tblank, t2, t4, t8, t16, t32, t64, t128, t256, t512, t1024, t2048, t4096, t8192;
	tblank.loadFromFile("Sprites\\emptycell.png");
	t2.loadFromFile("Sprites\\2.png");
	t4.loadFromFile("Sprites\\4.png");
	t8.loadFromFile("Sprites\\8.png");
	t16.loadFromFile("Sprites\\16.png");
	t32.loadFromFile("Sprites\\32.png");
	t64.loadFromFile("Sprites\\64.png");
	t128.loadFromFile("Sprites\\128.png");
	t256.loadFromFile("Sprites\\256.png");
	t512.loadFromFile("Sprites\\512.png");
	t1024.loadFromFile("Sprites\\1024.png");
	t2048.loadFromFile("Sprites\\2048.png");
	t4096.loadFromFile("Sprites\\4096.png");
	t8192.loadFromFile("Sprites\\8192.png");

	sf::Sprite sprite_blank(tblank);
	sf::Sprite sprite_2(t2);
	sf::Sprite sprite_4(t4);
	sf::Sprite sprite_8(t8);
	sf::Sprite sprite_16(t16);
	sf::Sprite sprite_32(t32);
	sf::Sprite sprite_64(t64);
	sf::Sprite sprite_128(t128);
	sf::Sprite sprite_256(t256);
	sf::Sprite sprite_512(t512);
	sf::Sprite sprite_1024(t1024);
	sf::Sprite sprite_2048(t2048);
	sf::Sprite sprite_4096(t4096);
	sf::Sprite sprite_8192(t8192);

	placeNewTitle();
	placeNewTitle();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && !win)
			{
				if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) Shift(Direction::Left);
				else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) Shift(Direction::Right);
				else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) Shift(Direction::Up);
				else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) Shift(Direction::Down);
			}
			else if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (!win) {
				for (int i = 0; i < getPoleSize(); i++)
				{
					for (int j = 0; j < getPoleSize(); j++)
					{
						if (map[i][j] == 2048) {
							win = 1;
							break;
						}
					}

				}
			}
			window.clear();
			for (int i = 0; i < getPoleSize(); i++)
			{
				for (int j = 0; j < getPoleSize(); j++)
				{
					if (map[i][j] == 0)
					{
						sprite_blank.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_blank);
					}
					else if (map[i][j] == 2) {
						sprite_2.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_2);
					}
					else if (map[i][j] == 4) {
						sprite_4.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_4);
					}
					else if (map[i][j] == 8) {
						sprite_8.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_8);
					}
					else if (map[i][j] == 16) {
						sprite_16.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_16);
					}
					else if (map[i][j] == 32) {
						sprite_32.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_32);
					}
					else if (map[i][j] == 64) {
						sprite_64.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_64);
					}
					else if (map[i][j] == 128) {
						sprite_128.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_128);
					}
					else if (map[i][j] == 256) {
						sprite_256.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_256);
					}
					else if (map[i][j] == 512) {
						sprite_512.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_512);
					}
					else if (map[i][j] == 1024) {
						sprite_1024.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_1024);
					}
					else if (map[i][j] == 2048) {
						sprite_2048.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_2048);
					}
					else if (map[i][j] == 4096) {
						sprite_4096.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_4096);
					}
					else if (map[i][j] == 4096) {
						sprite_8192.setPosition(j * TILESIZE, i * TILESIZE);
						window.draw(sprite_8192);
					}
				}

			}
			window.display();
		}
	}
}
