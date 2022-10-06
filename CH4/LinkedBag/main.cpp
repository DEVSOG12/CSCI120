#include <iostream>
#include "LinkedBag.hpp"
//using namespace std;


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
    LinkedBag<int> b1, b2;
    LinkedBag<int> b3 = b1;






    return 0;
}