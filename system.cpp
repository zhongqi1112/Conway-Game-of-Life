#include "system.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;

System::System()
{
    Initial(World);
}

void System::Initial(int Array[][size]) //Make all cells of the Array to 0
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            Array[i][j]=0;
        }
    }
}

void System::Random () //Add 50 cells into the screen
{
    //    Initial(World);
    for(int i=0; i<50; i++)
    {
        int x=rand() % size;
        int y=rand() % size;
        while(World[x][y])
        {
            x=rand() % size;
            y=rand() % size;
        }
        World[x][y]=1;
    }
}

void System::Step()
{
    //call the System to calculate the next generation
    //from here. uyou must bring in all the required
    //funcionts and make them part of the class.
    if(!pause)
    {
        Initial(NeighborCount); //Make every cell of NeighborCOunt array to 0
        NextGen(); //Get the next generation
    }
}

void System::Draw(sf::RenderWindow &window) //Display every thing on screen
{
    //There are cells, Button, and Pattern:
    sf::Vector2f Size(cell_lengh, cell_lengh); //size of cells
    sf::Vector2f pattern(3*cell_lengh, 3*cell_lengh); //size of pattern
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::RectangleShape shape;
    sf::RectangleShape patternS1;
    sf::RectangleShape patternS2;
    sf::RectangleShape patternS3;
    sf::RectangleShape patternS4;
    sf::RectangleShape patternS5;
    sf::RectangleShape patternS6;
    sf::RectangleShape patternS7;
    sf::RectangleShape patternS8;
    sf::RectangleShape patternS9;
    sf::RectangleShape patternL1;
    sf::RectangleShape patternL2;
    sf::RectangleShape patternL3;
    sf::RectangleShape patternL4;
    sf::RectangleShape patternL5;
    sf::RectangleShape patternL6;
    sf::RectangleShape patternL7;
    sf::RectangleShape patternL8;
    sf::RectangleShape patternL9;
    sf::Text Button_1;
    sf::Text Button_2;
    sf::Text Button_3;
    sf::Text Button_4;
    sf::Text Button_5;
    sf::Text Button_6;
    sf::Text Button_7;
    sf::Text Button_8;

    Button_1.setFont(font);
    Button_2.setFont(font);
    Button_3.setFont(font);
    Button_4.setFont(font);
    Button_5.setFont(font);
    Button_6.setFont(font);
    Button_7.setFont(font);
    Button_8.setFont(font);

    Button_1.setString("Start");
    Button_2.setString("Stop");
    Button_3.setString("Random");
    Button_4.setString("Reset");
    Button_5.setString("Load");
    Button_6.setString("Save");
    Button_7.setString("Pattern Save");
    Button_8.setString("Pattern Load");

    shape.setSize(Size);
    patternS1.setSize(pattern);
    patternS2.setSize(pattern);
    patternS3.setSize(pattern);
    patternS4.setSize(pattern);
    patternS5.setSize(pattern);
    patternS6.setSize(pattern);
    patternS7.setSize(pattern);
    patternS8.setSize(pattern);
    patternS9.setSize(pattern);
    patternL1.setSize(pattern);
    patternL2.setSize(pattern);
    patternL3.setSize(pattern);
    patternL4.setSize(pattern);
    patternL5.setSize(pattern);
    patternL6.setSize(pattern);
    patternL7.setSize(pattern);
    patternL8.setSize(pattern);
    patternL9.setSize(pattern);
    Button_1.setCharacterSize(word_size);
    Button_2.setCharacterSize(word_size);
    Button_3.setCharacterSize(word_size);
    Button_4.setCharacterSize(word_size);
    Button_5.setCharacterSize(word_size);
    Button_6.setCharacterSize(word_size);
    Button_7.setCharacterSize(word_size);
    Button_8.setCharacterSize(word_size);

    patternS1.setFillColor(sf::Color::Red);
    patternS2.setFillColor(sf::Color::Red);
    patternS3.setFillColor(sf::Color::Red);
    patternS4.setFillColor(sf::Color::Red);
    patternS5.setFillColor(sf::Color::Red);
    patternS6.setFillColor(sf::Color::Red);
    patternS7.setFillColor(sf::Color::Red);
    patternS8.setFillColor(sf::Color::Red);
    patternS9.setFillColor(sf::Color::Red);
    patternL1.setFillColor(sf::Color::Red);
    patternL2.setFillColor(sf::Color::Red);
    patternL3.setFillColor(sf::Color::Red);
    patternL4.setFillColor(sf::Color::Red);
    patternL5.setFillColor(sf::Color::Red);
    patternL6.setFillColor(sf::Color::Red);
    patternL7.setFillColor(sf::Color::Red);
    patternL8.setFillColor(sf::Color::Red);
    patternL9.setFillColor(sf::Color::Red);
    Button_1.setColor(sf::Color::Red);
    Button_2.setColor(sf::Color::Red);
    Button_3.setColor(sf::Color::Red);
    Button_4.setColor(sf::Color::Red);
    Button_5.setColor(sf::Color::Red);
    Button_6.setColor(sf::Color::Red);
    Button_7.setColor(sf::Color::Red);
    Button_8.setColor(sf::Color::Red);

    patternS1.setPosition(button_x, 7*CEW*cell_lengh);
    patternS2.setPosition(button_x+4*cell_lengh, 7*CEW*cell_lengh);
    patternS3.setPosition(button_x+8*cell_lengh, 7*CEW*cell_lengh);
    patternS4.setPosition(button_x, 8*CEW*cell_lengh);
    patternS5.setPosition(button_x+4*cell_lengh, 8*CEW*cell_lengh);
    patternS6.setPosition(button_x+8*cell_lengh, 8*CEW*cell_lengh);
    patternS7.setPosition(button_x, 9*CEW*cell_lengh);
    patternS8.setPosition(button_x+4*cell_lengh, 9*CEW*cell_lengh);
    patternS9.setPosition(button_x+8*cell_lengh, 9*CEW*cell_lengh);
    patternL1.setPosition(button_x, 11*CEW*cell_lengh);
    patternL2.setPosition(button_x+4*cell_lengh, 11*CEW*cell_lengh);
    patternL3.setPosition(button_x+8*cell_lengh, 11*CEW*cell_lengh);
    patternL4.setPosition(button_x, 12*CEW*cell_lengh);
    patternL5.setPosition(button_x+4*cell_lengh, 12*CEW*cell_lengh);
    patternL6.setPosition(button_x+8*cell_lengh, 12*CEW*cell_lengh);
    patternL7.setPosition(button_x, 13*CEW*cell_lengh);
    patternL8.setPosition(button_x+4*cell_lengh, 13*CEW*cell_lengh);
    patternL9.setPosition(button_x+8*cell_lengh, 13*CEW*cell_lengh);
    Button_1.setPosition(button_x, 0);
    Button_2.setPosition(button_x, CEW*cell_lengh);
    Button_3.setPosition(button_x, 2*CEW*cell_lengh);
    Button_4.setPosition(button_x, 3*CEW*cell_lengh);
    Button_5.setPosition(button_x, 4*CEW*cell_lengh);
    Button_6.setPosition(button_x, 5*CEW*cell_lengh);
    Button_7.setPosition(button_x, 6*CEW*cell_lengh);
    Button_8.setPosition(button_x, 10*CEW*cell_lengh);

    window.draw(shape);
    window.draw(patternS1);
    window.draw(patternS2);
    window.draw(patternS3);
    window.draw(patternS4);
    window.draw(patternS5);
    window.draw(patternS6);
    window.draw(patternS7);
    window.draw(patternS8);
    window.draw(patternS9);
    window.draw(patternL1);
    window.draw(patternL2);
    window.draw(patternL3);
    window.draw(patternL4);
    window.draw(patternL5);
    window.draw(patternL6);
    window.draw(patternL7);
    window.draw(patternL8);
    window.draw(patternL9);
    window.draw(Button_1);
    window.draw(Button_2);
    window.draw(Button_3);
    window.draw(Button_4);
    window.draw(Button_5);
    window.draw(Button_6);
    window.draw(Button_7);
    window.draw(Button_8);

    //the edge: color and thickness
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(outline);

    //Check every cells, if it is alive, fill out one color. If not, fill out another color
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            float box_x=cell_lengh*j;
            float box_y=cell_lengh*i;
            shape.setPosition(box_x, box_y);
            if(World[i][j])
            {
                shape.setFillColor(sf::Color::Cyan);
            }
            else
            {
                shape.setFillColor(sf::Color::Black);
            }
            window.draw(shape);
            window.draw(Button_1);
            window.draw(Button_2);
            window.draw(Button_3);
            window.draw(Button_4);
            window.draw(Button_5);
            window.draw(Button_6);
            window.draw(Button_7);
            window.draw(Button_8);
        }
    }
}

void System::NextGen() //Get the next generation
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            int X=i;
            int Y=j;
            for(int i=X-1; i<=X+1; i++)
            {
                for(int j=Y-1; j<=Y+1; j++)
                {
                    if(i==-1 && j==-1)
                    {
                        if(World[size-1][size-1]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==-1 && j==size)
                    {
                        if(World[size-1][0]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==size && j==-1)
                    {
                        if(World[0][size-1]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==size && j==size)
                    {
                        if(World[0][0]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==-1)
                    {
                        if(World[size-1][j]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(j==-1)
                    {
                        if(World[i][size-1]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(j==size)
                    {
                        if(World[i][0]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==size)
                    {
                        if(World[0][j]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else
                    {
                        if(World[i][j]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                }
            }
            if(World[X][Y]==1)
            {
                NeighborCount[X][Y]--;
            }
        }
    }

    //2. Fill out World(Next Generation):
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
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

}

void System::Show(int Array[][size]) //Display a Tow D Array on the screen
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            cout<<Array[i][j]<<" ";
        }
        cout<<endl;
    }
}

void System::Mouse_Start(int Start_x, int Start_y) //When drag the mouse, where the mouse starts
{
    MousePosition[0]=Start_x;
    MousePosition[1]=Start_y;
}

void System::Mouse_End(int End_x, int End_y) //When drag the mouse, where the mouse ends
{
    MousePosition[2]=End_x;
    MousePosition[3]=End_y;
    cout<<"Start: ("<<MousePosition[0]<<", "<<MousePosition[2]<<")"<<endl;
    cout<<"End  : ("<<MousePosition[1]<<", "<<MousePosition[3]<<")"<<endl;
}

void System::PatternStartEndPointsSave(char patternName[]) //The starting coordinate of the patteren
{
    ofstream inFile;
    inFile.open(patternName);
    int w=MouseLastStep[2]-MouseLastStep[0];
    int h=MouseLastStep[3]-MouseLastStep[1];
    inFile<<w<<" "<<h<<" ";
}

void System::PatternStartEndPointsLoad(char patternName[]) //The stopping coordinate of the patteren
{
    ifstream inFile;
    inFile.open(patternName);
    for(int i=0; i<1; i++)
    {
        inFile>>WH[i];
    }
}

void System::PatternSave(char patternName[]) //Save the pattern into a txt
{
    int Max_x, Min_x, Max_y, Min_y;
    if(MouseLastStep[0]<MouseLastStep[2])
    {
        Max_x=MouseLastStep[2];
        Min_x=MouseLastStep[0];
    }
    else
    {
        Max_x=MouseLastStep[2];
        Min_x=MouseLastStep[0];
    }
    if(MouseLastStep[1]<MouseLastStep[3])
    {
        Max_y=MouseLastStep[3];
        Min_y=MouseLastStep[1];
    }
    else
    {
        Max_y=MouseLastStep[1];
        Min_y=MouseLastStep[3];
    }

    ofstream inFile;
    inFile.open(patternName);
    for(int i=MouseLastStep[1]; i<=MouseLastStep[3]; i++)
    {
        for(int j=MouseLastStep[0]; j<=MouseLastStep[2]; j++)
        {
            if(i>=Min_y && i<=Max_y && j>=Min_x && j<=Max_x)
            {
                inFile<<World[i][j]<<" ";
            }
            else
            {
                inFile<<"0 ";
            }
        }
    }
    inFile.close();
}

void System::PatternLoad(char patternName[]) //Load the Pattern from the txt
{
    cout<<"Click on the Button 5_Load"<<endl;//Load
    ifstream inFile;
    inFile.open(patternName);
    for(int i=MouseLastClickStep[1]; i<=MouseLastClickStep[1]+WH[1]; i++)
    {
        for(int j=MouseLastClickStep[0]; j<=MouseLastClickStep[0]+WH[0]; j++)
        {
            inFile>>World[i][j];
        }
    }
    pause=true;
    inFile.close();
}

void System::MouseLeft(int x, int y) //Where my mouse click
{
    if(MousePosition[0]==MousePosition[2] && MousePosition[1]==MousePosition[3])
    {
        //Cells:  Change Array & Change Color
        if(x<size)
        {
            MouseLastClickStep[0]=MousePosition[0];
            MouseLastClickStep[1]=MousePosition[1];
            //Cells
            cout<<"Click on the cells"<<endl;
            if(World[y][x])
            {
                World[y][x]=0;
            }
            else
            {
                World[y][x]=1;
            }
            pause=true;
        }
        else
        {
            //Stat: Run
            if(y<=CEW)
            {
                //button_1
                cout<<"Click on the Button 1_Strat"<<endl;//Strat
                pause=false;
            }

            //Stop: Pause
            else if(y>CEW && y<=2*CEW)
            {
                //button_2
                cout<<"Click on the Button 2_Stop"<<endl;//Stop
                pause=true;
            }

            //Random
            else if(y>2*CEW && y<=3*CEW)
            {
                //button_3
                cout<<"Click on the Button 3_Random"<<endl;//Random
                Random();
                pause=true;
            }

            //Reset
            else if(y>3*CEW && y<=4*CEW)
            {
                //button_4
                cout<<"Click on the Button 4_Reset"<<endl;//Reset
                Initial(World);
                pause=true;
            }

            //Load file
            else if(y>4*CEW && y<=5*CEW)
            {
                //button_5
                cout<<"Click on the Button 5_Load"<<endl;//Load
                ifstream inFile;
                inFile.open("gameoflife.txt");
                for(int i=0; i<size; i++)
                {
                    for(int j=0; j<size; j++)
                    {
                        inFile>>World[i][j];
                    }
                }
                pause=true;
                inFile.close();
            }

            //Button_6  Save file
            else if(y>5*CEW && y<=6*CEW)
            {
                cout<<"Click on the Button_6 Save"<<endl;//Save
                ofstream inFile;
                inFile.open("gameoflife.txt");
                for(int i=0; i<size; i++)
                {
                    for(int j=0; j<size; j++)
                    {
                        inFile<<World[i][j];
                        inFile<<" ";
                    }
                }
                inFile.close();
            }

            // Save Pattern 1
            else if(y>=7*CEW && y<8*CEW)
            {
                if(x>=size+1 && x<size+4)
                {
                    cout<<"Click on the Pattern Save 1"<<endl;//Pattern 1
                    PatternSave("pattern1.txt");
                    PatternStartEndPointsSave("patterncoordinate1.txt");
                }
                else if(x>=size+5 && x<size+8)
                {
                    cout<<"Click on the Pattern Save 2"<<endl;//Pattern 2
                    PatternSave("pattern2.txt");
                    PatternStartEndPointsSave("patterncoordinate2.txt");
                }
                else if(x>=size+9 && x<size+12)
                {
                    cout<<"Click on the Pattern Save 3"<<endl;//Pattern 3
                    PatternSave("pattern3.txt");
                    PatternStartEndPointsSave("patterncoordinate3.txt");
                }
            }
            else if(y>=8*CEW && y<9*CEW)
            {
                if(x>=size+1 && x<size+4)
                {
                    cout<<"Click on the Pattern Save 4"<<endl;//Pattern 4
                    PatternSave("pattern4.txt");
                    PatternStartEndPointsSave("patterncoordinate4.txt");
                }
                else if(x>=size+5 && x<size+8)
                {
                    cout<<"Click on the Pattern Save 5"<<endl;//Pattern 5
                    PatternSave("pattern5.txt");
                    PatternStartEndPointsSave("patterncoordinate5.txt");
                }
                else if(x>=size+9 && x<size+12)
                {
                    cout<<"Click on the Pattern Save 6"<<endl;//Pattern 6
                    PatternSave("pattern6.txt");
                    PatternStartEndPointsSave("patterncoordinate6.txt");
                }
            }
            else if(y>=9*CEW && y<10*CEW)
            {
                if(x>=size+1 && x<size+4)
                {
                    cout<<"Click on the Pattern Save 7"<<endl;//Pattern 7
                    PatternSave("pattern7.txt");
                    PatternStartEndPointsSave("patterncoordinate7.txt");
                }
                else if(x>=size+5 && x<size+8)
                {
                    cout<<"Click on the Pattern Save 8"<<endl;//Pattern 8
                    PatternSave("pattern8.txt");
                    PatternStartEndPointsSave("patterncoordinate8.txt");
                }
                else if(x>=size+9 && x<size+12)
                {
                    cout<<"Click on the Pattern Save 9"<<endl;//Pattern 9
                    PatternSave("pattern9.txt");
                    PatternStartEndPointsSave("patterncoordinate9.txt");
                }
            }

            //Load Pattern
            else if(y>=11*CEW && y<12*CEW)
            {
                if(x>=size+1 && x<size+4)
                {
                    cout<<"Click on the Pattern Load 1"<<endl;//Pattern 1
                    PatternStartEndPointsLoad("patterncoordinate1.txt");
                    PatternLoad("pattern1.txt");
                }
                else if(x>=size+5 && x<size+8)
                {
                    cout<<"Click on the Pattern Load 2"<<endl;//Pattern 2
                    PatternStartEndPointsLoad("patterncoordinate2.txt");
                    PatternLoad("pattern2.txt");
                }
                else if(x>=size+9 && x<size+12)
                {
                    cout<<"Click on the Pattern Load 3"<<endl;//Pattern 3
                    PatternStartEndPointsLoad("patterncoordinate3.txt");
                    PatternLoad("pattern3.txt");
                }
            }
            else if(y>=12*CEW && y<13*CEW)
            {
                if(x>=size+1 && x<size+4)
                {
                    cout<<"Click on the Pattern Load 4"<<endl;//Pattern 4
                    PatternStartEndPointsLoad("patterncoordinate4.txt");
                    PatternLoad("pattern4.txt");
                }
                else if(x>=size+5 && x<size+8)
                {
                    cout<<"Click on the Pattern Load 5"<<endl;//Pattern 5
                    PatternStartEndPointsLoad("patterncoordinate5.txt");
                    PatternLoad("pattern5.txt");
                }
                else if(x>=size+9 && x<size+12)
                {
                    cout<<"Click on the Pattern Load 6"<<endl;//Pattern 6
                    PatternStartEndPointsLoad("patterncoordinate6.txt");
                    PatternLoad("pattern6.txt");
                }
            }
            else if(y>=13*CEW && y<14*CEW)
            {
                if(x>=size+1 && x<size+4)
                {
                    cout<<"Click on the Pattern Load 7"<<endl;//Pattern 7
                    PatternStartEndPointsLoad("patterncoordinate7.txt");
                    PatternLoad("pattern7.txt");
                }
                else if(x>=size+5 && x<size+8)
                {
                    cout<<"Click on the Pattern Load 8"<<endl;//Pattern 8
                    PatternStartEndPointsLoad("patterncoordinate8.txt");
                    PatternLoad("pattern8.txt");
                }
                else if(x>=size+9 && x<size+12)
                {
                    cout<<"Click on the Pattern Load 9"<<endl;//Pattern 9
                    PatternStartEndPointsLoad("patterncoordinate9.txt");
                    PatternLoad("pattern9.txt");
                }
            }

            else
            {
                cout<<"There is no Button"<<endl;
            }
        }
    }
    else //Get the mouse position of the mouse click on the cells area
    {
        MouseLastStep[0]=MousePosition[0];
        MouseLastStep[1]=MousePosition[1];
        MouseLastStep[2]=MousePosition[2];
        MouseLastStep[3]=MousePosition[3];
    }
    cout<<endl;
}

