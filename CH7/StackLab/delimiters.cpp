//--------------------------------------------------------------------
//
//  Laboratory 6 (Programming Exercise 3)               delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>

#if LAB6_TEST1
#   include "StackLinked.hpp"
#else
#   include "StackArray.hpp"
#endif

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine += ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below


bool delimitersOk ( const string &expression ) {
    StackArray<char> stack;
    for (char i : expression) {
        if (i == '[' || i == '(' || i == '{') {
            stack.push(i);
        } else if (i == ']' || i == ')' || i == '}') {
            if (stack.isEmpty()) {
                return false;
            }
            char top = stack.pop();
            if (i == ']' && top != '[' || i == ')' && top != '(' || i == '}' && top != '{') {
                return false;

            }
        }
    }
    return stack.isEmpty();
}

