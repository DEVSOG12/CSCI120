#include <iostream>
#include "LinkedStack.h"
using namespace std;
// Function that evaluates postfix expression and returns the value
int evaluatePostfix(string exp)
{
    //create a stack
    LinkedStack<int> stack;
    // Scan all characters one by one
    for (int i=0; i<exp.length(); i++)
    {
        // If the scanned character is an operand (number here),
        // push it to the stack.
        if (isdigit(exp[i]))
            stack.push(exp[i] - '0');

        //  If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = stack.peek();
            stack.pop();
            int val2 = stack.peek();
            stack.pop();
            switch (exp[i])
            {
            case '+': stack.push(val2 + val1); break;
            case '-': stack.push(val2 - val1); break;
            case '*': stack.push(val2 * val1); break;
            case '/': stack.push(val2/val1); break;
            }
        }
    }
    return stack.peek();
}
int main() {
//
//    //1) add code to create a LinkedStack object of type string
//    LinkedStack<string> stack;
//
//    //2) add code to push items "plate1", "plate2", "plate3"
//    // on your LinkedStack object
//    stack.push("plate1");
//    stack.push("plate2");
//    stack.push("plate3");
//
//
//
//    //3) add code to test/invoke the pick method
//    cout << stack.peek() << endl;
//
//
//
//    //4) add code to test/invoke the pop method
//    cout << stack.pop() << endl;
//
//
//    //5) add code to test/invoke IsEmpty method
//    cout << stack.isEmpty() << endl;
//
//
//    //6) add code to test/invoke the copy constructor
//    LinkedStack<string> stack2(stack);
//    cout << stack2.peek() << endl;
//
//
//
//    cout << "... all done. Good job! :)" << endl;
    std::cout << evaluatePostfix("231*+9-") << std::endl;;
    return 0;
}