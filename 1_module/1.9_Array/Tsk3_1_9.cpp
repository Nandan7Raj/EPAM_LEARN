//
// Created by NandanRaj on 25-01-2026.
//
#include<iostream>
#include<cstdlib> // For qsort
using namespace std;
// Function prototypes or declarations
void inputArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void qsortWrapper(int arr[], int size);
void printArray(int arr[], int size);

int main()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;
    /* Input size with validation */
    do{
        cout<<"Enter number of elements (1-100): ";
        cin>>size;
        if(cin.fail())
        {
            cin.clear(); // clear the fail state
            cin.ignore(1000, '\n'); // discard invalid input
            cout<<"Input unmatched! Please enter a valid integer.\n";
            continue;
        }
        if(size <= 0 || size > MAX_SIZE){
            cout<<"Invalid size! Please enter a value between 1 and 100.\n";
        }
    }while (size <= 0 || size > MAX_SIZE);
    // Input array elements
    inputArray(arr, size);
    // Giving user choice for sorting algorithm
    int choise;
    do  {
        cout<<"Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n3. Quick Sort\nEnter choice (1-3): ";
        cin>>choise;
        if(cin.fail())
        {
            cin.clear(); // clear the fail state
            cin.ignore(1000, '\n'); // discard invalid input
            cout<<"Input unmatched! Please enter a valid integer.\n";
            continue;
        }
        if(choise<=0 || choise > 3)
        {
            cout<<"Invalid choice! Please enter a value between 1 and 3.\n";
            continue;
        }
        }while(choise < 1 || choise > 3);

        void (*sortFunction)(int[], int);// Function pointer for selected sort
        switch(choise)
        {
            case 1:
                sortFunction = bubbleSort;// Assign Bubble Sort
                cout<<"Array sorted using Bubble Sort with complexity O(n^2): ";
                break;
            case 2:
                sortFunction = selectionSort; // Assign Selection Sort
                cout<<"Array sorted using Selection Sort with complexity O(n^2): ";
                break;
            case 3:
                sortFunction = qsortWrapper ;// Assign Quick Sort
                cout<<"Array sorted using Quick Sort with complexity O(n log n): ";
                break;
            default:// This case should never be reached due to validation
                cout<<"Unexpected error occurred.\n";
                return 0;
        }
        cout<<"\nOriginal array: ";
        printArray(arr, size);
        // Call the selected sorting function
        sortFunction(arr, size);
        cout<<"\nSorted array: ";
        printArray(arr, size);

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
// Bubble Sort implementation
void bubbleSort(int arr[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
// Selection Sort implementation
void selectionSort(int arr[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b); // Ascending order
}
// Quick Sort helper function
void qsortWrapper(int arr[], int size)
{
    qsort(arr, size, sizeof(int), compare);
}
// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}