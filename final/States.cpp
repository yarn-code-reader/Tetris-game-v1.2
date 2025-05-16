#include "States.h"
#include <iostream>
using namespace std;

States :: States(){}


//{} basically initalizes a 2d vector of textuere emty textures
States::States(int noOfB = 0, vector<Texture> texture = {}, std::string bg = "allTextures\\default.png"  ) : noOfButtons(noOfB), bg(bg) {
    //now copying 2d vectos of texture into each other

    //now we need to resize the vectors to acess them warna error aa jaiga
    textures.resize(noOfButtons);
    statesOfBtn.resize(noOfButtons);

    for (int i = 0; i < noOfButtons; i++)
    {
            textures[i] = texture[i];        
    }

    //initalizing my sprites into the 1st state of buttons
    //states of button by deafult normal ha yaini ka 0
    // issue is that default constructor for sprites doesnt exist 
    for (int i = 0; i < noOfButtons; i++) {
        sf::Sprite tempSprite(textures[i]);  // Create a temporary sprite object
        sprites.push_back(tempSprite);  // Add the initialized sprite to the vector
        statesOfBtn.push_back(0);  // Set the initial state to normal (0)
    }
}
// Initialize static members (important!)
bool States::menuOpen = true;
bool States::optionsOpen = false;
bool States::htpOpen = false;
bool States::exit = false;
bool States::gameOpen = false;
bool States::pauseScreenOpen = false;
 bool States:: highscoreOpen = false;
 bool States::scoreboardOpen = false;

// Getter implementations

 void States:: drawScreen(RenderWindow& win) {
    Sprite ScreenKaBg(bg);
    //scaling kar rahe take scren pa sab fit aa sake
    float x = win.getSize().x, y = win.getSize().y;
    ScreenKaBg.scale({ x / bg.getSize().x,  y / bg.getSize().y });

    win.clear();

    // draw background
    win.draw(ScreenKaBg);
    

}
bool States::isMenuOpen() {
    return menuOpen;
}

bool States::isPauseScreenOpen() {
    return pauseScreenOpen;
}
bool States::isOptionsOpen() {
    return optionsOpen;
}

bool States::isHtpOpen() {
    return htpOpen;
}

bool States::isGameOpen() {
    return gameOpen;
}

bool States::isScoreboardOpen() {
    return scoreboardOpen;
}

bool States::isHighscoreOpen() {
    return highscoreOpen;
}
bool States::shouldExit() {
    return exit;
}

// Setter implementations
void States::setMenuOpen(bool open) {
    menuOpen = open;
}

void States::setPauseScreenOpen(bool open) {
    pauseScreenOpen = open;
}

void States::setOptionsOpen(bool open) {
    optionsOpen = open;
}

void States::setHtpOpen(bool open) {
    htpOpen = open;
}

void States::setGameOpen(bool open) {
    gameOpen = open;
}

void States::setExit(bool shouldExit) {
    exit = shouldExit;
}

void States::setScoreboard(bool shouldExit) {
    scoreboardOpen = shouldExit;
}

void States::setHighscore(bool shouldExit) {
    highscoreOpen = shouldExit;
}

int States::onButtonClick(int index) {
    cout << "on btn click of states" << endl;
    return 0;
};

void States::checkEvents(sf::RenderWindow& win) {
    if (const std::optional myevent = win.pollEvent())
    {
        Vector2i mousePos = Mouse::getPosition(win);
        /// \note Converting the mouse position to world coordinates (if needed for sprites, buttons, etc.)
        Vector2f mouseWorldPos = win.mapPixelToCoords(mousePos);

        for (int i = 0; i < noOfButtons; i++)
        {
            if (sprites[i].getGlobalBounds().contains(mouseWorldPos))
            {
                // hover state
                statesOfBtn[i] = 1;
                break;
            }
            else {
                //orignal state
                statesOfBtn[i] = 0;
            }
        }

        if (myevent->is<sf::Event::Closed>())
            win.close();
        else if (auto* keyPressed = myevent->getIf<sf::Event::MouseButtonPressed>())
        {
            for (int i = 0; i < noOfButtons; i++)
            {
                if (sprites[i].getGlobalBounds().contains(mouseWorldPos) )
                {
                    //preseed state
                    statesOfBtn[i] = 2;
                   updateStates(i);
                    win.draw(sprites[i]);
                    win.display();
                    sleep(milliseconds(500));
                    if (onButtonClick(i) < 0) {
                        win.close();
                    }
                    break;
                }
            }
           // cout << "----------------------" << endl << endl;
        }

    }
}

void States::  updateStates(int i) {

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
