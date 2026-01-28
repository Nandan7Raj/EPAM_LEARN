//
// Created by NandanRaj on 25-01-2026.
//
#include<iostream>
using namespace std;
// Function prototypes or declarations
void inputArray(int arr[], int size);
int linearSearch(int arr[], int size, int key);
int binarySearch(int arr[], int size, int key);
void printResult(int index, int key);
bool isSorted(int arr[], int size);
int main()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
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
    int key;
    cout << "Enter the element to search for: ";
    cin >> key;
    int choice;
    do
    {
        cout<<"Choose search method:\n1. Binary Search (Array must be sorted)\n2. Linear Search\nEnter choice (1-2): ";
        cin>>choice;
        if(cin.fail())
        {
            cin.clear(); // clear the fail state
            cin.ignore(1000, '\n'); // discard invalid input
            cout<<"Input unmatched! Please enter a valid integer.\n";
            continue;
        }
        if(choice<=0 || choice>2)
        {
            cout<<"Invalid choice! Please enter a value between 1 and 2.\n";
            continue;
        }
        if(choice==1 && !isSorted(arr, size))
        {
            cout<<"Array is not sorted! Binary Search cannot be performed.\n";
            choice=0; // Reset choice to force re-selection
        }
    } while (choice<=0 || choice>2);

    int linearIndex ;
    if(choice==1)
        linearIndex = binarySearch(arr, size, key);
    else
        linearIndex = linearSearch(arr, size, key);

    printResult(linearIndex, key);


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
// Linear Search implementation
int linearSearch(int arr[], int size, int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
            return i; // Return index if found
    }
    return -1; // Return -1 if not found
}
bool isSorted(int arr[], int size)
{
    for(int i=1;i<size;i++)
    {
        if(arr[i]<arr[i-1])
            return false;
    }
    return true;
}
// Binary Search implementation (array must be sorted)
int binarySearch(int arr[], int size, int key)
{

    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid; // Return index if found
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Return -1 if not found
}
// Function to print the search result
void printResult(int index, int key)
{
    if(index != -1)
        cout << "Element " << key << " found at index " << index << "." << endl;
    else
        cout << "Element " << key << " not found in the array." << endl;
}