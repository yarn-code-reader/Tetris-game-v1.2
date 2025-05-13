#pragma once
#include "block.h"
#include "Menu.h"
#include "Pause.h"
#include "Grid.h"
#include "GameLoop.h"
#include "Highscore.h"
#include "Scoreboard.h"
#include "GlobalVar.h"
#include "htp.h"

//gloval variables 
int sizeOfBlock = 40;
float scaleConstantOfBlocks = 0.985;
float winW = 950;
float winH = 700;

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

    const int noOfS = 4;
    SoundBuffer buffers[noOfS] = {
        SoundBuffer("music\\gameMusic.mp3"),
        SoundBuffer("music\\blockPlacing.wav"),
        SoundBuffer("music\\scoreInc.wav"),
        SoundBuffer("music\\gameover.wav")
    };
   
  
    Sound s[noOfS] = {
        Sound(buffers[0]),
         Sound(buffers[1]),
          Sound(buffers[2]),
           Sound(buffers[3])
    };
    //intializing menu objetcs
  
    vector<Texture> menuBtnTextures = {
     Texture("allTextures\\playbtnStates.png"),
     Texture("allTextures\\optionbtn.png"),
     Texture("allTextures\\htpStates.png"), 
     Texture("allTextures\\highscorestates.png"),
     Texture("allTextures\\exitStates.png")
    };
    
    vector<Texture> scoreboardTextures = {
        Texture("allTextures\\replbtnStates.png"),
     Texture("allTextures\\backbtnScoreboardstates.png")
     
    };

    vector<Texture> highscorescreenTextures = {
        Texture("allTextures\\backbtnStates.png"),
         Texture("allTextures\\resetbtnstates.png")
    };



    Texture deleting_anim_1("allTextures\\anim1_1.png");
    Texture deleting_anim_2("allTextures\\anim1_2.png");
    Sprite deleting_anim_1_sprite(deleting_anim_1);
    Sprite deleting_anim_2_sprite(deleting_anim_2);

    GameLoop gameloop(&grid, "allTextures\\playscreen.png", "fonts\\Rockwell-Cond.ttf", noOfS, s);
    gameloop.makeAnimation(gameloop.getAnimationDeleting(), deleting_anim_1_sprite, deleting_anim_2_sprite, deleting_anim_2_sprite);



    Menu myMenu("allTextures\\menuBgWithoutButtons.png", menuBtnTextures, 5);
    Pause pause("allTextures\\pausescreen.png", arr_of_blocks);
    Scoreboard scoreboard("allTextures\\ScoreBoardScreen.png", scoreboardTextures, 2);
    Highscore highscore("allTextures\\PrevHowToPlayScreen.png", highscorescreenTextures, 2 , "database\\demo.txt", "fonts\\Rockwell-Cond.ttf");
    // run the program as long as the window is open
    htp howtoplay("allTextures\\howToPlayScreen.png", highscorescreenTextures, 1);
    gameloop.spawnPeice();

    Clock clock;

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        // clear the window with black color
        float dt = clock.restart().asSeconds();  // Time since last frame
        window.clear(sf::Color::Black);

        if (States::isGameOpen()) {
            // start the game
           // gameloop.StartGame();
            gameloop.draw(window);
            gameloop.update(dt);
            gameloop.checkevents(window);
        }
        else if (States::isOptionsOpen()) {
            // draw options
        }
        else if (States::isHtpOpen()) {
            howtoplay.drawScreen(window);
            howtoplay.checkEvents(window);
        }
        else if (States::isPauseScreenOpen()) {
            // pause screen
            pause.drawScreen(window);
            pause.checkevents(window);
        }
        else if (States::isScoreboardOpen()) {
            scoreboard.drawScreen(window);
            scoreboard.checkEvents(window);
        }
        else if (States::isHighscoreOpen()) {
            highscore.drawScreen(window);
            highscore.checkEvents(window);
        }
       
        else {
            // draw menu 
            myMenu.drawScreen(window);
            myMenu.checkEvents(window);
        }


        // end the current frame
        window.display();
    }

}