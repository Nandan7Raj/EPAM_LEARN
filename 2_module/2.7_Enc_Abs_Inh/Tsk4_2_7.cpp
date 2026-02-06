//
// Created by NandanRaj on 05-02-2026.
//
#include <iostream>
#include<vector>
#include<string>
#include<cmath>
static constexpr double PI = 3.14159265358979323846;
class Shape {
    public:
    virtual double area()=0;
    virtual double perimeter()=0;
    virtual void shape_name()=0;

    virtual ~Shape()= default;
};
class Circle : public Shape {
    double radius;
public:

    Circle(double radius):radius(radius){};
    double area() override {
        return PI * radius * radius;
    };
    double perimeter() override {
        return 2 * PI * radius;
    }
    void shape_name() override {
        std::cout<<"Circle"<<std::endl;
    }
};
class Rectangle : public Shape {
    double width;
    double height;
    public:
    Rectangle(double width, double height):width(width),height(height){};
    double area() override {
        return width * height;
    }
    double perimeter() override {
        return 2 * (width + height);
    }
    void shape_name() override {
        std::cout<<"Rectangle"<<std::endl;
    }
};
class Eql_Triangle : public Shape {
    double side;
    public:
    Eql_Triangle(double side):side(side){};
    double area() override {
        return (sqrt(3)/4) * side;
    }
    double perimeter() override {
        return 3*side;
    }
    void shape_name() override {
        std::cout<<"Eql_Triangle"<<std::endl;
    }
};
int main() {
    std::vector<Shape*> ptr_vec;
    Circle circle(2.2);
    Rectangle rectangle(5, 2);
    Eql_Triangle triangle(4);
    ptr_vec.push_back(&circle);
    ptr_vec.push_back(&rectangle);
    ptr_vec.push_back(&triangle);
    for (auto ptr : ptr_vec) {
        ptr->shape_name();
        std::cout<<"Area: "<<ptr->area()<<std::endl;
        std::cout<<"Perimeter: "<<ptr->perimeter()<<std::endl<<std::endl;
    }

}