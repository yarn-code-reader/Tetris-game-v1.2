#include "Scoreboard.h"
Scoreboard::Scoreboard(){}
Scoreboard::Scoreboard(std::string bgTexture = "allTextures\\default.png", std::vector<Texture> texture = {}, int noOfB = 0) : States(noOfB, texture, bgTexture) {
    for (int i = 0; i < noOfButtons; i++)
    {
       sprites[i].scale({ 1.5, 1.5 });
    }
}
void Scoreboard::drawScreen(sf::RenderWindow& win) {
    States::drawScreen(win);
    float x = win.getSize().x, y = win.getSize().y;
    
    for (int i = 0; i < noOfButtons; i++)
    {
        float btnWidth = sprites[i].getGlobalBounds().size.x;
        float btnHeight = sprites[i].getGlobalBounds().size.y;

        // Calculate x and y positions
        float xbtn = (x - btnWidth) / 2;   // Center horizontally (assuming 800 window width)
        float ybtn = 120.0 + (i * (btnHeight + 15));  // Vertical spacing based on button height

        // Set position and draw
        if (statesOfBtn[i] == 0)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 0 }, { 144, 130 })));
        }
        else if (statesOfBtn[i] == 1)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 135 }, { 144, 128 })));
        }
        else if (statesOfBtn[i] == 2)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 270 }, { 144, 145 })));
        }
        sprites[i].setPosition({ xbtn, ybtn });
        win.draw(sprites[i]);
    }
}
int Scoreboard::onButtonClick(int index) {
    switch (index) {
    case 0:
       // gameOpen = true; scoreboardOpen = false; break;
    case 1:
       // scoreboardOpen = false; menuOpen = true; break;
    default:
        break;
    }
    return 0;
}