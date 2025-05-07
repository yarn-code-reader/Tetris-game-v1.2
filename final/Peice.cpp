#include "Peice.h"

	 void Peice:: setAtt() {
		sizeOfBlock = 20;
		x = 240;
		y = 100;

		int temp[4][2] = {
	   {0,1},
	   {1,1},
	   {2,1},
	   {3,1}
		};

		for (int i = 0; i < 4; i++) {

			shape[i][0] = temp[i][0];
			shape[i][1] = temp[i][1];

		}
	}

	void  Peice:: draw(sf::RenderWindow& window) {

		float globalX = 0, globalY = 0, setx = x, sety = y;
		for (int i = 0; i < 4; i++)
		{
			setx = (shape[i][0] * sizeOfBlock) + x;
			sety = (shape[i][1] * sizeOfBlock) + y;
			sprite.setPosition({ setx, sety });
			window.draw(sprite);
		}
	}

	void  Peice:: moveDown() {
		y += sizeOfBlock;
	}

	void  Peice:: moveUp() {
		y -= sizeOfBlock;
	}

	void  Peice:: moveLeft() {
		x -= sizeOfBlock;
	}

	void Peice:: moveRight() {
		x += sizeOfBlock;
	}

	// Getter for x
	float  Peice:: getX()  {
		return x;
	}

	// Setter for x
	void  Peice:: setX(float newX) {
		x = newX;
	}

	// Getter for y
	float  Peice:: getY()  {
		return y;
	}

	// Setter for y
	void  Peice:: setY(float newY) {
		y = newY;
	}

	// Getter for rotationState
	int Peice:: getRotationState()  {
		return rotationState;
	}

	// Setter for rotationState
	void Peice:: setRotationState(int newRotationState) {
		rotationState = newRotationState;
	}


