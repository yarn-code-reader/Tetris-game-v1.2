
#include "Highscore.h"
#include <sstream>
#include <vector>
#include <fstream>
Highscore::Highscore(std::string bgTexture = "allTextures\\default.png", std::vector<Texture> texture = {}, int noOfB = 0, std::string filepath = "", std::string f = "") :
    States(noOfB, texture, bgTexture), file(filepath, ios::in), filepath(f), font(f), highscoreonscreen(font, "", 100) {
    for (int i = 0; i < noOfButtons; i++)
    {
        sprites[i].scale({ 1.5, 1.5 });
    }

    if (!file)
    {
        cout << "Score data base is not found";
        return;
    }
   
    data.resize(maxScore);

}
void Highscore::drawScreen(sf::RenderWindow& win) {
    States::drawScreen(win);
    float x = win.getSize().x, y = win.getSize().y;

    for (int i = 0; i < noOfButtons; i++)
    {
        float btnWidth = sprites[i].getGlobalBounds().size.x;
        float btnHeight = sprites[i].getGlobalBounds().size.y;

        // Calculate x and y positions
        float xbtn =  50;   // Center horizontally (assuming 800 window width)
        float ybtn = 20 + (i * (btnHeight + 15));  // Vertical spacing based on button height

        // Set position and draw
        if (statesOfBtn[i] == 0)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 0 }, { 144, 65 })));
        }
        else if (statesOfBtn[i] == 1)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 98 }, { 144, 65 })));
        }
        else if (statesOfBtn[i] == 2)
        {
            sprites[i].setTextureRect((sf::IntRect({ 0, 194 }, { 144, 258 })));
        }
        sprites[i].setPosition({ xbtn, ybtn });
        win.draw(sprites[i]);
    }

    ///\note creating strings
    std::string eachline;

    data.clear(); // to prevenrt duplication 
    file.clear();         // Clear any error flags
    file.seekg(0);        // Move the file pointer to the beginning
    if (file.peek() == EOF)                 ///\note checking if databse is empty --> if yes then display that no scores avilable 
        ///\note file.peek checks the next character and EOF tells the end of file 
        ///\note so if next character is empty file then indicates file is empty
    {
     //   win.clear(Color(4, 13, 30));

        ///\note drawing text
        Text noScores(font, "No Scores Available", 90);
        noScores.setFillColor(Color::White);
        noScores.setPosition({ 950 / 2 - 200, 700  / 2 - 50 });
        win.draw(noScores);
        return;
    }
   else {

        while (getline(file, eachline))
        {
            data.push_back(stoi(eachline));
            cout << eachline << endl;
        }
    }
    
    //sorting the vector
    for (int i = 0; i < data.size() - 1; i++)  ///\note i tracks how many elements have been sorted.
        for (int j = 0; j < data.size() - i - 1; j++) ///\note j iterates through the unsorted portion of the array (data.size() - i - 1).
            if (data[j] < data[j + 1])
                swap(data[j], data[j + 1]);


    float width = 300, height = 30, yoffset = 150, xoffset = 0;
    string temp;
    cout << data.size() << endl;
    for (int i = 0; i < data.size() && data.size() != 0; i++)
    {
       
        RectangleShape row(Vector2f((win.getSize().x) - 350, 50));
        row.setFillColor(Color(255,255,255));
        Color c = row.getFillColor();
        c.a = 100;
        row.setFillColor(c);
        row.setPosition({ width, yoffset });
        win.draw(row);

        
            Text text(font, to_string(i + 1)+".\t" + to_string(data[i]), 50);
            text.setFillColor(Color(6, 115, 83));
            text.setPosition({(((win.getSize().x) + 100) / 2) + xoffset, yoffset - 5});
            win.draw(text);
           
        
        yoffset += height + 50;
        cout << data[i] << endl;
    }

    ///\spare highscore
    int highscore = -1;

    for (int i = 0; i < data.size() && data.size() != 0; i++)
            if ((data[i]) > highscore)  
                highscore = (data[i]);

   
}


int Highscore::onButtonClick(int index) {

   
    switch (index) {
    case 0:
         menuOpen = true; highscoreOpen = false; break;
    case 1:
        if (file.is_open()) {
            file.close();  // Close the current file stream if open
        }
         file.open(filepath, std::ios::trunc);
       
        data.clear();
         highscoreOpen = false; menuOpen = true; break;
    default:
        break;
    }
    return 0;
}