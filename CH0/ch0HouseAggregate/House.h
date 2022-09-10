//
// Created by Oreofe Solarin on 9/9/22.
//

#ifndef CH0HOUSEAGGREGATE_HOUSE_H
#define CH0HOUSEAGGREGATE_HOUSE_H


#include "Triangle.h"
#include "Rectangle.h"

class House {
private:
    Triangle  roof1, roof2;
    Rectangle base;
public:
    House(const Triangle& r1, const Triangle& r2, const Rectangle& b);

    double getArea() const;
};



#endif //CH0HOUSEAGGREGATE_HOUSE_H
