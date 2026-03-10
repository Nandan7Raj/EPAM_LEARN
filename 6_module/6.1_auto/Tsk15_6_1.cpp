//
// Created by NandanRaj on 05-03-2026.
//
#include<iostream>
#include<vector>
#include<initializer_list>
class Matrix {
    std::vector<std::vector<int>> data;
public:
    Matrix(std::initializer_list<std::initializer_list<int>> list){
        for (const auto& row:list) {
            data.emplace_back(row);
        }
    }
    void printAndDouble() {
        std::cout<<"Matrix element:"<<std::endl;
        for (auto& row:data) {
            for (auto& col:row) {
                std::cout<<col<<" ";
                col*=2;// doubling the elm(in-place)
            }
            std::cout << std::endl;
        }
    }
    void print() const {
        std::cout << "Matrix elements:" << std::endl;
        for (const auto& row : data) {
            for (const auto& col : row) {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    Matrix mat{{2,3},{4,5}};
    mat.printAndDouble();
    std::cout << "After doubling:" << std::endl;
    mat.print();


}