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
std::ostream& operator<<(std::ostream &out, const Rectangle<T1,T2> &r);

template<class T1, class T2>
class Rectangle{
private:
    T1 len;
    T2 width;
public:
    Rectangle(T1 l, T2 w);
    // Step 2: Include <T1,T2> (or just <>) to indicate this is a template
    friend std::ostream& operator<< <T1,T2>(std::ostream &out, const Rectangle<T1,T2> &r);

};// here ends the definition of class




// Here starts the implementation of class Rectangle
template<class T1, class T2>
Rectangle<T1,T2>::Rectangle(T1 l, T2 w){
    len = l;
    width = w;
}

// Step 3: Finally define the operator
template<class T1, class T2>
std::ostream& operator<<(std::ostream &out, const Rectangle<T1,T2> &r){
    out << "Len: " << r.getLen() << "\n";
    out << "Width: " << r.getWidth() << "\n";
    //or all the above can be replaced by the next line
    //r.display(out);
    return out;
}



#endif //RECTANGLETEMP_RECTANGLE_HPP
