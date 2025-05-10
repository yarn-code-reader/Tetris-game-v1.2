#pragma once
#include "Peice.h"
#include "Grid.h"
#include "Shape.h"
#include "Animation.h"
#include "GlobalVar.h"
#include <cstdlib>
#include <ctime>

class GameLoop
{
public:
    Grid* grid;
    Peice* peice;
    Peice* next_peice;
    Animation placing;
    Animation deleting;
    Texture bgTexture;
    bool isRunning = true;
    int score = 0;
    int lines = 0;
    int levels = 0;
    float fallDelay = 1.0f; // seconds between drops
    float timer = 0.0;
    bool PeiceColided = false;
    int rowToBeDel = 0;

public:

    GameLoop() : peice(nullptr), next_peice(nullptr), grid(nullptr), isRunning(true) {

    }

    GameLoop(Grid * grid = nullptr, string t = "") : peice(nullptr), next_peice(nullptr), grid(grid), bgTexture(t), isRunning(true){

    }
    bool isrunningTrue() {
        return isRunning;
    }

    void StartGame() {
       
        spawnPeice();

    }

    void spawnPeice() {
        srand(time(0));
        int randomnumber = rand() % 7;
        float peiceStartx = grid->getStartx() + 3 * sizeOfBlock;
        float peiceStarty = grid->getStarty();
        cout << randomnumber << endl;
        if (peice != nullptr) {
            delete peice;
        }

        if (randomnumber == 0) {
            cout << "Creating I-shape" << endl;
            peice = new I_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 1) {
            cout << "Creating J-shape" << endl;
            peice = new J_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 2) {
            cout << "Creating L-shape" << endl;
            peice = new L_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 3) {
            cout << "Creating O-shape" << endl;
            peice = new O_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 4) {
            cout << "Creating S-shape" << endl;
            peice = new S_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 5) {
            cout << "Creating T-shape" << endl;
            peice = new T_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 6) {
            cout << "Creating Z-shape" << endl;
            peice = new Z_Shape(peiceStartx, peiceStarty);
        }
        else {
            cout << "Invalid random number: " << randomnumber << endl;
        }

        cout << "peice type: " << peice->getType() << endl;
        peice->setSpriteOfPeice(grid->getAllBlocks(peice->getType()));
     //   peice->setType(randomnumber + 1);

        int yOfPeice = 0, xOfPeice = 0;
        for (int i = 0; i < 4;i++)
        {
            xOfPeice = calculating_x_off_set(peice->getShape()[i][0]);
            yOfPeice = calculating_y_off_set(peice->getShape()[i][1]);
            if (grid->activity_status[yOfPeice][xOfPeice] != 0) {
                isRunning = false;
                cout << "GAME OVER" << endl;
            }
        }
    }

    int calculating_x_off_set(int x) {
        int temp = ((peice->getX() + (x * sizeOfBlock)) - (grid->startx + sizeOfBlock)) / sizeOfBlock;
        return temp;
    }

    int calculating_y_off_set(int y) {
        int temp = ((peice->getY() + (y * sizeOfBlock)) - (grid->starty)) / sizeOfBlock;;
        return temp;
    }

    bool detectCollission(int opt)
    {
        int xOfPeice = 0, yOfPeice = 0;

        for (int i = 0; i < 4;i++)
        {
            xOfPeice = calculating_x_off_set(peice->getShape()[i][0]);
            yOfPeice = calculating_y_off_set(peice->getShape()[i][1]);

            if (opt == 1) {
                if (isWrongCoordinates(yOfPeice + 1, xOfPeice)) {
                    return false;
                }
            }
            else if (opt == 2) {
                if (isWrongCoordinates(yOfPeice, xOfPeice - 1)) {
                    return false;
                }
            }
            else if (opt == 3) {
                if (isWrongCoordinates(yOfPeice, xOfPeice + 1)) {
                    return false;
                }
            }
        }
        return true;
    }
    void lock_the_peice() {
        int peicex = 0, peicey = 0, xOfPeice = 0, yOfPeice = 0;

        for (int i = 0; i < 4;i++)
        {
            peicex = peice->getShape()[i][0];
            peicey = peice->getShape()[i][1];
            xOfPeice = ((peice->getX() + (peicex * sizeOfBlock)) - (grid->startx + sizeOfBlock)) / sizeOfBlock;;
            yOfPeice = ((peice->getY() + (peicey * sizeOfBlock)) - (grid->starty)) / sizeOfBlock;;

            grid->activity_status[yOfPeice][xOfPeice] = peice->getType();

            //       grid->print();
              //     cout << endl;


        }
    }
    void move_the_peice_down() {
        cout << "1\n";
        // basically send
        if (isRunning) {
            if (detectCollission(1)) {
                peice->moveDown();
                PeiceColided = false;
            }
            else {
                PeiceColided = true;
                placing.reset();
            }
        }
    }
    void move_the_peice_left() {

        // basically send
        if (isRunning) {
            if (detectCollission(2)) {
                peice->moveLeft();
            }
            else {
                cout << "cannot move peice there" << endl;
            }
        }
    }

    void move_the_peice_right() {

        // basically send
        if (isRunning) {
            if (detectCollission(3)) {
                peice->moveRight();
            }
            else {
                cout << "cannot move peice there" << endl;
            }
        }
    }

    bool isWrongCoordinates(int xOfGrid, int yOfGrid) {
        if (yOfGrid >= grid->maxCol || xOfGrid > grid->maxRow || yOfGrid < 0 || xOfGrid < 0 || grid->activity_status[xOfGrid][yOfGrid] != 0) {
            return true;
        }

        return false;
    }


    bool peice_can_rotate(int x, int y) {
        if (!(isWrongCoordinates(x, y))) {
            return true;
        }

        return false;
    }

    void rotate_the_peice() {
        if (isRunning) {
            int temp[4][2] = { 0 };
            peice->rotate(temp);
            bool copy = true;

            int xOfPeice = 0, yOfPeice = 0;
            for (int i = 0; i < 4;i++)
            {
                xOfPeice = calculating_x_off_set(temp[i][0]);
                yOfPeice = calculating_y_off_set(temp[i][1]);

                if (peice_can_rotate(yOfPeice, xOfPeice)) {
                    copy = true;

                }
                else {
                    cout << "Peice cannot rotate" << endl;
                    cout << xOfPeice << endl;
                    cout << yOfPeice << endl;
                    copy = false;
                    break;
                }
            }

            if (copy) {
                for (int i = 0; i < 4; i++) {

                    peice->getShape()[i][0] = temp[i][0];
                    peice->getShape()[i][1] = temp[i][1];

                }
            }
        }

    }

    void clear_row(int row) {
        for (int i = 0; i < grid->maxCol; i++)
        {
            grid->activity_status[row][i] = 0;
        }
    }

    void move_everything_down(int row) {
        for (int i = row; i > -0; i--)
        {
            for (int j = 0; j < grid->maxCol; j++)
            {
                grid->activity_status[i][j] = grid->activity_status[i - 1][j];
            }
        }

        //clear top row
        for (int i = 0; i < grid->maxCol; i++)
        {
            grid->activity_status[0][i] = 0;
        }
    }
    void updateSpeed() {
        fallDelay -= (0.1) * fallDelay;
        cout << fallDelay << endl;
    }

    void update_level() {
        if (lines == 10) {
            levels++;
            if (levels == 8) {
                levels = 1;
                fallDelay = 1.0f;
            }
            lines = 0;
            updateSpeed();
        }
    }
    void check_if_any_row_is_filled() {
        bool allFilled = true;
        for (int i = 0; i < grid->maxRow; i++)
        {
            allFilled = true;
            for (int j = 0; j < grid->maxCol; j++) {
                if (grid->activity_status[i][j] == 0) {
                    allFilled = false;
                    break;
                }
            }

            if (allFilled) {
                cout << "Clear A row" << endl;
                score += 100;
                lines += 1;
                rowToBeDel = i;
                deleting.reset();
                update_level();
                clear_row(i);
                move_everything_down(i);
                i--;
            }
        }
    }

    void hardDrop() {
        while (!PeiceColided) {
            move_the_peice_down();
        }
    }

    void checkevents(RenderWindow& win)
    {
        if (const std::optional myevent = win.pollEvent())
        {
            if (myevent->is<sf::Event::Closed>())
                win.close();
            else if (auto* keyPressed = myevent->getIf<sf::Event::KeyPressed>())
            {
                cout << "Key pressed" << endl;
                if (keyPressed->scancode == sf::Keyboard::Scancode::Z)
                {
                    updateSpeed();
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Up)
                {
                    rotate_the_peice();
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Down)
                {
                    move_the_peice_down();
                    move_the_peice_down();
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Right)
                {
                    move_the_peice_right();
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Left)
                {
                    move_the_peice_left();
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::A)
                {
                    spawnPeice();
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Space)
                {
                    hardDrop();
                }

            }
        }
    }
    Animation& getAnimationPlacing() {
        return placing;
    }

    Animation& getAnimationDeleting() {
        return deleting;
    }

    void makeAnimation(Animation& a, Sprite as, Sprite bs, Sprite cs ) {
        a.setRectangles(as, bs, cs);
    }
// in GameLoop.h
    void draw(sf::RenderWindow& window) {
        Sprite bg(bgTexture);
        //scaling kar rahe take scren pa sab fit aa sake
        float x = window.getSize().x, y = window.getSize().y;
        bg.scale({ x / bgTexture.getSize().x,  y / bgTexture.getSize().y });

        window.clear();

        // draw background
        window.draw(bg);
        if (grid) {
            if (deleting.isAnimationLocked()) {
                // draw the current flash?frame for each block
                float setx = 0, sety = 100;
                Sprite regularGridBlock(grid->getAllBlocks(0).getSprite());

                for (int i = 0; i < 20; ++i) {
                    setx = grid->startx + sizeOfBlock;
                    for (int j = 0; j < 10; ++j)
                    {
                        //  cout << "setx " << setx << "\tsety " << sety << endl;
                        if (grid->activity_status[i][j] == 0) {
                            regularGridBlock.setPosition(
                                { setx , sety }
                            );
                            window.draw(regularGridBlock);
                            setx += sizeOfBlock;
                            continue;
                        }
                        Sprite cell = deleting.getFrames()[deleting.getAnimFrame()];
                        cout << "while drawing deleting anim frame = " << deleting.getAnimFrame() << endl;
                        cell.setPosition(
                            { setx , sety }
                        );
                        window.draw(cell);
                        setx += sizeOfBlock;
                    }
                    sety += sizeOfBlock;
                }


            }
            else {
                grid->draw(window);
            }
        }

        if (peice) {
            if (placing.isAnimationLocked()) {
                // draw the current flash?frame for each block
                for (int i = 0; i < 4; ++i) {
                    Sprite cell = grid->getAllBlocks(peice->getType()).getSprite() ;
                    Color color = cell.getColor();
                    color.a = 128;
                    float x = peice->getX() + peice->getShape()[i][0] * sizeOfBlock;
                    float y = peice->getY() + peice->getShape()[i][1] * sizeOfBlock;
                    cell.setPosition(
                        { x , y }
                    );
                    cell.scale({ scaleConstantOfBlocks , scaleConstantOfBlocks });
                    window.draw(cell);
                }
            }
            else {
                peice->draw(window);
            }
        }
    }

    void update(float dt) {
        if (placing.isAnimationLocked()) {
            placing.update(dt);
            if (!(placing.isAnimationLocked())) {

                cout << "me true" << endl;
                lock_the_peice();
                check_if_any_row_is_filled();
                spawnPeice();
            }
        }
        else if (isRunning) {
            timer += dt;
            if (timer >= fallDelay) {
                move_the_peice_down();
                timer = 0;
            }
        }

        deleting.update(dt);
    }
};



