#include "Pause.h"

Pause::Pause(std::string bgTexture = "allTextures\\default.png") : currentSpriteCount(0){
    bg.loadFromFile(bgTexture);
}
   
void  Pause:: drawScreen(sf::RenderWindow& win){
    cout << "Pause screen drawing" << endl;
    Sprite menuKaBg(bg);
    //scaling kar rahe take scren pa sab fit aa sake
    float x = win.getSize().x, y = win.getSize().y;
    menuKaBg.scale({ x / bg.getSize().x,  y / bg.getSize().y });

   
    // draw background
    win.draw(menuKaBg);

}
