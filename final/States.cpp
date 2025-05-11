#include "States.h"
#include <iostream>
using namespace std;

States :: States(){}
//{} basically initalizes a 2d vector of textuere emty textures
States::States(int noOfB = 0, std::vector<std::vector<Texture>> texture = {}, std::string bg = "allTextures\\default.png") : noOfButtons(noOfB) , bg(bg){
    //now copying 2d vectos of texture into each other

    //now we need to resize the vectors to acess them warna error aa jaiga
    textures.resize(noOfButtons, std::vector<Texture>(3));
    statesOfBtn.resize(noOfButtons);

    for (int i = 0; i < noOfButtons; i++)
    {
        for (int j = 0; j < 3;j++) {
            textures[i][j] = texture[i][j];
        }
    }

    //initalizing my sprites into the 1st state of buttons
    //states of button by deafult normal ha yaini ka 0
    // issue is that default constructor for sprites doesnt exist 
    for (int i = 0; i < noOfButtons; i++) {
        sf::Sprite tempSprite(textures[i][0]);  // Create a temporary sprite object
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
// Getter implementations

 void States:: drawScreen(RenderWindow& win) {
    cout << "draw screen of base class" << endl;
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
                updateStates(i,1);
                break;
            }
            else {
                updateStates(i, 0);
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
                   updateStates(i, 2);
                    win.draw(sprites[i]);
                    win.display();
                    sleep(milliseconds(5000));
                    if (onButtonClick(i) < 0) {
                        win.close();
                    }
                    break;
                }
            }
            cout << "----------------------" << endl << endl;
        }

    }
}