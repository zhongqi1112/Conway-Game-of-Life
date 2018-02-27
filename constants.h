#ifndef CONSTANTS_H
#define CONSTANTS_H

//User can change the following data:

const int SCREEN_WIDTH = 1600; //change width of screen
const int SCREEN_HEIGHT = 900; //change height of screen
const int size=100; //change size of array
const int cell_lengh=8; // change the size of each cell & the size of buttons
const int outline=1; //change the distance between two cells
const int CEW=4; // change the how many cell the button equal

//User can not change:
const int button_x=(size+1)*cell_lengh;
const int word_size=CEW*cell_lengh; //Size of word

#endif // CONSTANTS_H
