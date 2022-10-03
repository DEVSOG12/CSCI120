//--------------------------------------------------------------------
//
//  		                                           ListArray.hpp
//  
//  Class declaration and implementation
//  for the array implementation of the List ADT
//
//--------------------------------------------------------------------

#ifndef LISTARRAY_HPP
#define LISTARRAY_HPP

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType >
class List
{
  public:

    static const int MAX_LIST_SIZE = 10;   // Default maximum list size

    // Constructors
    
    // Creates an empty list. Allocates enough memory for maxNumber
	// data items (defaults to MAX_LIST_SIZE).
    List ( int maxNumber = MAX_LIST_SIZE );	// Default constructor
    List ( const List& source );		// Copy constructor
    
    // Overloaded assignment operator
    List<DataType> & operator= ( const List& source );

    // Destructor
    virtual ~List ();

    // List manipulation operations
    virtual void insert ( const DataType& newDataItem )  // Insert after cursor
	throw ( logic_error );  
    void remove () throw ( logic_error );        // Remove data item
    virtual void replace ( const DataType& newDataItem ) // Replace data item
	throw ( logic_error ); 
    void clear ();                               // Clear list

    // List status operations
    bool isEmpty () const;                    // List is empty
    bool isFull () const;                     // List is full

    // List iteration operations
    void gotoBeginning ()                     // Go to beginning
        throw ( logic_error );
    void gotoEnd ()                           // Go to end
        throw ( logic_error );
    bool gotoNext ()                          // Go to next data item
        throw ( logic_error );
    bool gotoPrior ()                         // Go to prior data item
        throw ( logic_error );
    DataType getCursor () const
        throw ( logic_error );                // Return data item

    // Output the list structure -- used in testing/debugging
     void showStructure () const;

    DataType getItem (int index); // Returns the item at index

    std::vector<DataType> toVectorM(); // Converts the List to a vector

    DataType operator[](int i); // Subscript accessor

    // these are not needed for this lab
    // void moveToNth ( int n )                  // Move data item to pos. n
    //    throw ( logic_error );  
    // bool find ( const DataType& searchDataItem )     // Find data item
    //    throw ( logic_error );  

  protected:

    // Data members
    int maxSize,
        size,             // Actual number of data item in the list
        cursor;           // Cursor array index
    DataType *dataItems;  // Array containing the list data item
};


// below this line, students implement the required methods
// the one-argument constructor is implemented for you as model

template <typename DataType>
List<DataType>::List ( int maxNumber ): 
maxSize(maxNumber),
size(0),
cursor(-1)
{
    dataItems = new DataType[maxSize];
}


// Pre: .
// Post: Returns a boolean value if the List is empty
// Checks cursor and size are equal to -1 and 0 respectively
template <typename DataType>
bool List<DataType>::isEmpty () const{
    if(size == 0 && cursor == -1) return true;
    return false;
}                 

// Pre: .
// Post: Returns a boolean value if the List is full
// Checks if the size  == maxSize
template <typename DataType>    
bool List<DataType>::isFull () const{
    if(size == maxSize) return true;
    return false;
}


// Pre: Req. a [List] source
// Post: Return a  [List] after populating
template<typename DataType>
List<DataType>::List(const List &source) {
cursor = source.cursor;
size = source.size;
maxSize = source.maxSize;
dataItems = source.dataItems;

}

// Pre: .
// Post: Aka Destruction
// Frees up memory after it has been allocated
template<typename DataType>
List<DataType>::~List() {
    delete [] dataItems;

}

// Pre: .
// Post: std::cout items in the List<DataType>
// std::cout all items in the list assuming the item object [DataType] are std::cout possible
template <typename DataType>
void List<DataType>:: showStructure () const {
    std::cout << "Size = " << size << "\t";
    std::cout << "Cursor = " << cursor << std::endl;
    for (int i = 0; i < maxSize; ++i) {
        std::cout << i <<  "     " ;
    }
    std::cout << std::endl;
    for (int i = 0; i < maxSize; ++i) {
        if(cursor == i - 1){
            std::cout << "[" << dataItems[i] << "]" << "     ";

        }else{
            std::cout << dataItems[i] << "     ";

        }
    }
    std::cout << std::endl;
}

// Pre: Req. [DataType] newDataItem
// Post: Insert an item at the position of the cursor if insertable
// Adds an element into the List at the position of the cursor
template<typename DataType>
void List<DataType>::insert(const DataType &newDataItem) throw(logic_error) {
    bool canInsert = ((cursor + 1) >= 0)
                     && ((cursor + 1) <= size + 1)
                     && (size < maxSize );
    if(canInsert){


        for (int entryPosition = size; entryPosition >= (cursor + 1); entryPosition--)
            dataItems[entryPosition + 1] = dataItems[entryPosition]; // copy the entry right


        // Insert new entry
        dataItems[cursor + 1] = newDataItem;
        if(cursor + 2  < maxSize) cursor++;

        if(cursor + 2  < maxSize) size++;
    } else {
        throw logic_error("Can Not Add Element into the List. It could be because the List is full ore at the wrong position");
    }


}

// Pre: .
// Post: Removes an item at the position of the cursor if removable
// Removes an element into the List at the position of the cursor
template<typename DataType>
void List<DataType>::remove() throw(logic_error) {

    bool ableToRemove = (cursor + 1 >= 0) && (cursor + 1 <= size) && dataItems[cursor] != NULL;
    if (ableToRemove)
    {
        // Remove entry by shifting all entries after the one at
        // position toward the beginning of the array
        // (no shift if position == itemCount)
        for (int entryPosition = cursor + 1; entryPosition < size; entryPosition++)
            dataItems[entryPosition] = dataItems[entryPosition + 1]; // copy entry on the right to left

        size--;  // Decrease count of entries
    }  // end if
    else{
        throw logic_error("Cannot Remove Item for List");
    }


}

// Pre: Req. [DataType] newDataItem
// Post: Replaces an item at the position of the cursor if replaceable
// Replaces an element in the List at the position of the cursor
template<typename DataType>
void List<DataType>::replace(const DataType &newDataItem) throw(logic_error) {
    if(cursor != -1) {
        dataItems[cursor] = newDataItem;
    }
    else{
        throw logic_error("Cannot Replace: Out of Bounds");
    }
}

// Pre: .
// Post: Insert an item at the position of the cursor if insertable
// Adds an element into the List at the position of the cursor
template<typename DataType>
void List<DataType>::clear() {
    for (int i = 0; i < size; ++i) {
        dataItems[i] = NULL;
    }
    cursor = -1;
    size = 0;

}

// Pre: .
// Post: Moves the cursor to initial position (-1)
// Moves the cursor to the Beginning
template<typename DataType>
void List<DataType>::gotoBeginning() throw(logic_error) {
if(cursor != -1){
    cursor = -1;
}else{
    throw logic_error("Already At the Beginning");
}
}

// Pre: .
// Post: Moves the cursor to end position (size -2)
// Moves the cursor to the End
template<typename DataType>
void List<DataType>::gotoEnd() throw(logic_error) {
if(cursor != size - 1){
    cursor = size - 2;
}else{
    throw logic_error("Already At the End");
}
}

// Pre: .
// Post: Moves the cursor to next position cursor++
// Moves the cursor to the next
template<typename DataType>
bool List<DataType>::gotoNext() throw(logic_error) {
    if(cursor > maxSize - 3) {

        return false;
        throw logic_error("cannot move");
    }
   cursor++;
    return true;

}

// Pre: .
// Post: Moves the cursor to prior position cursor--
// Moves the cursor to the prior position
template<typename DataType>
bool List<DataType>::gotoPrior() throw(logic_error) {
    if(cursor == -1 || cursor > maxSize) return false;
        cursor--;
        return true;
}

// Pre: .
// Post: Returns the item at the cursor
// Returns the value of the item at the cursor index
template<typename DataType>
DataType List<DataType>::getCursor() const throw(logic_error) {
    if(dataItems[cursor] == NULL) return 'N';
    return dataItems[cursor];
}

// Pre: .
// Post: Converts the List to a Vector by iterating
// Converts the List to a Vector
template<typename DataType>
vector<DataType> List<DataType>::toVectorM() {
    vector<DataType> mrm;

    for (int i = 0; i < size; ++i) {
        mrm[i] = dataItems[i];
    }
    return mrm;
}

// Pre: Req [int] index
// Post: Return the item at index of the List
// Returns value of the item at the position index
template<typename DataType>
DataType List<DataType>::getItem(int index) {
    return dataItems[index];
}

template<typename DataType>
DataType List<DataType>::operator[](int i) {
    return dataItems[i];
}


// Pre: Req. [List] Source
// Post: Returns List[DataType] as a reference to the source.
// Copies items in the source to the List
template <typename DataType>
List<DataType>& List<DataType>:: operator= ( const List &source )

// Overloaded assignment operator. Resets a list object to contain a
// deep-copy of the provided model object, source.

{
    // Set buffer to correct size. If current buffer too small, allocate a new one.
    // NOTE: this also happens to protect against self-destruction.  Explicit
    // checks against &source vs. this will appear later (e.g. Stack).
    if( source.maxSize > maxSize ) {
        delete [] dataItems;
        dataItems = new DataType[source.maxSize];
    }

    maxSize = source.maxSize;
    size = source.size;
    cursor = source.cursor;

    for( int i=0; i<size; i++ ) {
        dataItems[i] = source.dataItems[i];
    }

    // Return an object reference to support multiple assignment.
    // E.g., "a = b = c".
    return *this;
}



#endif

