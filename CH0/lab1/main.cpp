#include <iostream>
#include "count.h"

using namespace std;

// Prototype function of [countDown] function
void countDown1(int max);

int main() {
    // For Lab Par1
    cout << "Lab Part 1\n";
    string name;
    cout << "Enter your name \n";
    cin >> name;
    cout << "Hello, World! " << name << endl;

    // For Lab Par2
    cout << "Lab Part 2\n";
    countDown1(21);

    // For Lab Par3
    cout << "Lab Part 3\n";
    countDown(21);


    // For Lab P1
    cout << "Lab P1\n";
    cout << "Ans: " << average(4,7, 10) << '\n';


    // For Lab P2
     cout << "Lab P2\n";
    cout << "Value a: " << 0 << "Value b: " << 1 << "\n" << "Ans: " << isTrue(0,1) << "\n";

    // For Lab P3
    cout << "Lab P3\n";
    checkMe();

    // For Lab P4
    cout << "Lab P4 Test factorial (4)";
    cout << '\n' <<factorial(4);


    return 0;
}


// Function of type void that counts down
void countDown1(int max ){
    while(max  != 0){
        cout << max << '\n';
        max--;

    }
}
