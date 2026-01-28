#include <iostream>
using namespace std;

class DynamicArray {
    static int count;     // Keeps track of how many DynamicArray objects are created
    int* data;            // Pointer to dynamically allocated array
    int arrNo;            // Unique ID for each array object (for tracking)

public:
    //Default constructor
    DynamicArray() :data(new int[4]) {
        arrNo = count++;
        cout << "DynamicArray constructor(Default) for array " << arrNo << endl;
    }
    // Parametrized Constructor: allocates dynamic memory
    DynamicArray(int siz) :data(new int[siz]) {
        arrNo = count++;
        cout << "DynamicArray constructor(Parametrized) for array " << arrNo << endl;
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

// function that declares a local array of DynamicArray Obj
void demoDestructors() {
    //Each object's default constructor will be called as the array is created.
    DynamicArray arr[4];
}
int main() {
    demoDestructors();

    return 0;
}
