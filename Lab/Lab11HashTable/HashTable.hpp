//
// Created by Oreofe Solarin on 11/14/22.
//
#include "LinkedList.hpp"
#include <iostream>
#include <vector>

#ifndef LAB11HASHTABLE_HASHTABLE_HPP
#define LAB11HASHTABLE_HASHTABLE_HPP


class HashTable {
private:
    std::vector<LinkedList> table;

public:
    HashTable();
    ~HashTable();
    void insert(std::string& value);
    void remove(std::string value);
    bool contains(std::string value);
    void print();
    unsigned long hash(std::string value);
};

// Constructor
// Initialize table to a vector of LinkedLists
// @pre none
// @post table is initialized to a vector of LinkedLists
// @return none
HashTable::HashTable() {
    table = std::vector<LinkedList>(13);
}

// Destructor
// Delete table
// @pre table is not nullptr
// @post table is deleted
// @return none
HashTable::~HashTable() {
    table.clear();
}

// Insert
// Insert a new node into the linked list at the index of the hash value
// @pre value is not empty
// @post a new node is created and inserted into the linked list at the index of the hash value
// @return none

void HashTable::insert(std::string& value) {
    unsigned long index = hash(value);
    // Check if hash has collision
    if (!table[index].contains(value)) {
        // Add to linked list table[index]
//        std::cout << "No collision at index " << index << std::endl;
        table[index].insert(value);

    }
}

// Remove
// Remove a node from the linked list at the index of the hash value
// @pre value is not empty
// @post a node is removed from the linked list at the index of the hash value
// @return none

void HashTable::remove(std::string value) {
    unsigned long index = hash(value);
   table[index].remove(value);
}

// Contains
bool HashTable::contains(std::string value) {
    unsigned long index = hash(value);
    // Check if hash has collision
    return table[index].contains(value);
}

// Print
// Print the linked list at the index of the hash value
// @pre none
// @post the linked list at the index of the hash value is printed
// @return none

void HashTable::print() {
    for (int i = 0; i < table.size(); i++) {
        std::cout << "Index " << i << ": ";
        table[i].print();
    }

}

// Hash
// Hash the value
// @pre value is not empty
// @post the value is hashed
// @return the hash value
unsigned long int HashTable::hash(std::string value) {
//    h(item) = item % table-size
// h ( s tr) = (sum of the ASCII codes of the first three characters of s tr) % table_size
    unsigned long int hash = 0;
    for (int i = 0; i < 3; i++) {
        hash += value[i];
    }
//    std::cout << "Hash: " << hash << std::endl;
    return hash % table.size();
}


#endif //LAB11HASHTABLE_HASHTABLE_HPP
