/*
*  block.h
*  snake
*
*  Created by Mathieu Allaire on 11-01-23.
*  Copyright 2011 mathieuallaire.ca. All rights reserved.
*
*/

#ifndef _BLOCK_
#define _BLOCK_
#include <SFML/Graphics.hpp>
using namespace std;

class Block
{
private:
	int _x;
	int _y;
	int _dir;
public:

	Block(float x, float y, int dir);
	int getX();
	int getY();
	int DIR();
};

#endif