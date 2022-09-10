//
// Created by Oreofe Solarin on 9/9/22.
//



#ifndef CH0RECTANGLE_RECTANGLE_H
#define CH0RECTANGLE_RECTANGLE_H


#include <iostream>

class Rectangle{

private:
    int len;
    int width;


public:
    Rectangle();

    Rectangle(int length, int width);

    void setLen(int l);

    void setWidth(int w);

    int getLen() const;

    int getWidth() const;

    int getArea() const ;

    void display(std::ostream& stream) const;

//    void input(std::ostream &stream) const;

//    void input(std::istream &stream) const;

    friend std::ostream &operator<<(std::ostream &out, const Rectangle &r);


    friend std::istream &operator>>(std::istream &in,  Rectangle &r);

    bool operator==(const Rectangle &r);
};


#endif CH0RECTANGLE_RECTANGLE_H
