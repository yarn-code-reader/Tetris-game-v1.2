#pragma once
#include "block.h"
class Peice : public block
{
protected:
	int type;
	int shape[4][2];
	float x;
	float y;
	int rotationState = 1;

public:

	virtual void setAtt();
	virtual	void rotate(int temp[4][2]) = 0;

	void draw(sf::RenderWindow& window);
	void moveDown();

	void moveUp();

	void moveLeft();

	void moveRight();
	// getters 

	
    // Getter for x
    float getX();

    // Setter for x
    void setX(float newX);

    // Getter for y
    float getY();

    // Setter for y
    void setY(float newY);

    // Getter for rotationState
	int getRotationState();

    // Setter for rotationState
	void setRotationState(int newRotationState);
};


