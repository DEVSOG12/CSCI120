//
// Created by Oreofe Solarin on 12/4/22.
//

#include <iostream>
//#include "blocks.cpp"
//#include <vector>
#include <random>
#include <fstream>

using namespace std;
// We will be a creating a recreation of the game "Mondrian Blocks" using the C++ language. The game is a puzzle game where the player must place blocks of different shapes and colors on a grid. The goal is to fill the grid with blocks without overlapping any blocks. The game is played on a 10x10 grid. The player has 7 different blocks to choose from. Each block has a different shape and color. The blocks are as follows:
// Grid = 0
// Grid = 8x8

// 3 Black Blocks consisting: 1x1, 1x2, 1x3 = 1 + 2 + 3 = 6
// Black Blocks = F (fixed)

// 3 Yellow blocks consisting: 2x3, 2x4, and 2x5 = 6 + 8 + 10 = 24 blocks
// Yellow Blocks = Y

// 2 blue blocks consisting: 2x2 and 3x3 = 4 + 9 = 13 blocks
// Blue Blocks = B

// 2 white blocks consisting of 1x4 and 1x5 = 4 + 5 = 9 blocks
// White Blocks = W

// 1 red block consisting of: 3x4. = 12 blocks
// Red Blocks = R

//Total Blocks = 6 + 24 + 13 + 9 + 12 = 64 blocks
// A function to create a 8x8 matrix of "0"s as a char grid to represent the game board



void createGrid(vector<vector<char>>& grid) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            grid[i][j] = '0';
        }
    }
}

bool isEmpty(vector<vector<char>>& grid, int row, int col) {
    // if the space is "0" then it is empty
    if (grid[row][col]  == '0') {
        return true;
    }
        // if the space is not "0" then it is not empty
    else {
        return false;
    }
}



// Black Blocks = F (fixed)
// 1x1, 1x2, 1x3

// populateBlack will take in the grid as a parameter
void populateBlack(vector<vector<char>>& grid , int row1, int col1, int row2, int col2, int row3, int col3) {
    // check if the space is empty
    // if the space is empty then place the block
    // if the space is not empty then do not place the block
    // place a block of size 1x1 in the grid[0][0] position
    if (isEmpty(grid, row1, col1)) {
        grid[row1][col1] = 'F';
    }
    // place a block of size 1x2 in the grid[0][1] position
    if (isEmpty(grid, row2, col2)) {
        grid[row2][col2] = 'F';
        grid[row2 + 1][col2] = 'F';
    }
    // place a block of size 1x3 in the grid[0][2] position
    if (isEmpty(grid, row3, col3)) {
        grid[row3][col3] = 'F';
        grid[row3 +1][col3] = 'F';
        grid[row3 +2][col3] = 'F';
    }

}


/// Yellow Blocks = Y
/// 2x3, 2x4, and 2x5
bool placeYellow(vector<vector<char>>& grid, int row, int col, int caseNum, bool isVertical) {

    // Place each different block in the grid randomly if the space is empty and if the block is not overlapping another block

    switch (caseNum) {
        /// 2x3 if [isVertical] is false
        /// 3x2 if [isVertical] is true
        case 0:
            // 2x3
            // if is Vertical is true then place the block vertically as 2x3]
            // else then place the block horizontally as 3x2

            if (!isVertical) {
                /// 2x3 Vertical
                if (isEmpty(grid, row, col) && isEmpty(grid, row, col + 1) && isEmpty(grid, row, col + 2)) {
                    grid[row][col] = 'Y';
                    grid[row][col + 1] = 'Y';
                    grid[row][col + 2] = 'Y';
                    grid[row + 1][col] = 'Y';
                    grid[row + 1][col + 1] = 'Y';
                    grid[row + 1][col + 2] = 'Y';

                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                /// 3x2 Horizontal
                if (isEmpty(grid, row, col) && isEmpty(grid, row + 1, col) && isEmpty(grid, row + 2, col)) {
                    // Place 3x2 matrix of "Y"s in the grid
                    grid[row][col] = 'Y';
                    grid[row + 1][col] = 'Y';
                    grid[row + 2][col] = 'Y';
                    grid[row][col + 1] = 'Y';
                    grid[row + 1][col + 1] = 'Y';
                    grid[row + 2][col + 1] = 'Y';

                    return true;
                }
                else {
                    return false;
                }
            }

        case 1:
            /// 2x4
            /// if is Vertical is true then place the block vertically as 4x2
            /// else then place the block horizontally as 2x4
            if (!isVertical) {
                /// 2x4 Horizontal
                if (isEmpty(grid, row, col) && isEmpty(grid, row, col + 1) && isEmpty(grid, row, col + 2) && isEmpty(grid, row, col + 3)) {
                    grid[row][col] = 'Y';
                    grid[row][col + 1] = 'Y';
                    grid[row][col + 2] = 'Y';
                    grid[row][col + 3] = 'Y';
                    grid[row + 1][col] = 'Y';
                    grid[row + 1][col + 1] = 'Y';
                    grid[row + 1][col + 2] = 'Y';
                    grid[row + 1][col + 3] = 'Y';

                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                /// 4x2 Vertical
                if (isEmpty(grid, row, col) && isEmpty(grid, row + 1, col) && isEmpty(grid, row + 2, col) && isEmpty(grid, row + 3, col)) {
                    grid[row][col] = 'Y';
                    grid[row + 1][col] = 'Y';
                    grid[row + 2][col] = 'Y';
                    grid[row + 3][col] = 'Y';
                    grid[row][col + 1] = 'Y';
                    grid[row + 1][col + 1] = 'Y';
                    grid[row + 2][col + 1] = 'Y';
                    grid[row + 3][col + 1] = 'Y';
                    return true;
                }
                else {
                    return false;
                }
            }
        case 2:
            /// 2x5
            /// if is Vertical is true then place the block vertically as 5x2
            /// else then place the block horizontally as 2x5

            if (!isVertical) {
                /// 2x5 Horizontal
                if (isEmpty(grid, row, col) && isEmpty(grid, row, col + 1) && isEmpty(grid, row, col + 2) && isEmpty(grid, row, col + 3) && isEmpty(grid, row, col + 4)) {
                    grid[row][col] = 'Y';
                    grid[row][col + 1] = 'Y';
                    grid[row][col + 2] = 'Y';
                    grid[row][col + 3] = 'Y';
                    grid[row][col + 4] = 'Y';
                    grid[row + 1][col] = 'Y';
                    grid[row + 1][col + 1] = 'Y';
                    grid[row + 1][col + 2] = 'Y';
                    grid[row + 1][col + 3] = 'Y';
                    grid[row + 1][col + 4] = 'Y';

                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                /// 5x2 Vertical
                if (isEmpty(grid, row, col) && isEmpty(grid, row + 1, col) && isEmpty(grid, row + 2, col) && isEmpty(grid, row + 3, col) && isEmpty(grid, row + 4, col)) {
                    grid[row][col] = 'Y';
                    grid[row + 1][col] = 'Y';
                    grid[row + 2][col] = 'Y';
                    grid[row + 3][col] = 'Y';
                    grid[row + 4][col] = 'Y';
                    grid[row][col + 1] = 'Y';
                    grid[row + 1][col + 1] = 'Y';
                    grid[row + 2][col + 1] = 'Y';
                    grid[row + 3][col + 1] = 'Y';
                    grid[row + 4][col + 1] = 'Y';
                    return true;

                }
                else {
                    return false;
                }
            }

        default:
            return false;
    }

}

// Blue Blocks = B
bool placeBlue(vector<vector<char>>& grid, int row, int col, int caseNum) {

    // Place each different block in the grid randomly if the space is empty and if the block is not overlapping another block

    switch (caseNum) {
        case 0:
            // 2x2
            if (isEmpty(grid, row, col) && isEmpty(grid, row + 1, col) && isEmpty(grid, row, col + 1) && isEmpty(grid, row + 1, col + 1)) {
                grid[row][col] = 'B';
                grid[row + 1][col] = 'B';
                grid[row][col + 1] = 'B';
                grid[row + 1][col + 1] = 'B';
                return true;
            }
            else {
                return false;
            }
        case 1:
            // 3x3
            if (isEmpty(grid, row, col) && isEmpty(grid, row + 1, col) && isEmpty(grid, row + 2, col) && isEmpty(grid, row, col + 1) && isEmpty(grid, row + 1, col + 1) && isEmpty(grid, row + 2, col + 1) && isEmpty(grid, row, col + 2) && isEmpty(grid, row + 1, col + 2) && isEmpty(grid, row + 2, col + 2)) {
                grid[row][col] = 'B';
                grid[row + 1][col] = 'B';
                grid[row + 2][col] = 'B';
                grid[row][col + 1] = 'B';
                grid[row + 1][col + 1] = 'B';
                grid[row + 2][col + 1] = 'B';
                grid[row][col + 2] = 'B';
                grid[row + 1][col + 2] = 'B';
                grid[row + 2][col + 2] = 'B';
                return true;
            }
            else {
                return false;
            }
        default:
            return false;
    }

}

// Red Blocks = R
bool placeRed(vector<vector<char>>& grid, int row, int col, int caseNum, bool isVertical) {

    // Place each different block in the grid randomly if the space is empty and if the block is not overlapping another block

    switch (caseNum) {
        case 0:
            // 3x4
            // If the block is vertical then 4x3  else 3x4
            if (!isVertical) {
                if (isEmpty(grid, row, col) && isEmpty(grid, row + 1, col) && isEmpty(grid, row + 2, col) && isEmpty(grid, row, col + 1) && isEmpty(grid, row + 1, col + 1) && isEmpty(grid, row + 2, col + 1) && isEmpty(grid, row, col + 2) && isEmpty(grid, row + 1, col + 2) && isEmpty(grid, row + 2, col + 2) && isEmpty(grid, row, col + 3) && isEmpty(grid, row + 1, col + 3) && isEmpty(grid, row + 2, col + 3)) {
                    grid[row][col] = 'R';
                    grid[row + 1][col] = 'R';
                    grid[row + 2][col] = 'R';
                    grid[row][col + 1] = 'R';
                    grid[row + 1][col + 1] = 'R';
                    grid[row + 2][col + 1] = 'R';
                    grid[row][col + 2] = 'R';
                    grid[row + 1][col + 2] = 'R';
                    grid[row + 2][col + 2] = 'R';
                    grid[row][col + 3] = 'R';
                    grid[row + 1][col + 3] = 'R';
                    grid[row + 2][col + 3] = 'R';
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
//            Build 4x3
                if (isEmpty(grid, row, col) && isEmpty(grid, row + 1, col) && isEmpty(grid, row, col + 1) && isEmpty(grid, row + 1, col + 1) && isEmpty(grid, row, col + 2) && isEmpty(grid, row + 1, col + 2) && isEmpty(grid, row, col + 3) && isEmpty(grid, row + 1, col + 3) && isEmpty(grid, row + 2, col) && isEmpty(grid, row + 2, col + 1) && isEmpty(grid, row + 2, col + 2) && isEmpty(grid, row + 2, col + 3)) {
                    // Build a 4x3 block
                    grid[row][col] = 'R'; //1
                    grid[row + 1][col] = 'R'; //2
                    grid[row][col + 1] = 'R'; // 5
                    grid[row + 1][col + 1] = 'R'; // 6
                    grid[row][col + 2] = 'R'; // 9
                    grid[row + 1][col + 2] = 'R'; // 10
                    grid[row + 2][col] = 'R'; //3
                    grid[row + 3][col] = 'R'; //4
                    grid[row + 2][col + 1] = 'R'; //7
                    grid[row + 3][col + 1] = 'R'; //8
                    grid[row + 2][col + 2] = 'R'; //11
                    grid[row + 3][col + 2] = 'R'; //12


                    return true;
                }
                else {
                    return false;
                }
            }

        default:
            return false;
    }

}

// White Blocks = W
// 1x4 1x5
bool placeWhite(vector<vector<char>>& grid, int row, int col, int caseNum, bool isVertical) {

    // Place each different block in the grid randomly if the space is empty and if the block is not overlapping another block

    switch (caseNum) {
        case 0:
            // 1x4
            if (!isVertical) {
                if (isEmpty(grid, row, col) && isEmpty(grid, row, col + 1) && isEmpty(grid, row, col + 2) && isEmpty(grid, row, col + 3)) {
                    grid[row][col] = 'W';
                    grid[row][col + 1] = 'W';
                    grid[row][col + 2] = 'W';
                    grid[row][col + 3] = 'W';

                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                //4x1
                if (isEmpty(grid, row, col) && isEmpty(grid, row + 1, col) && isEmpty(grid, row + 2, col) && isEmpty(grid, row + 3, col)) {
                    grid[row][col] = 'W';
                    grid[row + 1][col] = 'W';
                    grid[row + 2][col] = 'W';
                    grid[row + 3][col] = 'W';

                    return true;
                }
                else {
                    return false;
                }
            }

        case 1:
            // 1x5
            if (!isVertical) {
                if (isEmpty(grid, row, col) && isEmpty(grid, row, col + 1) && isEmpty(grid, row, col + 2) && isEmpty(grid, row, col + 3) && isEmpty(grid, row, col + 4)) {
                    grid[row][col] = 'W';
                    grid[row][col + 1] = 'W';
                    grid[row][col + 2] = 'W';
                    grid[row][col + 3] = 'W';
                    grid[row][col + 4] = 'W';
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                //5x1
                if (isEmpty(grid, row, col) && isEmpty(grid, row + 1, col) && isEmpty(grid, row + 2, col) && isEmpty(grid, row + 3, col) && isEmpty(grid, row + 4, col)) {
                    grid[row][col] = 'W';
                    grid[row + 1][col] = 'W';
                    grid[row + 2][col] = 'W';
                    grid[row + 3][col] = 'W';
                    grid[row + 4][col] = 'W';

                    return true;
                }
                else {
                    return false;
                }
            }
        default:
            return false;
    }

}

void placeOrientedBlack(vector<vector<char>>& grid, int numSpace, int row, int col, bool orient) {
    if (orient){
        for (int count = 0; count < numSpace ; count++){
            if (isEmpty(grid, row, col)){
                grid[row][col] = 'F';
                row ++;
            }
        }
    }
    else{
        for (int count =0; count < numSpace ; count++){
            if (isEmpty(grid, row, col)){
                grid[row][col] = 'F';
                col ++;
            }
        }
    }
}

// Check if the whole grid is filled by check if each space is filled with anything other than '0'
bool isGridFull(vector<vector<char>>& grid) {
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (grid[row][col] == '0') {
                return false;
            }
        }
    }
    return true;
}



void printGrid(vector<vector<char>>& grid) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Prompting user to choose level
int chooseDifficulty () {
    cout << "What level of difficulty do you want for your puzzle? Easy: 1-6, Intermediate: 23- 28 ,Advanced: 45-50, Expert: 67-72 :  " ;
    int setlevel;
    cin >> setlevel;

    //Loop
    while (!((setlevel >= 1 && setlevel <= 6 )|| (setlevel >= 23 && setlevel <= 28 ) || (setlevel >= 45 && setlevel <= 50 ) || (setlevel >= 67 && setlevel <= 72 ))){
        cout << "Please Try Again using the Given Parameters:  " ;
        cin >> setlevel;
    }
    return setlevel;
}

int main() {
    vector<vector<char>> grid;

// Choosing level
    char level = chooseDifficulty();


// Filename
    string fileName;
    string myText;

    fileName = "Level" + to_string(level) + ".txt";

    cout << "This is your chosen level" << endl;

    ifstream file("/Users/oreofe/Desktop/CS120/SmartPtrDemo/" + fileName);
    string line;
    // Read the next line from File untill it reaches the end. into a vector<char> not including white space
    while (getline(file, line)) {
        vector<char> row;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ') {
                row.push_back(line[i]);
            }
        }
        grid.push_back(row);
    }

    // Close the file
    file.close();


   // While the grid is not full,
   // User is prompted to choose a block to place at a specific location row and column
    // The block is placed in the grid if the space is empty and if the block is not overlapping another block
    // If the block is not successfully placed, the user is prompted to choose another block to place at a specific location row and column
    // If the block is successfully placed, the user is prompted to choose another block to place at a specific location row and column

    vector<vector<char>> grid2 = grid;
    while (!isGridFull(grid)) {

        printGrid(grid);
        char color;
        cout << "What color block do you want to place? (W for white, Y for Yellow, R for Red, and B for Blue): "
             << endl;
        cin >> color;


        // Ask which size block they want to place based on the color
        int size;
        switch (color) {
            case 'W':
                cout << "What size block do you want to place? (1 for 1x4, 2 for 1x5): " << endl;
                cin >> size;
                break;
            case 'Y':
                cout << "What size block do you want to place? (1 for 2x3, 2 for 2x4, 3 for 2x5): " << endl;
                cin >> size;
                break;
            case 'R':
                cout << "What size block do you want to place? (1 for 3x4): " << endl;
                cin >> size;
                break;
            case 'B':
                cout << "What size block do you want to place? (1 for 2x2, 2 for 3x3): " << endl;
                cin >> size;
                break;
            default:
                // If the user enters an invalid color, the user is prompted to choose a valid color
                cout << "Please enter a valid color" << endl;
                continue;
        }
        // Ask user if they want to place the block vertically or horizontally
        bool orientation;
        if (color != 'B') {
            cout << "Do you want to place the block vertically or horizontally? (V for vertical, H for horizontal): "
                 << endl;
            char orient;
            cin >> orient;
           // If the user enters an invalid orientation, the user is prompted to choose a valid orientation
            while (orient != 'V' && orient != 'H') {
                cout << "Please enter a valid orientation" << endl;
                cin >> orient;
            }
            orientation = (orient == 'V');
        }
        // Ask user what color block they want to place
        int row, col;
        cout << "Enter the row and column of the block you want to place: " << endl;
        cin >> row >> col;
        // If the user enters an invalid row or column, the user is prompted to choose a valid row or column
        while (row < 0 || row > 7 || col < 0 || col > 7) {
            cout << "Please enter a valid row and column" << endl;
            cin >> row >> col;
        }

        // Place the block in the grid if the space is empty and if the block is not overlapping another block
        // If the block is not successfully placed, the user is prompted to choose another block to place at a specific location row and column

        if (color == 'W') {
            if (size == 1) {
                if (placeWhite(grid, row, col, size - 1, orientation)) {
                    cout << "Block successfully placed." << endl;
                } else {
                    cout << "Block not successfully placed. Please try again." << endl;
                }
            } else if (size == 2) {
                if (placeWhite(grid, 2, row, size - 1, orientation)) {
                    cout << "Block successfully placed." << endl;
                } else {
                    cout << "Block not successfully placed. Please try again." << endl;
                }
            }
        } else if (color == 'Y') {
            if (size == 1) {
                if (placeYellow(grid, row, col, size - 1, orientation )) {
                    cout << "Block successfully placed." << endl;
                } else {
                    cout << "Block not successfully placed. Please try again." << endl;
                }
            } else if (size == 2) {
                if (placeYellow(grid, row, col, size - 1, orientation )) {
                    cout << "Block successfully placed." << endl;
                } else {
                    cout << "Block not successfully placed. Please try again." << endl;
                }
            } else if (size == 3) {
                if (placeYellow(grid, row, col, size - 1, orientation)) {
                    cout << "Block successfully placed." << endl;
                } else {
                    cout << "Block not successfully placed. Please try again." << endl;
                }
            }
        } else if (color == 'R') {
            if (size == 1) {
                if (placeRed(grid, row, col, size - 1, orientation)) {
                    cout << "Block successfully placed." << endl;
                } else {
                    cout << "Block not successfully placed. Please try again." << endl;
                }
            }
        } else if (color == 'B') {
            if (size == 1) {
                if (placeBlue(grid, row, col, size - 1)) {
                    cout << "Block successfully placed." << endl;
                } else {
                    cout << "Block not successfully placed. Please try again." << endl;
                }
            } else if (size == 2) {
                if (placeBlue(grid, row, col, size - 1)) {
                    cout << "Block successfully placed." << endl;
                } else {
                    cout << "Block not successfully placed. Please try again." << endl;
                }
            }

        }

        // Ask user if they want to clear the grid
        printGrid(grid);
        cout << "Do you want to clear the grid? (Y for yes, N for no): " << endl;
        char clear;
        cin >> clear;
        if (clear == 'Y') {
            grid2 = grid;
        }




    }


//     if(placeWhite(grid, 0, 0, 0, true)){
//         cout << "Placed W-1x4" << endl;
//     }
//     else{
//         cout << "Failed to place W-1x4" << endl;
//     }
//
//    if(placeWhite(grid, 1, 0, 1, true)){
//        cout << "Placed W-1x5" << endl;
//    }
//    else{
//        cout << "Failed to place W-1x5" << endl;
//    }

//    if(placeRed(grid, 2, 0, 0, true)){
//        cout << "Placed R-4x3" << endl;
//    }
//    else{
//        cout << "Failed to place R-4x3" << endl;
//    }

//    if(placeYellow(grid, 0, 0, 0, true)){
//        cout << "Placed Y-2x3" << endl;
//    }
//    else{
//        cout << "Failed to place Y-2x3" << endl;
//    }
//
//    if(placeYellow(grid, 0, 0, 1, true)){
//        cout << "Placed Y-2x4" << endl;
//    }
//    else{
//        cout << "Failed to place Y-2x4" << endl;
//    }
//
//    if(placeYellow(grid, 0, 5, 2, true)){
//        cout << "Placed Y-2x5" << endl;
//    }
//    else{
//        cout << "Failed to place Y-2x5" << endl;
//    }
//
//    if(placeBlue(grid, 0, 0, 0)){
//        cout << "Placed B-2x2" << endl;
//    }
//    else{
//        cout << "Failed to place B-2x2" << endl;
//    }

//    if (placeBlue(grid, 0, 0, 1)) {
//        cout << "Placed B-3x3" << endl;
//    } else {
//        cout << "Failed to place B-3x3 Please pick a different location" << endl;
//    }


    printGrid(grid);
//
}
