//
// Created by NandanRaj on 09-02-2026.
//
#include<iostream>
class Complex {
    double real;
    double imag;
public:
    Complex(double real, double imag):real(real),imag(imag) {
        std::cout<<"value initialized"<<std::endl;
    }
    Complex operator+(const Complex& other) {
        return Complex(real+other.real,imag+other.imag);

    }
    friend std::ostream& operator<<(std::ostream& os, const Complex& com);
};
std::ostream& operator<<(std::ostream& os, const Complex& com) {
    os<<com.real<<" + "<<com.imag<<"i";
    return os;
}
int main() {
    Complex com1(2,3.3),com2(0,1);
    std::cout<<"First Complex value is "<<com1<<std::endl;
    // std::cout<<com1<<std::endl;
    std::cout<<"Second Complex value is "<<com2<<std::endl;
    Complex com3=com1+com2;

    std::cout<<"Sum of two complex numbers "<<com3<<std::endl;
}
