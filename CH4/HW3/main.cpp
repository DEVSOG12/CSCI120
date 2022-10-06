#include <iostream>
#include <vector>
#include "Bag.hpp"

#include "Polynomials.hpp"



int sum(std::vector<int> array) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum = sum + array[i];
    }

    return sum;
}

int main() {
    Polynomials polynomials("2x^3+5x^2-9x^1+10");
    Polynomials p( "-4x^3 + 5x^2 + 7");
    Polynomials q ( "2x^2 -2");

    p.add(q);

    Polynomials x = (p + q);

    x.display(std::cout);
    Polynomials polynomias("7x^8+5x^3+5x^2-9x^1+11");

    polynomials.add(polynomias);

    polynomials.display(std::cout);

    polynomials.increase(3,4);

    polynomials.display(std::cout);

    polynomials.displayCoeffHighest();

//    p.display(std::cout);


    std::vector<int> xa = {1,2,3,4,5,6,7,8,9,10};

    std::cout <<  sum(xa) << std::endl;

    Bag<std::string> fragileBag, storeBag, groceryBag;
    storeBag.add("eggs");
    storeBag.add("apples");
    storeBag.add("milk");
    storeBag.add("bread");
    storeBag.add("eggs");
    storeBag.add("shoes");
    std::cout << "Original store bag: " << std::endl;
    storeBag.display(std::cout); // make sure you have a display method in Bag.cpp, a possible display method is given below

    for (int i = 0; i < storeBag.getCurrentSize(); ++i) {
        std::string item = storeBag.toVector()[i];
        if(item == "bread" || item == "eggs"){
            fragileBag.add(item);
        }
        else{
            groceryBag.add(item);

        }

    }
    storeBag.clear();

    std::cout << "Fragile store bag: " << std::endl;
    fragileBag.display(std::cout);

    std::cout << "Grocery store bag: " << std::endl;

    groceryBag.display(std::cout);

    std::cout << "Original store bag after removing all items: " << std::endl;
    storeBag.display(std::cout);

    return 0;
}
