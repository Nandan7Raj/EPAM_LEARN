//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
#include<functional>
#include<string>

void invokeCallback(std::function<void(const std::string&)> callback, const std::string& name) {
    callback(name);
}
int main() {
    invokeCallback([](const std::string& n) {
        std::cout<<"Lambda callback says:Welcome, " << n << "!" << std::endl;
    },"Nandan");
}