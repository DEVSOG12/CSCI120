//--------------------------------------------------------------------
//
//  Class declaration and implementation of the linked Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_HPP
#define STACKLINKED_HPP

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

public:

    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

private:

    class StackNode {
    public:
        StackNode(const DataType& nodeData, StackNode* nextPtr);

        DataType dataItem;
        StackNode* next;
    };

    StackNode* top;
};


//--------------------------------------------------------------------
//
//  ** Linked list implementation of the Stack ADT **
//
//--------------------------------------------------------------------
//--------------------------------------------------------------------

// Constructors
// @pre None
// @post Creates an empty stack
// @param maxNumber Maximum number of elements in the stack
template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& newDataItem,
                                            StackLinked<DataType>::StackNode* nextPtr)

// Creates a stack node containing item newDataItem and next pointer
// nextPtr.

        : dataItem(newDataItem), next(nextPtr)
{
}

//--------------------------------------------------------------------
// @pre None
// @post Creates an empty stack
// @param maxNumber Maximum number of elements in the stack

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
        : top(0)

// Creates an empty stack. The parameter maxNumber is provided for
// compatability with the array implementation and is ignored.

{

}

//--------------------------------------------------------------------
// @pre None
// @post Creates a new stack that is a copy of the stack passed as a
//       parameter
//     (i.e., the new stack contains the same data items as the
//      original stack)
// @param other The stack to be copied

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)

// Copy constructor for linked stack

        : top( 0 )
{
    StackNode* p = other.top;
    StackNode* q = 0;
    StackNode* r = 0;

    while (p != 0)
    {
        q = new StackNode(p->dataItem, 0);
        if (top == 0)
            top = q;
        else
            r->next = q;
        r = q;
        p = p->next;
    }
   
}

//--------------------------------------------------------------------
// @pre None
// @post The stack passed as a parameter is copied into the current
//       stack
// @param other The stack to be copied
// @return A reference to the current stack
//
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)

// Overloaded assignment operator for the StackLinked class.
// Because this function returns a StackLinked object reference,
// it allows chained assignment (e.g., stack1 = stack2 = stack3).

{
    if (this != &other)
    {
        clear();
        StackNode* p = other.top;
        StackNode* q = 0;
        StackNode* r = 0;

        while (p != 0)
        {
            q = new StackNode(p->dataItem, 0);
            if (top == 0)
                top = q;
            else
                r->next = q;
            r = q;
            p = p->next;
        }
    }
    return *this;
}

//--------------------------------------------------------------------
// @pre None
// @post The stack is destroyed
template <typename DataType>
StackLinked<DataType>::~StackLinked()

// Destructor. Frees the memory used by a stack.

{
    clear();
}

//--------------------------------------------------------------------
// @pre None
// @post The data item is added to the top of the stack
// @param newDataItem The data item to be added to the stack
// @throw logic_error if the stack is full
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)

// Inserts newDataItem onto the top of a stack.

{
    if (isFull())
        throw logic_error("Stack is full");
    else
        top = new StackNode(newDataItem, top);
   
}

//--------------------------------------------------------------------
// @pre None
// @post The top data item is removed from the stack
// @return The top data item
// @throw logic_error if the stack is empty
template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)

// Removes the topmost item from a stack and returns it.

{
    if (isEmpty())
        throw logic_error("Stack is empty");
    else
    {
        DataType temp = top->dataItem;
        StackNode* p = top;
        top = top->next;
        delete p;
        return temp;
    }
    
}

//--------------------------------------------------------------------
// @pre None
// @post The stack is empty
template <typename DataType>
void StackLinked<DataType>::clear()

// Removes all the data items from a stack.

{
    while (!isEmpty())
        pop();
}

//--------------------------------------------------------------------
// @pre None
// @post None
// @return true if the stack is empty, false otherwise
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const

// Returns true if a stack is empty. Otherwise, returns false.

{
    return top == 0;
}

//--------------------------------------------------------------------
// @pre None
// @post None
// @return true if the stack is full, false otherwise
template <typename DataType>
bool StackLinked<DataType>::isFull() const

// Returns true if a stack is full. Otherwise, returns false.

{




    /*
    // Alternatively, can use implementation below.
    // This is a somewhat awkward way to test if the list is full.
    // If a node can be successfully allocated than the list is not
    // full.  If the allocation fails it is implied that there is no
    // more free memory therefore the list is full.
    // We are not aware of any other standard/portable way of
    // performing the test. And this can fail due to external issues
    // such as the system exhausting swap or another thread stealing
    // the remaining memory between when isFull returns its result and
    // the caller does something that assumes that isFull() returned
    // a valid answer.
    //
    // Alternatives include just the line "return false", which is
    // probably good enough in this context, or platform-dependent
    // checks for available memory.
   */

        auto* p = new StackNode(0, 0);
        if (p == 0)
            return true;
        else
        {
            delete p;
            return false;
        }
}

//--------------------------------------------------------------------
// @pre None
// @post None
// @return prints structure of stack
// @throw logic_error if the stack is empty

template <typename DataType>
void StackLinked<DataType>::showStructure() const

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
        cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
        for (StackNode* temp = top; temp != 0; temp = temp->next) {
            if( temp == top ) {
                cout << '[' << temp->dataItem << "]\t";
            }
            else {
                cout << temp->dataItem << "\t";
            }
        }
        cout << "Bottom" << endl;
    }
}




#endif		//#ifndef







