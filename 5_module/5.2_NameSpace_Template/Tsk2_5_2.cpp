//
// Created by NandanRaj on 03-03-2026.
//
#include<iostream>
#include<iostream>
namespace Geometry {
    struct Point {
        int x,y;
    };
    void printPoint(const Point& pt ) {
        std::cout << "(" << pt.x << ", " << pt.y << ")"<<std::endl;
    }
}
namespace G=Geometry;
int main() {
    G::Point p{3,5};
    G::printPoint(p);
    return 0;
}