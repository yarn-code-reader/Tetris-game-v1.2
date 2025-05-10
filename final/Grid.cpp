#include "Grid.h"
#include "GlobalVar.h"

Grid::Grid(float sx = 0, float sy = 0, int maxR = 0, int maxC = 0 ):
startx(sx), starty(sy), maxRow(maxR), maxCol(maxC) {}


void Grid::setBlockArray(block arr_blocks[8]) {
	for (int i = 0; i < 8; i++)
	{
		allBlock[i] = arr_blocks[i];
	}
}

void Grid:: print() {
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << activity_status[i][j] << " ";
		}
		cout << endl;
	}
}

void Grid:: draw(sf::RenderWindow& window) {
	// Set the position of the block to (0, 0) before drawing
	float setx = startx, sety = starty;
	for (int i = 0; i < maxRow; i++)
	{
		setx = startx + sizeOfBlock;
		for (int j = 0; j < maxCol; j++)
		{
			Sprite sp = allBlock[activity_status[i][j]].getSprite();
			sp.setPosition({ setx, sety });
			sp.scale({ scaleConstantOfBlocks , scaleConstantOfBlocks });
			window.draw(sp);
			setx += sizeOfBlock;
		}
		sety += sizeOfBlock;

	};
}


void Grid::resetGrid() {
	for (int i = 0; i < maxRow; i++)
	{
		for (int j = 0; j < maxCol; j++)
		{
			activity_status[i][j] = 0;
		}
	}
}



