#include "game.h"

/*
 * logic of game
 * /
 *
/**
 * @brief Game::Game: draw the display window
 */
Game::Game()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game of Life!", sf::Style::Titlebar | sf::Style::Close);
}

/**
 * @brief Game::run: start the logic of game
 */
void Game::run()
{
    std::cout<<"Start Game of life \n\n";
    loadExistedPattern();
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

/**
 * @brief Game::loadExistedPattern: load existing patterns from files
 */
void Game::loadExistedPattern()
{
    system.Load();
}

/**
 * @brief Game::update: update screen
 */
void Game::update()
{
    system.Update();
}

/**
 * @brief Game::render: draw everything on screen
 */
void Game::render()
{
    system.Render(window);
}

/**
 * @brief Game::processEvents: process event on screen
 */
void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) //or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            system.Save();
            window.close();
            std::cout<<"End of Game"<<std::endl;
            break;

            // mouse event:
        case sf::Event::MouseButtonPressed:
            mouseX = event.mouseButton.x;
            mouseY = event.mouseButton.y;
            cellX = mouseX / 8;
            cellY = mouseY / 8;

            system.ClickOnScreen(cellX, cellY);

            if(system.GameStatusIsPause())
            {
                std::cout<<"Game is stopped \n";
            }
            else
            {
                std::cout<<"Game is running \n";
            }
            std::cout << "Mouse: (" << mouseX << ", " << mouseY << ") \n";

            if(cellX < 100 && cellY < 100)
            {
                std::cout << "Cell:  (" << cellX << ", " << cellY << ") \n\n";
            }
            else
            {
                std::cout << "Cell: Out of cells \n\n";
            }
            break;
        default:
            break;
        }
    }
}
