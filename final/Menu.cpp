#include "Menu.h"
#include <SFML/Audio.hpp>
Menu :: Menu(){}
Menu ::Menu(std::string bgTexture = "allTextures\\default.png", vector<Texture> texture = {}, int noOfB = 0, Sound* s = nullptr) :bgSound(s), States(noOfB, texture, bgTexture) {
    for (int i = 0; i < noOfButtons; i++)
    {
        sprites[i].scale({ 0.75, 0.75 });
    }
    if (bgSound) {
        
        bgSound->play();
        bgSound->setLooping(true);
    }

}



void Menu::drawScreen(sf::RenderWindow& win) {
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
            sprites[i].setTextureRect((sf::IntRect({ 0, 0 }, { 144, 127 })));
        }else if (statesOfBtn[i] == 1)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 127 }, { 144, 127 })));
        }else if (statesOfBtn[i] == 2)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 254 }, { 144, 127 })));
        }
        sprites[i].setPosition({ xbtn, ybtn });
        win.draw(sprites[i]);
    }
}
int Menu ::  onButtonClick(int index)  {
    std::cout << "on btn click of menu" << endl;;
    switch (index) {
    case 0:
        cout << "in menu.cpp " << bgSound->getVolume() << endl;
        gameOpen = true; menuOpen = false; break;
    case 1:
        optionsOpen = true; menuOpen = false; break;
    case 2: 
        cout << "htp true " << endl;
        htpOpen = true; menuOpen = false; break;
    case 3:

        highscoreOpen = true; menuOpen = false; break;
    case 4: 
        if (bgSound) {
        bgSound->stop();
    }
        return -1;
    default: 
       
        break;
    }
    return 0;
}