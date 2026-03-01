//
// Created by NandanRaj on 19-02-2026.
//
#include<iostream>
#include <limits>
#include<stdexcept>
double divide(int numerator, int denominator) {
    if (denominator == 0)
        throw std::runtime_error("Division by zero cannot be performed.");
    return  1.0*numerator/denominator;
}
int main() {
    int numerator,denominator;
    std::cout<<"Enter numerator and denominator: ";
    std::cin>>numerator;
    if (std::cin.fail()) {
        std::cerr<<"Invalid input!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        return 1;
    }
    std::cin>>denominator;
    if (std::cin.fail()) {
        std::cerr<<"Invalid input!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        return 1;
    }
    try {
        std::cout<<"Result of Division: "<<divide(numerator,denominator)<<std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr<<e.what()<<std::endl;
    }

}