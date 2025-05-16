#pragma once
#include "States.h"
class Option :
    public States
{
	private:
		Sound* bgSound;
		bool soundOn;

public:
	Option();
	Option(std::string bgTexture, std::vector<Texture> texture, int noOfB, Sound* s);
	void drawScreen(sf::RenderWindow& win);
	int onButtonClick(int index);

};

