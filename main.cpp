// Author   : Austin Klein (With a base function originating from CS-A211 @ UAA)
// Date     : 08-Oct-22
// Purpose  : Class Assignment 2 Part 3 (Mazes)
// Details  :

#include <iostream>
#include <cmath>
using namespace std;

const int width = 40;
const int height = 40;

void initMaze(char maze[][width]);
void buildMaze(char maze[][width],int x0, int y0, int rows, int columns);
void printMaze(char maze[][width]);

// ///////////////////////
// ///  MAIN PROGRAM   ///
// ///////////////////////
int main() {
    srand(time(NULL));

    // Init maze with 'X' borders and filled with all spaces
    char maze[height][width];
    initMaze(maze);

    // Install walls in the maze with recursive buildMaze()
    // Requirements for each recursion include marking out interior space available by passing in (x, y) sub 0 as the top left point and inferring the rest through the size of the height and width minus the borders.
    int init_X_0 = 1;
    int init_Y_0 = 1;
    int init_rows = height - 2;
    int init_columns = width - 2;
    buildMaze(maze, init_X_0, init_Y_0, init_rows, init_columns);

    printMaze(maze);

    return 0;
}
// ///////////////////////////////////////////// End Main ////////////////////////////////////////////////////

// ///////////////////////
// FUNCTION DEFINITIONS //
// ///////////////////////

void initMaze(char maze[][width]){
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            if (row == 0 || row == height - 1 || column == 0 || column == width - 1) maze[row][column] = 'X';
            else maze[row][column] = ' ';
        }
    }
}

void buildMaze(char maze[][width],int x0, int y0, int rows, int columns){

    if (rows > 2 && columns > 2) {
        if (rows >= columns) {
            // Picks a random index of the passed in space corresponding to a row to build a wall across
            int randomRowWall = (rand()%(rows - 2))  + y0 + 1;
            for (int columnOfWall = x0; columnOfWall <= columns + x0 - 1; columnOfWall++) {
                maze[randomRowWall][columnOfWall] = 'X';
            }
            if (maze[randomRowWall][x0 - 1] != 'X') {
                maze[randomRowWall][x0] = ' ';
            }
            if (maze[randomRowWall][x0 + columns] != 'X') {
                maze[randomRowWall][x0 + columns - 1] = ' ';
            }
            maze[randomRowWall][(rand() % (columns - 2)) + x0 + 1] = ' ';

            // Build walls in the two halves generated from the construction of the previous wall
            buildMaze(maze, x0, y0, randomRowWall - y0, columns);
            buildMaze(maze, x0, randomRowWall + 1, rows - ((randomRowWall - y0) + 1), columns);
        }
        else {
            // Picks a random index of the passed in space corresponding to a column to build a wall across
            int randomColumnWall = (rand()%(columns - 2))  + x0 + 1;
            for (int rowOfWall = y0; rowOfWall <= rows + y0 - 1; rowOfWall++) {
                maze[rowOfWall][randomColumnWall] = 'X';
            }
            if (maze[y0 - 1][randomColumnWall] != 'X') {
                maze[y0][randomColumnWall] = ' ';
            }
            if (maze[y0 + rows][randomColumnWall] != 'X') {
                maze[y0 + rows - 1] [randomColumnWall]= ' ';
            }
            maze[(rand() % (rows - 2)) + y0 + 1][randomColumnWall] = ' ';
            // Build walls in the two halves generated from the construction of the previous wall
            buildMaze(maze, x0, y0, rows, randomColumnWall - x0);
            buildMaze(maze, randomColumnWall + 1, y0, rows, columns - ((randomColumnWall - x0) + 1));
        }
    }
}

void printMaze(char maze[][width]) {
    for (int rows = 0; rows < height; ++rows) {
        for (int columns = 0; columns < width; ++columns) {
            cout << maze[rows][columns];
        }
        cout << endl;
    }
    cout << endl;
}