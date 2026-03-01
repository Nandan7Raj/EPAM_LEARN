//
// Created by NandanRaj on 27-01-2026.
//
#include <iostream>
using namespace std;

// Structure Point
// By default, members of a structure are public
// This allows direct access to data members
struct Point {
    int x;
    int y;
};

// Class Rectangle
// By default, members of a class are private
// This helps in data hiding and encapsulation
class Rectangle {
private:
    int length;
    int width;

public:
    // Setter function to assign values to private data members
    void setDimensions(int newLength, int newWidth) {
        length = newLength;
        width = newWidth;
    }

    // Function to display rectangle dimensions
    void showDimensions() {
        cout << "Length = " << length << " cm\n";
        cout << "Width = " << width << " cm\n";
    }
};

// Function to read x and y coordinates with input validation
void readPointCoordinates(int& xCoord, int& yCoord) {
    while (true) {
        cout << "Enter X and Y coordinates: ";
        cin >> xCoord >> yCoord;

        if (cin.fail()) {
            cout << "Invalid input. Please enter integer values only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }
}

// Function to assign values to Point structure
// Direct access is allowed because members are public
void assignPoint(Point* pointObj) {
    int x, y;
    readPointCoordinates(x, y);

    pointObj->x = x;
    pointObj->y = y;

    cout << "Point coordinates assigned successfully.\n";
}

// Function to display Point values
void displayPoint(const Point* pointObj) {
    cout << "Point is (" << pointObj->x << ", " << pointObj->y << ")\n";
}

// Function to read rectangle dimensions with input validation
void readRectangleDimensions(int& rectLength, int& rectWidth) {
    while (true) {
        cout << "Enter rectangle length and width in cm: ";
        cin >> rectLength >> rectWidth;

        if (cin.fail()) {
            cout << "Invalid input. Please enter integer values only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }
}

// Function to assign rectangle dimensions
// Private members are accessed using setter functions
void assignRectangleDimensions(Rectangle* rectObj) {
    int length, width;
    readRectangleDimensions(length, width);

    rectObj->setDimensions(length, width);

    cout << "Rectangle dimensions set using setter function.\n";
}

// Function to display rectangle dimensions
void displayRectangleDimensions(Rectangle* rectObj) {
    rectObj->showDimensions();
}

int main() {
    Point point;
    Rectangle rectangle;

    cout << "Setting and getting values of Point structure\n";
    assignPoint(&point);
    displayPoint(&point);

    cout << "\nSetting and getting values of Rectangle class\n";
    assignRectangleDimensions(&rectangle);
    displayRectangleDimensions(&rectangle);

    cout << "\nEND\n";
    return 0;
}
