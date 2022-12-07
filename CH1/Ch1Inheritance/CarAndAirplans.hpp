//
// Created by Oreofe Solarin on 10/28/22.
//

#ifndef CH1INHERITANCE_CARANDAIRPLANS_HPP
#define CH1INHERITANCE_CARANDAIRPLANS_HPP
#include "Vehicle.hpp"
#include <iostream>
using namespace std;

// public inheritance allows to inherit all public and
// protected members from the base class as such
class Car : public Vehicle
{
public:
    void Start(){
        speed = 0.0;
        cout << "You properly started this car!";
    }

    // this overrides the base-class implementation of Accelerate
    virtual void Accelerate(float acc) {
        cout << "[I accelerate in Car class] ";
        speed = speed + acc;
    }

};

class Airplane : public Vehicle
{
public:
    void Start(){
        speed = 5.0;
        cout << "You properly started this airplane!  You rock.";
    }
    // this overrides the base-class implementation of Accelerate
    virtual void Accelerate(float acc) {
        cout << "[I accelerate in Airplane class] ";
        speed = speed + acc*3;
    }

};

class Helicopter : public Vehicle
{
public:
    void Start(){
        speed = 20.5;
        cout << "You properly start this helicopter.  Is there anything you can't do??";
    }

    // this overrides the base-class implementation of Accelerate
    virtual void Accelerate(float acc) {
        cout << "[I accelerate in Helicopter class] ";
        speed = speed + acc*2;
    }

};

#endif //CH1INHERITANCE_CARANDAIRPLANS_HPP
