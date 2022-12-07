//
// Created by Oreofe Solarin on 12/4/22.
//

// Read from file into vector<vector<char>>.
// Each line is a vector of chars.
// Each vector of chars is a row.
// Each char is a column.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {


    // Print out the grid.
    for (vector<char> row : grid) {
        for (char c : row) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}