//
// Created by NandanRaj on 04-02-2026.
//
#include<iostream>
class LeakDemo {
    public:
    LeakDemo() {
        std::cout<<"obj created"<< std::endl;
    }
    ~LeakDemo() {
        std::cout<<"obj deleted"<< std::endl;
    }
};
int main() {
    for (int i=0;i<1000000

    ;i++) {
        LeakDemo *obj = new LeakDemo();
        delete obj;
    }
    std::cout<<"Loop finished"<< std::endl;
    return 0;

}