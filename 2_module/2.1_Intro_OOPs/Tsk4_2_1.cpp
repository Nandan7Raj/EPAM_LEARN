#include <iostream>
using namespace std;

class DynamicArray {
    static int count;     // Keeps track of how many DynamicArray objects are created
    int* data;            // Pointer to dynamically allocated array
    int size;             // Size of the array
    int arrNo;            // Unique ID for each array object (for tracking)

public:
    // Constructor: allocates dynamic memory
    DynamicArray(int siz) : size(siz), data(new int[siz]) {
        arrNo = count++;
        cout << "DynamicArray constructor for array " << arrNo << endl;
    }

    // Copy constructor (DEEP COPY)
    // Allocates new memory and copies data from the source object
    DynamicArray(const DynamicArray& arr) : size(arr.size), data(new int[arr.size]) {
        arrNo = count++;
        cout << "DynamicArray copy constructor (DEEP COPY) for array " << arrNo << endl;

        // Copy each element
        for (int i = 0; i < size; i++) {
            data[i] = arr.data[i];
        }
    }

    // Destructor: releases allocated memory
    ~DynamicArray() {
        cout << "DynamicArray destructor called for array " << arrNo
             << " (memory freed)" << endl;
        delete[] data;
    }

    // Prints the starting address of the allocated array
    void printAddress() const {
        cout << "Starting address of array " << arrNo << " : " << data << endl;
    }
};

// Static member initialization
int DynamicArray::count = 1;

int main() {
    DynamicArray a(4);    // Constructor called
    DynamicArray b = a;   // Copy constructor called (deep copy)

    // Addresses will be different because of deep copy
    a.printAddress();
    b.printAddress();


    return 0;
}
