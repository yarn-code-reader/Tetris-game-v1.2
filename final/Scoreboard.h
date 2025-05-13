#pragma once
#include "States.h"
class Scoreboard : public States
{
public:
	Scoreboard();
	Scoreboard(std::string bgTexture, std::vector<Texture> texture, int noOfB);
	void drawScreen(sf::RenderWindow& win);
	int onButtonClick(int index);
};

