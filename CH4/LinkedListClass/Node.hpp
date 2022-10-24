//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file Node.cpp 
    Listing 4-2 */
#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
using namespace std;

template<class ItemType>
class Node           // A node on the list
{
public:
    // these two methods are accessed by the ostream<<
    // which is friend to LinkedList, NOT to Node
    // so we must make them public
    ItemType getItem() const;
    Node<ItemType>* getNext() const;

private:
    ItemType item;        // A data item on the list
    Node<ItemType>* next; // Pointer to next node

    Node();
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    Node(const ItemType& anItem);
    void setItem(const ItemType& anItem);
    void setNext( Node<ItemType>* nextNodePtr);

    // Friend class - now LinkedList can access private parts of Node
    template<class friendItemType>
    friend class LinkedList;
};

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
} // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
} // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
                item(anItem), next(nextNodePtr)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext( Node<ItemType>* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
//    if(item != NULL)

   return item;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
   return next;
} // end getNext

#endif