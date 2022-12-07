//
// Created by Oliver on 11/17/2022.
//

#ifndef PIZZA_DRIVER_HPP
#define PIZZA_DRIVER_HPP

#include <string>
using namespace std;

#include "Time.hpp"

class Driver {
private:
    string name;
    bool loggedIn;
    string status;
    Time timeDeparted;
    Time timeOrdered;
    float totalDeliveryTime;
    float totalTripTime;
    float totalTips;
public:
    Driver(string name);
    ~Driver();
    string getName();
    bool isLoggedIn();
    void login();
    void logout();
    void setStatus(string status);
    string getStatus();
    void setDeparted(Time time);
    Time getDeparted();
    void setOrdered(Time time);
    Time getOrdered();
    void setDeliveryTime(float time);
    float getDeliveryTime();
    void setTripTime(float time);
    float getTripTime();
    void setTips(float tips);
    float getTips();
    std::string toString();
    void deliver(Time& time, float tip);
};

// Constructor
// @pre: None
// @post: Creates a nw Driver object with the specified name data
Driver::Driver(std::string name) {
    Driver::name = name;
    loggedIn = false;
    totalDeliveryTime = 0;
    totalTripTime = 0;
    totalTips = 0;
}

// Destructor
// @pre: None
// @post: Frees the space occupied by the Driver object
Driver::~Driver() {
}

// @pre: None
// @post: Returns the name data for the Driver object
string Driver::getName() {
    return name;
}

// @pre: None
// @post: Returns the log in status of the Driver object
bool Driver::isLoggedIn() {
    return loggedIn;
}

// @pre: None
// @post: Sets the Driver object's log in status to true and updates the status message
void Driver::login() {
    loggedIn = true;
    status = "Ready to take order";
}

// @pre: None
// @post: Sets the Driver object's log in status to false
void Driver::logout() {
    loggedIn = false;
}

// @pre: None
// @post: Sets the Driver object's status message
void Driver::setStatus(std::string status) {
    Driver::status = status;
}

// @pre: None
// @post: Returns the Driver object's status message
string Driver::getStatus() {
    return status;
}

// @pre: None
// @post: Sets the Driver object's departure time
void Driver::setDeparted(Time time) {
    timeDeparted = time;
}

// @pre: None
// @post: Returns the Driver object's departure time
Time Driver::getDeparted() {
    return timeDeparted;
}

// @pre: None
// @post: Sets the time at which the Driver's current delivery was originally ordered
void Driver::setOrdered(Time time) {
    timeOrdered = time;
}

// @pre: None
// @post: Returns the time at which the Driver's current delivery was originally ordered
Time Driver::getOrdered() {
    return timeOrdered;
}

// @pre: None
// @post: Sets the Driver object's total time from departure to delivery
void Driver::setDeliveryTime(float time) {
    totalDeliveryTime = time;
}

// @pre: None
// @post: Returns the Driver object's total time from departure to delivery
float Driver::getDeliveryTime() {
    return totalDeliveryTime;
}

// @pre: None
// @post: Sets the Driver object's total time from departure to return
void Driver::setTripTime(float time) {
    totalTripTime = time;
}

// @pre: None
// @post: Returns the Driver object's total time from departure to return
float Driver::getTripTime() {
    return totalTripTime;
}

// @pre: None
// @post: Sets the Driver object's total tips
void Driver::setTips(float tips) {
    totalTips = tips;
}

// @pre: None
// @post: Returns the Driver object's total tips
float Driver::getTips() {
    return totalTips;
}

#endif //PIZZA_DRIVER_HPP
