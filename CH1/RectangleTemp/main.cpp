#include <iostream>
#include <array>
#include "Rectangle.hpp"
//template<typename K>

template <typename T>


 T max(const T arr[], int size)
{
     float start = arr[0];
    for (unsigned int i = 0; i < size; ++i) {

        if(arr[i] > start)
        {
            start = arr[i];
        }


    }
    return start;
}

int main() {
//    int const sizeArray = 3;
//    float array[sizeArray] = {2, 77.8, 9.2};
//    std::cout << "Max of float array: "<< max(array, sizeArray) << std::endl;
//
//    int array2[sizeArray] = {55, 67, 33};
//    std::cout << "Max of int array: " << max(array2, sizeArray) << std::endl;

    Rectangle<int,int> bath(2,3);
    std::cout << "Testing out Rectangle with ints, ";
    std::cout << "and display: " << std::endl;
    bath.display(std::cout);

    std::cout << "Testing out Rectangle with float and int, ";
    std::cout << "and getArea(): " << std::endl;
    Rectangle<float,int> room(2.5,3);
    std::cout << room.getArea() << std::endl;
//room
    std::cout << "Testing out crazzy Rectangle with strings, ";
    std::cout << "and overloaded operator<<: " << std::endl;
    Rectangle<std::string,std::string> crazzyRoom("amc","pppp");
//    crazzyRoom.getArea();
//crazzyRoom.display(std::cout);
    std::cout << crazzyRoom;
//
//    std::cin >> crazzyRoom;
//
//    crazzyRoom.display(std::cout);


    return 0;
}
