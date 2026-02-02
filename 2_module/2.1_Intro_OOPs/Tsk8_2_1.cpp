//
// Created by NandanRaj on 29-01-2026.
//
#include <iostream>
using namespace std;
class Box {
    // private member variables
    string name;
    int length;
    int width;
    int height;
public:
    // Constructor
    Box(string name) {
        // Initialize member variables using 'this' pointer
        this->name = name;
    }
    // Member function to set dimensions
    void set_dimension(int length,int width,int height) {
        // Use 'this' pointer to distinguish between member variables and parameters
        this->length = length;
        this->width = width;
        this->height = height;
        cout<<"dimenstion set for "<<name<<endl;
    }
    // Member function to calculate volume and is const qualified
    int getVolume() const {
        return length * width * height;
    }
    // Member function to get name
    string getName() {
        return name;
    }
    // Member function to compare volumes of two boxes
    const Box& compareVolume(const Box& box){
        int cur_box_volume=this->getVolume();// volume of current object
        int passed_box_volume=box.getVolume();// volume of passed object
        if (cur_box_volume >= passed_box_volume) {
            return *this;// return current object if its volume is greater or equal
        }
        return box;// return passed object otherwise
    }
};
int main() {
    Box box1("box1");// Create first Box object
    Box box2("box2");// Create second Box object
    box1.set_dimension(2,3,4);//  Set dimensions for box1
    box2.set_dimension(3,4,3);// Set dimensions for box2

    Box temp = box1.compareVolume(box2);// Compare volumes of box1 and box2
    cout << "Box with more volume is "<<temp.getName() << endl;// Print the name of the box with more volume

}