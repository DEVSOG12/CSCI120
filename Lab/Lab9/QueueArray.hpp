// QueueArray.hpp

#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

template <typename DataType>
class QueueArray : public Queue<DataType> {
  public:
    QueueArray(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE);
    QueueArray(const QueueArray& other);
    QueueArray& operator=(const QueueArray& other);
    ~QueueArray();

    void enqueue(const DataType& newDataItem) throw (logic_error);
    DataType dequeue() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    //void putFront(const DataType& newDataItem) throw (logic_error);
    //DataType getRear() throw (logic_error);
    //int getLength() const;

    void showStructure() const;

  private:
    int maxSize;
    int front;
    int back;
    DataType* dataItems;
};



//--------------------------------------------------------------------
//
//  Laboratory 7                                       
//
//  ** Array implementation of the Queue ADT **
//
//--------------------------------------------------------------------
//--------------------------------------------------------------------

// Constructor
// Creates an empty queue. Allocates enough memory for maxNumber elements.
// @Pre None
// @Post An empty queue with enough memory for maxNumber elements
// @param maxNumber The maximum number of elements that can be in the queue
template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)

// Creates an empty queue. Allocates enough memory for maxNumber
// data items (defaults to MAX_QUEUE_SIZE in class declaration).

    : maxSize(maxNumber), front(-1), back(-1)
{
    dataItems = new DataType[maxSize];
}

//--------------------------------------------------------------------
// Destructor
// Frees the memory used by the queue
// @Pre None
// @Post The memory used by the queue is freed
template <typename DataType>
QueueArray<DataType>::~QueueArray() 

// Frees the memory used by a queue.

{
    delete [] dataItems;
}

//--------------------------------------------------------------------
// Enqueue
// Adds newDataItem to the back of the queue
// @Pre The queue is not full
// @Post newDataItem is added to the back of the queue
// @param newDataItem The data item to be added to the queue
// @throw logic_error if the queue is full
template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error) 

// Inserts newDataItem at the rear of a queue.

{
    if (isFull()) {
        throw logic_error("Queue is full");
    }
    if (isEmpty()) {
        front = 0;
    }
    back = (back + 1) % maxSize;
    dataItems[back] = newDataItem;
    
}

//--------------------------------------------------------------------
// Dequeue
// Removes the front of the queue
// @Pre The queue is not empty
// @Post The front of the queue is removed
// @return The data item that was removed from the queue
// @throw logic_error if the queue is empty
template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error) 

// Removes the least recently added (front) data item from a queue
// and returns it.

{
    if (isEmpty())
        throw logic_error("Queue is empty");
    else
    {
        DataType temp = dataItems[front];
        if (front == back)
            front = back = -1;
        else
            front = (front + 1) % maxSize;
        return temp;
    }
}

//--------------------------------------------------------------------
// Clear
// Removes all the elements from the queue
// @Pre None
// @Post The queue is empty
// @return None
template <typename DataType>
void QueueArray<DataType>::clear() 

// Removes all the data items from a queue.

{
    front = -1;
    back = -1;
}

//--------------------------------------------------------------------
// Is Empty
// Checks if the queue is empty
// @Pre None
// @Post None
// @return True if the queue is empty, false otherwise
template <typename DataType>
bool QueueArray<DataType>::isEmpty() const 
{
    // Check if the Queue is empty
    if (front == -1 && back == -1)
        return true;
    else
        return false;
}

//--------------------------------------------------------------------
// Is Full
// Checks if the queue is full
// @Pre None
// @Post None
// @return True if the queue is full, false otherwise
// @throw logic_error if the queue is full
template <typename DataType>
bool QueueArray<DataType>::isFull() const 
{
    // Check if the Queue is full
    if ((back + 1) % maxSize == front)
        return true;
    else
        return false;

}

//--------------------------------------------------------------------

//--------------------------------------------------------------------
 
//--------------------------------------------------------------------
// Show Structure
// Outputs the elements in a queue. If the queue is empty, outputs
// "Empty queue". This operation is intended for testing and
// debugging purposes only.
// @Pre None
// @Post The queue is unchanged
// @return None
template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}


#endif
