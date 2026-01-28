//
// Created by NandanRaj on 25-01-2026.
//
#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

/* ---------- Utility Validation Functions ---------- */
bool isValidDimension(int rows, int cols)
{
    return rows > 0 && cols > 0 && rows <= MAX && cols <= MAX;
}

bool validateInput()
{
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

/* ---------- Input & Output Functions ---------- */
void inputMatrix(int rows, int cols, int matrix[][MAX], const string& name)
{
    cout << "Enter elements for " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
            if (!validateInput()) {
                cout << "Invalid input detected.\n";
                return;
            }
        }
    }
}

void printMatrix(int rows, int cols, int matrix[][MAX])
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/* ---------- Matrix Operations ---------- */
void addMatrices(int rows, int cols,
                 int mat1[][MAX], int mat2[][MAX], int result[][MAX])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = mat1[i][j] + mat2[i][j];
}

void subtractMatrices(int rows, int cols,
                      int mat1[][MAX], int mat2[][MAX], int result[][MAX])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = mat1[i][j] - mat2[i][j];
}

void multiplyMatrices(int r1, int c1, int r2, int c2,
                      int mat1[][MAX], int mat2[][MAX], int result[][MAX])
{
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int rows, int cols,
                     int matrix[][MAX], int result[][MAX])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = matrix[i][j];
}

/* ---------- Main Function ---------- */
int main()
{
    int choice;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];

    cout << "Matrix Operations Menu\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Transpose\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (!validateInput()) {
        cout << "Invalid menu choice.\n";
        return 0;
    }

    switch (choice)
    {
        case 1: {
            int rows, cols;
            cout << "Enter rows and columns: ";
            cin >> rows >> cols;

            if (!isValidDimension(rows, cols)) {
                cout << "Invalid matrix dimensions.\n";
                break;
            }

            inputMatrix(rows, cols, mat1, "Matrix A");
            inputMatrix(rows, cols, mat2, "Matrix B");

            addMatrices(rows, cols, mat1, mat2, result);

            cout << "Result (Addition):\n";
            printMatrix(rows, cols, result);
            break;
        }

        case 2: {
            int rows, cols;
            cout << "Enter rows and columns: ";
            cin >> rows >> cols;

            if (!isValidDimension(rows, cols)) {
                cout << "Invalid matrix dimensions.\n";
                break;
            }

            inputMatrix(rows, cols, mat1, "Matrix A");
            inputMatrix(rows, cols, mat2, "Matrix B");

            subtractMatrices(rows, cols, mat1, mat2, result);

            cout << "Result (Subtraction):\n";
            printMatrix(rows, cols, result);
            break;
        }

        case 3: {
            int r1, c1, r2, c2;
            cout << "Enter rows and columns of first matrix: ";
            cin >> r1 >> c1;
            cout << "Enter rows and columns of second matrix: ";
            cin >> r2 >> c2;

            if (!isValidDimension(r1, c1) || !isValidDimension(r2, c2) || c1 != r2) {
                cout << "Invalid dimensions for multiplication.\n";
                break;
            }

            inputMatrix(r1, c1, mat1, "Matrix A");
            inputMatrix(r2, c2, mat2, "Matrix B");

            multiplyMatrices(r1, c1, r2, c2, mat1, mat2, result);

            cout << "Result (Multiplication):\n";
            printMatrix(r1, c2, result);
            break;
        }

        case 4: {
            int rows, cols;
            cout << "Enter rows and columns: ";
            cin >> rows >> cols;

            if (!isValidDimension(rows, cols)) {
                cout << "Invalid matrix dimensions.\n";
                break;
            }

            inputMatrix(rows, cols, mat1, "Matrix");

            transposeMatrix(rows, cols, mat1, result);

            cout << "Result (Transpose):\n";
            printMatrix(cols, rows, result);
            break;
        }

        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}
