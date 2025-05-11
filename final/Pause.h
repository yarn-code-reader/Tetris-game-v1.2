#pragma once
#include "States.h"
#include <iostream>
using namespace std;

class Pause : public States
{
    int currentSpriteCount;
public:
    Pause(std::string bgTexture );

	void drawScreen(sf::RenderWindow& win);

    void checkevents(RenderWindow& win)
    {
        cout << "pause scheck events" << endl;
        while (const std::optional event = win.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                win.close();

            else if (auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
               
                    if (keyPressed->scancode == sf::Keyboard::Scancode::P)
                    {
                        pauseScreenOpen = false;
                        gameOpen = true;
                    }
                
            }
        }
    }
};

