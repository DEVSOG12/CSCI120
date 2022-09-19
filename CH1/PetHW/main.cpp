#include <iostream>
#include "pet.h"

int main()
{
    Pet pet1("Jazz","cat",3);
    std::cout << "Pet 1 has age: " << pet1.getAge() << "." << std::endl;
    pet1.display(std::cout);
    std::cout << std::endl;
    Pet pet2;
    pet2.setName("Bangles");
    pet2.setType("dog");
    pet2.setAge(1);
    Pet pet3("MRM", "FH", 16);
    Pet pet4("SFRM", "FFH", 16);
    std::cout << "Pet 2 has type: " << pet2.getType() << "." <<std:: endl;
    std::cout << "pet 1: " << pet1 << std::endl;
    std::cout << "pet 2: "<< pet2 << std::endl;
    std::cout << "pet 3: " << pet3 << std::endl;
    std::cout << "pet 4: "<< pet4 << std::endl;

//here comes student code from part 8. below



    for (int i = 0; i < 10; ++i) {

    }

    return  0;
}
