#include "test.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

void Test::testEmptyenqueue()
{
    cout << "\nTest 1: enqueue() on empty queue\n";

    Queue q;
    q.enqueue(1, 3);

    q.printQueue();
}

void Test::testOneenqueue()
{
    cout << "\nTest 2: enqueue() with one node already in queue\n";

    Queue q;
    q.enqueue(1, 2);
    q.enqueue(2, 4);

    q.printQueue();
}

void Test::testOnedequeue()
{
    cout << "\nTest 3: dequeue() on queue with one node\n";

    Queue q;
    q.enqueue(1, 5);

    Data* removed = q.dequeue();

    if (removed != nullptr)
    {
        cout << "Removed customer #" << removed->getCustomerNumber() << endl;
        delete removed;
    }
    else
    {
        cout << "Dequeue failed.\n";
    }

    q.printQueue();
}

void Test::testTwodequeue()
{
    cout << "\nTest 4: dequeue() on queue with two nodes\n";

    Queue q;
    q.enqueue(1, 2);
    q.enqueue(2, 3);

    Data* removed = q.dequeue();

    if (removed != nullptr)
    {
        cout << "Removed customer #" << removed->getCustomerNumber() << endl;
        delete removed;
    }
    else
    {
        cout << "Dequeue failed.\n";
    }

    q.printQueue();
}

void Test::testSimulation()
{
    cout << "\nTest 5: simulation for 24 hours\n";

    int runTime = 24 * 60;
    runSimulation(runTime);
}

void Test::runSimulation(int runTime)
{
    int totalTimeRan = 0;
    int expressArrival = rand() % 5 + 1;
    int normalArrival = rand() % 6 + 3;
    int customerCounter = 0;

    Queue normalQueue;
    Queue expressQueue;

    srand((unsigned int)time(NULL));

    while (totalTimeRan < runTime)
    {
        // Express arrival
        if (expressArrival == 0)
        {
            int expressServiceTime = rand() % 5 + 1;

            customerCounter++;
            if (customerCounter > 1440)
            {
                customerCounter = 1;
            }

            expressQueue.enqueue(customerCounter, expressServiceTime);

            cout << "Minute " << totalTimeRan
                << ": Customer #" << customerCounter
                << " arrived in the Express Queue.\n";

            expressArrival = rand() % 5 + 1;
        }

        // Normal arrival
        if (normalArrival == 0)
        {
            int normalServiceTime = rand() % 6 + 3;

            customerCounter++;
            if (customerCounter > 1440)
            {
                customerCounter = 1;
            }

            normalQueue.enqueue(customerCounter, normalServiceTime);

            cout << "Minute " << totalTimeRan
                << ": Customer #" << customerCounter
                << " arrived in the Normal Queue.\n";

            normalArrival = rand() % 6 + 3;
        }

        // Process customers
        expressQueue.processCustomer();
        normalQueue.processCustomer();

        // Print queues every 10 minutes
        if (totalTimeRan > 0 && totalTimeRan % 10 == 0)
        {
            cout << "\n************** EXPRESS QUEUE **************\n";
            expressQueue.printQueue();

            cout << "\n************** NORMAL QUEUE ***************\n";
            normalQueue.printQueue();
        }

        totalTimeRan++;
        normalArrival--;
        expressArrival--;

        normalQueue.incrementWaitTime();
        expressQueue.incrementWaitTime();
    }
}