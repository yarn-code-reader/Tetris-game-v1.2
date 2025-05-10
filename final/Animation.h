#pragma once
#include "Peice.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation
{
    vector<Sprite> frames;
    float totalTime;
    int animFrame = 0;
    float animStepDur = 0.1;
    bool animationLock = false;

public:
    Animation();
    void update(float deltaTime);
    void reset();

    float getTotalTime() const;
    int getAnimFrame() const;
    float getAnimStepDur() const;
    bool isAnimationLocked() const;

    // Setters
    void setTotalTime(float time);
    void setAnimFrame(int frame);
    void setAnimStepDur(float duration);
    void setAnimationLock(bool locked);


    vector<Sprite>& getFrames() {
        return frames;
    }
    void setRectangles(Sprite pic1, Sprite pic2, Sprite  pic3) {
        sf::Sprite tempSprite(pic1);  // Create a temporary sprite object
        frames.push_back(tempSprite);

        sf::Sprite tempSprite1(pic2);  // Create a temporary sprite object
        frames.push_back(tempSprite1);

        sf::Sprite tempSprite2(pic3);  // Create a temporary sprite object
        frames.push_back(tempSprite2);
    }
};