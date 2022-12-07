//
// Created by Thedo on 4/15/2022.
//

// NOTE 1: add a Time variable to the Driver class that represents the time
// the Driver last left the restaurant. Then, when they return to the restaurant,
// we can figure out how much time they spent out, and add it to their
// total driving time.

// NOTE 2: the Order class needs an additional status for having been cooked, but
// still waiting at the restaurant.

// NOTE 3: the status constant variables for Driver and Order need to be moved
// to the public section, so that their terminology can be used in the Restaurant
// class.

#ifndef PIZZATRACKING_RESTAURANT_H
#define PIZZATRACKING_RESTAURANT_H

#include <stdexcept>
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <list>
#include <queue>

#include "Order.hpp"
#include "Time.h"
#include "Driver.hpp"

class Restaurant {
public:
    Restaurant(string restName);

    // Coding Status: Drafted, needs testing
    void status();
    // Coding Status: Drafted, needs testing
    void summary();

    // Coding Status: Drafted, needs testing
        // Pre: None.
        // Post: Returns the driver with the given name.
    Driver* getDriver(string name);

    // Coding Status: Drafted, needs testing
        // Pre: None.
        // Post: Adds the driver to the end of the drivers List.
    void addDriver(Driver& driver);

    // Coding Status: Drafted, needs testing
        // Pre: None.
        // Post: Adds the order to the end of the cookingOrders list.
    void addOrder(Order& order);

    // Coding Status: Drafted, needs testing
        // Pre: The cookingOrders deque is not empty.
        // Post: Removes the oldest order in the cookingOrders queue,
        // and adds it to the end of the departingOrders queue.
    void serveNextOrder() throw(logic_error);

    // Coding Status: Drafted, needs testing
        // Pre: The departingOrders queue is not empty.
        // Post: Removes the oldest order in the departingOrders queue,
        // gives it to the driver
        // WHAT DO WE DO WITH TIME? CHECK NOTE 3
    Order* departNextOrder(Driver *driver, Time time) throw(logic_error);

    // Coding Status: Drafted, needs testing
        // Pre: The driver is delivering an order.
        // Post: Delivers the driver's held order.
    void deliver(Driver* driver, Time time, float tip) throw(logic_error);

private:
    string name;
    int ordersCompleted;
    int totalOrderTime;
    list<Driver>* drivers;
    deque<Order>* cookingOrders;
    deque<Order>* departingOrders;
};

#endif //PIZZATRACKING_RESTAURANT_H
