//
// Created by Oreofe Solarin on 10/24/22.
//

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include "LinkedStack.h"

#ifndef LINKEDSTACK_B_HPP
#define LINKEDSTACK_B_HPP

bool isPalindrome(std::string & s){
    LinkedStack<char> stack;
    for (char & i : s){
        stack.push(i);
    }
    for (char & i : s){
        if (i != stack.peek()){
            return false;
        }
        stack.pop();
    }
    return true;
}


int main() {

    //1) add code to create a LinkedStack object of type string
    LinkedStack<std::string> stack;

    //2) add code to push items "plate1", "plate2", "plate3"
    // on your LinkedStack object
    stack.push("plate1");
    stack.push("plate2");
    stack.push("plate3");



    //3) add code to test/invoke the peek method
    std::cout << stack.peek() << std::endl;

    //4) add code to test/invoke the pop method
    std::cout << stack.pop() << std::endl;

    //5) add code to test/invoke IsEmpty method
    std::cout << "Is Empty? " << std::boolalpha <<  stack.isEmpty() << std::endl;

    //6) add code to test/invoke the copy constructor
    LinkedStack<std::string> stack2(stack);
    std::cout << stack2.peek() << std::endl;



    std::cout << "... all done. Good job! :)" << std::endl;
    return 0;
}




#endif //LINKEDSTACK_B_HPP
