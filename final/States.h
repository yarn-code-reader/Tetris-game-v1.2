#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
class States
{
protected:
    static bool menuOpen;
    static bool optionsOpen;
    static bool htpOpen;
    static bool exit;
    static bool gameOpen;
    static bool pauseScreenOpen;

    int noOfButtons;
    std::vector<std::vector<Texture>> textures;
    std::vector<Sprite> sprites;
    std::vector<int>statesOfBtn;
    Texture bg;
    
public:
    States();
    States(int noOfB, std::vector<std::vector<Texture>> texture, std::string bg);
    // Getters
    static bool isMenuOpen();
    static bool isOptionsOpen();
    static bool isHtpOpen();
    static bool isGameOpen();
    static bool shouldExit();
    static bool isPauseScreenOpen();

    // Setters
    static void setMenuOpen(bool open);
    static void setPauseScreenOpen(bool open);
    static void setOptionsOpen(bool open);
    static void setHtpOpen(bool open);
    static void setGameOpen(bool open);
    static void setExit(bool shouldExit);

     virtual int onButtonClick(int index);
    void checkEvents(sf::RenderWindow& win);

    void updateStates(int i , int state) {
        
            statesOfBtn[i] = state;
            sprites[i].setTexture(textures[i][statesOfBtn[i]]);
    }

    virtual void drawScreen(RenderWindow& win);
};