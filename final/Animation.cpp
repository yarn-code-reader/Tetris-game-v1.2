#include "Animation.h"
//not putting  frames in constructor 
Animation :: Animation()
    : totalTime(0.0f), animFrame(0), animationLock(false) {
   /* for (int i = 0; i < 3; i++) {
        sf::Sprite tempSprite(textures[i][0]);  // Create a temporary sprite object
        frames.push_back(tempSprite);  // Add the initialized sprite to the vector
    }*/
}

void Animation:: update(float deltaTime) {
    totalTime += deltaTime;
    if (totalTime >= animStepDur) {
        totalTime -= animStepDur;
        animFrame++;
        if (animFrame >= 3) {
            animationLock = false;
        }
    }
}

void Animation::reset() {
    animationLock = true;
    totalTime = 0;
    animFrame = 0;
}


float Animation::getTotalTime() const
{
    return totalTime;
}

int Animation::getAnimFrame() const
{
    return animFrame;
}

float Animation::getAnimStepDur() const
{
    return animStepDur;
}

bool Animation::isAnimationLocked() const
{
    return animationLock;
}

// Setter implementations
void Animation::setTotalTime(float time)
{
    totalTime = time;
}

void Animation::setAnimFrame(int frame)
{
    animFrame = frame;
}

void Animation::setAnimStepDur(float duration)
{
    animStepDur = duration;
}

void Animation::setAnimationLock(bool locked)
{
    animationLock = locked;
}