//
// Created by NandanRaj on 09-02-2026.
//
#include <iostream>
class Fraction {
    int numerator, denominator;
    public:
    //Default
    Fraction(): numerator(0),denominator(1){};
    //Parametrized
    Fraction(int numerator, int denominator){
        if (denominator==0) {
            throw std::invalid_argument("Denominator is 0");
        }
        this->numerator=numerator;
        this->denominator=denominator;
    }
    bool operator==(const Fraction& frac ) const {
        return numerator*frac.denominator==frac.numerator*denominator;
    }
    bool operator<(const Fraction& frac ) const {
        return numerator*frac.denominator<frac.numerator*denominator;
    }

};
int main() {
    try {
        Fraction f1(1,2);
        // Fraction frac2(2,0);
        Fraction f2(2,4);
        Fraction f3(1,3);

        std::cout<<"Comparing f1 and f2"<<std::endl;
        if (f1==f2)
            std::cout<<"f1 and f2 are equal"<<std::endl;
        else if (f1<f2)
            std::cout<<"f1 is less than f2"<<std::endl;
        else
            std::cout<<"f1 is greater than f2"<<std::endl;

        std::cout<<"\nComparing f1 and f2"<<std::endl;
        if (f1==f3)
            std::cout<<"f1 and f3 are equal"<<std::endl;
        else if (f1<f3)
            std::cout<<"f1 is less than f3"<<std::endl;
        else
            std::cout<<"f1 is greater than f3"<<std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout<<"Error! "<<e.what();
    }

}
