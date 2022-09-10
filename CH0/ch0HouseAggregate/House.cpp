//
// Created by Oreofe Solarin on 9/9/22.
//

#include "House.h"

House::House(const Triangle &r1, const Triangle &r2, const Rectangle &b) {
    roof1 = r1;
    roof2 = r2;
    base = b;
}

double House::getArea() const {
    return roof1.getArea() + roof2.getArea() + base.getArea();
}
