#include <iostream>
#include "LinkedBag.hpp"
using namespace std;


void displayBag(LinkedBag<std::string>& bag)
{
    std::cout << "The bag contains " << bag.getCurrentSize()
              << " items:" << std::endl;
    std::vector<std::string> bagItems = bag.toVector();

    int numberOfEntries = (int) bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
    {
        std::cout << bagItems[i] << " ";
    }  // end for
    std::cout << std::endl << std::endl;

}  // end display

int main() {
    //cout << "Testing LinkedBag" << endl;

    LinkedBag<string> aldi;

    aldi.add("milk");
    aldi.add("bread");
    aldi.add("juice");

    //displayBag(aldi);

    LinkedBag<string> walmart(aldi);
    walmart.remove("milk");
    displayBag(aldi);
    displayBag(walmart);

    return 0;
}