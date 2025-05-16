#pragma once
#include "States.h"
#include<fstream>
#include <iostream>
using namespace std;
class Highscore :
    public States
{
	vector<int> data;
	Text highscoreonscreen;
	Font font;
	std::fstream file;
	string filepath;

public:
	Highscore(std::string bgTexture, std::vector<Texture> texture, int noOfB, string filepath, string f );
	void drawScreen(sf::RenderWindow& win);
	int onButtonClick(int index);

};

