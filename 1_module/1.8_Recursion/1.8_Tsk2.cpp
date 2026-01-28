//
// Created by NandanRaj on 25-01-2026.
//
#include <iostream>
#include <ctime>
using namespace std;

// Predefined cache size
#define MAX_STEPS 50

// Global cache array
int cache[MAX_STEPS + 1];

// Recursive function with memoization
int stairCaseCounter(int totalSteps)
{
    // Base cases
    if (totalSteps == 0)
        return 1;  // already at top
    if (totalSteps == 1)
        return 1;
    if (totalSteps == 2)
        return 2;

    // Return cached result if already computed
    if (cache[totalSteps] != -1)
        return cache[totalSteps];

    // Recursive computation
    cache[totalSteps] =
        stairCaseCounter(totalSteps - 1) +
        stairCaseCounter(totalSteps - 2);

    return cache[totalSteps];
}

int main()
{
    int totalSteps;

    // Initialize cache with -1
    for (int i = 0; i <= MAX_STEPS; i++)
        cache[i] = -1;

    // User input
    cout << "Enter total number of steps: ";
    cin >> totalSteps;

    // Input validation
    if (totalSteps < 0)
    {
        cout << "Error: Number of steps cannot be negative." << endl;
        return 0;
    }

    if (totalSteps > MAX_STEPS)
    {
        cout << "Error: Maximum allowed steps is " << MAX_STEPS << "." << endl;
        return 0;
    }

    // Time measurement (to observe memoization benefit)
    clock_t start = clock();
    int ways = stairCaseCounter(totalSteps);
    clock_t end = clock();

    // Output
    cout << "Total number of ways to climb "
         << totalSteps << " steps: "
         << ways << endl;

    cout << "Execution time: "
         << double(end - start) / CLOCKS_PER_SEC
         << " seconds" << endl;

    return 0;
}
