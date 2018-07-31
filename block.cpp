/*
*  block.cpp
*  snake
*
*  Created by Mathieu Allaire on 11-01-23.
*  Copyright 2011 mathieuallaire.ca. All rights reserved.
*
*/

#include "block.h"
#include <SFML/Graphics.hpp>
using namespace std;

Block::Block(float x, float y, int dir)
{
	_x = x;
	_y = y;
	_dir = dir;
}

int Block::getX()
{
	return _x;
}

int Block::getY()
{
	return _y;
}
int Block::DIR()
{
	return _dir;
}