#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GlobalVar.h"

using namespace std;
using namespace sf;

class block
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	block();
	block(string t);

	void setSprite(string s);

	void scale(float reqX, float reqY);

	void draw(sf::RenderWindow& window);

	Sprite getSprite();

	void setP(float nx, float ny);

};
