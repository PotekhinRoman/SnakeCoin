/*
*  fruit.h
*  snake
*
*  Created by Mathieu Allaire on 11-01-24.
*  Copyright 2011 mathieuallaire.ca. All rights reserved.
*
*/

#ifndef _FRUIT_
#define _FRUIT_

#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Fruit
{
private:
	sf::RenderWindow *_app;
	float _x;
	float _y;
public:
	Image image_block;
	Texture texture_block;
	Sprite sprite_block;
	Fruit(Image &image, float W, float H, sf::RenderWindow&);
	float w, h;
	void spawn(float, float);

	float getX();
	float getY();
};

#endif#pragma once
