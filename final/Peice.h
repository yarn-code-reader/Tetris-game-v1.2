#pragma once
#include "block.h"
#include "GlobalVar.h"

class Peice : public block
{
protected:
	int type;
	int shape[4][2];
	float x;
	float y;
	int rotationState = 1;

public:

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

	virtual int getType() {
		return type;
	}

	void setType(int n) {
		type = n;
	}
	int(&getShape())[4][2]{
	return shape;
	}

		void setSpriteOfPeice(block allBlocks) {
		for (int i = 0; i < 4; i++)
		{
			this->sprite = allBlocks.getSprite();
			sprite.scale({ scaleConstantOfBlocks , scaleConstantOfBlocks });
		}
	}
};


