#pragma once
#include "States.h"
#include "block.h"
#include "GlobalVar.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

class Pause : public States
{
    int currentSpriteCount;
    int maxCount = 50;
    float MAX_SPEED = 5;
    block allblock[8];
    vector<Vector2f> vel;

public:
    Pause(std::string bgTexture, block b[8]);
    void drawScreen(sf::RenderWindow& win);
    void create_a_sprite();
    void moveSprite(Sprite& s, int i);
    void checkevents(RenderWindow& win);
};

