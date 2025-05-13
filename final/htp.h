#pragma once
#include "States.h"
class htp :
    public States
{

public:
	htp();
	htp(std::string bgTexture, std::vector<Texture> texture, int noOfB);
	void drawScreen(sf::RenderWindow& win);
	int onButtonClick(int index);
};

