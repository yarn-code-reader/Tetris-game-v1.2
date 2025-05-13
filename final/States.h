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
    static bool highscoreOpen;
    static bool scoreboardOpen;

    int noOfButtons;
    std::vector<Texture> textures;
    std::vector<Sprite> sprites;
    std::vector<int>statesOfBtn;
    Texture bg;
    
public:
    States();
    States(int noOfB, std::vector<Texture> texture, std::string bg);
    // Getters
    static bool isMenuOpen();
    static bool isOptionsOpen();
    static bool isHtpOpen();
    static bool isGameOpen();
    static bool shouldExit();
    static bool isPauseScreenOpen();
    static bool isScoreboardOpen();
    static bool isHighscoreOpen();

    // Setters
    static void setMenuOpen(bool open);
    static void setPauseScreenOpen(bool open);
    static void setOptionsOpen(bool open);
    static void setHtpOpen(bool open);
    static void setGameOpen(bool open);
    static void setExit(bool shouldExit);
    static void setHighscore(bool shouldExit);
    static void setScoreboard(bool shouldExit);
     virtual int onButtonClick(int index);
      
    void checkEvents(sf::RenderWindow& win);

    void updateStates(int i) {
          
            if (statesOfBtn[i] == 0)
            {
                sprites[i].setTextureRect((sf::IntRect({ 0, 0 }, { 144, 127 })));
            }
            else if (statesOfBtn[i] == 1)
            {
                sprites[i].setTextureRect((sf::IntRect({ 0, 127 }, { 144, 127 })));
            }
            else if (statesOfBtn[i] == 2)
            {
                sprites[i].setTextureRect((sf::IntRect({ 0, 254 }, { 144, 127 })));
            }
    }

    virtual void drawScreen(RenderWindow& win);
};