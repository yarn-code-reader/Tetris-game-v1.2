#pragma once
#include "Peice.h"
#include "Grid.h"
#include "Shape.h"
#include "States.h"
#include "Animation.h"
#include "GlobalVar.h"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <SFML/Audio.hpp>
#include <fstream>

class GameLoop
{
public:
    Grid* grid;
    Peice* peice;
    Peice* next_peices[3];
    Peice* hold;
    Vector2f coordinates[4];
    Animation placing;
    Animation deleting;
    Texture bgTexture;
    bool isRunning = true;
    int score = 0;
    int lines = 0;
    int levels = 1;
    float fallDelay = 1.0f; // seconds between drops
    float timer = 0.0;
    bool PeiceColided = false;
    int next_peices_count = 3;
    sf::Text scoreOnScreen;
    sf::Text levelOnScreen;
    sf::Text linesOnScreen;
    Font font;
    int fontSize;
    stringstream tempStream;
    //sf::SoundBuffer soundbuffer[4];
    sf::Sound* sounds[4]; // using pointe rkioke sound class ka default constructor nahi ha 
    int noOfSounds;
    string filepath;
    fstream file;
    vector<int>data;
    int prevScore;

public:
    GameLoop(Grid* grid , string t , string f , int noOfS, Sound s[4], string fileAdd );
        

    ~GameLoop();
    
    bool isrunningTrue();

    void resetGame();

    void checkFile();
    void create_a_peice(Peice*& p);
    void generatePeices();
    void shift_array_left();
    void spawnPeice();
    void hold_the_peice();
    int calculating_x_off_set(int x);

    int calculating_y_off_set(int y);

    bool detectCollission(int opt);
    void lock_the_peice();
    void move_the_peice_down();
    void move_the_peice_left();

    void move_the_peice_right();
    bool isWrongCoordinates(int xOfGrid, int yOfGrid);

    bool peice_can_rotate(int x, int y);

    void rotate_the_peice();
    void clear_row(int row);

    void move_everything_down(int row);
    void updateSpeed();
    void update_text(Text& t, int demo);
    void update_level();
    void check_if_any_row_is_filled();
    void hardDrop();

    void checkevents(RenderWindow& win);

    Animation& getAnimationPlacing();

    Animation& getAnimationDeleting();
    void makeAnimation(Animation& a, Sprite as, Sprite bs, Sprite cs);
// in GameLoop.h
    void draw(sf::RenderWindow& window);
    void update(float dt);
    int getScore();
};