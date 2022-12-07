#include <iostream>
#include <fstream>
#include <sstream>
#include "HashTable.hpp"



int main() {
//    HashTable hashTable(10);
//    hashTable.insert("Hello");
//    hashTable.insert("World");
//    hashTable.insert("Hello");
//    hashTable.insert("World");
//    hashTable.insert("Hello");
//    hashTable.insert("World11");

//    hashTable.print();

// Read from file inputTest11.txt and insert into hash table
HashTable hashTable;

    std::ifstream file("/Users/oreofe/Desktop/CS120/Lab/Lab11HashTable/test.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
//            split line into words
            std::string word;
            std::istringstream iss(line);
            while (iss >> word) {
                hashTable.insert(word);
            }
        }
        file.close();
    }

    hashTable.print();
    return 0;
}
