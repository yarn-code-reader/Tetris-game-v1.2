#include <iostream>
#include <string>
#include "Scoreboard.h"
Scoreboard::Scoreboard(std::string bgTexture = "allTextures\\default.png", std::vector<Texture> texture = {}, int noOfB = 0, std::string fontPath= "") : font(fontPath), Sos(font , "0", 100), States(noOfB, texture, bgTexture) {
    for (int i = 0; i < noOfButtons; i++)
    {
       sprites[i].scale({ 1.5, 1.5 });
    }

    Sos.setFillColor(Color(17, 62, 42));

}
void Scoreboard::updateStates(int i) {
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
        sprites[i].setTextureRect((sf::IntRect({ 0, 270 }, { 144, 128 })));
    }
}
void Scoreboard::drawScreen(sf::RenderWindow& win, int score) {
    States::drawScreen(win);
    float x = win.getSize().x, y = win.getSize().y;
    Sos.setString(std::to_string(score));
    Sos.setPosition({ x /2 + 50, 250 });

    for (int i = 0; i < noOfButtons; i++)
    {
        float btnWidth = sprites[i].getGlobalBounds().size.x;
        float btnHeight = sprites[i].getGlobalBounds().size.y;

        // Calculate x and y positions
        float xbtn = ( 40+ btnWidth)+(i * (btnWidth + 30));   // Center horizontally (assuming 800 window width)
        float ybtn = 360.0 ; 

        // Set position and draw
        updateStates(i);
        sprites[i].setPosition({ xbtn, ybtn });
        win.draw(sprites[i]);
    }
    win.draw(Sos);
}


int Scoreboard::onButtonClick(int index) {
    switch (index) {
    case 0:
       gameOpen = true; scoreboardOpen = false; break;
    case 1:
        scoreboardOpen = false; menuOpen = true; break;
    default:
        break;
    }
    return 0;
}