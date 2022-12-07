#include "Vehicle.hpp"
#include "CarAndAirplans.hpp"
#include <iostream>

// We want to test drive vehicles
// that can be cars or airplanes or helicopters
void TestDriveThis(Vehicle *vehicle)
{
    vehicle->Start();

    float targetSpeed = 150;
    while (vehicle->get_Speed() < targetSpeed)
    {
        // this shows polymorphism: (1) the types of the objects
        // created with new are Car, Airplane, Helicopter
        // but (2) the Accelerate is called from the coreesponing classes NOT
        // from the base class Vehicle, eventhough here vehicle is a pointer
        // to a Vehicle object
        vehicle->Accelerate(70);

        //If you want to call Accelerate from the base class Vehicle
        // use  vehicle->Vehicle::Accelerate(70);
        //vehicle->Vehicle::Accelerate(70);
        cout << "Pedal to the metal\n";
    }
    //You reach the target speed
    vehicle->Stop();
}

int main() {
    Car myCar;
    myCar.Start();

    // here comes code from students
    // Hint: explore these two options:
    // myCar.Accelerate(10);
    // myCar.Vehicle::Accelerate(10);
    cout << "My car is going " << myCar.get_Speed() << " km/h\n";

    myCar.Accelerate(10);
    cout << "My car is going " << myCar.get_Speed() << " km/h " << "after accelerating in Car class\n";
    myCar.Vehicle::Accelerate(10);
    cout << "My car is going " << myCar.get_Speed() << " km/h " << "after accelerating in Vehicle class\n";
    cout << endl << endl;
    cout << "****** This will illustrate polymorphism********" << endl;
    cout << "This is a Vehicle pointer pointing to an Airplane object." << endl;
    Vehicle* myAirForceOne = new Airplane();

    myAirForceOne->Start();

    // here comes code from students

    cout << "My airplane is going " << myAirForceOne->get_Speed() << " km/h\n";

    myAirForceOne->Accelerate(10);
    cout << " My airplane is going " << myAirForceOne->get_Speed() << " km/h " << "after accelerating in Airplane class\n";
    myAirForceOne->Vehicle::Accelerate(10);
    cout << "My airplane is going " << myAirForceOne->get_Speed() << " km/h " << "after accelerating in Vehicle class\n";
    cout << endl << endl;

    return 0;
}

// Sample of Queue Implementation

class Queue
{
private:
    int *queueArray;
    int queueSize;
    int front;
    int rear;
    int numItems;

public:
    Queue(int);
    ~Queue();
    void enqueue(int);
    void dequeue(int &);
    bool isEmpty();
    bool isFull();
    void clear();

    // Methods
    void printQueue();
    void printQueueFront();
    void printQueueRear();
    void printQueueSize();



};

Queue::Queue(int size) {
    queueArray = new int[queueSize];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;

}

Queue::~Queue() {
    delete [] queueArray;

}

void Queue::enqueue(int) {
    if (isFull()) {
        cout << "The queue is full.\n";
    } else {
        rear = (rear + 1) % queueSize;
        queueArray[rear] = value;
        numItems++;
    }

}






