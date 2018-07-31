#ifndef _SNAKE_
#define _SNAKE_

#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Block;

class Snake
{
private:
	list<Block> _snake;
	sf::RenderWindow *_app;
	enum direction { UP, RIGHT, DOWN, LEFT };
	enum { left, right, up, down, jump, stay } state;
	int _direction; int lenght = 3; int _dir;
	
public:	
	Image image_snake;
	Texture texture_snake;
	Sprite sprite_snake;

	Snake(Image &image, float W, float H, sf::RenderWindow&);
	float w, h; 
	void move(int);
	virtual void draw();

	void grow();
	void shrink();
	int Lenght();
	list<Block> getBlocks();

	int getX();
	int getY();



};

#endif