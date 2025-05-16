#pragma once
#include "States.h"
class Scoreboard : public States
{
    Font font;
    sf::Text Sos;
public:
	Scoreboard(std::string bgTexture, std::vector<Texture> texture, int noOfB, std::string f);
	void drawScreen(sf::RenderWindow& win, int s);
	int onButtonClick(int index);
	void updateStates(int i);
};

