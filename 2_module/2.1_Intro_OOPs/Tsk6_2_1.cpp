//
// Created by NandanRaj on 28-01-2026.
//

#include <algorithm>
#include <iostream>
using namespace std;

/*
 * Counter class
 * Keeps track of how many Counter objects are currently alive
 * using a static data member.
 */
class Counter {
    static int count;   // Shared among all objects, tracks live objects

public:
    // Constructor: called when an object is created
    Counter() {
        count++;        // Increment count on object creation
    }

    // Destructor: called when an object is destroyed
    ~Counter() {
        count--;        // Decrement count on object destruction
    }

    // Static member function to access current count
    static int getCount() {
        return count;
    }
};

// Definition and initialization of static member
int Counter::count = 0;

/*
 * Utility function to print
 * current number of live Counter objects
 */
void printCount() {
    cout << "Current count of objects: "
         << Counter::getCount() << endl;
}

int main(int argc, char *argv[]) {

    // No objects created yet
    printCount();

    // Dynamically create two Counter objects
    Counter *c1 = new Counter();
    Counter *c2 = new Counter();
    printCount();   // Count should be 2

    // Destroy first object
    delete c1;
    c1 = nullptr;   // Avoid dangling pointer
    printCount();   // Count should be 1

    // Create another object
    Counter *c3 = new Counter();

    // Destroy second object
    delete c2;
    c2 = nullptr;

    // Create fourth object
    Counter *c4 = new Counter();
    printCount();   // Count should be 2

    // Create fifth object
    Counter *c5 = new Counter();
    printCount();   // Count should be 3

    // Destroy third object
    delete c3;
    c3 = nullptr;
    printCount();   // Count should be 2

    // Destroy remaining objects
    delete c4;
    c4 = nullptr;

    delete c5;
    c5 = nullptr;

    // All objects destroyed
    printCount();   // Count should be 0
}

