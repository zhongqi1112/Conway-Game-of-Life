#include "gui.h"

/*
 * Frontend of game: draw and display components on screen.
 * /

/**
 * @brief Gui::SetupWindow: call set up functions of cells, buttons and patterns,
 * draw and display everything on screen.
 * @param window: screen
 */
void Gui::SetupWindow(sf::RenderWindow &window)
{
    CellsSetup();
    ButtonsSetup();
    PatternsSetup();
    Draw(window);
    window.display();
}

/**
 * @brief Gui::CellsSetup: set up atrribues for cells
 */
void Gui::CellsSetup()
{
    sf::Vector2f SIZE_CELL(CELL_LENGTH, CELL_LENGTH);
    cells.setSize(SIZE_CELL);
    cells.setOutlineColor(sf::Color::Blue);
    cells.setOutlineThickness(0.6);
}

/**
 * @brief Gui::ButtonsSetup: set up atrribues for buttons
 */
void Gui::ButtonsSetup()
{
    font.loadFromFile("arial.ttf");
    Button_1.setFont(font);
    Button_2.setFont(font);
    Button_3.setFont(font);
    Button_4.setFont(font);
    Button_5.setFont(font);
    Button_6.setFont(font);
    Button_7.setFont(font);
    Button_8.setFont(font);

    Button_1.setString("START");
    Button_2.setString("STOP");
    Button_3.setString("ADD CELLS");
    Button_4.setString("CLEAN WORLD");
    Button_5.setString("LOAD WORLD");
    Button_6.setString("SAVE WORLD");
    Button_7.setString("SAVE PATTERN");
    Button_8.setString("LOAD PATTERN");

    Button_1.setCharacterSize(CEW * CELL_LENGTH);
    Button_2.setCharacterSize(CEW * CELL_LENGTH);
    Button_3.setCharacterSize(CEW * CELL_LENGTH);
    Button_4.setCharacterSize(CEW * CELL_LENGTH);
    Button_5.setCharacterSize(CEW * CELL_LENGTH);
    Button_6.setCharacterSize(CEW * CELL_LENGTH);
    Button_7.setCharacterSize(CEW * CELL_LENGTH);
    Button_8.setCharacterSize(CEW * CELL_LENGTH);

    Button_1.setColor(sf::Color::Green);
    Button_2.setColor(sf::Color::Green);
    Button_3.setColor(sf::Color::Green);
    Button_4.setColor(sf::Color::Green);
    Button_5.setColor(sf::Color::Green);
    Button_6.setColor(sf::Color::Green);
    Button_7.setColor(sf::Color::Red);
    Button_8.setColor(sf::Color::Red);

    Button_1.setPosition(BUTTON_X, 0);
    Button_2.setPosition(BUTTON_X, CEW*CELL_LENGTH);
    Button_3.setPosition(BUTTON_X, 2*CEW*CELL_LENGTH);
    Button_4.setPosition(BUTTON_X, 3*CEW*CELL_LENGTH);
    Button_5.setPosition(BUTTON_X, 4*CEW*CELL_LENGTH);
    Button_6.setPosition(BUTTON_X, 5*CEW*CELL_LENGTH);
    Button_7.setPosition(BUTTON_X, 6*CEW*CELL_LENGTH);
    Button_8.setPosition(BUTTON_X, 10*CEW*CELL_LENGTH);
}

/**
 * @brief Gui::PatternsSetup: set up atrribues for patterns
 */
void Gui::PatternsSetup()
{
    sf::Vector2f SIZE_PATTERN(3*CELL_LENGTH, 3*CELL_LENGTH);

    patternSave1.setSize(SIZE_PATTERN);
    patternSave2.setSize(SIZE_PATTERN);
    patternSave3.setSize(SIZE_PATTERN);
    patternSave4.setSize(SIZE_PATTERN);
    patternSave5.setSize(SIZE_PATTERN);
    patternSave6.setSize(SIZE_PATTERN);
    patternSave7.setSize(SIZE_PATTERN);
    patternSave8.setSize(SIZE_PATTERN);
    patternSave9.setSize(SIZE_PATTERN);
    patternLoad1.setSize(SIZE_PATTERN);
    patternLoad2.setSize(SIZE_PATTERN);
    patternLoad3.setSize(SIZE_PATTERN);
    patternLoad4.setSize(SIZE_PATTERN);
    patternLoad5.setSize(SIZE_PATTERN);
    patternLoad6.setSize(SIZE_PATTERN);
    patternLoad7.setSize(SIZE_PATTERN);
    patternLoad8.setSize(SIZE_PATTERN);
    patternLoad9.setSize(SIZE_PATTERN);

    patternSave1.setFillColor(sf::Color::Green);
    patternSave2.setFillColor(sf::Color::Green);
    patternSave3.setFillColor(sf::Color::Green);
    patternSave4.setFillColor(sf::Color::Green);
    patternSave5.setFillColor(sf::Color::Green);
    patternSave6.setFillColor(sf::Color::Green);
    patternSave7.setFillColor(sf::Color::Green);
    patternSave8.setFillColor(sf::Color::Green);
    patternSave9.setFillColor(sf::Color::Green);
    patternLoad1.setFillColor(sf::Color::Green);
    patternLoad2.setFillColor(sf::Color::Green);
    patternLoad3.setFillColor(sf::Color::Green);
    patternLoad4.setFillColor(sf::Color::Green);
    patternLoad5.setFillColor(sf::Color::Green);
    patternLoad6.setFillColor(sf::Color::Green);
    patternLoad7.setFillColor(sf::Color::Green);
    patternLoad8.setFillColor(sf::Color::Green);
    patternLoad9.setFillColor(sf::Color::Green);

    patternSave1.setPosition(BUTTON_X, 7*CEW*CELL_LENGTH);
    patternSave2.setPosition(BUTTON_X+4*CELL_LENGTH, 7*CEW*CELL_LENGTH);
    patternSave3.setPosition(BUTTON_X+8*CELL_LENGTH, 7*CEW*CELL_LENGTH);
    patternSave4.setPosition(BUTTON_X, 8*CEW*CELL_LENGTH);
    patternSave5.setPosition(BUTTON_X+4*CELL_LENGTH, 8*CEW*CELL_LENGTH);
    patternSave6.setPosition(BUTTON_X+8*CELL_LENGTH, 8*CEW*CELL_LENGTH);
    patternSave7.setPosition(BUTTON_X, 9*CEW*CELL_LENGTH);
    patternSave8.setPosition(BUTTON_X+4*CELL_LENGTH, 9*CEW*CELL_LENGTH);
    patternSave9.setPosition(BUTTON_X+8*CELL_LENGTH, 9*CEW*CELL_LENGTH);
    patternLoad1.setPosition(BUTTON_X, 11*CEW*CELL_LENGTH);
    patternLoad2.setPosition(BUTTON_X+4*CELL_LENGTH, 11*CEW*CELL_LENGTH);
    patternLoad3.setPosition(BUTTON_X+8*CELL_LENGTH, 11*CEW*CELL_LENGTH);
    patternLoad4.setPosition(BUTTON_X, 12*CEW*CELL_LENGTH);
    patternLoad5.setPosition(BUTTON_X+4*CELL_LENGTH, 12*CEW*CELL_LENGTH);
    patternLoad6.setPosition(BUTTON_X+8*CELL_LENGTH, 12*CEW*CELL_LENGTH);
    patternLoad7.setPosition(BUTTON_X, 13*CEW*CELL_LENGTH);
    patternLoad8.setPosition(BUTTON_X+4*CELL_LENGTH, 13*CEW*CELL_LENGTH);
    patternLoad9.setPosition(BUTTON_X+8*CELL_LENGTH, 13*CEW*CELL_LENGTH);
}

/**
 * @brief Gui::Draw: draw setted up gui on screen
 * @param window: screen
 */
void Gui::Draw(sf::RenderWindow& window)
{
    window.draw(patternSave1);
    window.draw(patternSave2);
    window.draw(patternSave3);
    window.draw(patternSave4);
    window.draw(patternSave5);
    window.draw(patternSave6);
    window.draw(patternSave7);
    window.draw(patternSave8);
    window.draw(patternSave9);
    window.draw(patternLoad1);
    window.draw(patternLoad2);
    window.draw(patternLoad3);
    window.draw(patternLoad4);
    window.draw(patternLoad5);
    window.draw(patternLoad6);
    window.draw(patternLoad7);
    window.draw(patternLoad8);
    window.draw(patternLoad9);
    window.draw(Button_1);
    window.draw(Button_2);
    window.draw(Button_3);
    window.draw(Button_4);
    window.draw(Button_5);
    window.draw(Button_6);
    window.draw(Button_7);
    window.draw(Button_8);
}

/**
 * @brief Gui::SetCells: if cell is alive, filling outwith white color,
 * If not, filling out with black color.
 * @param cellPositionX: x-axis coordinate of cell
 * @param cellPositionY: y-axis coordinate of cell
 * @param alive: cell is alive or dead
 * @param window: screen
 */
void Gui::SetCells(int cellPositionX, int cellPositionY, int alive, sf::RenderWindow &window)
{
    cells.setPosition(cellPositionX, cellPositionY);
    if (alive)
    {
        cells.setFillColor(sf::Color::White);
    }
    else
    {
        cells.setFillColor(sf::Color::Black);
    }
    window.draw(cells);
}
