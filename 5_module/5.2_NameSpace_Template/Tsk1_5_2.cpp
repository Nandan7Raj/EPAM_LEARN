//
// Created by NandanRaj on 03-03-2026.
//
#include<iostream>
namespace Geometry {
    struct Point {
        int x,y;
    };
    void printPoint(const Point& pt ) {
        std::cout << "(" << pt.x << ", " << pt.y << ")"<<std::endl;
    }
}
int main() {
    Geometry::Point p{3,5};
    Geometry::printPoint(p);
    return 0;
}