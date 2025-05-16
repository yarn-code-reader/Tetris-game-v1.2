#include "GameLoop.h"
    GameLoop::GameLoop(Grid* grid = nullptr, string t = "", string f = "", int noOfS = 0, Sound s[4] = {}, string fileAdd = "") : hold(nullptr), peice(nullptr), grid(grid),
        bgTexture(t), isRunning(true), score(0), lines(0), levels(0), fallDelay(1.0),
        timer(0), PeiceColided(false), font(f), scoreOnScreen(font, "0", fontSize),
        levelOnScreen(font, "0", fontSize), noOfSounds(noOfS), linesOnScreen(font, "0", fontSize),
        filepath(fileAdd), file(filepath, ios::in | ios::out), prevScore(0) {

        srand(time(0));
        generatePeices();

        scoreOnScreen.setFillColor(Color(244, 244, 186));
        scoreOnScreen.setPosition({ 175,110 });

        levelOnScreen.setFillColor(Color(244, 244, 186));
        levelOnScreen.setPosition({ 175,185 });

        linesOnScreen.setFillColor(Color(244, 244, 186));
        linesOnScreen.setPosition({ 175,265 });
        // set attributes of text 

        for (int i = 0; i < noOfSounds; i++)
        {
            sounds[i] = new Sound(s[i]);
        }

        data.resize(maxScore);
    }

    GameLoop :: ~GameLoop() {
        for (int i = 0; i < noOfSounds; i++)
        {
            delete sounds[i];
        }
    }

    bool GameLoop::isrunningTrue() {
        return isRunning;
    }

    void GameLoop::resetGame() {
        cout << "reseetiing the game" << endl;
        grid->resetGrid();
        generatePeices();
        hold = nullptr;
        score = 0;
        levels = 0;
        lines = 0;
        update_text(scoreOnScreen, score);
        update_text(linesOnScreen, lines);
        update_text(levelOnScreen, levels);
        spawnPeice();
        isRunning = true;
    }

    void GameLoop::checkFile() {
        //transfer the data of file to a vector
        data.clear(); // to prevenrt duplication 
        file.clear();         // Clear any error flags
        file.seekg(0);        // Move the file pointer to the beginning
        if (file.peek() == EOF)
            ///\note checking if databse is empty --> if yes then display that no scores avilable 
            ///\note file.peek checks the next character and EOF tells the end of file 
            ///\note so if next character is empty file then indicates file is empty
        {
            // just add the data to the file
            //Use seekp(0) to reset the write pointer to the start of the file after reading
            file.clear();   // Clear any previous error states
            file.seekp(0);  // Reset the write pointer
            file << score << endl;
            return;
        }
        else {
            string eachline;
            int currentScore = 0;
            bool scoreAdded = false;
            while (getline(file, eachline))
            {
                data.push_back(stoi(eachline));
                cout << eachline << endl;
                currentScore++;
            }
        }
        file.close();  // Close after reading

        //sorting the vector
        for (int i = 0; i < data.size() - 1; i++)  ///\note i tracks how many elements have been sorted.
            for (int j = 0; j < data.size() - i - 1; j++) ///\note j iterates through the unsorted portion of the array (data.size() - i - 1).
                if (data[j] < data[j + 1])
                    swap(data[j], data[j + 1]);

        cout << "after sorting " << endl;
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;


        // traverse the vector to see if score > vec[i]
        bool scoreAdded = false;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] < score) {
                scoreAdded = true;
                data[i] = score;
            }
        }

        if (data.size() < maxScore && !scoreAdded) {
            cout << "adding score kioke kahin pa match nahi huwa data mai" << endl;
            if (score > 0) {
                data.push_back(score);
            }
        }

        // now updating the file with updated scores
        file.open(filepath, ios::out | std::ios::trunc);
        cout << "upating fike" << endl;
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << endl;
            file << data[i] << endl;
        }
        cout << endl;
        file.close();

    }
    void GameLoop::create_a_peice(Peice*& p) {
        // srand(time(0));
        int randomnumber = rand() % 7;
        //dummy values
        float peiceStartx = 10, peiceStarty = 10;

        cout << randomnumber << endl;
        if (randomnumber == 0) {
            cout << "Creating I-shape" << endl;
            p = new I_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 1) {
            cout << "Creating J-shape" << endl;
            p = new J_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 2) {
            cout << "Creating L-shape" << endl;
            p = new L_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 3) {
            cout << "Creating O-shape" << endl;
            p = new O_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 4) {
            cout << "Creating S-shape" << endl;
            p = new S_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 5) {
            cout << "Creating T-shape" << endl;
            p = new T_Shape(peiceStartx, peiceStarty);
        }
        else if (randomnumber == 6) {
            cout << "Creating Z-shape" << endl;
            p = new Z_Shape(peiceStartx, peiceStarty);
        }
        else {
            cout << "Invalid random number: " << randomnumber << endl;
        }
        p->setSpriteOfPeice(grid->getAllBlocks(p->getType()));

    }

    void GameLoop::generatePeices() {
        //initalize the array with three ointers, only to be called once 
         //outside of gameloop
        for (int i = 0; i < next_peices_count; i++)
        {
            create_a_peice(next_peices[i]);
            coordinates[i].x = 50 + (i * 235);
            coordinates[i].y = 600;
        }
    }

    void GameLoop::shift_array_left() {
        for (int i = 0; i < next_peices_count - 1; i++)
        {
            next_peices[i] = next_peices[i + 1];
        }

        create_a_peice(next_peices[next_peices_count - 1]);
    }

    void GameLoop::spawnPeice() {
        float peiceStartx = grid->getStartx() + 3 * sizeOfBlock;
        float peiceStarty = grid->getStarty();

        if (peice != nullptr) {
            delete peice;
        }

        if (next_peices[0] != nullptr) {
            peice = next_peices[0];
        }
        else {
            cout << "next_peices[0] is a nullptr" << endl;
            return;
        }
        shift_array_left();
        peice->setX(peiceStartx);
        peice->setY(peiceStarty);

        int typeOfPeice = peice->getType();

        makeAnimation(
            getAnimationPlacing(),
            grid->getAllBlocks(typeOfPeice).getSprite(),
            grid->getAllBlocks(typeOfPeice).getSprite(),
            grid->getAllBlocks(typeOfPeice).getSprite());

        int yOfPeice = 0, xOfPeice = 0;
        for (int i = 0; i < 4;i++)
        {
            xOfPeice = calculating_x_off_set(peice->getShape()[i][0]);
            yOfPeice = calculating_y_off_set(peice->getShape()[i][1]);
            if (grid->activity_status[yOfPeice][xOfPeice] != 0) {
                isRunning = false;
                if (sounds[noOfSounds - 1] != nullptr) {
                    sounds[noOfSounds - 1]->play();
                }
                cout << "GAME OVER" << endl;
                checkFile();
                States::setScoreboard(true);
                States::setGameOpen(false);
                prevScore = score;
                resetGame();
            }
        }
    }

    void GameLoop::hold_the_peice() {
        if (hold == nullptr) {
            cout << "hold is null" << endl;
            hold = peice;
            peice = nullptr;
            spawnPeice();
        }
        else {
            float tempx = peice->getX();
            float tempy = peice->getY();
            Peice* temp = peice;
            peice = hold;
            hold = temp;
            peice->setX(tempx);
            peice->setY(tempy);
        }

        hold->setX(coordinates[next_peices_count].x + next_peices_count * 255);
        hold->setY(600);
    }
    int GameLoop::calculating_x_off_set(int x) {
        int temp = ((peice->getX() + (x * sizeOfBlock)) - (grid->startx + sizeOfBlock)) / sizeOfBlock;
        return temp;
    }

    int GameLoop::calculating_y_off_set(int y) {
        int temp = ((peice->getY() + (y * sizeOfBlock)) - (grid->starty)) / sizeOfBlock;;
        return temp;
    }

    bool GameLoop::detectCollission(int opt)
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
    void GameLoop::lock_the_peice() {
        int peicex = 0, peicey = 0, xOfPeice = 0, yOfPeice = 0;

        for (int i = 0; i < 4;i++)
        {
            peicex = peice->getShape()[i][0];
            peicey = peice->getShape()[i][1];
            xOfPeice = ((peice->getX() + (peicex * sizeOfBlock)) - (grid->startx + sizeOfBlock)) / sizeOfBlock;;
            yOfPeice = ((peice->getY() + (peicey * sizeOfBlock)) - (grid->starty)) / sizeOfBlock;;

            grid->activity_status[yOfPeice][xOfPeice] = peice->getType();
        }
    }
    void GameLoop::move_the_peice_down() {
        // basically send
        if (isRunning) {
            if (detectCollission(1)) {
                peice->moveDown();
                PeiceColided = false;
            }
            else {
                if (sounds[noOfSounds - 3] != nullptr) {
                    sounds[noOfSounds - 3]->play();
                }
                PeiceColided = true;
                placing.reset();
            }
        }
    }
    void GameLoop::move_the_peice_left() {

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

    void GameLoop::move_the_peice_right() {

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

    bool GameLoop::isWrongCoordinates(int xOfGrid, int yOfGrid) {
        if (yOfGrid >= grid->maxCol || xOfGrid > grid->maxRow || yOfGrid < 0 || xOfGrid < 0 || grid->activity_status[xOfGrid][yOfGrid] != 0) {
            return true;
        }

        return false;
    }


    bool GameLoop::peice_can_rotate(int x, int y) {
        if (!(isWrongCoordinates(x, y))) {
            return true;
        }

        return false;
    }

    void GameLoop::rotate_the_peice() {
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

    void GameLoop::clear_row(int row) {
        for (int i = 0; i < grid->maxCol; i++)
        {
            grid->activity_status[row][i] = 0;
        }
    }

    void GameLoop::move_everything_down(int row) {
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
    void GameLoop::updateSpeed() {
        fallDelay -= (0.1) * fallDelay;
        cout << fallDelay << endl;
    }

    void GameLoop::update_text(Text& t, int demo) {
        tempStream.str("");
        tempStream.clear();
        tempStream << demo;
        t.setString(tempStream.str());
    }
    void GameLoop::update_level() {
        if (lines == 10) {
            levels++;
            if (levels == 8) {
                levels = 1;
                fallDelay = 1.0f;
            }
            lines = 0;
            update_text(levelOnScreen, levels);
            update_text(linesOnScreen, lines);

            updateSpeed();
        }
    }
    void GameLoop::check_if_any_row_is_filled() {
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
                if (sounds[noOfSounds - 2] != nullptr) {
                    sounds[noOfSounds - 2]->play();
                }
                score += 100;
                lines += 1;

                update_text(scoreOnScreen, score);
                update_text(linesOnScreen, lines);

                deleting.reset();
                update_level();
                clear_row(i);
                move_everything_down(i);
                i--;
            }
        }
    }

    void GameLoop::hardDrop() {
        while (!PeiceColided) {
            move_the_peice_down();
        }
    }

    void GameLoop::checkevents(RenderWindow& win)
    {
        while (const std::optional event = win.pollEvent())
        {
            // "close requested" event: we close the window
            Vector2i mousePos = Mouse::getPosition(win);
            /// \note Converting the mouse position to world coordinates (if needed for sprites, buttons, etc.)
            Vector2f mouseWorldPos = win.mapPixelToCoords(mousePos);
            //  cout << mouseWorldPos.x << "\t" << mouseWorldPos.y << endl;

            if (event->is<sf::Event::Closed>())
                win.close();

            else if (auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (isRunning)
                {
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
                    else if (keyPressed->scancode == sf::Keyboard::Scancode::P)
                    {
                        States::setPauseScreenOpen(true);
                        States::setGameOpen(false);
                    }
                    else if (keyPressed->scancode == sf::Keyboard::Scancode::C)
                    {
                        hold_the_peice();
                    }
                }
            }
        }
    }


    Animation& GameLoop:: getAnimationPlacing() {
        return placing;
    }

    Animation& GameLoop::getAnimationDeleting() {
        return deleting;
    }

    void GameLoop::makeAnimation(Animation& a, Sprite as, Sprite bs, Sprite cs) {
        a.setRectangles(as, bs, cs);
    }
    // in GameLoop.h
    void GameLoop::draw(sf::RenderWindow& window) {
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
                float setx = grid->startx, sety = grid->starty;


                for (int i = 0; i < grid->maxRow; ++i) {
                    setx = grid->startx + sizeOfBlock;
                    for (int j = 0; j < grid->maxCol; ++j)
                    {
                        //  cout << "setx " << setx << "\tsety " << sety << endl;
                        if (grid->activity_status[i][j] == 0) {
                            Sprite regularGridBlock(grid->getAllBlocks(0).getSprite());
                            regularGridBlock.setPosition(
                                { setx , sety }
                            );
                            regularGridBlock.scale({ scaleConstantOfBlocks , scaleConstantOfBlocks });
                            window.draw(regularGridBlock);
                            setx += sizeOfBlock;
                            continue;
                        }
                        Sprite cell = deleting.getFrames()[deleting.getAnimFrame()];

                        cell.setPosition(
                            { setx , sety }
                        );
                        cell.scale({ 0.157 , 0.157 });
                        window.draw(cell);

                        setx += sizeOfBlock;
                    }
                    sety += sizeOfBlock;
                }
                //    sleep(milliseconds(2000));

            }
            else {
                grid->draw(window);
            }
        }

        if (peice) {
            if (placing.isAnimationLocked()) {
                // draw the current flash?frame for each block
                for (int i = 0; i < 4; i++) {
                    Sprite cell = placing.getFrames()[placing.getAnimFrame()];
                    Color color = cell.getColor();
                    color.a = 128 + (placing.getAnimFrame() * 30);
                    cell.setColor(color);
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

        // drawing peices array
        for (int i = 0; i < next_peices_count; i++)
        {
            if (next_peices[i] != nullptr) {
                //  cout << "drawing " << "\t" << next_peices[i]->getType()<<"\t" << next_peices[i]->getX() << "\t" << next_peices[i]->getY() << endl;
                next_peices[i]->setX(coordinates[i].x);
                next_peices[i]->setY(coordinates[i].y);
                next_peices[i]->draw(window);
            }
        }
        //   cout << "-------" << endl;

           // drawing hold peics
        if (hold != nullptr)
        {
            hold->draw(window);
        }
        // drawing levels
        window.draw(levelOnScreen);

        // drawing score
        window.draw(scoreOnScreen);

        // drawing lines
        window.draw(linesOnScreen);
    }

    void GameLoop::update(float dt) {
        if (placing.isAnimationLocked()) {
            placing.update(dt);
            if (!(placing.isAnimationLocked())) {
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


    int GameLoop :: getScore() {
        return prevScore;
    }