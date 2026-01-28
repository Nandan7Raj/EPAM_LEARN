//
// Created by NandanRaj on 25-01-2026.
//
#include <iostream>
#include <iomanip>
using namespace std;

// Function to take input and store values in the array
void inputArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Function to calculate and return the sum of array elements
int sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

/* Function to calculate and return the average */
float calculateAverage(int sum, int size)
{
    return static_cast<float>(sum) / size;
}

int main()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    /* Input size with validation */
    do {
        cout << "Enter number of elements (1-100): ";
        cin >> size;

        if (size <= 0 || size > MAX_SIZE) {
            cout << "Invalid size! Please enter a value between 1 and 100.\n";
        }
    } while (size <= 0 || size > MAX_SIZE);

    /* Function calls */
    inputArray(arr, size);
    int sum = sumArray(arr, size);
    float average = calculateAverage(sum, size);

    /* Output */
    cout << fixed << setprecision(2);
    cout << "\nSum of elements: " << sum << endl;
    cout << "Average of array elements: " << average << endl;

    return 0;
}
