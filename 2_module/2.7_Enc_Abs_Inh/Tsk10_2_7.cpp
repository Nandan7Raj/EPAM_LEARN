//
// Created by NandanRaj on 06-02-2026.
//
#include <iostream>
static constexpr double PI = 3.14159265358979323846;
class Shape {
    public:
    virtual void draw()=0;
    virtual void area()=0;
    virtual void perimeter()=0;
    ~Shape(){};
};
class Circle: public Shape {
    int radius;
    public:
    Circle(int radius):radius(radius){};
    void draw() {
        std::cout << "Circle draw" << std::endl;
    }
    void area() {
        double area=PI*radius*radius;
        std::cout << "Circle area: " << area<<" CM^2"<<std::endl;
    }
    void perimeter() {
        double peri=PI*2*radius;
        std::cout << "Perimeter of Circle :" << peri<<" CM"<<std::endl;
    }
};
class Square: public Shape {
    double side;
    public:
    Square(double side):side(side){};
    void draw() {
        std::cout << "Square draw" << std::endl;
    }
    void area() {
        double area=side*side;
        std::cout << "Square area :" << area<<" CM^2"<<std::endl;
    }
    void perimeter() {
        double peri=side*4;
        std::cout << "Perimeter of Square :" << peri<<" CM"<<std::endl;
    }
};
class Rectangle: public Shape {
    double height;
    double  width;
    public:
    Rectangle(double height, double width):height(height),width(width){};
    void draw() {
        std::cout << "Rectangle draw" << std::endl;
    }
    void area() {
        double area=width*height;
        std::cout << "Rectangle area :" << area<< " CM^2"<<std::endl;
    }
    void perimeter() {
        double peri=2*(width+height);
        std::cout << "Rectangle perimeter :" <<peri<<" CM"<< std::endl;
    }
};
int main() {
    Circle circle(2);
    Square square(2);
    Rectangle rectangle(5,4);
    square.draw();
    square.area();
    square.perimeter();
    rectangle.draw();
    rectangle.area();
    rectangle.perimeter();
    circle.draw();
    circle.area();
    circle.perimeter();

}