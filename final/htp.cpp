#include "htp.h"
#include <iostream>
using namespace std;
htp::htp() {}
htp::htp(std::string bgTexture = "allTextures\\default.png", std::vector<Texture> texture = {}, int noOfB = 0) : States(noOfB, texture, bgTexture) {
    for (int i = 0; i < noOfButtons; i++)
    {
        sprites[i].scale({ 1.5, 1.5 });
    }
}



void htp::drawScreen(sf::RenderWindow& win) {
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
int htp::onButtonClick(int index) {
    switch (index) {
    case 0:
        menuOpen = true; htpOpen = false; break;
   
    default:
        break;
    }
    return 0;
}