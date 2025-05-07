#pragma once
#include "block.h"
#include "Grid.h"
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
        arr_of_blocks[i].scale(30, 30);
    }
    sf::RenderWindow window(sf::VideoMode({ 950, 700 }), "My window");

    Grid grid(360.0, 40.0, 20 ,10);
    grid.setBlockArray(arr_of_blocks);

    grid.activity_status[10][5] = 1;
    grid.activity_status[11][5] = 2;
    grid.activity_status[12][5] = 3;
    grid.activity_status[13][5] = 4;
    grid.activity_status[1][5] = 5;
    grid.activity_status[2][5] = 6;
    grid.activity_status[3][5] = 7;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        sf::Texture txt("allTextures\\blockOfGrid.png");
        Texture bg("allTextures\\playscreen.png");
        Sprite menubg(bg);
        float x = window.getSize().x, y = window.getSize().y;
        menubg.scale({ x / bg.getSize().x,  y / bg.getSize().y });

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(menubg);
        grid.draw(window);
        grid.print();
        // end the current frame
        window.display();
    }
}

