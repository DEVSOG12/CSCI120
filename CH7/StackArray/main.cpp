/*--------------------------------------------------------------------------
   Convert infix expressions to postfix.
 
   Input:  An infix expression and user responses
   Output: The postfix expression
--------------------------------------------------------------------------*/

#include <iostream>       // <<, >>, cout, cin
#include <string>         // string, ==, find, npos
#include <cassert>        // assert()
#include <cctype>         // alnum()
using namespace std;
#include "ArrayStack.h"       // Stack class
//#include<stack>

string postfix(string exp);


int main(){

    // this demos the use of try-catch errors when
    // peeking in an empty stack
    ArrayStack<int> grades;
    grades.push(98);

    try{
        cout << grades.peek();
    }
    catch(std::logic_error &e)
    {
        cout << "empty stack, continued by ignoring the peek";
    }

    cout << "\nbye\n" << 2+3 <<endl;
    return 0;
}



string postfix(string exp)
/*-------------------------------------------------------------------------
   Function to convert an infix expression exp to postfix.

   Precondition:  exp is received
   Postcondition: postfix expression corresponding to exp is returned
       or an error message displayed if an error was found in exp.
-------------------------------------------------------------------------*/
{
    char token,                   // character in exp
            topToken;                // token on top of opStack
    ArrayStack<char> opStack;                // stack of operators
    string RPNexp;                // postfix expression
    const string BLANK = " ";
    for (int i = 0; i < exp.length(); i++)
    {

        token = exp[i];
        switch(token)
        {
            //case ' ' : break;       // do nothing -- skip blanks
            case '(' : opStack.push(token);
                break;
            case ')' : for (;;)
                {
                    assert (!opStack.isEmpty());
                    topToken = opStack.peek();
                    opStack.pop();
                    if (topToken == '(') break;
                    RPNexp.append(BLANK + topToken);
                }
                break;
            case '+' : case '-' :
            case '*' : case '/': case'%':
                for (;;)
                {
                    if (opStack.isEmpty() ||
                        opStack.peek() == '(' ||
                        (token == '*' || token == '/' || token == '%') &&
                        (opStack.peek() == '+' || opStack.peek() == '-'))
                    {
                        opStack.push(token);
                        break;
                    }
                    else
                    {
                        topToken = opStack.peek();
                        opStack.pop();
                        RPNexp.append(BLANK + topToken);
                    }
                }
                break;
            default :  // operand
                RPNexp.append(BLANK + token);
                for(;;)
                {
                    if ( !isalnum(exp[i+1]) ) break;  // end of identifier
                    i++;
                    token = exp[i];
                    RPNexp.append(1, token);
                }
        }
    }
    // Pop remaining operators on the stack
    for (;;)
    {
        if (opStack.isEmpty()) break;
        topToken = opStack.peek();
        opStack.pop();
        if (topToken != '(')
        {
            RPNexp.append(BLANK + topToken);
        }
        else
        {
            cout << " *** Error in infix expression ***\n";
            break;
        }
    }
    return RPNexp;
}

int mainx(){

    string exp;            // infix expression
    cout << "NOTE: Enter # for infix expression to stop.\n";
    for (;;)
    {
        cout << "\nInfix expression? ";
        cin >> exp;

        if (exp == "#") break;

        cout << "Postfix expression is " << postfix(exp) << endl;

     }

return 0;
}
