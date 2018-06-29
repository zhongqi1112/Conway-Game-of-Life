#include "system.h"

/*
 * Backend of game: process the logic of game and call gui class to display window
 * /

/**
 * @brief System::System: declare the world
 */
System::System()
{
    Initial(World);
}

/**
 * @brief System::Initial: initialize a zeros 2D array
 * @param Array: array need to be initialized
 */
void System::Initial(int Array[][SIZE_OF_ARRAY])
{
    for(int i=0; i<SIZE_OF_ARRAY; i++)
    {
        for(int j=0; j<SIZE_OF_ARRAY; j++)
        {
            Array[i][j]=0;
        }
    }
}

/**
 * @brief System::RandomAdd: random add 50 cells into the screen
 */
void System::RandomAdd()
{
    for(int i=0; i<50; i++)
    {
        int x = rand() % SIZE_OF_ARRAY;
        int y = rand() % SIZE_OF_ARRAY;
        while(World[x][y])
        {
            x = rand() % SIZE_OF_ARRAY;
            y = rand() % SIZE_OF_ARRAY;
        }
        World[x][y]=1;
    }
}

/**
 * @brief System::Update: update the world to the next generation
 */
void System::Update()
{
    if(!Pause)
    {
        Initial(NeighborCount);
        NextGen();
    }
}

/**
 * @brief System::NextGen: calculate the alive neighbor for cells,
 * and get next generation of world.
 */
void System::NextGen()
{
    // 1. check the counts of eight neighbors of one cell:
    for(int worldX=0; worldX<SIZE_OF_ARRAY; worldX++)
    {
        for(int worldY=0; worldY<SIZE_OF_ARRAY; worldY++)
        {
            // loop through eight neighbors
            for(int i=worldX-1; i<=worldX+1; i++)
            {
                for(int j=worldY-1; j<=worldY+1; j++)
                {
                    if(i==-1 && j==-1)
                    {
                        if(World[SIZE_OF_ARRAY-1][SIZE_OF_ARRAY-1]==1)
                        {
                            NeighborCount[worldX][worldY]++;
                        }
                    }
                    else if(i==-1 && j==SIZE_OF_ARRAY)
                    {
                        if(World[SIZE_OF_ARRAY-1][0]==1)
                        {
                            NeighborCount[worldX][worldY]++;
                        }
                    }
                    else if(i==SIZE_OF_ARRAY && j==-1)
                    {
                        if(World[0][SIZE_OF_ARRAY-1]==1)
                        {
                            NeighborCount[worldX][worldY]++;
                        }
                    }
                    else if(i==SIZE_OF_ARRAY && j==SIZE_OF_ARRAY)
                    {
                        if(World[0][0]==1)
                        {
                            NeighborCount[worldX][worldY]++;
                        }
                    }
                    else if(i==-1)
                    {
                        if(World[SIZE_OF_ARRAY-1][j]==1)
                        {
                            NeighborCount[worldX][worldY]++;
                        }
                    }
                    else if(j==-1)
                    {
                        if(World[i][SIZE_OF_ARRAY-1]==1)
                        {
                            NeighborCount[worldX][worldY]++;
                        }
                    }
                    else if(j==SIZE_OF_ARRAY)
                    {
                        if(World[i][0]==1)
                        {
                            NeighborCount[worldX][worldY]++;
                        }
                    }
                    else if(i==SIZE_OF_ARRAY)
                    {
                        if(World[0][j]==1)
                        {
                            NeighborCount[worldX][worldY]++;
                        }
                    }
                    else
                    {
                        if(World[i][j]==1)
                        {
                            NeighborCount[worldX][worldY]++;
                        }
                    }
                }
            }
            if(World[worldX][worldY]==1)
            {
                NeighborCount[worldX][worldY]--;
            }
        }
    }

    //2. fill out World(Next Generation):
    for(int i=0; i<SIZE_OF_ARRAY; i++)
    {
        for(int j=0; j<SIZE_OF_ARRAY; j++)
        {
            if(NeighborCount[i][j]==3)
            {
                World[i][j]=1;
            }
            else if(NeighborCount[i][j]==2)
            {
                World[i][j]=World[i][j];
            }
            else
            {
                World[i][j]=0;
            }
        }
    }

    if(IsEmptyWorld(World))
    {
        Pause = true;
    }
}

/**
 * @brief System::Render: set up and show everything on screen
 * @param window: screen is going to be showed
 */
void System::Render(sf::RenderWindow &window)
{
    for(int i=0; i<SIZE_OF_ARRAY; i++)
    {
        for(int j=0; j<SIZE_OF_ARRAY; j++)
        {
            gui.SetCells(8*j, 8*i, World[i][j], window);
        }
    }
    gui.SetupWindow(window);
}

/**
 * @brief System::ShowWorldInConsole: show a 2D array on the console for debug
 * @param Array: world is going to be showed
 */
void System::ShowWorldInConsole(int Array[][SIZE_OF_ARRAY])
{
    for(int i=0; i<SIZE_OF_ARRAY; i++)
    {
        for(int j=0; j<SIZE_OF_ARRAY; j++)
        {
            std::cout<<Array[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

/**
 * @brief System::ClickOnScreen: process the effect of event
 * @param cellPositionX: x-axis coordinate of cell
 * @param cellPositionY: y-axis coordinate of cell
 */
void System::ClickOnScreen(int cellPositionX, int cellPositionY)
{
    int clickedButton = IdentifyButton(cellPositionX, cellPositionY);

    if (Pause)
    {
        switch (clickedButton) {
        case 0:
            std::cout<<"Click on the cells \n";
            if(World[cellPositionY][cellPositionX])
            {
                World[cellPositionY][cellPositionX]=0;
            }
            else
            {
                World[cellPositionY][cellPositionX]=1;
            }
            break;
        case 1:
            std::cout<<"Click on the Button_1 Start \n";
            Pause = false;
            break;
        case 2:
            std::cout<<"Click on the Button_2 Stop \n";
            Pause = true;
            break;
        case 3:
            std::cout<<"Click on the Button_3 Add \n";
            RandomAdd();
            break;
        case 4:
            std::cout<<"Click on the Button_4 Clean \n";
            Initial(World);
            break;
        case 5:
            std::cout<<"Click on the Button_5 Load \n";
            PatternLoad(patternWorld);
            break;
        case 6:
            std::cout<<"Click on the Button_6 Save \n";
            PatternSave(patternWorld);
            break;
        case 11:
            std::cout<<"Click on the Save Pattern 1 \n";;
            PatternSave(pattern1);
            break;
        case 12:
            std::cout<<"Click on the Save Pattern 2 \n";;
            PatternSave(pattern2);
            break;
        case 13:
            std::cout<<"Click on the Save Pattern 3 \n";
            PatternSave(pattern3);
            break;
        case 14:
            std::cout<<"Click on the Save Pattern 4 \n";
            PatternSave(pattern4);
            break;
        case 15:
            std::cout<<"Click on the Save Pattern 5 \n";
            PatternSave(pattern5);
            break;
        case 16:
            std::cout<<"Click on the Save Pattern 6 \n";
            PatternSave(pattern6);
            break;
        case 17:
            std::cout<<"Click on the Save Pattern 7 \n";
            PatternSave(pattern7);
            break;
        case 18:
            std::cout<<"Click on the Save Pattern 8 \n";
            PatternSave(pattern8);
            break;
        case 19:
            std::cout<<"Click on the Save Pattern 9 \n";
            PatternSave(pattern9);
            break;
        case 21:
            std::cout<<"Click on the Load Pattern 1 \n";;
            PatternLoad(pattern1);
            break;
        case 22:
            std::cout<<"Click on the Load Pattern 2 \n";
            PatternLoad(pattern2);
            break;
        case 23:
            std::cout<<"Click on the Load Pattern 3 \n";
            PatternLoad(pattern3);
            break;
        case 24:
            std::cout<<"Click on the Load Pattern 4 \n";
            PatternLoad(pattern4);
            break;
        case 25:
            std::cout<<"Click on the Load Pattern 5 \n";
            PatternLoad(pattern5);
            break;
        case 26:
            std::cout<<"Click on the Load Pattern 6 \n";
            PatternLoad(pattern6);
            break;
        case 27:
            std::cout<<"Click on the Load Pattern 7 \n";
            PatternLoad(pattern7);
            break;
        case 28:
            std::cout<<"Click on the Load Pattern 8 \n";
            PatternLoad(pattern8);
            break;
        case 29:
            std::cout<<"Click on the Load Pattern 9 \n";
            PatternLoad(pattern9);
            break;
        default:
            std::cout<<"There is no Button \n";
            break;
        }
    }
    else if (!Pause && clickedButton == 2)
    {
        std::cout<<"Click on the Button_2 Stop \n";
        Pause = true;
    }
    else
    {
        std::cout<<"Game is running, click STOP, then give next command. \n";
    }
}

/**
 * @brief System::Save: when user exit game,
 * save patterns vectors of to files, so user could load them in next game.
 */
void System::Save()
{
    std::cout<<"Saving patterns to files \n";
    PatternSaveToFile("gameoflife.txt", patternWorld);
    PatternSaveToFile("pattern1.txt", pattern1);
    PatternSaveToFile("pattern2.txt", pattern2);
    PatternSaveToFile("pattern3.txt", pattern3);
    PatternSaveToFile("pattern4.txt", pattern4);
    PatternSaveToFile("pattern5.txt", pattern5);
    PatternSaveToFile("pattern6.txt", pattern6);
    PatternSaveToFile("pattern7.txt", pattern7);
    PatternSaveToFile("pattern8.txt", pattern8);
    PatternSaveToFile("pattern9.txt", pattern9);
    std::cout<<"Saved patterns to files \n\n";
}

/**
 * @brief System::Load: when user start game,
 * load all existing patterns from files, so user could use them in this game.
 */
void System::Load()
{
    std::cout<<"Loading patterns from files \n";
    PatternLoadFromFile("gameoflife.txt", patternWorld);
    PatternLoadFromFile("pattern1.txt", pattern1);
    PatternLoadFromFile("pattern2.txt", pattern2);
    PatternLoadFromFile("pattern3.txt", pattern3);
    PatternLoadFromFile("pattern4.txt", pattern4);
    PatternLoadFromFile("pattern5.txt", pattern5);
    PatternLoadFromFile("pattern6.txt", pattern6);
    PatternLoadFromFile("pattern7.txt", pattern7);
    PatternLoadFromFile("pattern8.txt", pattern8);
    PatternLoadFromFile("pattern9.txt", pattern9);
    std::cout<<"Loaded patterns from files \n\n";
}

/**
 * @brief System::PatternSave
 * when click on save button, save coordinates of cells to pattern vectors.
 * @param patternList: the pattern vector to be saved.
 */
void System::PatternSave(std::vector<std::pair<int, int> >& patternList)
{
    patternList.clear();
    for(int i=0; i<SIZE_OF_ARRAY; i++)
    {
        for(int j=0; j<SIZE_OF_ARRAY; j++)
        {
            if (World[i][j])
            {
                patternList.push_back(std::make_pair(j, i));
            }
        }
    }
}

/**
 * @brief System::PatternSaveToFile: save pattern vector to file
 * @param fileName: file name of this saved pattern
 * @param patternList: pattern vector to be saved
 */
void System::PatternSaveToFile(std::string fileName, std::vector<std::pair<int, int> > patternList)
{
    std::ofstream inFile;

    inFile.open(fileName.c_str());
    for(int i=0; i<patternList.size(); i++)
    {
        inFile<<" ";
        inFile<<patternList[i].first;
        inFile<<" ";
        inFile<<patternList[i].second;

    }
    inFile.close();
}

/**
 * @brief System::PatternLoad: load pattern vector from file
 * @param patternList: pattern vector to be loaded
 */
void System::PatternLoad(std::vector<std::pair<int, int> > patternList)
{
    Initial(World);
    for(int i=0; i<patternList.size(); i++)
    {
        World[patternList[i].second][patternList[i].first] = 1;
    }
}

/**
 * @brief System::PatternLoadFromFile: load pattern vector from file
 * @param fileName: file name of loading pattern
 * @param patternList: pattern vector to be loaded
 */
void System::PatternLoadFromFile(std::string fileName, std::vector<std::pair<int, int> > &patternList)
{
    std::ifstream inFile;
    inFile.open(fileName.c_str());
    int first;
    int second;
    while (!inFile.eof() && !IsEmptyFile(inFile))
    {
        inFile>>first;
        inFile>>second;
        patternList.push_back(std::make_pair(first, second));
    }

    inFile.close();
}

/**
 * @brief System::IsEmptyWorld: check if the world is empty
 * @param Array: 2D array of world
 * @return boolean: true if there is not any cell in the world
 *                  false if there are cells in the world
 */
bool System::IsEmptyWorld(int Array[][SIZE_OF_ARRAY])
{
    for(int i=0; i<SIZE_OF_ARRAY; i++)
    {
        for(int j=0; j<SIZE_OF_ARRAY; j++)
        {
            if(Array[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief System::IsEmptyFile: check if the pattern file is empty
 * @param inFile: name of file
 * @return boolean: true if file is empty, false if file is not empty
 */
bool System::IsEmptyFile(std::ifstream& inFile)
{
    return inFile.peek() == std::ifstream::traits_type::eof();
}

/**
 * @brief System::IdentifyButton: identitfy which button the mouse was clicked on
 * @param x: x-axis corrdinate of mouse
 * @param y: y-axis corrdinate of mouse
 * @return integer: number represents different buttons on screen
 */
int System::IdentifyButton(int x, int y)
{
    // cells
    if(x < SIZE_OF_ARRAY && y < SIZE_OF_ARRAY)
    {
        return 0;
    }
    else
    {
        // start: Run (button_1)
        if(y <= CEW)
        {
            return 1;
        }

        // stop: Pause (button_2)
        else if(y>CEW && y<=2*CEW)
        {
            return 2;
        }

        // add: add 50 cells (button_3)
        else if(y>2*CEW && y<=3*CEW)
        {
            return 3;
        }

        // clean: clean up world (button_4)
        else if(y>3*CEW && y<=4*CEW)
        {
            return 4;
        }

        // Load World (button_5)
        else if(y>4*CEW && y<=5*CEW)
        {
            return 5;
        }

        // Save World (button_6)
        else if(y>5*CEW && y<=6*CEW)
        {
            return 6;
        }
        // Save Pattern
        else if(y>=7*CEW && y<8*CEW)
        {
            if(x>=SIZE_OF_ARRAY+1 && x<SIZE_OF_ARRAY+4)
            {
                return 11; // Save Pattern 1
            }
            else if(x>=SIZE_OF_ARRAY+5 && x<SIZE_OF_ARRAY+8)
            {
                return 12; // Save Pattern 2
            }
            else if(x>=SIZE_OF_ARRAY+9 && x<SIZE_OF_ARRAY+12)
            {
                return 13; // Save Pattern 3
            }
        }
        else if(y>=8*CEW && y<9*CEW)
        {
            if(x>=SIZE_OF_ARRAY+1 && x<SIZE_OF_ARRAY+4)
            {
                return 14; // Save Pattern 4
            }
            else if(x>=SIZE_OF_ARRAY+5 && x<SIZE_OF_ARRAY+8)
            {
                return 15; // Save Pattern 5
            }
            else if(x>=SIZE_OF_ARRAY+9 && x<SIZE_OF_ARRAY+12)
            {
                return 16; // Save Pattern 6
            }
        }
        else if(y>=9*CEW && y<10*CEW)
        {
            if(x>=SIZE_OF_ARRAY+1 && x<SIZE_OF_ARRAY+4)
            {
                return 17; // Save Pattern 7
            }
            else if(x>=SIZE_OF_ARRAY+5 && x<SIZE_OF_ARRAY+8)
            {
                return 18; // Save Pattern 8
            }
            else if(x>=SIZE_OF_ARRAY+9 && x<SIZE_OF_ARRAY+12)
            {
                return 19; // Save Pattern 9
            }
        }

        // Load Pattern
        else if(y>=11*CEW && y<12*CEW)
        {
            if(x>=SIZE_OF_ARRAY+1 && x<SIZE_OF_ARRAY+4)
            {
                return 21; // Load Pattern 1
            }
            else if(x>=SIZE_OF_ARRAY+5 && x<SIZE_OF_ARRAY+8)
            {
                return 22; // Load Pattern 2
            }
            else if(x>=SIZE_OF_ARRAY+9 && x<SIZE_OF_ARRAY+12)
            {
                return 23; // Load Pattern 3
            }
        }
        else if(y>=12*CEW && y<13*CEW)
        {
            if(x>=SIZE_OF_ARRAY+1 && x<SIZE_OF_ARRAY+4)
            {
                return 24; // Load Pattern 4
            }
            else if(x>=SIZE_OF_ARRAY+5 && x<SIZE_OF_ARRAY+8)
            {
                return 25; // Load Pattern 5
            }
            else if(x>=SIZE_OF_ARRAY+9 && x<SIZE_OF_ARRAY+12)
            {
                return 26; // Load Pattern 6
            }
        }
        else if(y>=13*CEW && y<14*CEW)
        {
            if(x>=SIZE_OF_ARRAY+1 && x<SIZE_OF_ARRAY+4)
            {
                return 27; // Load Pattern 7
            }
            else if(x>=SIZE_OF_ARRAY+5 && x<SIZE_OF_ARRAY+8)
            {
                return 28; // Load Pattern 8
            }
            else if(x>=SIZE_OF_ARRAY+9 && x<SIZE_OF_ARRAY+12)
            {
                return 29; // Load Pattern 9
            }
        }
        else
        {
            return -1;
        }
    }
}

/**
 * @brief System::GameStatus: get status of game
 * @return boolean: ture if game is paused, false if game is running
 */
bool System::GameStatusIsPause()
{
    return this->Pause;
}
