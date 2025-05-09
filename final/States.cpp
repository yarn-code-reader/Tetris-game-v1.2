#include "States.h"
#include <iostream>
using namespace std;

States :: States(){}
//{} basically initalizes a 2d vector of textuere emty textures
States::States(int noOfB = 0, std::vector<std::vector<Texture>> texture = {}, std::string bg = "allTextures\\default.png") : noOfButtons(noOfB) , bg(bg){
    //now copying 2d vectos of texture into each other

    for (int i = 0; i < noOfButtons; i++)
    {
        for (int j = 0; j < 3;j++) {
            textures[i][j] = texture[i][j];
        }
    }

    //initalizing my sprites into the 1st state of buttons
    //states of button by deafult normal ha yaini ka 0
    for (int i = 0; i < noOfButtons; i++)
    {
        sprites[i].setTexture(textures[i][0]);
        statesOfBtn[i] = 0;
    }

}
// Initialize static members (important!)
bool States::menuOpen = false;
bool States::optionsOpen = false;
bool States::htpOpen = false;
bool States::exit = false;
bool States::gameOpen = false;
bool States::pauseScreenOpen = false;
// Getter implementations
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

int States::onButtonClick(int index) {
    return 0;
};

void States::checkEvents(sf::RenderWindow& win) {
    if (const std::optional myevent = win.pollEvent())
    {
        Vector2i mousePos = Mouse::getPosition(win);
        /// \note Converting the mouse position to world coordinates (if needed for sprites, buttons, etc.)
        Vector2f mouseWorldPos = win.mapPixelToCoords(mousePos);

        if (myevent->is<sf::Event::Closed>())
            win.close();
        else if (auto* keyPressed = myevent->getIf<sf::Event::MouseButtonPressed>())
        {
            for (int i = 0; i < noOfButtons; i++)
            {
                if (sprites[i].getGlobalBounds().contains(mouseWorldPos) )
                {
                    if (onButtonClick(i) < 0) {
                        win.close();
                    }
                    break;
                }
            }
        }

    }
}