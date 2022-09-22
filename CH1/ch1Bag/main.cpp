#include <iostream> // For cout and cin
#include <string>   // For string objects
#include "Bag.hpp"    // For ADT bag
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//
//    std::string clubs[] = { "Joker", "Ace", "Two", "Three", "Four", "Five",
//                            "Six", "Seven", "Eight", "Nine", "Ten", "Jack",
//                            "Queen", "King" };
//
//    // Create our bag to hold cards.
//    Bag<std::string> grabBag;
//
//    // Place six cards in the bag.
//    grabBag.add(clubs[1]);
//    grabBag.add(clubs[2]);
//    grabBag.add(clubs[4]);
//    grabBag.add(clubs[8]);
//    grabBag.add(clubs[10]);
//    grabBag.add(clubs[12]);
//
//    // Get friendâ€™s guess and check it.
//    int guess = 0;
//    int tries = 10;
//    while (!grabBag.isEmpty() && tries != 0)
//    {
//        std::cout << "What is your guess? (1 for Ace to 13 for King):";
//        std::cin >> guess;
//
//        // Is card in the bag?
//        if (grabBag.contains(clubs[guess]))
//        {
//            // Good guess â€“ remove card from the bag.
//            std::cout << "You get the card!\n";
//            grabBag.remove(clubs[guess]);
//        }
//        else
//        {
//            std::cout << "Sorry, card was not in the bag.\n";
//        }  // end if
//        tries--;
//    }  // end while
//    if(tries == 0){
//        std::cout << "You've ran out of tries\n";
//
//    }
//    std::cout << "No more cards in the bag. Game over!\n";
//    return 0;
//}; // end main
///*
// What is your guess? (1 for Ace to 13 for King):3
// Sorry, card was not in the bag.
// What is your guess? (1 for Ace to 13 for King):5
// Sorry, card was not in the bag.
// What is your guess? (1 for Ace to 13 for King):2
// You get the card!
// What is your guess? (1 for Ace to 13 for King):1
// You get the card!
// What is your guess? (1 for Ace to 13 for King):10
// You get the card!
// What is your guess? (1 for Ace to 13 for King):12
// You get the card!
// What is your guess? (1 for Ace to 13 for King):8
// You get the card!
// What is your guess? (1 for Ace to 13 for King):8
// Sorry, card was not in the bag.
// What is your guess? (1 for Ace to 13 for King):4
// You get the card!
// No more cards in the bag. Game over!
// */

void displayBag(Bag<std::string>& bag)
{
    std::cout << "The bag contains " << bag.getCurrentSize()
              << " items:" << std::endl;
    std::vector<std::string> bagItems = bag.toVector();
    int numberOfEntries = (int)bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
    {
        std::cout << bagItems[i] << " ";
    }  // end for
    std::cout << std::endl << std::endl;
}  // end displayBag


int sumOfBag(Bag<int>& aBag) {
    vector<int> me = aBag.toVector();
    int sum = 0;
    for(int i : me){
        sum = sum + i;
    }

    return sum;
}

bool replace(Bag<string>& aBag, string itemToReplace, string replacement ) {
    if(aBag.contains(itemToReplace)) {
        aBag.remove(itemToReplace);
        aBag.add(replacement);
        return true;
    } else{
        return false;
    }

}


int main(){

    Bag<int> grades;
    grades.add(22);
    grades.add(44);
    grades.add(66);
    grades.add(88);
    cout << "Sum of grades is: " << sumOfBag(grades) << endl << endl;;


    Bag<string> aldi;
    aldi.add("milk");
    aldi.add("juice");
    aldi.add("eggs");
    cout << "Content of my original aldi bag: " << endl;
    displayBag(aldi);

    bool success = replace(aldi, "juice", "plums");
    cout << "Content of my aldi bag after replacing juice is: " << endl;
    displayBag(aldi);

    return 0;
}
