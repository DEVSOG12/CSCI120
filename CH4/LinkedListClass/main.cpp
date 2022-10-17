//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "LinkedList.hpp" // ADT list operations
#include <iostream>
#include <string>

using namespace std;

void displayList(ListInterface<int>* listPtr)
{
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      cout << listPtr->getEntry(pos) << " ";
   } // end for
	cout << endl;
}  // end displayList


int main(){
    LinkedList<int> grades;
    grades.insert(1,87);
    grades.insert(2,98);
    grades.insert(3,15);
    grades.insert(4,44);
    cout << "List grades: ";
    displayList(&grades);


    // test assignment op
    cout << "*** Testing assignment operator (grades is copied over prices, ***"<< endl;
    cout << "*** then we remove last element from prices and this does NOT affect grades.) ***" << endl;
    LinkedList<int> prices;
    prices = grades;
    cout << "List prices: ";
    prices.remove(4);
    displayList(&prices);
    cout << "List grades: ";
    displayList(&grades);

    // test copy constructor
    cout << "*** Testing copy constructor (temperatures is created as a copy of grades) ***" << endl;
    LinkedList<int> temperatures(grades);
    cout << "List temperatures: ";
    displayList(&temperatures);

//*/
    return 0;
}






/*

int main44()
{
   cout << "Testing the == operator:" << endl;

   LinkedList<string>* list1Ptr = new LinkedList<string>() ;
	string data[] = {"one", "two", "three", "four", "five", "six"};
	for (int i = 0; i < 6; i++)
      list1Ptr->insert(i + 1, data[i]);
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << endl;
   
   LinkedList<string>* list2Ptr = new LinkedList<string>() ;
	for (int i = 0; i < 6; i++)
      list2Ptr->insert(i + 1, data[i]);
   cout << "List 2:" << endl;
   displayList(list2Ptr);
   cout << endl;
   
   cout << "Comparing Lists 1 and 2:\n";
   if (*list1Ptr == *list2Ptr)
      cout << "Lists 1 and 2 are equal\n";
   else
      cout << "Lists 1 and 2 are NOT equal -- ERROR!\n";
   
   cout << endl;
   list1Ptr->remove(2);
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << endl;
   cout << "List 2:" << endl;
   displayList(list2Ptr);
   cout << endl;
   cout << "Comparing Lists 1 and 2:\n";
   
   if (list1Ptr == list2Ptr)
      cout << "Lists 1 and 2 are equal-- ERROR!\n";
   else
      cout << "Lists 1 and 2 are NOT equal \n";
   
   cout << endl;
   list1Ptr->insert(2, "TWO");
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << endl;
   cout << "List 2:" << endl;
   displayList(list2Ptr);
   cout << endl;
   cout << "Comparing Lists 1 and 2:\n";
   
   if (list1Ptr == list2Ptr)
      cout << "Lists 1 and 2 are equal-- ERROR!\n";
   else
      cout << "Lists 1 and 2 are NOT equal \n";
   //===============================================================
   cout << endl;
   cout << "Testing the + operator by concatenating the previous two lists:" << endl;
   LinkedList<string> list3 = *list1Ptr + *list2Ptr;
   //displayList(list2Ptr);
   //auto copyPtr = new LinkedList<string>(*list2Ptr);
   displayList(&list3 );

   
   
   //===============================================================
   cout << endl;
   cout << "Testing the = operator:" << endl;
   
   LinkedList<string> assignedList = *list1Ptr;
   cout << "List 1:" << endl;
   displayList(list1Ptr);
   cout << "List assigned:" << endl;
   displayList(new LinkedList<string>(assignedList));
   
   //===============================================================
   cout << endl;
   cout << "Testing the << operator by displaying List 1:" << endl;
   *list1Ptr = *list1Ptr;
   cout << *list1Ptr;



   return 0;
}  // end main

/*
 Testing the == operator:
 List 1:
 one two three four five six
 
 List 2:
 one two three four five six
 
 Comparing Lists 1 and 2:
 Lists 1 and 2 are equal
 
 List 1:
 one three four five six
 
 List 2:
 one two three four five six
 
 Comparing Lists 1 and 2:
 Lists 1 and 2 are NOT equal
 
 List 1:
 one TWO three four five six
 
 List 2:
 one two three four five six
 
 Comparing Lists 1 and 2:
 Lists 1 and 2 are NOT equal
 
 Testing the + operator by concatenating the previous two lists:
 one TWO three four five six one two three four five six
 
 Testing the = operator:
 List 1:
 one TWO three four five six
 List assigned:
 one TWO three four five six
 
 Testing the << operator by displaying List 1:
 1	one
 2	TWO
 3	three
 4	four
 5	five
 6	six
 */
