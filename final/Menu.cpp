#include "Menu.h"
Menu :: Menu(){}
Menu ::Menu(std::string bgTexture = "allTextures\\default.png", vector<vector<Texture>> texture = {}, int noOfB = 0) : States(noOfB, texture, bgTexture) {
    for (int i = 0; i < noOfButtons; i++)
    {
        sprites[i].scale({ 0.75, 0.75 });
    }
}



void Menu::drawScreen(sf::RenderWindow& win) {
    Sprite menuKaBg(bg);
    //scaling kar rahe take scren pa sab fit aa sake
    float x = win.getSize().x, y = win.getSize().y;
    menuKaBg.scale({ x / bg.getSize().x,  y / bg.getSize().y });

    win.clear();

    // draw background
    win.draw(menuKaBg);
    // draw buttons 

    for (int i = 0; i < noOfButtons; i++)
    {
        float btnWidth = sprites[i].getGlobalBounds().size.x;
        float btnHeight = sprites[i].getGlobalBounds().size.y;

        // Calculate x and y positions
        float xbtn = (x - btnWidth) / 2;   // Center horizontally (assuming 800 window width)
        float ybtn = 120.0 + (i * (btnHeight + 15));  // Vertical spacing based on button height

        // Set position and draw
        sprites[i].setPosition({ xbtn, ybtn });
        win.draw(sprites[i]);
    }
}
int Menu ::  onButtonClick(int index)  {
    std::cout << "on btn click of menu" << endl;;
    switch (index) {
    case 0:
        gameOpen = true; menuOpen = false; break;
    case 1:
        optionsOpen = true; menuOpen = false; break;
    case 2: 
        htpOpen = true; menuOpen = false; break;
    case 3: 
        return -1;
    default: 
        break;
    }
    return 0;
}