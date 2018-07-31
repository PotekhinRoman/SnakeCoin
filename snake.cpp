/*
*  snake.cpp
*  snake
*
*  Created by Mathieu Allaire on 11-01-23.
*  Copyright 2011 mathieuallaire.ca. All rights reserved.
*
*/

#include <SFML/Graphics.hpp>

#include "snake.h"
#include "block.h"
#include <iostream>

using namespace std;
using namespace sf;
Snake::Snake(Image &image, float W, float H, sf::RenderWindow &App)
{
	_app = &App;
	_direction = RIGHT;
	W = w; H = h;
	image.createMaskFromColor(Color(100, 100, 100));
	texture_snake.loadFromImage(image);
	sprite_snake.setTexture(texture_snake);
	sprite_snake.setOrigin(w / 2, h / 2);

	// Draws the initial snake
	_snake.push_front(Block(30, 0, RIGHT));
	_snake.push_front(Block(60, 0, RIGHT));
	_snake.push_front(Block(90, 0, RIGHT));
}

void Snake::move(int newDirection)
{


	if (newDirection == UP)
	{
		if (_direction != DOWN)
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() - 30, UP));
			
			_direction = UP;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() + 30, UP));
			
		}
	}

	else if (newDirection == RIGHT)
	{
		if (_direction != LEFT)
		{
			_snake.push_front(Block(_snake.front().getX() + 30, _snake.front().getY(), RIGHT));

			_direction = RIGHT;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX() - 30, _snake.front().getY(), RIGHT));
			
		}
	}

	else if (newDirection == DOWN)
	{
		if (_direction != UP)
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() + 30, DOWN));
			
			_direction = DOWN;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX(), _snake.front().getY() - 30, DOWN));
			
		}

	}

	else if (newDirection == LEFT)
	{
		if (_direction != RIGHT)
		{
			_snake.push_front(Block(_snake.front().getX() - 30, _snake.front().getY(), LEFT));
			
			_direction = LEFT;
		}
		else
		{
			_snake.push_front(Block(_snake.front().getX() + 30, _snake.front().getY(), LEFT));
			
		}
	}
	_snake.pop_back();
}


inline void Snake::draw()
{
	for (list<Block>::iterator it = _snake.begin(); it != _snake.end(); it++)
	{
		float x = it->getX();
		float y = it->getY();
switch (it->DIR())
	{
	case RIGHT:
		h = 0;
		break;
	case LEFT:
		h = 30;
		break;
	case DOWN:
		h = 60;
		break;
	case UP:
		h = 90;
		break;
	}
		sprite_snake.setTextureRect(IntRect(0, h, 30, 30));
		sprite_snake.setPosition(x, y);
		_app->draw(sprite_snake);
	}
}

void Snake::grow()
{
	
	_snake.push_back(Block(_snake.back().getX(), _snake.back().getY(), _direction));
	lenght++;
}

void Snake::shrink()
{
	_snake.pop_back();
}

list<Block> Snake::getBlocks()
{
	return _snake;
}

int Snake::getX()
{
	return _snake.front().getX();
}

int Snake::getY()
{
	return _snake.front().getY();
}
int Snake::Lenght()
{
	return lenght;
}