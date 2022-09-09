//
// Created by Oreofe Solarin on 9/5/22.
//

#include "Rectangle.h"




Rectangle::Rectangle() {
    len = 0;
    width = 0;
}

Rectangle::Rectangle(int l, int w) {
    len = l;
    width = w;
}

void Rectangle::setLen(int l){
    len = l;
}

void Rectangle::setWidth(int w) {
    width = w;
}

int Rectangle::getLen() const {
    return len;
}

int Rectangle::getWidth() const {
    return width;
}

int Rectangle::getArea() const{
    return width * len;
}


 std::ostream &operator<<(std::ostream &out, const Rectangle &r) {
   r.display(out);
     return out;

}

std::istream &operator>>(std::istream &in,  Rectangle &r) {
    std::cout << "Input Len: ";
    in >> r.len;
    r.setLen(r.len);
    std::cout << "Input Width: ";
    in >> r.width;
    r.setWidth(r.width);
    r.display(std::cout);
    return  in;
}

bool Rectangle::operator==(const Rectangle &r) {
    if(len * width == r.len * r.width) {
        return true;
    }
    return false;
}


void Rectangle::display(std::ostream& stream) const {
    stream << "Length: " << len << std::endl;
    stream << "Width: " << width << std::endl;
    stream << "Area: " << width * len << std::endl;
}

//std::istream &operator<<(std::istream &in, const Rectangle &r) {
//    return <#initializer#>;
//}

//void Rectangle::input(std::istream &stream) const {
//   stream >> len;
//}