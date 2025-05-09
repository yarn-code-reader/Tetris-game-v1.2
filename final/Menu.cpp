#include "Menu.h"
Menu :: Menu(){}
Menu ::Menu(std::string bgTexture = "allTextures\\default.png", vector<vector<Texture>> texture = {}, int noOfB = 0) : States(noOfB, texture, bgTexture) {}

int Menu ::  onButtonClick(int index)  {
    std::cout << "sdjvkvjkds";
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