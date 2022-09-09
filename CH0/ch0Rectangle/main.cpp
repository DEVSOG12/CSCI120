#include <iostream>
#include "Rectangle.h"


//using namespace std; // I'm not using namespace


int main(){
    Rectangle bath(2,3), dorm(3,2), kitchen;
    std::cout << "Testing My overload operator  << " << std::endl;
    std::cout << "My Bath is: " << std::endl << bath << std::endl;


    std::cout << "Testing overload operator  =="<< std::endl;
    if (bath == dorm) {
        std::cout << "My Bath and Dorm have the same area namely"<< std::endl <<    bath.getArea() <<" units"<< std::endl<< std::endl;

    }else{
        std::cout << "My Bath and Dorm don't have the same area namely"<< std::endl <<bath.getArea() <<" units"<< std::endl<< std::endl;

    }

    std::cout << "Testing My overload operator  \n>> " << std::endl;
    std::cout << "Original Dimension for Kitchen are: " << std::endl;
    std::cout << kitchen << std::endl;
    std::cin >> kitchen;
    std::cout << "New Dimension for Kitchen are: \n1" << std::endl;
    std::cout << kitchen;




    return 0;
}
