#include <iostream>
#include "StackArray.hpp"

int main() {
    StackArray<char> permuteStack(10);
    char ch;
    cin >> ch;
    permuteStack.push(ch);
    cin >> ch;
    permuteStack.push(ch);
    cin >> ch;
    permuteStack.push(ch);
    ch = permuteStack.pop();
    cout << ch << endl;
    ch = permuteStack.pop();
    cout << ch << endl;
    ch = permuteStack.pop();
    cout << ch << endl;



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
