//
// Created by Oreofe Solarin on 8/29/22.
//
#include <iostream>
using namespace std;


// Function of type void that counts down
void countDown(int max) {
    while(max  != 0){
        cout << max << '\n';
        max--;

    }
}


// Function that returns a floating type after computing the average of three given numbers
float average(int a, int b, int c) {
    cout << "average of " << a << " " << b <<" "<< c << "\n";
    return (a + b + c) / 3;
}

// Function that returns a boolean type if the tow truth values are true and false
bool isTrue(bool one, bool two){
    return one == two ? 0 : one || two;

}

// Function that checks a char inputted is "Y" else keeps running till "Y" is inputted
int checkMe(){
    string m;

    while(m != "Y"){
        cout << "Enter any char, enter Y to exit  \n";
        cin  >> m;
    }
    return 0;
}

// Function that returns a int type after computing the factorial of the given number
int factorial(int number){
    int fact = 1;
    while (number != 0) {
      fact = number * fact;
      number--;
    }
    return fact;
}