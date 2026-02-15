//
// Created by NandanRaj on 09-02-2026.
//
#include <iostream>

#include<string>
class Printer {
    public:
    virtual void print(const std::string& msg="Base Printer") const {
        std::cout << msg << std::endl;
        std::cout<<"func body of base"<<std::endl;
    }
};
class ColorPrinter:public Printer {
public:
    void print(const std::string&msg = "Color Printer") const override{
        std::cout << msg << std::endl;
        std::cout<<"func body of derived"<<std::endl;
    }
};

int main(int argc, char *argv[]) {
    ColorPrinter cp;
    cp.print();
    Printer* p=&cp;
    p->print();//the compiler substitutes the default argument from
               //Printer's declaration: "Base Printer", even though
               //the function body called is from ColorPrinter.
    p->print("user parameter");

}
