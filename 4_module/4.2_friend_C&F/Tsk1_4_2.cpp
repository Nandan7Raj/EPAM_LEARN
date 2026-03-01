//
// Created by NandanRaj on 17-02-2026.
//
#include <iostream>
class Box {
    double length,width,height;
    public:
    Box(const double& length, const  double& width, const double& height):
    length(length), width(width), height(height){};
    friend double volume(const Box& box);
};
double volume(const Box& box) {
    double vol=box.length * box.width* box.height;
    return vol;
}
int main() {
    Box box(3.0, 4.0, 5.0);
    std::cout << "Volume: "<<volume(box) << std::endl;

}