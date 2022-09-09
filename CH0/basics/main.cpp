#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
using namespace std;

/*
 part of Prob 5
int Sum(int x, int y)
{
    return x + y;
}

//computes the sum of two formal input arguments, x and y,
//and places result in formal output parameter sum
void ComputeSum(int x, int y, int &sum)
{
    sum = x + y;
}
 
 */
int main() {

    // Problem .1
    /*   int no = 23;

       int a = no++;

       cout << "Variable a = " << a << endl;
       cout << "Variable n = " << no << endl;

Output:
Variable a = 23
Variable n = 24

// Problem .2
int no = 23;
int a = ++no;

  cout << "Variable a = " << a << endl;
  cout << "Variable n = " << no << endl;

Output:
  Variable a = 24
  Variable n = 24

// Problem .3
cout << fixed << setprecision(4) << 3.2 << endl;

Output:
3.2000



// Problem .4

typedef float real;



    // Problem .5

    int a, b;    //input from user
    cout << "Please enter two integers: ";
    cin >> a >> b;
    cout << "Sum from pass by value = " << Sum(a, b) << endl; //actual parameters a, b

    int mySum;    //sum of two integers
    ComputeSum(a, b, mySum);    //actual parameters (arguments) a, b, mySum
    cout << "Sum from pass by reference = " << mySum << endl;

    List the formal parameters that accept pass by reference: &sum
    List the actual parameters which are passed by reference: mySum
    List the formal parameters that accept pass by value: x, y
    List the actual parameters which are passed by value: a, b
    Which variable from main is changed outside main? mySum



    int a[3] = {2,4,7};
    int b[3];
    b = a;
    cout << b;



    int a,b;
     float average;
     int minimum;

    void magic(int x, int y, float &avg, int &mini);

    magic(a,b ,average, minimum);
     
     //returns the sum of two formal input arguments, x and y

void magic(int x, int y, float &avg, int &mini)
{
    avg = (x +y) / 2.0;
    mini = min(x,y);
}


     What is the main use here of passing avg and min by reference? to have the variable value change
     
          */

    // Problem .6

/*
    int m[4] = {1,2,3,4,};

    int b[4];

    for(int i = 0; i < 4; ++i) {
        b[i] = m[i];
    }

    for (int i = 0; i < 4; ++i) {
        cout << b[i] << '\t';
    }

//    Orr..

    array<int, 4> staticArray =  {1,2,3,4,};
    array<int, 4> newArray = staticArray;

*/


/*
Problem .8
    int foo()
    {
      char *pBuffer; //nothing allocated yet (excluding the pointer itself, which is allocated here on the stack).
      bool b = true; // Allocated on the stack.
      if(b)
      {
        //Create 500 bytes on the stack
        char buffer[500];

        //Create 500 bytes on the heap
        pBuffer = new char[500];

       }//<-- buffer is deallocated here, pBuffer is not
    }//<--- oops there's a memory leak, I should have called delete[] pBuffer;
*/
    /*
Problem .9

    char answer;
    do
    {
    int* iPtr = new int [10];
    assert(iPtr != 0);
        cout << iPtr << endl;
        delete iPtr;
    cout << "Do another (y or n)?";
    cin >> answer;
            //here comes code from students
    }
    while(answer != 'n');
*/


    /*
    char ch;
    int no;


    cout << "Enter a char: ";
    ch = cin.get(); // We need to use cin.get() first before using std::cin >>
    cout << "Enter a number: ";
    cin >> no;
    cout << "Number is: " << no << endl;
    cout << "Char is: "<< ch << endl;

     */

    return 0;
}
