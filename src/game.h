#ifndef GAME_H
#define GAME_H

#include <system.h>

class Game
{
public:
    Game();
    void run();
    void processEvents();
    void update();
    void render();
    void loadExistedPattern();
private:
    int mouseX;
    int mouseY;
    int cellX;
    int cellY;
    sf::RenderWindow window;
    System system;
};

#endif // GAME_H
