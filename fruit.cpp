/*
*  fruit.cpp
*  snake
*
*  Created by Mathieu Allaire on 11-01-24.
*  Copyright 2011 mathieuallaire.ca. All rights reserved.
*
*/

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "fruit.h"

using namespace std;
using namespace sf;
Fruit::Fruit(Image &image, float W, float H, sf::RenderWindow &App)
{
	_app = &App;
	W = w; H = h;

	image.createMaskFromColor(Color(0, 0, 0));
	texture_block.loadFromImage(image);
	sprite_block.setTexture(texture_block);
	sprite_block.setOrigin(w / 2, h / 2);
	sprite_block.setTextureRect(IntRect(0, 0, 30, 30));
}

void Fruit::spawn(float x, float y)
{
	sf::RectangleShape block(sf::Vector2f(30, 30));
	sprite_block.setPosition(x, y);
	_x = x;
	_y = y;
	_app->draw(sprite_block);
}

float Fruit::getX()
{
	return _x;
}

float Fruit::getY()
{
	return _y;
}