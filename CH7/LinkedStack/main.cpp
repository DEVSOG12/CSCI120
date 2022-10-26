#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main() {

    //1) add code to create a LinkedStack object of type string
    LinkedStack<string> stack;

    //2) add code to push items "plate1", "plate2", "plate3"
    // on your LinkedStack object
    stack.push("plate1");
    stack.push("plate2");
    stack.push("plate3");



    //3) add code to test/invoke the pick method
    cout << stack.peek() << endl;



    //4) add code to test/invoke the pop method
    cout << stack.pop() << endl;


    //5) add code to test/invoke IsEmpty method
    cout << stack.isEmpty() << endl;


    //6) add code to test/invoke the copy constructor
    LinkedStack<string> stack2(stack);
    cout << stack2.peek() << endl;



    cout << "... all done. Good job! :)" << endl;
    return 0;
}