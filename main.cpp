
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "map.h"
#include "snake.h"
#include "block.h"
#include "fruit.h"
#include "view.h"
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(810, 660), "SnakeCoin_v2");
	view.reset(FloatRect(0, 0, 810, 660));
	window.setFramerateLimit(10);
	////////////////////////////////////////////////
	// Load images
	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	Image heroImage;
	heroImage.loadFromFile("images/snake.png");
	Image coin;
	coin.loadFromFile("images/btc.png");
	////////////////////////////////////////////////
	list<Block> blocks;
	list<Block>::iterator it;
	enum direction { UP, RIGHT, DOWN, LEFT };
	int direction = RIGHT; int w = 0; int h = 0;
	Snake snake(heroImage, w, h, window);
	Fruit fruit(coin, 30, 30, window);

	// Tells if we need to respawn a fruit
	bool mustSpawnFruit = true;

	// Coords of the fruit
	int fruitX;
	int fruitY;

	while (window.isOpen())
		{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) { direction = LEFT; } 
		if (Keyboard::isKeyPressed(Keyboard::Right)) { direction = RIGHT;} 
		if (Keyboard::isKeyPressed(Keyboard::Up)) { direction = UP;} 
		if (Keyboard::isKeyPressed(Keyboard::Down)) { direction = DOWN;}
																		
		// Paint map
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 30, 30));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 30, 30));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 30, 30));

				s_map.setPosition(j * 30, i * 30);

				window.draw(s_map);
			}
		/**
		* Spawn a fruit if necessary
		**/
		if (mustSpawnFruit)
		{
			bool safe = true;

			// We make sure that it doesn't spawn on the snake
			do
			{
				fruitX = (rand() % 30) * 30 + 30 ;
				fruitY = (rand() % 25) * 30 + 30 ;
				if (fruitX == 810 || fruitX == 780 || fruitX == 900 || fruitX == 840 || fruitX == 870) { fruitX = 750; }
				if (fruitY == 660 || fruitY == 630 || fruitY == 750 || fruitY == 690 || fruitY == 720) { fruitY = 600; }
				blocks = snake.getBlocks();

				for (it = blocks.begin(); it != blocks.end(); it++)
				{
					if (it->getX() == fruitX && it->getY() == fruitY)
					{
						safe = false;
						break;
					}
					else
					{
						safe = true;
					}
				}
			} while (safe != true);

			mustSpawnFruit = false;
		}

		fruit.spawn(fruitX, fruitY);

		snake.move(direction);
		snake.draw();

		/**
		* Detects if the snake hits the bounds of the board
		**/

		if (snake.getX() >= 810 || snake.getX() < 0 || snake.getY() >= 660 || snake.getY() < 0)
		{
			window.close();
		}

		/**
		* Detects if the snake hits a fruit
		**/

		if (snake.getX() == fruit.getX() && snake.getY() == fruit.getY())
		{
			mustSpawnFruit = true;

			snake.grow();
		}

		/**
		* Detects if the snake hits himself
		**/
		
		blocks = snake.getBlocks();
		it = blocks.begin();

		it++; // Since we know the last inserted block is the same position as the snake's head, we skip it

		for (it; it != blocks.end(); it++)
		{
			if (it->getX() == snake.getX() && it->getY() == snake.getY())
			{
				window.close();
			}
		}
	
		
		window.display();
		std::cout << direction << " " << snake.getX() << " " << snake.getY() << " " << fruitX << " " << fruitY << " " << snake.Lenght() << endl;
	}

	return EXIT_SUCCESS;
	}
