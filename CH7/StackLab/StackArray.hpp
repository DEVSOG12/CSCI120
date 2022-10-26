//--------------------------------------------------------------------
//
//  Class declaration and implementation for the array Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackArray : public Stack<DataType> {
public:
    StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackArray(const StackArray& other);
    StackArray& operator=(const StackArray& other);
    ~StackArray();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

private:
    int maxSize;
    int top;
    DataType* dataItems;
};

//--------------------------------------------------------------------
//
//
//  ** Array implementation of the Stack ADT **
//
//--------------------------------------------------------------------
//--------------------------------------------------------------------

// Constructors
// @pre None
// @post Creates an empty stack
// @param maxNumber Maximum number of elements in the stack

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)

// Creates an empty stack.

        : maxSize(maxNumber), top(-1)
{
    dataItems = new DataType[maxSize];
}

//--------------------------------------------------------------------
// Copy constructor
// @pre None
// @post Creates a new stack that is a copy of the other stack
// @param other The stack to be copied
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)

// Copy constructor for  stack

        : maxSize( other.maxSize ), top( other.top )
{
    dataItems = new DataType[maxSize];
    for (int j = 0; j <= top; j++)
        dataItems[j] = other.dataItems[j];
}

//--------------------------------------------------------------------
// Assignment operator
// @pre None
// @post Sets the stack to be a copy of the other stack
// @param other The stack to be copied
// @return A reference to the stack
template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)

// Overloaded assignment operator for the StackArray class.
// Because this function returns a StackArray object reference,
// it allows chained assignment (e.g., stack1 = stack2 = stack3).

{
    if (this != &other) {
        maxSize = other.maxSize;
        top = other.top;
        delete [] dataItems;
        dataItems = new DataType[maxSize];
        for (int j = 0; j <= top; j++)
            dataItems[j] = other.dataItems[j];
    }
    return *this;
}

//--------------------------------------------------------------------
// Destructor
// @pre None
// @post The stack is empty
// @param None
// @return None
template <typename DataType>
StackArray<DataType>::~StackArray()

// Frees the memory used by a stack.

{
    clear();

}

//--------------------------------------------------------------------
// Pushes an item onto the top of the stack
// @pre None
// @post The item is pushed onto the top of the stack
// @param newDataItem The item to be pushed onto the stack
// @return None
// @throw logic_error if the stack is full
template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)

// Inserts newDataItem onto the top of a stack.

{
    if( isFull() ) {
    throw logic_error("Stack is full");
    }
    else {
    dataItems[++top] = newDataItem;
    std::cout <<  dataItems[top] << " pushed" << std::endl;
    }

   
}

//--------------------------------------------------------------------
// Pops an item off the top of the stack
// @pre None
// @post The item is popped off the top of the stack
// @param None
// @return The item popped off the top of the stack
// @throw logic_error if the stack is empty
template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)

// Removes the topmost data item from a stack and returns it.

{
    if( isEmpty() ) {
    throw logic_error("Stack is empty");
    }
    else {
    return dataItems[top--];
    }
}

//--------------------------------------------------------------------
// Clears the stack
// @pre None
// @post The stack is empty
// @param None
// @return None

template <typename DataType>
void StackArray<DataType>::clear()

// Removes all the data items from a stack.

{
    top = -1;
}

//--------------------------------------------------------------------
// Checks if the stack is empty
// @pre None
// @post None
// @param None
// @return True if the stack is empty, false otherwise

template <typename DataType>
bool StackArray<DataType>::isEmpty() const

// Returns true if a stack is empty. Otherwise, returns false.

{
    return top == -1;
}

//--------------------------------------------------------------------
// Checks if the stack is full
// @pre None
// @post None
// @param None
// @return True if the stack is full, false otherwise
template <typename DataType>
bool StackArray<DataType>::isFull() const

// Returns true if a stack is full. Otherwise, returns false.

{
    return top == maxSize - 1;
}

//--------------------------------------------------------------------
// Displays the stack
// @pre None
// @post None
// @param None
// @return None

template <typename DataType>
void StackArray<DataType>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( isEmpty() )
    cout << "Empty stack" << endl;
    else
    {
    cout << "top = " << top << endl;
    for ( j = 0 ; j < maxSize ; j++ )
        cout << j << "\t";
    cout << endl;
    for ( j = 0 ; j <= top ; j++ )
        cout << dataItems[j] << "\t";
    cout << endl;
    }
   
}



#endif		//#ifndef STACKARRAY_HPP
