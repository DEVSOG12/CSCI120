//
// Created by Oreofe Solarin on 9/9/22.
//

#ifndef CH0HOUSEAGGREGATE_TRIANGLE_H
#define CH0HOUSEAGGREGATE_TRIANGLE_H

class Triangle {
private:
    double sideLen;
public:
    Triangle(double side);
    Triangle();

    double getArea() const;

    void setLen(double newLen);
};



#endif //CH0HOUSEAGGREGATE_TRIANGLE_H
