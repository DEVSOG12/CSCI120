//
// Created by Sofia Visa on 9/22/20.
//

#ifndef CH4LINKEDBAG_LINKEDBAG_HPP
#define CH4LINKEDBAG_LINKEDBAG_HPP

#include "BagInterface.h"
#include "Node.hpp"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node
    int itemCount;           // Current count of bag items

    // Returns either a pointer to the node containing a given entry
    // or the null pointer if the entry is not in the bag.
    Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
    virtual ~LinkedBag();                       // Destructor should be virtual
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    std::vector<ItemType> toVector() const;
    bool addAtEnd(const ItemType& newEntry);
    LinkedBag<ItemType> unionBag(const LinkedBag<ItemType>& otherBag);
    LinkedBag<ItemType> operator=(const LinkedBag<ItemType>& otherBag);
    void printBag();

}; // end LinkedBag


template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain

    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original bag is empty
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer

        while (origChainPtr != nullptr)
        {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();

            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while

        newChainPtr->setNext(nullptr);              // Flag end of chain
    }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
    clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
    // Add to beginning of chain: new node references rest of chain;
    // (headPtr is null if chain is empty)
    Node<ItemType>* nextNodePtr = new Node<ItemType>();

    nextNodePtr->setItem(newEntry);
    nextNodePtr->setNext(headPtr);  // New node points to chain
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

    headPtr = nextNodePtr;          // New node is now first node
    itemCount++;
//std::cout << nextNodePtr->setNext() << std::endl;
    return true;
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }  // end while

    return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem)
    {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());

        // Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    } // end if

    return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;

        nodeToDeletePtr = headPtr;
    }  // end while
    // headPtr is nullptr; nodeToDeletePtr is nullptr

    itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
        {
            frequency++;
        } // end if

        counter++;
        curPtr = curPtr->getNext();
    } // end while

    return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
    return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
}
*/
/* ALTERNATE 2
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
    bool found = false;
    Node<ItemType>* curPtr = headPtr;

    while (!found && (curPtr != nullptr))
    {
        if (anEntry == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    } // end while

    return curPtr;
}

// Add at the End of the Linked List
// @pre: none
// @post: a new node is added at the end of the linked list
// @param: newEntry, the item to be added to the linked list
// @return: true if the addition is successful, false otherwise
template<class ItemType>
bool LinkedBag<ItemType>::addAtEnd(const ItemType &newEntry) {
    Node<ItemType>* nextNodePtr = new Node<ItemType>();
    nextNodePtr->setItem(newEntry);
    nextNodePtr->setNext(nullptr);
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount)) {
        curPtr = curPtr->getNext();
        counter++;
    }
    curPtr->setNext(nextNodePtr);
    itemCount++;
    return true;
}

// Union of two Linked Lists
// @pre: none
// @post: a new linked list is created that contains the union of the two linked lists
// @param: aBag, the second linked list
// @return: a new linked list that contains the union of the two linked lists
template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::unionBag(const LinkedBag<ItemType>& otherBag)
{
    LinkedBag<ItemType> unionBag;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount)) {
        unionBag.add(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }
    curPtr = otherBag.headPtr;
    counter = 0;
    while ((curPtr != nullptr) && (counter < otherBag.itemCount)) {
        unionBag.add(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }
    return unionBag;
}

template<class ItemType>
void LinkedBag<ItemType>::printBag() {
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount)) {
        std::cout << curPtr->getItem() << std::endl;
        curPtr = curPtr->getNext();
        counter++;
    }

}
// Overloaded operator =
// @pre: none
// @post: the linked list is assigned to the other linked list
// @param: otherBag, the linked list to be assigned to the current linked list
// @return: the current linked list

template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::operator=(const LinkedBag<ItemType> &rightHandSide) {
    if (this != &rightHandSide) {
        clear();
        Node<ItemType>* curPtr = rightHandSide.headPtr;
        int counter = 0;
        while ((curPtr != nullptr) && (counter < rightHandSide.itemCount)) {
            add(curPtr->getItem());
            curPtr = curPtr->getNext();
            counter++;
        }
    }
    return *this;
}
// end getPointerTo


#endif //CH4LINKEDBAG_LINKEDBAG_HPP
