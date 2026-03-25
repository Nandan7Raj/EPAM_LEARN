//
// Created by NandanRaj on 18-03-2026.
//
#include<iostream>
#include<memory>
#include<string>
#include<utility>
class Widget {
    std::string s;
public:
    Widget(std::string s):s(std::move(s)) {
        std::cout<<"Constructor for "<<this->s<<"\n";
    }
    ~Widget() {
        std::cout<<"Destructor for "<<s<<"\n";
    }
};
auto makeUniquePtr() {
    std::unique_ptr<Widget> smrtPtr=std::make_unique<Widget>("smart allocation(RAII)");
    return smrtPtr;
}
int main() {
    std::cout << "===== Smart pointer (unique_ptr) example ====\n";
    {
        auto widgetPtr = makeUniquePtr();
    }// smart ptr goes out of scope

    std::cout << "\n==== Manual new/delete (anti-pattern) ====\n";
    {
        Widget* w = new Widget("Manual allocation");
        delete w; // forget this line and you have a leak!
    }
    std::cout<<"END OF MAIN\n";

}