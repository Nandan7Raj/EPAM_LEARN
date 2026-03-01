//
// Created by NandanRaj on 17-02-2026.
//
#include<iostream>
#include<cmath>
class Circle;
class Rectangle {
    double width, length;
    public:
    Rectangle(const double &width, const double& length):width(width),length(length){};
    friend double compareArea(const Circle& circle, const Rectangle& rectangle);
};
class Circle {
    double radius;
    public:
    explicit Circle(const double &radius):radius(radius){};
    friend double compareArea(const Circle& circle, const Rectangle& rectangle);
};
double compareArea(const Circle& circle, const Rectangle& rectangle) {
    double circle_area=M_PI*(circle.radius)*circle.radius;
    double rectangle_area=rectangle.length*rectangle.width;
return circle_area>=rectangle_area?circle_area:rectangle_area;
}

int main(int argc, char *argv[]) {
    Circle circle(2);
    Rectangle rectangle(3.0, 4.0);
    double area=compareArea(circle, rectangle);
    std::cout<<"Greater area: "<<area<< std::endl;
}
