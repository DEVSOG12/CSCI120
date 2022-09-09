////
//// Created by Oreofe Solarin on 9/5/22.
////
//
//
///*--- search.cpp -----------------------------------------------------
//  Program to read a 3 X 3 matrix of integers mat and an integer item,
//  and search mat to see if it contains item.
//
//  Add your name here and other info requested by your instructor.
// --------------------------------------------------------------------*/ #include <iostream>
//using namespace std;
//const int SIZE = 3;               // Set matrix size
//typedef int Matrix[SIZE][SIZE];   // Define data type Matrix
//bool matrixSearch(Matrix & mat, int n, int item);
///*---------------------------------------------------------------------
//  Search the n X n matrix mat in rowwise order for item.
//  Precondition:  Matrix mat is an n X n matrix of integers with n > 0.
//  Postcondition: True is returned if item is found in mat, else false.
// ---------------------------------------------------------------------*/
//int main()
//{
//    // Enter the matrix
//    Matrix mat;
//    cout << "Enter the elements of the " << SIZE << " X " << SIZE
//         << " matrix rowwise:\n";
//    for (int i = 0; i < SIZE; i++)
//        for (int j = 0; j < SIZE; j++)
//            cin >> mat[i][j];
//    // Search mat for various items
//    int itemToFind;
//    char response;
//    do
//    {
//        cout << "Enter integer to search for: ";
//        cin >> itemToFind;
//        if (matrixSearch(mat, SIZE, itemToFind))
//            cout << "item found\n";
//        else
//            cout << "item not found\n";
//        cout << "\nMore items to search for (Y or N)? ";
//        cin >> response;
//    }
//    while (response == 'Y' || response == 'y');
//}
////-- (-- Incorrect --) Definition of matrixSearch()
//bool matrixSearch(Matrix & mat, int n, int item)
///*--------------------------------------------------------------------
//  Search the n X n matrix mat in rowwise order for item
//  Precondition:  Matrix mat is an n X n matrix of integers with n > 0.
//  Postcondition: True is returned if item is found in mat, else false.
//  NOTE: mat[row][col] denotes the entry of the matrix in the
//        (horizontal) row numbered row (counting from 0) and the
//        (vertical) column numbered col.
// -------------------------------------------------------------------*/
//{
//    bool found = false;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (mat[i][j] == item) {
//                found = true;
//                return found;
//                break;
//            }
//        }
//
//    }
//    return found;
//
//
//}