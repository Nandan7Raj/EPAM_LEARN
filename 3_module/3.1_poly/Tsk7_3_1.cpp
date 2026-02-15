//
// Created by NandanRaj on 10-02-2026.
//
#include <iostream>
#include <stdexcept>
#include <string>

class SquareMatrix; // forward declare

class Matrix {
protected:
    double* mat;
    int row, col;

    int idx(int r, int c) const { return r * col + c; }

public:
    Matrix(int row, int col) : row(row), col(col), mat(new double[row * col]{0.0}) {
        std::cout << "Matrix created\n";
    }

    virtual ~Matrix() {
        delete[] mat;
        std::cout << "Matrix deleted\n";
    }

    virtual void display() const = 0;

    void setValue(int r, int c, int val) {
        if (r < 0 || r >= row || c < 0 || c >= col) throw std::out_of_range("row/col out of range");
        mat[idx(r, c)] = static_cast<double>(val);
    }

    void setValue(double r_d, double c_d, double val) {
        int r = static_cast<int>(r_d);
        int c = static_cast<int>(c_d);
        if (r < 0 || r >= row || c < 0 || c >= col) throw std::out_of_range("row/col out of range");
        mat[idx(r, c)] = val;
    }

    double getValue(int r, int c) const {
        if (r < 0 || r >= row || c < 0 || c >= col) throw std::out_of_range("row/col out of range");
        return mat[idx(r, c)];
    }

    // return a concrete matrix (square here to keep it short) as can't have obj of Matrix(Abstract class)
    SquareMatrix operator+(const Matrix& m2) const;
};

class SquareMatrix : public Matrix {
public:
    SquareMatrix(int n) : Matrix(n, n) {}

    void display() const override {
        std::cout << "[SquareMatrix " << row << "x" << col << "]\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                std::cout << getValue(i, j) << " ";
            std::cout << "\n";
        }
    }
};

class IdentityMatrix : public SquareMatrix {
public:
    IdentityMatrix(int n) : SquareMatrix(n) {
        for (int i = 0; i < n; i++) setValue(i, i, 1);
    }

    void display() const override {
        std::cout << "[IdentityMatrix " << row << "x" << col << "]\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                std::cout << (i == j ? 1 : 0) << " ";
            std::cout << "\n";
        }
    }
};

// define after SquareMatrix exists
SquareMatrix Matrix::operator+(const Matrix& m2) const {
    if (row != m2.row || col != m2.col) throw std::invalid_argument("dimension mismatch while adding");
    if (row != col) throw std::invalid_argument("this demo returns SquareMatrix, so must be square");

    SquareMatrix res(row);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res.setValue(1.0*i, 1.0*j, getValue(i, j) + m2.getValue(i, j));
    return res;
}

int main() {
    SquareMatrix A(2), B(2);

    // compile-time polymorphism (overload)
    A.setValue(0, 0, 5);          // int,int,int
    A.setValue(0.0, 1.0, 2.5);    // double,double,double

    B.setValue(0, 0, 3);
    B.setValue(1, 1, 4);

    // compile-time polymorphism (operator overloading)
    SquareMatrix C = A + B;

    IdentityMatrix I(2);

    // run-time polymorphism (virtual dispatch)
    Matrix* arr[] = { &A, &I, &C };
    for (auto* m : arr) {
        m->display();
        std::cout << "----\n";
    }
}
