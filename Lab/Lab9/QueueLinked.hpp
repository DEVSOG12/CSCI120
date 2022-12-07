// QueueLinked.h


#ifndef QUEUELINKED_HPP
#define QUEUELINKED_HPP

#include <iostream>
#include <stdexcept>
#include <iostream>
using namespace std;

#include "Queue.h"

template <typename DataType>
class QueueLinked : public Queue<DataType> {
  public:
    QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE);
    QueueLinked(const QueueLinked& other);
    QueueLinked& operator=(const QueueLinked& other);
    ~QueueLinked();

    void enqueue(const DataType& newDataItem) throw (logic_error);
    DataType dequeue() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    // Programming Exercise 2
    //void putFront(const DataType& newDataItem) throw (logic_error);
    //DataType getRear() throw (logic_error);
    // Programming Exercise 3
    //int getLength() const;

    void showStructure() const;

  private:
    class QueueNode {
      public:
	QueueNode(const DataType& nodeData, QueueNode* nextPtr);

	DataType dataItem;
	QueueNode* next;
    };

    QueueNode* front;
    QueueNode* back;
};


//--------------------------------------------------------------------
//
//  Laboratory 7                                       
//
//  ** Linked list implementation of the Queue ADT **
//
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Constructor
// Creates an empty queue. Allocates enough memory for maxNumber elements.
// @Pre None
// @Post An empty queue with enough memory for maxNumber elements
// @param maxNumber The maximum number of elements that can be in the queue
template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& newDataItem,
					  QueueLinked<DataType>::QueueNode* nextPtr)

// Creates a queue node containing data item nodeDataItem and next
// pointer nextPtr.

    : dataItem(newDataItem), next(nextPtr)
{

}

//--------------------------------------------------------------------
// Constructor
// Creates an empty queue. Allocates enough memory for maxNumber elements.
// @Pre None
// @Post An empty queue with enough memory for maxNumber elements
// @param maxNumber The maximum number of elements that can be in the queue
template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber) : front(0), back(0) 

// Creates an empty queue. Parameter is provided for compatability
// with the array implementation and is ignored.

{}
 
//--------------------------------------------------------------------
// Destructor
// Frees the memory used by a queue.
// @Pre None
// @Post Queue is empty and has no allocated memory.
template <typename DataType>
QueueLinked<DataType>::~QueueLinked() 

// Frees the memory used by a queue.

{
    clear();

    
}

//--------------------------------------------------------------------
// Enqueue
// Adds newDataItem to the "back" of a queue and returns it.
// @Pre Queue is not full.
// @Post newDataItem is at the "back" of the queue.
// @param newDataItem The data item to be added to the queue.
// @return The data item that was added to the queue.
// @throw logic_error if the queue is full.
template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error) 

// Inserts newDataItem at the rear of a queue.

{
    if (isFull()) {
        throw logic_error("Queue is full");
    }
    else {
        QueueNode* newNode = new QueueNode(newDataItem, 0);
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode;
        }
    }
    
}

// Dequeue
// Removes the least recently added ("front") item from a queue and returns it.
// @Pre Queue is not empty.
// @Post The least recently added item is removed from the queue.
// @return The data item that was removed from the queue.
// @throw logic_error if the queue is empty.
template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error) 

// Removes the least recently (front) element from a queue and
// returns it.

{
   

    if (isEmpty()) {
        throw logic_error("Queue is empty");
    }
    else {
        QueueNode* temp = front;
        DataType tempData = front->dataItem;
        front = front->next;
        delete temp;
        return tempData;
    }

}

//--------------------------------------------------------------------
// Clear
// Removes all the data items from a queue.
// @Pre None
// @Post Queue is empty.
template <typename DataType>
void QueueLinked<DataType>::clear() 

// Removes all the elements from a queue.

{
    while (!isEmpty()) {
        dequeue();
    }
    
}

//--------------------------------------------------------------------
// isEmpty
// Determines if a queue is empty.
// @Pre None
// @Post None
// @return true if the queue is empty, otherwise false.
template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const 

// Returns true if a queue is empty. Otherwise, returns false.

{
    return (front == 0);
}

//--------------------------------------------------------------------
// isFull
// Determines if a queue is full.
// @Pre None
// @Post None
// @return true if the queue is full, otherwise false.
template <typename DataType>
bool QueueLinked<DataType>::isFull() const 

// Returns true if a queue is full. Otherwise, returns false.
// The main reason it is included in the linked implementation is for
// operation compatibility with the array-based implementation.


{

    // Implementation option #1. Not always true, but probably good 
    // enough for our purposes.

    /*
    // Implementation option #2.
    // This is a ugly and clumsy way to test if the list is full.
    // If a node can be successfully allocated than the list is not
    // full.  If the allocation fails it is implied that there is no
    // more free memory therefore the list is full.
*/
    try {
        QueueNode* newNode = new QueueNode(0, 0);
        delete newNode;
        return false;
    }
    catch (bad_alloc exception) {
        return true;
    }



}

//--------------------------------------------------------------------
// showStructure
// Outputs the data items in a queue. If the queue is empty, outputs
// "Empty queue". This operation is intended for testing and
// debugging purposes only.
// @Pre None
// @Post The queue's contents, from front to back, have been output.
template < typename DataType >
void QueueLinked<DataType>:: showStructure () const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
    QueueNode* p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << "[" << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}


#endif		// #ifndef QUEUELINKED_HPP

