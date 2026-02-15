//
// Created by NandanRaj on 13-02-2026.
//
#include <iostream>
#include <vector>
using namespace std;

class Box {

    int w;
public:
    Box(int w) : w(w) {}

    // friend declaration needed if w is private
    friend ostream& operator<<(ostream& os, const Box& b);

    Box operator+(const Box& b) {

       Box c{w + b.w};
        return c;
    }

};

ostream& operator<<(ostream& os, const Box& b) {
    os << "Box(w=" << b.w << ")";
    return os;
}

int main() {
    Box b1(7);
    Box b2(3);
    Box b3=b1+b2;
    cout<<b3;
}
