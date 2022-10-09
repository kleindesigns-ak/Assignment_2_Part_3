// Author   : Austin Klein (With a base function originating from CS-A211 @ UAA)
// Date     : 08-Oct-22
// Purpose  : Class Assignment 2 Part 3 (Mazes)
// Details  :

#include <iostream>
using namespace std;

const int width = 40;
const int height = 40;

void initMaze(char maze[][height]);
// ///////////////////////
// ///  MAIN PROGRAM   ///
// ///////////////////////
int main() {
    // Init maze with 'X' borders and filled with all spaces
    char maze[width][height];
    initMaze(maze);


    return 0;
}

// ///////////////////////
// FUNCTION DEFINITIONS //
// ///////////////////////

void initMaze(char maze[][height]){
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            if (row == 0 || row == height - 1 || column == 0 || column == width - 1) maze[row][column] = 'X';
            else maze[row][column] = ' ';
        }
    }
}