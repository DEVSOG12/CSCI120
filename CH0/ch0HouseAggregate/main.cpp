#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "House.h"

int main() {

    // Rectangle Obj
    Rectangle myBase(80, 60);
    Triangle roof1(30), roof2(50);
    House profVisaHouse(roof1,roof2,myBase);
    std::cout << "area of roof1: " << roof1.getArea()  << std::endl;
    std::cout << "area of roof2: " << roof2.getArea()  << std::endl;
    std::cout << "area of base: "  << myBase.getArea() << std::endl;
    std::cout << "Visa House area: " << profVisaHouse.getArea() << std::endl;

    return 0;
}
