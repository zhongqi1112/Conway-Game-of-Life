#ifndef System_H
#define System_H
#include <constants.h>
#include <SFML/Graphics.hpp>

class System
{
public:
    System();
    void Step();
    void Initial(int Array[][size]);
    void Random ();
    void NextGen();
    void Show(int Array[][size]);
    void Mouse_Start(int Start_x, int Start_y);
    void Mouse_End(int End_x, int End_y);
    void MouseLeft(int x, int y);
    void MouseLeftWithoutCtrl(int x, int y);
    void PatternStartEndPointsSave(char patternName[]);
    void PatternStartEndPointsLoad(char patternName[]);
    void PatternSave(char patternName[]);
    void PatternLoad(char patternName[]);
    void Draw(sf::RenderWindow& window);
private:
    int World[size][size];
    int NeighborCount[size][size];
    int MousePosition[4];
    int MouseLastStep[4];
    int MouseLastClickStep[2];
    int WH[2];//Wide and Hight of a pattern
    bool pause;
};

#endif // System_H
