#include "Option.h"
#include <iostream>
using namespace std;
Option::Option() {}
Option::Option(std::string bgTexture = "allTextures\\default.png", std::vector<Texture> texture = {}, int noOfB = 0, Sound* s = nullptr) : bgSound(s), States(noOfB, texture, bgTexture) {
    for (int i = 0; i < noOfButtons; i++)
    {
        sprites[i].scale({ 1.5, 1.5 });
    }
    soundOn = true;
}

void Option::drawScreen(sf::RenderWindow& win) {
   
    States::drawScreen(win);
    float x = win.getSize().x, y = win.getSize().y;

    for (int i = 0; i < noOfButtons; i++)
    {
        float btnWidth = sprites[i].getGlobalBounds().size.x;
        float btnHeight = sprites[i].getGlobalBounds().size.y;

        // Calculate x and y positions
           // Calculate x and y positions
        float xbtn = 50;   // Center horizontally (assuming 800 window width)
        float ybtn = 50 + (i * (btnHeight + 15));  // Vertical spacing based on button height

        // Set position and draw
        if (statesOfBtn[i] == 0)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 0 }, { 144, 65 })));
        }
        else if (statesOfBtn[i] == 1)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 98 }, { 144, 65 })));
        }
        else if (statesOfBtn[i] == 2)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 194 }, { 144, 258 })));
        }
        sprites[i].setPosition({ xbtn, ybtn });
        win.draw(sprites[i]);
    }
}
int Option::onButtonClick(int index) {
    switch (index) {
    case 0:
        menuOpen = true; optionsOpen = false; break;
    case 1:
  /* if(bgSound != nullptr && soundOn) {
        bgSound->setVolume(0);
   }
   else if(bgSound != nullptr && !soundOn){
       bgSound->setVolume(100);
   }*/


    default:
        break;
    }
    return 0;
}