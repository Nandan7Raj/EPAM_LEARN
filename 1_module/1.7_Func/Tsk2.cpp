//
// Created by NandanRaj on 25-01-2026.
//
#include <iostream>
#include <iomanip>
using namespace std;

// Function to validate marks
bool isValidMarks(int marks) {
    if (marks < 0 || marks > 100) {
        cout << "Invalid marks. Enter value between 0 and 100.\n";
        return false;
    }
    return true;
}

// Function to input scores (REQUIRED by assignment)
void inputScores(int marks[], int numSubjects) {
    for (int i = 0; i < numSubjects; i++) {
        while (true) {
            cout << "Enter marks for subject " << i + 1 << ": ";
            cin >> marks[i];

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter an integer value.\n";
            }
            else if (!isValidMarks(marks[i])) {
                continue;
            }
            else {
                break;
            }
        }
    }
}

// Function to calculate average marks
float calculateAverage(int marks[], int numSubjects) {
    int sum = 0;
    for (int i = 0; i < numSubjects; i++) {
        sum += marks[i];
    }
    return static_cast<float>(sum) / numSubjects;
}

// Function to determine grade
char determineGrade(float average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

// Function to display results
void displayResult(int marks[], int numSubjects, float average, char grade) {
    cout << "\n--- Student Result ---\n";
    cout << "Marks: ";
    for (int i = 0; i < numSubjects; i++) {
        cout << marks[i] << " ";
    }
    cout << "\nAverage Marks: " << fixed << setprecision(2) << average;
    cout << "\nFinal Grade: " << grade << endl;
}

int main() {
    int numSubjects;

    // Input number of subjects
    do {
        cout << "Enter number of subjects: ";
        cin >> numSubjects;

        if (cin.fail() || numSubjects <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid positive number.\n";
        }
    } while (numSubjects <= 0);

    int* marks = new int[numSubjects];

    inputScores(marks, numSubjects);

    float average = calculateAverage(marks, numSubjects);
    char grade = determineGrade(average);

    displayResult(marks, numSubjects, average, grade);

    delete[] marks;
    return 0;
}
