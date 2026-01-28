//
// Created by NandanRaj on 25-01-2026.
//
#include<iostream>
using namespace std;
// Function prototypes or declarations
void inputArray(int arr[], int size);
void reverseArray(int arr[], int reversedArr[], int size);
void printArray(int arr[], int size);
int main()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int reversedArr[MAX_SIZE];
    int size;
    /* Input size with validation */
    do {
        cout << "Enter number of elements (1-100): ";
        cin >> size;
        if(cin.fail())
        {
            cin.clear(); // clear the fail state
            cin.ignore(1000, '\n'); // discard invalid input
            cout<<"Input unmatched! Please enter a valid integer.\n";
            continue;
        }
        if (size <= 0 || size > MAX_SIZE ) {
            cout << "Invalid size! Please enter a value between 1 and 100.\n";
        }
    } while (size <= 0 || size > MAX_SIZE);
    /* Function calls */
    inputArray(arr, size);
    cout<<"Original array: ";
    printArray(arr, size);
    reverseArray(arr, reversedArr, size);
    cout<<"Reversed array: ";
    printArray(reversedArr, size);
    return 0;
}
// Function to take input and store values in the array
void inputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}
// Function to reverse the array
void reverseArray(int arr[],int reversedArr[], int size)
{
    for (int i = 0; i < size; i++) {
        reversedArr[i]=arr[size-1-i]; // Fill reversed array
    }
}
// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}