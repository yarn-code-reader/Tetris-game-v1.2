#pragma once
#include <iostream>
#include <vector>
#include "States.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Menu : public States
{
private:
	Sound* bgSound;
public:
	// default constructor
	Menu();
	Menu(std::string bgTexture,vector<Texture> texture , int noOfB, Sound* s);
	void drawScreen(sf::RenderWindow& win);
	int onButtonClick(int index) ;
};

