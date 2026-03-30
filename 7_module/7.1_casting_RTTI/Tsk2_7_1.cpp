//
// Created by NandanRaj on 25-03-2026.
//
#include<iostream>
#include <typeinfo>
class Shape {
public:
    virtual ~Shape()=default;
    virtual void draw() const {
        std::cout<<"Drawing shape\n";
    }
};
class Circle: public Shape {
public:
    void draw() const override{
        std::cout<<"Drawing circle\n";
    }
    void circleSpecific() const {
        std::cout << "Circle method\n";
    }

};
class Rectangle: public Shape {
public:
    void draw()const override {
        std::cout<<"Drawing rectangle\n";
    }
    void rectangleSpecific() const {
        std::cout << "Rectangle method\n";
    }

};
int main() {
    Shape* ptrS=new Circle();
    std::cout<<"Before Casting-----\n";
    ptrS->draw();

    std::cout<<"\nAfter Casting------\n";
    // downcasting using static_cast
    Circle* ptrC1=static_cast<Circle *>(ptrS);// No check , but as obj is of type Circle so work fine
    if (ptrC1)
    ptrC1->circleSpecific();
    // Bad static_cast
    Shape* ptrS2 = new Rectangle();
    // Circle* ptrR1 = static_cast<Circle*>(s2); // This is UNDEFINED BEHAVIOR if called!

    // downcasting using dynamic_cast
    if(Circle* ptrC2=dynamic_cast<Circle *>(ptrS)) {
        ptrC2->draw();
        std::cout << "dynamic_cast to Circle* succeeded.\n";
    }
    else {
        std::cout << "dynamic_cast to Circle* failed.\n";

    }
    // Benefits of dynamic over static
    Rectangle* ptrR2 = dynamic_cast<Rectangle*>(ptrS); // Fails
    if (ptrR2) {
        ptrR2->rectangleSpecific();
    } else {
        std::cout << "dynamic_cast to Rectangle* failed (nullptr)\n";
    }
    delete ptrS;
    delete ptrS2;
}