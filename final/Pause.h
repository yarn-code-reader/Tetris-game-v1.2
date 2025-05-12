#pragma once
#include "States.h"
#include "block.h"
#include "GlobalVar.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

class Pause : public States
{
    int currentSpriteCount;
    int maxCount = 50;
    float MAX_SPEED = 5;
    block allblock[8];
    vector<Vector2f> vel;

public:
    Pause(std::string bgTexture, block b[8]);

    void drawScreen(sf::RenderWindow& win) {
        States::drawScreen(win);
        //scaling kar rahe take scren pa sab fit aa sake

        // now to draw random blocks which keep increasing in number till they reach a 
        //max value

        if (currentSpriteCount < maxCount)
        {
            create_a_sprite();
        }



        //move all random squares
        for (int i = 0; i < currentSpriteCount; i++)
        {
            moveSprite(sprites[i], i);
        }


        // draw background

        // draw all the squares
        for (int i = 0; i < currentSpriteCount; i++)
        {
            
            win.draw(sprites[i]);
        }

    }

    void create_a_sprite() {
       // srand(static_cast<unsigned int>(time(0)));
        int randomnumber = rand() % 7;
        float randomSpawnx = rand() % 970;
        float randomSpawny = rand() % 500;
       
        Sprite tempSprite(allblock[randomnumber].getSprite());  // Create a temporary sprite object
        tempSprite.setPosition({  randomSpawnx,  randomSpawny });
       
        float angle = (rand() % 360) * (3.14159f / 180.0f); // Convert to radians
        float speed = (rand()) / RAND_MAX * MAX_SPEED + 1.0f;    // Ensure speed is > 0
        float r = static_cast<float>(5 + (rand() % (10 - 5 + 1))) / 10;
        cout << r << endl;
        tempSprite.scale({ r , r });
       
        vel.push_back({ cos(angle) * speed ,sin(angle) * speed });
        sprites.push_back(tempSprite);
        currentSpriteCount++;
    }
    void moveSprite(Sprite& s, int i) {
        Vector2f sPos = s.getPosition();

        /// \note agar ball left side pa ja rahi ha yaini uske x comonent negative ho raha to usko reflect kar do
        if (sPos.x < 0 || sPos.x >= (winW - 30.0))
            vel[i].x *= -1;

        /// \note agar ball upar sa kahin jahi rahi to uska y negative ho raha 
        /// \note agar ball neecha ja rahi to uska y window ki height sa bara ho raha
        /// \note 10 aur 570 islia kioka border set kiya huwa 
        if (sPos.y <= 0 || sPos.y >= (winH - 30.0)) ///\note 30 serves as padding warna ball adhi sa zaida screen ss bahir jati phir return hoti , 30 add karna sa wo halka sa touch karti aur wais aa jati
            vel[i].y *= -1;

        float randomSpawn = 0;

        sPos.x += vel[i].x;
        sPos.y += vel[i].y;

        s.setPosition(sPos);

    }

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

