#pragma once
#include "block.h"
#include "Menu.h"
#include "Grid.h"
#include "GameLoop.h"
#include "GlobalVar.h"

//gloval variables 
int sizeOfBlock = 40;
float scaleConstantOfBlocks = 0.985;

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

    Grid grid(360.0, 40.0, 14, 10);
    grid.setBlockArray(arr_of_blocks);



    //intializing menu objetcs
    States* currentState = new States[4]{
    Menu(),
   Menu(),
   Menu(),
   Menu()
    };
    vector<vector<Texture>> menuBtnTextures = {
     {Texture("allTextures\\menuPlayBtn.png"), Texture("allTextures\\menuPlayHover.png"), Texture("allTextures\\menuPlaybtnPressed.png")},
     {Texture("allTextures\\menubtnOpt.png"), Texture("allTextures\\menuOptHover.png"), Texture("allTextures\\menuOptPressed.png")},
     {Texture("allTextures\\menuHTPbtn.png"), Texture("allTextures\\menuHTPHover.png"), Texture("allTextures\\menuHTPPressed.png")},
     {Texture("allTextures\\menubtnExit.png"), Texture("allTextures\\menuExitbtnHover.png"), Texture("allTextures\\menuExitPressed.png")}
    };

    Texture deleting_anim_1("allTextures\\anim1_1.png");
    Texture deleting_anim_2("allTextures\\anim1_2.png");
    Sprite deleting_anim_1_sprite(deleting_anim_1);
    Sprite deleting_anim_2_sprite(deleting_anim_2);

    GameLoop gameloop(&grid, "allTextures\\playscreen.png");
    gameloop.makeAnimation(gameloop.getAnimationDeleting(), deleting_anim_1_sprite, deleting_anim_2_sprite, deleting_anim_2_sprite);



    Menu myMenu("allTextures\\menuBgWithoutButtons.png", menuBtnTextures, 4);

    // run the program as long as the window is open
    gameloop.generatePeices();
    gameloop.spawnPeice();

    Clock clock;

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop


        if (States::isMenuOpen()) {
            myMenu.checkEvents(window);
        }
        else if (States::isGameOpen()) {
            gameloop.checkevents(window);
        }



        // clear the window with black color
        float dt = clock.restart().asSeconds();  // Time since last frame
        window.clear(sf::Color::Black);

        if (States::isGameOpen()) {
            // start the game
           // gameloop.StartGame();
            gameloop.draw(window);
            gameloop.update(dt);
        }
        else if (States::isOptionsOpen()) {
            // draw options
        }
        else if (States::isHtpOpen()) {
            // draw how to play
        }
        else if (States::isPauseScreenOpen()) {
            // pause screen
        }
        else {
            // draw menu 
            myMenu.drawMenu(window);
        }


        // end the current frame
        window.display();
    }

}