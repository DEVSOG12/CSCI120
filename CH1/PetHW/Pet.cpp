//
// Created by Oreofe Solarin on 9/16/22.
//

#include "Pet.h"
#include <iostream>

Pet::Pet() {
    age = 0;
    name = "HelloWorld!";
    type = "Default";
}

Pet::Pet(std::string kName, std::string kType, int kAge) {
    age = kAge;
    name = kName;
    type = kType;
}


void Pet::setAge(int newAge)  {
    age = newAge;
}

void Pet::setName(std::string newName) {
    name = newName;
}

void Pet::setType(std::string newType) {
    type = newType;
}

int Pet::getAge() const {
    return age;
}

std::string Pet::getName() const {
    return name;
}

std::string Pet::getType() const {
    return type;
}



void Pet::display(std::ostream &stream) {
    stream << std::endl<< "Pet Name: " << name << std::endl;
    stream << "Pet Age: " << age << std::endl;
    stream << "Pet Type: " << type << std::endl;
}



std::ostream & operator<<(std::ostream& stream,   Pet &pet){
    pet.display(stream);
    return stream;
}