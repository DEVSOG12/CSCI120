//
// Created by Oreofe Solarin on 10/28/22.
//

#ifndef CH1INHERITANCE_VEHICLE_HPP
#define CH1INHERITANCE_VEHICLE_HPP
#include <iostream>
using namespace std;

class Vehicle
{
public:
    // is abstract class because has at least one pure virtual method
    // abstract classes are base classes, they cannot be instantiated

    // this pure virtual method cannot be implemented here,
    // but derived classes MUST implement it
    virtual void Start() = 0;

    // The virtual keyword allows a member function of a parent (base)
    // class to be over-ridden in its child (derived) classes.
    // If a derived class also implements Stop(),
    // one of the two implementations is called at runtime
    virtual void Stop()
    {
        speed = 0;
    }
    virtual void Accelerate(float acc)
    {
        cout << "[I accelerate in Vehicle base-class] ";
        speed = speed + 20;
    }
    virtual float get_Speed()
    {
        return speed;
    }
protected: // can be accessed by derived class, but not outside of it
    float speed;
};
#endif //CH1INHERITANCE_VEHICLE_HPP
