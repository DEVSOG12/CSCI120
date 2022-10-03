//
// Created by Oreofe Solarin on 9/28/22.
//

#include <iostream>
#include "ListArray.hpp"
int main() {

        struct Point{
        float x;
        float y;
        float z;
          };

    List<Point> coords(20);

    Point nw,ne, me;

    coords.insert(ne);
    coords.insert(nw);
    coords.insert(me);



    std::cin.get();
}