#pragma once
#include "block.h"
#include "Menu.h"
#include "Grid.h"
#include "GlobalVar.h"

//gloval variables 
int sizeOfBlock = 40;

int main()
{
    //initalizing everything
    block arr_of_blocks[8] = {
        block("allTextures\\blockOfGrid.png"),
        block("allTextures\\myBlock1.png"),
        block("allTextures\\myBlock2.png"),
        block("allTextures\\myBlock3.png"),
        block("allTextures\\myBlock4.png"),
        block("allTextures\\myBlock5.png"),
        block("allTextures\\myBlock6.png"),
        block("allTextures\\myBlock7.png")
    };

    for (int i = 0; i < 8; i++)
    {
        arr_of_blocks[i].scale(sizeOfBlock, sizeOfBlock);
    }
    sf::RenderWindow window(sf::VideoMode({ 950, 700 }), "My window");

    Grid grid(360.0, 40.0, 20 ,10);
    grid.setBlockArray(arr_of_blocks);

    //intializing menu objetcs
    States* currentState = new States[4]{
    Menu(), 
   Menu(),
   Menu(),
   Menu()
    };
   

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();

            currentState[0].checkEvents(window);
        }

        sf::Texture txt("allTextures\\blockOfGrid.png");
        Texture bg("allTextures\\playscreen.png");
        Sprite menubg(bg);
        float x = window.getSize().x, y = window.getSize().y;
        menubg.scale({ x / bg.getSize().x,  y / bg.getSize().y });

        // clear the window with black color
        window.clear(sf::Color::Black);

        if (States::isGameOpen()) {
            // start the game
        }
         else if (States::isOptionsOpen()) {
             // draw options
        }else if (States::isHtpOpen()) {
            // draw how to play
        }
        else if (States::isPauseScreenOpen()) {
            // pause screen
        }
        else  {
            // draw menu 
        }


        // end the current frame
        window.display();
    }
}

