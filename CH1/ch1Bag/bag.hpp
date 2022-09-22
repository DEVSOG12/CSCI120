//
// Created by Oreofe Solarin on 9/16/22.
//

#ifndef CH1BAG_BAG_HPP
#define CH1BAG_BAG_HPP



#include <vector>
#include "BagInterface.h"
#include <cstddef>
#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
class Bag : public BagInterface<T>
{
private:
    static const int DEFAULT_BAG_SIZE = 6;
    T items[DEFAULT_BAG_SIZE]; // array of bag items
    int itemCount;                    // current count of bag items
    int maxItems;                     // max capacity of the bag

    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain
    // the target.
    int getIndexOf(const T& target) const;

public:
    Bag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const T& newEntry);
    bool remove(const T& anEntry);
    void clear();
    bool contains(const T& anEntry) const;
    int getFrequencyOf(const T& anEntry) const;
    std::vector<T> toVector() const;
//    void display(ostream &out) const;
};  // end Bag



#include <cstddef>
#include <stdio.h>


template<class T>
Bag<T>::Bag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor

template<class T>
int Bag<T>::getCurrentSize() const
{
    return itemCount;
}  // end getCurrentSize

template<class T>
bool Bag<T>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class T>
bool Bag<T>::add(const T& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    }  // end if

    return hasRoomToAdd;
}  // end add

template<class T>
bool Bag<T>::remove(const T& anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }  // end if

    return canRemoveItem;
}  // end remove

template<class T>
void Bag<T>::clear()
{
    itemCount = 0;
}  // end clear

template<class T>
int Bag<T>::getFrequencyOf(const T& anEntry) const
{
    int frequency = 0;
    int searchIndex = 0;
    while (searchIndex < itemCount)
    {
        if (items[searchIndex] == anEntry)
        {
            frequency++;
        }  // end if

        searchIndex++;
    }  // end while

    return frequency;
}  // end getFrequencyOf

template<class T>
bool Bag<T>::contains(const T& anEntry) const
{
    return getIndexOf(anEntry) > -1;
}  // end contains





/* ALTERNATE 1
 template<class T>
 bool Bag<T>::contains(const T& anEntry) const
 {
 return getFrequencyOf(anEntry) > 0;
 }  // end contains
 */
/* ALTERNATE 2
 template<class T>
 bool Bag<T>::contains(const T& anEntry) const
 {
 bool found = false;
 for (int i = 0; !found && (i < itemCount); i++)
 {
 if (anEntry == items[i])
 {
 found = true;
 } // end if
 } // end for

 return found;
 }  // end contains
 */

template<class T>
std::vector<T> Bag<T>::toVector() const
{
    std::vector<T> bagContents;
    for (int i = 0; i < itemCount; i++)
        bagContents.push_back(items[i]);
    return bagContents;
}  // end toVector

// private
template<class T>
int Bag<T>::getIndexOf(const T& target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    // if the bag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }  // end if
    }  // end while

    return result;
}  // end getIndexOf


#endif //CH1BAG_BAG_HPP