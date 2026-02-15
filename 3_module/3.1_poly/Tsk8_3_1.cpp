//
// Created by NandanRaj on 10-02-2026.
//
#include <iostream>
#include <string>
class Messenger {
public:
    void send(const std::string& msg) {
        std::cout << "single argument : ";
        std::cout << msg << std::endl;
    }
    void send(const std::string& msg, const int& priority=1) {
        std::cout << "double argument : ";
        std::cout <<"priority "<<priority<<""<<msg << std::endl;
    }
};
void print(const std::string& msg) {
    std::cout << "bbbbbbbbbbbbbbbbbbb"<<std::endl;
}

int main(int argc, char *argv[]) {
    Messenger messenger;
    print("Hello!");
    std::string msg = "Hello";
    messenger.send(msg);
    messenger.send("Urgent! ", 5);
    messenger.send("Default priority!");//

}
