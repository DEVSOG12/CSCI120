//
// Created by Oreofe Solarin on 9/16/22.
//
#include <string>
#ifndef PETHW_PET_H
#define PETHW_PET_H


class Pet {
private:
    int age;
    std::string name;
    std::string type;

public:
    // Pre Condition: Nothing req.
    // Post: Creates an Object Pat with def. constructors
    Pet();

    // Pre Condition: Parameters name and type as string and age as int passed as arguements.
    // Post: Creates an Object Pat with data passed through the constructors
    Pet(std::string name, std::string type, int age);

    // Pre Condition: Parameter int newAge as the new age to be
    // Post: Sets private var age to newAge
    void setAge(int newAge);

    // Pre Condition: Parameter newType as the new Type to be
    // Post: Sets private var type to newType
    void setType(std::string newType);


    // Pre Condition: Parameter newName as the new Name to be
    // Post: Sets private var name to newName
    void setName(std::string newName);

    // Pre Condition: Not req
    // Post: Gets int  age
    int getAge() const;

    // Pre Condition: Not req
    // Post: Gets String type
    std::string getType() const;

    // Pre Condition: Not req
    // Post: Gets String name
    std::string getName() const;

    // Pre Condition: Parameter as std::ostream
    // Post:
    void display(std::ostream & stream);

    // Pre Condition: Parameter as std::ostream and object pet passed by reference
    // Post: requires a return type of std::ostream
    friend std::ostream &operator<<(std::ostream & stream, Pet &pet);

    };


#endif //PETHW_PET_H
