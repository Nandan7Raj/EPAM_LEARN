//
// Created by NandanRaj on 25-01-2026.
//
#include <iostream>
using namespace std;

// Function to add two numbers
float add(float num1, float num2) {
    return num1 + num2;
}

// Function to subtract two numbers
float subtract(float num1, float num2) {
    return num1 - num2;
}

// Function to multiply two numbers
float multiply(float num1, float num2) {
    return num1 * num2;
}

// Function to divide two numbers
float divide(float num1, float num2) {
    if (num2 == 0) {
        throw "Error: Division by zero is undefined.";
    }
    return num1 / num2;
}

int main() {
    float num1, num2, result;
    int choice;
    char again;

    do {
        cout << "\n--- Basic Calculator ---" << endl;
        cout << "\nChoose Operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                cout << "Result of addition: " << result << endl;
                break;

            case 2:
                result = subtract(num1, num2);
                cout << "Result of subtraction: " << result << endl;
                break;

            case 3:
                result = multiply(num1, num2);
                cout << "Result of multiplication: " << result << endl;
                break;

            case 4:
                try{
                    result = divide(num1, num2);
                    cout << "Result of division: " << result << endl;
                } catch(const char* msg) {
                    cout << msg << endl;
                }
                break;

            default:
                cout << "Invalid choice! Please select between 1 to 4." << endl;
        }

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Thank you for using the calculator!" << endl;
    return 0;
}
