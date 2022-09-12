////
//// Created by Oreofe Solarin on 9/12/22.
////
//#include <fstream>
//#include <string>
//#include <iostream>
//
//using namespace std;
//#include "Text.h"
//
///* A command-line user interface that allows the user to read in a file
// * containing a program consisting of words or tokens separated by whitespace.
// * Requirements: none
// * Results: For each word in the file specified by the user (including any
// * blank lines), each word is printed out on a new line in the form 1: [word1], where 1
// * is a counter indicating the current number of the word and wordi is the ith
// * token in the file.
// *
// */
//int main() {
//    /*** YOUR CODE HERE ***/
//    /**********************/
//    //set up counter variable to 0
//
//    Text token; // Text object that can hold a word
//    string fileName;
//    cout << "Enter a file name: ";
//    cin >> fileName;
//
//    ifstream in;				// Object representing input from a file.
////    std::ifstream input("/home/bob/stuff.txt");
//
//    in.open(fileName.c_str());		// Open the file for reading.
//    if (in.is_open()) {
//    int count = 1;
//        while( in >> token )
//        {
//            /*** YOUR CODE HERE ***/
//            /**********************/
//            // Increment your word counter.
//
//
//
//            /*** YOUR CODE HERE ***/
//            /**********************/
//            // Print word as specified in requirements
//
//            cout << count << " : " << token << endl;
//
//count++;
//        }//end while
//        in.close();		// Close the file.
//
//    } else {
//        cout << "Error: Couldn't read " << fileName << endl;
//

//    }
//}