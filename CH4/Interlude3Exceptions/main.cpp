//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <string>
#include <iostream>
#include <vector>
#include "PlainBox.hpp"
using namespace std;

// Listing C3-3
PlainBox<string> findBox(const vector<PlainBox<std::string>>& boxes,
                         const std::string& target) noexcept(false)
{
    for ( auto  i : boxes) if (i.getItem() == target) return i;
        throw std::logic_error("Target not found in a box!");
} // end findBox

int main()
{
    // Listing C3-4
    // Create and initialize an array of boxes
    vector<PlainBox<string>> myBoxes(5); // Array of PlainBox objects
    myBoxes[0] = PlainBox<std::string>("ring");
    myBoxes[1] = PlainBox<std::string>("hat");
    myBoxes[2] = PlainBox<std::string>("shirt");
    myBoxes[3] = PlainBox<std::string>("sock");
    myBoxes[4] = PlainBox<std::string>("shoe");
    PlainBox<std::string> foundBox;

    //foundBox = findBox(myBoxes, 5, "glasses");
   // Try to find a box containing glasses
    try
    {
        foundBox = findBox(myBoxes, "shoe");
    }
    catch(std::logic_error &logErr)
    {
        cout << logErr.what() << endl;          // Display error message to user
        foundBox = PlainBox<string>("nothing"); // Fix problem
    } // end try-catch
    // Because we catch the exception and fix the problem, the following
    // statement should work even if the target is not found

    std::cout << "Found box contains: " << foundBox.getItem() << endl;
    cout<< "\nI could continue on with my program...." << endl;

    return 0;
}
/*
 Target not found in a box!
 nothing
 */
