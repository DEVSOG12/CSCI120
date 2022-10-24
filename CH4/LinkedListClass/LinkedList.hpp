//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT list: Link-based implementation.
    @file LinkedList.h */

#ifndef LINKEDLIST_hpp
#define LINKEDLIST_hpp

#include <memory>
#include "ListInterface.h"
#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"

#include <cassert>
#include <iostream>
#include <vector>


template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int itemCount;           // Current count of list items


    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    auto getNodeAt(int position) const;
    auto copyListNodes(Node<ItemType>* origChainPtr) const;

public:
    //*******************************************
    // Overloaded Operators:
    // Placed here for easy access in Interlude
    // See top of LinkedList.cpp
    bool operator==(const LinkedList<ItemType>& rightHandSide) const;
    LinkedList<ItemType>& operator=(const LinkedList<ItemType>& rightHandSide);
    LinkedList<ItemType> operator+(const LinkedList<ItemType>& rightHandSide) const;
    template<class friendItemType>
    friend std::ostream& operator<<(std::ostream& outStream, const LinkedList<friendItemType>& outputList);
    //*******************************************


    // LinkedList methods from interface
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);
    virtual ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    ItemType getEntry(int position) const throw(PrecondViolatedExcep);

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    void replace(int position, const ItemType& newEntry)
    throw(PrecondViolatedExcep);

}; // end LinkedList


//********************************************************************************
// Overloaded Operators

template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType>& rightHandSide) const
{
   bool isEqual = true; // Assume equal
   
   // First check number of items is the same
   if (itemCount != rightHandSide.getLength())
      isEqual = false;
   else
   {  // Then compare items
      auto leftSidePtr = headPtr;
      auto rightSidePtr = rightHandSide.headPtr;
      
      while ((leftSidePtr != nullptr) && (rightSidePtr != nullptr) && isEqual)
      {
         ItemType leftItem = leftSidePtr->getItem();
         ItemType rightItem = rightSidePtr->getItem();
         isEqual = (leftItem == rightItem);
         
         leftSidePtr = leftSidePtr->getNext();
         rightSidePtr = rightSidePtr->getNext();
      }  // end whiile
   }  // end if
   
   return isEqual;
}  // end operator==



template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList<ItemType>& rightHandSide) const
{
   LinkedList<ItemType> concatList;
   
   auto leftChainPtr = copyListNodes(headPtr);
   concatList.headPtr = leftChainPtr;
   auto rightChainPtr = copyListNodes(rightHandSide.headPtr);
   
   concatList.itemCount = itemCount;
   auto leftChainTailPtr = concatList.getNodeAt(itemCount);
   leftChainTailPtr->setNext(rightChainPtr);
   concatList.itemCount += rightHandSide.itemCount;
   
   return concatList;
}  // end operator+

template<class friendItemType>
std::ostream& operator<<(std::ostream& outStream, const LinkedList<friendItemType>& outputList)
{
   int position = 1;
   auto currPtr = outputList.headPtr;
   while (currPtr != nullptr)
   {
       outStream << position << "\t" << currPtr->getItem() << std::endl;
      currPtr = currPtr->getNext();
      position++;
   }
   return outStream;
} // end operator<<

//**********************************************************************
// Private methods for copying List for Overloaded Operators
// PRIVATE:
template<class ItemType>
auto LinkedList<ItemType>::copyListNodes(Node<ItemType>* origChainPtr) const
{
   Node<ItemType>* newChainPtr;
   //Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      newChainPtr = nullptr;                      // Original list is empty
   else
   {
      ItemType nextItem = origChainPtr->getItem();
      
      // Create first node in chain
      newChainPtr = new Node<ItemType>(nextItem);
      auto tailPtr = newChainPtr;      // Points to last node in new chain
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         tailPtr->setNext(new Node<ItemType>(nextItem));
         
         // Advance pointer to new last node
         tailPtr = tailPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      tailPtr->setNext(nullptr);                 // Flag end of chain
   }  // end if
   
   return newChainPtr;
}  // end copyListNodes


//**********************************************************************
//**********************************************************************

// List methods from previous chapters
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{


}  // end default constructor


template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert) // Copilot is
   {
      // Create a new node containing the new entry 
      auto newNodePtr = new Node<ItemType>(newEntry);
      
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr); 
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         auto prevPtr = getNodeAt(newPosition - 1);
         
         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext()); 
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         auto prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;

       itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);

}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      auto nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      std::string message = "getEntry() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      auto nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      std::string message = "replace() called with an invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end replace

template<class ItemType>
auto LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}


// @pre None.

template<class ItemType>
LinkedList<ItemType> &LinkedList<ItemType>::operator=(const LinkedList<ItemType> &rightHandSide) {
    if (this != &rightHandSide) {
            clear();
            itemCount = rightHandSide.itemCount;
            headPtr = copyListNodes(rightHandSide.headPtr);
        }
        return *this;
}


template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &aList) {
    headPtr = copyListNodes(aList.headPtr);
    itemCount = aList.itemCount;

}
// end getNodeAt


#endif