//
// Created by Oreofe Solarin on 9/12/22.
//

#ifndef RECTANGLETEMP_RECTANGLE_HPP
#define RECTANGLETEMP_RECTANGLE_HPP


#include <stdio.h>
#include <iostream>

// Step 1: Declare the class template, because we need it
// to declare the operator
template<class T1, class T2>
class Rectangle;




// Declare the operator, because templates must be declared
// in the namespace before you can declare them friends.
// At this point, we can't define the operator, since
// the class template is incomplete.
template<class T1, class T2>
std::ostream & operator<<(std::ostream &out, const Rectangle<T1,T2> &r);


template<class T1, class T2>
std::istream & operator>>(std::istream &in,  Rectangle<T1,T2> &r);



template<class T1, class T2>
class Rectangle{
private:
    T1 len;
    T2 width;
public:
    Rectangle(T1 l, T2 w);
    // Step 2: Include <T1,T2> (or just <>) to indicate this is a template
    friend std::ostream& operator<< <T1,T2>(std::ostream &out, const Rectangle<T1,T2> &r);

    friend std::istream & operator>> <T1,T2>(std::istream &in,  Rectangle<T1,T2> &r);

    T1 getLength() const;

    T2 getWidth() const;

    void display(std::ostream& stream) const;

//    bool operator==(const Rectangle<T1,T2> &r);


    float getArea() const ;


};// here ends the definition of class




// Here starts the implementation of class Rectangle
template<class T1, class T2>
Rectangle<T1,T2>::Rectangle(T1 l, T2 w){
    len = l;
    width = w;
}
//template<class T1, class T2>
//bool Rectangle::operator==() {
//    if(len * width == r.len * r.width) {
//        return true;
//    }
//    return false;
//}


template<class T1, class T2>
T1 Rectangle<T1, T2>::getLength() const {
    return len;
}

template<class T1, class T2>
T2 Rectangle<T1, T2>::getWidth()  const {
    return width;
}

template<class T1, class T2>
float Rectangle<T1, T2>::getArea() const{
    return width * len;
}

template<class T1, class T2>
void Rectangle<T1,T2>:: display(std::ostream& stream) const {

    stream << "Length: " << len << std::endl;
    stream << "Width: " << width << std::endl;
//    if(typeid(len) != typeid(std::string)){
//        stream << "A STRING";
////        stream << "Area: " << width * len << std::endl;
//
//    }
}



// Step 3: Finally define the operator
template<class T1, class T2>
std::ostream& operator<<(std::ostream &out, const Rectangle<T1,T2> &r){
    out << "Len: " << r.getLength() << std::endl;
    out << "Width: " << r.getWidth() << std::endl;
    //or all the above can be replaced by the next line
    //r.display(out);
    return out;
}


template<class T1, class T2>
std::istream & operator>>(std::istream &in,  Rectangle<T1,T2> &r){
    std::cout << "Input Length: " << std::endl;
    std::cin >> r.len ;
    std::cout << "Input Length: " << std::endl;

    std::cin >> r.width ;
    //or all the above can be replaced by the next line
    //r.display(out);
    return in;
}



#endif //RECTANGLETEMP_RECTANGLE_HPP
