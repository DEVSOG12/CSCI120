//
// Created by Oreofe Solarin on 11/14/22.
//
#include "Node.hpp"
#include <iostream>
#ifndef LAB11HASHTABLE_LINKEDLIST_HPP
#define LAB11HASHTABLE_LINKEDLIST_HPP

class LinkedList {
    // Public methods
public:
    LinkedList();
    ~LinkedList();
    void insert(std::string value);
    void remove(std::string value);
    void reverse();
    bool contains(std::string value);
    void print();
private:
    Node* head;
    int size;


};

// Constructor
// Initialize head to nullptr
// Initialize size to 0
LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

// Destructor
// Delete head
// @pre head is not nullptr
// @post head is deleted
// @return none
LinkedList::~LinkedList() {
    delete head;
}

// Insert
// Insert a new node at the beginning of the linked list
// @pre value is not empty
// @post a new node is created and inserted at the beginning of the linked list
// @return none

void LinkedList::insert(std::string value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}

// Remove
// Remove a node from the linked list
// @pre value is not empty
// @post a node is removed from the linked list
// @return none
void LinkedList::remove(std::string value) {
    if (head == nullptr) {
        return;
    } else if (head->getValue() == value) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
        size--;
    } else {
        Node* current = head;
        while (current->getNext() != nullptr) {
            if (current->getNext()->getValue() == value) {
                Node* temp = current->getNext();
                current->setNext(current->getNext()->getNext());
                delete temp;
                size--;
                return;
            }
            current = current->getNext();
        }
    }
}

// Contains
// Check if the linked list contains a node with the given value
// @pre value is not empty
// @post none
// @return true if the linked list contains a node with the given value, false otherwise
bool LinkedList::contains(std::string value) {
    if (head == nullptr) {
        return false;
    } else {
        Node* current = head;
        while (current != nullptr) {
            if (current->getValue() == value) {
                return true;
            }
            current = current->getNext();
        }
        return false;
    }
}

// Print
// Print the linked list
// @pre none
// @post the linked list is printed
// @return none
void LinkedList::print() {
    reverse(); // I'm reversing so that the list prints in the correct order like Prof. Visa own lol.
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        std::cout << std::endl;
        return;

    } else {

        Node* current = head;
//        int count = 0;
        while (current != nullptr) {
            std::cout  << current->getValue() << " ";
            current = current->getNext();
//            count++;
        }

        std::cout << std::endl;

        std::cout << std::endl;
    }

}


void LinkedList::reverse() {
    if (head == nullptr) {
        return;
    } else {
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->getNext();
            current->setNext(prev);
            prev = current;
            current = next;
        }
        head = prev;
    }
}

#endif //LAB11HASHTABLE_LINKEDLIST_HPP
