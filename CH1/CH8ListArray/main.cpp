#include <iostream>
#include "ArrayList.hpp"

int main() {
    ArrayList<int> grades;
    ArrayList<int> g3(grades);
    for (int i = 1; i < 51; ++i) {
        grades.insert(i, i*7);

    }

grades.remove(1);
    for (int i = 1; i < 6; ++i) {
//        if(grades.)
        std::cout << grades.getEntry(i) << std::endl;
    }


//    std::cout  << std::boolalpha << (grades.insert(,89));
    std::cout << "Hello, World!" << std::endl;

    return 0;
}