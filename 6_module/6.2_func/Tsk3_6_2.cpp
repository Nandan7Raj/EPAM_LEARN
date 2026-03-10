//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
#include<string>
#include<functional>
void greet(const std::string& name) {
    std::cout<<"hello "<<name<<std::endl;
}
void invokeCallback(std::function<void(const std::string&)> callback,const std::string& name) {
    callback(name);
}
int main() {
    invokeCallback(greet,"Nandan");
    // pass a lambda as  callback
    std::string greeting = "Hello";
    invokeCallback([&greeting](const std::string& name) {
        std::cout<<"lambda says "<<greeting<<" to "<<name<<std::endl;
    },"Nandan");
}
