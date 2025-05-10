#pragma once
#include "block.h"
class Grid 
{
public:
	int activity_status[20][10] = { 0 };
	float startx;
	float starty;
	int maxRow ;
	int maxCol ;
	block allBlock[8];

public:
	Grid(float sx, float sy, int maxR, int maxC);
	void print();
	void draw(sf::RenderWindow& window);
	void setBlockArray(block b[8]);
	void resetGrid();
	block& getAllBlocks(int i) {
		return allBlock[i];
	}

	float getStartx() {
		return startx;
	}

	float getStarty() {
		return starty;
	}
};


