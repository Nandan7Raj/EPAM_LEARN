//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
#include<string>
void greetMorning(const std::string& name) {
    std::cout<<"Good Morning "<<name<<std::endl;
}
void greetEvening(const std::string& name) {
    std::cout<<"Good Evening "<<name<<std::endl;
}
void invokeCallback(void (*callback)(const std::string&),const std::string & name) {
    callback(name);
}
int main() {
    invokeCallback(greetMorning,"Nandan");
    invokeCallback(greetEvening, "Nandan");
}