//
// Created by Thedo on 4/15/2022.
//

#include "Restaurant.h"
#include "Restaurant (1).h"

#include "Driver.hpp"

#include "Order.hpp"

Restaurant::Restaurant(string restName) {
    name = restName;
    ordersCompleted = 0;
    totalOrderTime = 0;

    drivers = new list<Driver*>;
    cookingOrders = new deque<Order*>;
    departingOrders = new deque<Order*>;
}

void Restaurant::status() {
    cout << "Status of restaurant: " << name << endl;

    cout << "Orders waiting to cook:" << endl;
    for (auto it = cookingOrders->begin() ; it != cookingOrders->end(); ++it) {
        cout << (*it)->toString() << endl;
    }

    cout << "Orders waiting to depart:" << endl;
    for (auto it = departingOrders->begin() ; it != departingOrders->end(); ++it) {
        cout << (*it)->toString() << endl;
    }

    cout << "Drivers:" << endl;
    for (auto it = drivers->begin() ; it != drivers->end(); ++it) {
        cout << (*it)->toString() << endl;
    }
}

void Restaurant::summary() {
    cout << "Summarizing operations of restaurant: " << name << endl;

    for (auto it = drivers->begin() ; it != drivers->end(); ++it) {
        totalOrderTime += (*it)->getDeliveryTime(); //
    }

    if (ordersCompleted == 0)
        cout << "No completed orders." << endl;
    else {
        cout << "Number of orders completed: " << ordersCompleted << endl;
        cout << "Average time per order: " << totalOrderTime/ordersCompleted << endl;
    }

    cout << "Drivers:" << endl;
    for (auto it = drivers->begin() ; it != drivers->end(); ++it) {
        cout << (*it)->toString() << endl;
    }
}

/*
Driver* Restaurant::getDriver(string name) {
    for (list<Driver>::iterator it = drivers->begin() ; it != drivers->end(); ++it) {
        if (it->getName() == name) {
            Driver driver = *it;
            return &driver;
        }
    }

    return nullptr;
}
 */

void Restaurant::addDriver(Driver driver) {
    drivers->push_back(&driver);
}

void Restaurant::addOrder(Order order) {
    cookingOrders->push_back(&order);
}

void Restaurant::serveNextOrder() throw(logic_error) {
    if (cookingOrders->size() == 0)
        throw logic_error("There are no orders waiting to be served.");

    departingOrders->push_back(cookingOrders->front());
    cookingOrders->pop_front();
}


Order* Restaurant::departNextOrder(Driver *driver, Time time) throw(logic_error) {
    if (departingOrders->size() == 0)
        throw logic_error("There are no orders waiting to depart.");
    //if (driver->getStatus() != Driver::WAITING)
    //    throw logic_error("That driver is not available to take an order.");

    driver->setDeparted(time);

    departingOrders->pop_front();
}

void Restaurant::deliver(Driver *driver, Time time, float tip) throw(logic_error) {
    //if (driver->getStatus() != Driver::DELIVERING)
    //    throw logic_error("That driver is not delivering an order.");

    ordersCompleted += 1;
    driver->deliver(time, tip);
}
