//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#ifndef STACK_INTERFACE_CPP
#define STACK_INTERFACE_CPP
#include <vector>
#include <cassert>       // For assert
#include "ArrayStack.h"  // Header file

template<class ItemType>
ArrayStack<ItemType>::ArrayStack(unsigned long i) : top(-1)
{
}  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
    return top < 0;
}  // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
    bool result = false;
    if (top < MAX_STACK - 1)  // Does stack have room for newEntry?
    {
        top++;
        items[top] = newEntry;
        result = true;
    }  // end if

    return result;
}  // end push


template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    }  // end if

    return result;
}  // end pop

#include <stdexcept>
template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
    //assert(!isEmpty());  // Enforce precondition

    if(isEmpty())
        throw std::logic_error("Stack is empty!!!");

    // Stack is not empty; return top
    return items[top];
}  // end peek
// End of implementation file.

#endif

