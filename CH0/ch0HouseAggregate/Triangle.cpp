//
// Created by Oreofe Solarin on 9/9/22.
//

#include "Triangle.h"
#include <cmath>

Triangle::Triangle() {
    sideLen = 0;
}

Triangle::Triangle(double side) {
    sideLen = side;
}

double Triangle::getArea() const {
    // Sqrt ( s (s-a)^3)
    int s = ( 3.0 * sideLen ) / 2.00;

    return sqrt(s * ( (s - sideLen) *  (s - sideLen) * (s - sideLen)));
}

void Triangle::setLen(double newLen) {
    sideLen = newLen;
}
