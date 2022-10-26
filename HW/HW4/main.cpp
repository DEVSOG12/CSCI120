#include <iostream>
#include <string>
#include "LinkedBag.hpp"

int main() {
    LinkedBag<std::string> bag1, bag2,combined;
    bag1.add("milk");
    bag1.add("juice");
    bag1.add("milk");
    bag2.add("milk");
    bag2.add("bread");
    std::cout << "Bag Combined: " << std::endl;
    combined = bag1.unionBag(bag2);
    //LinkedBag<string> combined(bag1.unionBag(bag2));  //this does NOT need assignment operator= because it calls the copy constructor
    combined.printBag();
    std::cout << "Bag 1: " << std::endl;
    bag1.printBag();
    std::cout << "Bag 2: " << std::endl;
    bag2.printBag();
    return 0;
}
