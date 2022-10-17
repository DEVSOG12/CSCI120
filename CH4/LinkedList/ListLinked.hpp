//--------------------------------------------------------------------
//
//  Laboratory 5                                          ListLinked.hpp
//
//  Class declaration and implementation for the linked List ADT
//
//--------------------------------------------------------------------

#ifndef LISTLINKED_HPP
#define LISTLINKED_HPP

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType>
class List {
  public:
    List(int ignored = 0);
    List(const List& other);
    List& operator=(const List& other);
    ~List();

    void insert(const DataType& newDataItem) throw (logic_error);
    void remove() throw (logic_error);
    void replace(const DataType& newDataItem) throw (logic_error);
    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void gotoBeginning() throw (logic_error);
    void gotoEnd() throw (logic_error);
    bool gotoNext() throw (logic_error);
    bool gotoPrior() throw (logic_error);

    DataType getCursor() const throw (logic_error);

    // Programming exercise 2
    //void moveToBeginning () throw (logic_error);

    // Programming exercise 3
    //void insertBefore(const DataType& newDataItem) throw (logic_error);
    
    void showStructure() const;

  private:
    class ListNode {
      public:
	ListNode(const DataType& nodeData, ListNode* nextPtr);

	DataType dataItem;
	ListNode* next;
    };

    ListNode* head;
    ListNode* cursor;

};



//--------------------------------------------------------------------
//  Laboratory 5                                        
//
//  Below come the linked list implementation of the List ADT ***
//
//--------------------------------------------------------------------



//--------------------------------------------------------------------
// NOTE: because ListNode is an inner class, references to ListNode do not take
// the <DataType> template qualifier. If it were a separate external class, then
// the <DataType> would be required.
// We switched from an external class in the 2nd edition to an inner class in
// order to demonstrate better OO design, as well as to get away from the ugly use of
// a private constructor in ListNode and "friend" to allow the List class to access 
// the ListNode's private data.
//--------------------------------------------------------------------
template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData,
				   ListNode* nextPtr)
// Creates a list node containing item elem and next pointer
// nextPtr.

    : dataItem(nodeData), next(nextPtr)
{
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>::List(int ignored)

// Creates an empty list. The argument is included for compatibility
// with the array implementation (maxSize specifier) and is ignored.

    : head(0), cursor(0)
{
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>::List(const List& other)
    : head(0), cursor(0)

// Copy constructor. Creates a list which is equivalent in content
// to the "other" list.

{
   
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)

// Overloaded assignment operator. Reinitializes the list to be 
// equivalent in content to the "other" list.
// Note: we include self-assignment protection by checking whether
// "this" object is identical to the "other" object.

{
  
    return *this;
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>::~List() 

// Destructor. Frees the memory used by a list.

{
    free(head);
    free(cursor);
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) item in the list.
// In either case, moves the cursor to newDataItem.


}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::remove() throw (logic_error) 

// Removes the item marked by the cursor from a list. Moves the
// cursor to the next item in the list. Assumes that the first list
// item "follows" the last list item.

{
   
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
   
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::clear() 

// Removes all the items from a list. Sets head and cursor to 0.

{
   
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::isEmpty() const 

// Returns true if a list is empty. Otherwise, returns false.

{
    return true;
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::isFull() const 

// Returns true if a list is full. Otherwise, returns false.
//
// Note: determining whether the free store/heap would be able to
// satisfy the request to allocate another ListNode is either ugly,
// non-portable, or both. We explain the issue to our students and
// tell them that it is acceptible to simply return false. The main
// reason we include isFull() is for compatibility with the array-based
// implementation of the list. 

{
    return false;		// See note above and alternative below.

    /*
    // One alternative implementation: Not really recommended, but
    // might have some pedagogic value.
    // Below is a somewhat hacked way to test if the list is full.
    // If a node can be successfully allocated than the list is not
    // full.  If the allocation fails it is implied that there is no
    // more free memory therefore the list is full.
    
    DataType testDataItem;
    ListNode *p;
    
    try
    {
        p = new ListNode(testDataItem, 0);
    }
    catch ( bad_alloc &e )
    {
        return true;
    }

    delete p;
    return false;

    // End of alternative implementation.
    */
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)

// If a list is not empty, then moves the cursor to the beginning of
// the list. If list is empty, throws logic error.

{
   
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)

// If a list is not empty, then moves the cursor to the end of the
// list. Otherwise, throws logic_error.

{
   
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise, 
// leaves cursor unmoved and returns false.

{
    return true;
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
    return true;
}

//--------------------------------------------------------------------

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)

// Returns the item marked by the cursor. Requires that list is not empty.

{
   
   return cursor->dataItem;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::showStructure() const

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
    {
        if ( isEmpty() )
        {
            cout << "Empty list" << endl;
        }
        else
        {
            for (ListNode* temp = head; temp != 0; temp = temp->next) {
                if (temp == cursor) {
                    cout << "[";
                }

                // Assumes that dataItem can be printed via << because
                // is is either primitive or operator<< is overloaded.
                cout << temp->dataItem;

                if (temp == cursor) {
                    cout << "]";
                }
                cout << " ";
            }
            cout << endl;
        }
    }
   
}




#endif
