//
// Created by Oreofe Solarin on 11/14/22.
//
#include <string>

#ifndef LAB11HASHTABLE_NODE_HPP
#define LAB11HASHTABLE_NODE_HPP


class Node {
public:
    Node(std::string value);
    ~Node();
    std::string getValue();
    Node* getNext();
    void setNext(Node* next);
private:
    std::string value;
    Node* next;

};

Node::Node(std::string value) {
    this->value = value;
    this->next = nullptr;
}

Node::~Node() {
    delete next;
}

std::string Node::getValue() {
    return value;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* next_Ptr) {
    this->next = next_Ptr;
}




#endif //LAB11HASHTABLE_NODE_HPP
