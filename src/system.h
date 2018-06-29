#ifndef System_H
#define System_H

#include <gui.h>

class System
{
public:
    System();
    void Initial(int Array[][SIZE_OF_ARRAY]);
    void RandomAdd();
    void Update();
    void NextGen();
    void Render(sf::RenderWindow& window);
    void ShowWorldInConsole(int Array[][SIZE_OF_ARRAY]);
    void ClickOnScreen(int cellPositionX, int cellPositionY);
    void Save();
    void Load();
    void PatternSave(std::vector<std::pair<int, int> > &patternList);
    void PatternSaveToFile(std::string fileName, std::vector<std::pair<int, int> > patternList);
    void PatternLoad(std::vector<std::pair<int, int> > patternList);
    void PatternLoadFromFile(std::string fileName, std::vector<std::pair<int, int> > &patternList);
    bool IsEmptyWorld(int Array[][SIZE_OF_ARRAY]);
    bool IsEmptyFile(std::ifstream& inFile);
    int IdentifyButton(int x, int y);
    bool GameStatusIsPause();
private:
    int World[SIZE_OF_ARRAY][SIZE_OF_ARRAY];
    int NeighborCount[SIZE_OF_ARRAY][SIZE_OF_ARRAY];
    std::vector<std::pair<int, int> > patternWorld;
    std::vector<std::pair<int, int> > pattern1;
    std::vector<std::pair<int, int> > pattern2;
    std::vector<std::pair<int, int> > pattern3;
    std::vector<std::pair<int, int> > pattern4;
    std::vector<std::pair<int, int> > pattern5;
    std::vector<std::pair<int, int> > pattern6;
    std::vector<std::pair<int, int> > pattern7;
    std::vector<std::pair<int, int> > pattern8;
    std::vector<std::pair<int, int> > pattern9;
    bool Pause;
    Gui gui;
};

#endif // System_H
