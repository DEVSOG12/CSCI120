//--------------------------------------------------------------------
//
//  Laboratory 7, Programming Exercise 1                   storesim.cs
//
//  Program implementation shell.
//
//--------------------------------------------------------------------

// Simulates the flow of customers through a line in a store.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// Use which ever implementation is currently configured.
#if LAB7_TEST1
#   include "QueueLinked.hpp"
#else
#   include "QueueArray.hpp"
#endif

using namespace std;

int main ()
{
#if LAB7_TEST1
    QueueLinked<int> custQ;      // Line (queue) of customers containing the
#else
    QueueArray<int> custQ;       // Line (queue) of customers containing the
#endif 				 //   time that each customer arrived and
                                 //   joined the line
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        timeArrived,             // Time dequeued customer arrived
        waitTime,                // How long dequeued customer waited
        totalServed = 0,         // Total customers served
        totalWait   = 0,         // Total waiting time
        maxWait     = 0,         // Longest wait
        numArrivals = 0;         // Number of new arrivals

    // Seed the random number generator. Equally instructive to run the
    // simulation with the generator seeded and not seeded.
    srand( time(NULL) );

    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    // Put your code here to run this simulation. Use "rand()" to get
    // a pseudorandom number that you can use to calculate probabilities.

    // Start the simulation
    custQ.clear();
    for (minute = 0; minute < simLength; minute++)
    {
        // Check for new arrivals
        if (rand() % 3 == 0 && !custQ.isFull())
        {
            // Put your code here to add a new arrival to the queue
            custQ.enqueue(minute);
            numArrivals++;
        }

        // Check for customers to be served
        if (rand() % 4 == 0)
        {
            // Put your code here to dequeue a customer from the queue
            if (!custQ.isEmpty())
            {
                timeArrived = custQ.dequeue();
                waitTime = minute - timeArrived;
                totalServed++;
                totalWait += waitTime;
                if (waitTime > maxWait)
                    maxWait = waitTime;
            }
        }
    }






    // Print out simulation results
    cout << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait << endl;

    return 0;
}
