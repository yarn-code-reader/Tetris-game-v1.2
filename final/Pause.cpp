#include "Pause.h"

Pause::Pause(std::string bgTexture = "allTextures\\default.png", block b[8] = {}) : currentSpriteCount(0) {
    bg.loadFromFile(bgTexture);
	for (int i = 0; i < 8; i++)
	{
		allblock[i] = b[i];
	}
}


