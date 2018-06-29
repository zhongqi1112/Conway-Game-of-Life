#ifndef GUI_H
#define GUI_H

#include <constants.h>
#include <SFML/Graphics.hpp>

class Gui
{
public:
    void SetupWindow(sf::RenderWindow& window);
    void CellsSetup();
    void ButtonsSetup();
    void PatternsSetup();
    void Draw(sf::RenderWindow& window);
    void SetCells(int cellPositionX, int cellPositionY, int alive, sf::RenderWindow& window);
private:
    sf::Font font;
    sf::RectangleShape cells;
    sf::RectangleShape patternSave1;
    sf::RectangleShape patternSave2;
    sf::RectangleShape patternSave3;
    sf::RectangleShape patternSave4;
    sf::RectangleShape patternSave5;
    sf::RectangleShape patternSave6;
    sf::RectangleShape patternSave7;
    sf::RectangleShape patternSave8;
    sf::RectangleShape patternSave9;
    sf::RectangleShape patternLoad1;
    sf::RectangleShape patternLoad2;
    sf::RectangleShape patternLoad3;
    sf::RectangleShape patternLoad4;
    sf::RectangleShape patternLoad5;
    sf::RectangleShape patternLoad6;
    sf::RectangleShape patternLoad7;
    sf::RectangleShape patternLoad8;
    sf::RectangleShape patternLoad9;
    sf::Text Button_1;
    sf::Text Button_2;
    sf::Text Button_3;
    sf::Text Button_4;
    sf::Text Button_5;
    sf::Text Button_6;
    sf::Text Button_7;
    sf::Text Button_8;
};

#endif // GUI_H
