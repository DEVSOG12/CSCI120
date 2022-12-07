
#include <iostream>
#include <vector>

using namespace std;

// Prototype
void mergeSort(int *array, int size);
void merge(int *array, const int *left, const int *right, int leftSize, int rightSize);
void printArray(int *array, int size);
// Quick Sort
void quickSort(int *array, int size);

vector<int>x;
bool in(){
 // get random index in vector x
    int index = rand() % x.size();
    // get value at index
    int value = x[index];

}
void me(int* me);
int main()
// Merge sort algorithm
// Merge sort is a divide and conquer algorithm that was invented by John von Neumann in 1945.
// It is a comparison sort that is generally considered to be more efficient than quicksort.
// Merge sort is a recursive algorithm that continually splits a list in half.
// If the list is empty or has one item, it is sorted by definition (the base case).
// If the list has more than one item, we split the list and recursively invoke a merge sort on both halves.

// Once the two halves are sorted, the fundamental operation, called a merge, is performed.
// Merging is the process of taking two smaller sorted lists and combining them together into a single, sorted, new list.




{

    int array[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    int size = sizeof(array) / sizeof(array[0]);
//    mergeSort(array, size);
    printArray(array, size);
    cout << endl;
    printArray(array + 4, size);
    int * me;
    me = new int;
    std::cout << me(me);



    return 0;
}

// non recursive merge sort
void mergeSort(int *array, int size)
{
    int *left, *right;
    int mid, i, j, k;
    mid = size / 2;
    if (size < 2)
        return;
    left = new int[mid];
    right = new int[size - mid];
    for (i = 0; i < mid; i++)
        left[i] = array[i];
    for (i = mid; i < size; i++)
        right[i - mid] = array[i];
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    // merge
    i = 0; // left index
    j = 0; // right index
    k = 0; // merged index
    while (i < mid && j < size - mid) // while both arrays have elements
    {
        // if left element is less than right element
        if (left[i] <= right[j])
            array[k++] = left[i++]; // add left element to merged array
        else
            array[k++] = right[j++]; // add right element to merged array
    }
    while (i < mid) // if left array has elements
        array[k++] = left[i++]; // add them to merged array
    while (j < size - mid) // if right array has elements
        array[k++] = right[j++]; // add them to merged array
    delete[] left;
    delete[] right;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int me(int me)
{
    return me;
}
// Quick Sort
void quickSort(int *array, int size)
{
    int i, j, pivot, temp;
    if (size < 2)
        return;
    pivot = array[size / 2];
    for (i = 0, j = size - 1;; i++, j--) // infinite loop
    {
        while (array[i] < pivot) // find element on left that should be on right
            i++;
        while (array[j] > pivot) // find element on right that should be on left
            j--;
        if (i >= j) // if pointers cross
            break; // break out of loop
        temp = array[i]; // swap elements pointed to by i and j
        array[i] = array[j];
        array[j] = temp;
    }
    quickSort(array, i);
    quickSort(array + i, size - i); // quicksort the other half
    // Q: Why is this array + i and array?
    // A: Because the array is a pointer to the first element of the array.
    //    So, array + i is a pointer to the i-th element of the array.
    // Thank you
    // https://stackoverflow.com/questions/119657/what-is-the-difference-between-array-and-array
}


// ABC+D*+ Postfix to Infix stack


