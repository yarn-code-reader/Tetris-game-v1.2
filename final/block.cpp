#include "block.h"
block::block(string t = "allTextures\\blockOfGrid.png") :texture(t), sprite(texture){
	if (!t.empty()) {
		texture.loadFromFile(t);
		sprite.setTexture(texture);
	}
}

block::block() : texture("allTextures\\blockOfGrid.png"), sprite(texture) {}

void block::setSprite(string s) {
	texture.loadFromFile(s);
	sprite.setTexture(texture);
}

void block::scale(float reqX, float reqY) {
	sprite.scale({ reqX / texture.getSize().x,  reqY / texture.getSize().y });
}

void block::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

Sprite block::getSprite() {
	return sprite;
}

void block::setP(float nx, float ny) {
	sprite.setPosition({ nx, ny });
}
