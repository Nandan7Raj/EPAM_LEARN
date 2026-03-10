//
// Created by NandanRaj on 10-03-2026.
//
#include <functional>
#include<iostream>
#include<string>

void greet(const std::string &name) {
  std::cout<<"Hello "<<name<<std::endl;
}

void invokeCallback(void(*callback)(const std::string&),const std::string& name) {
  callback(name);
}
// now with std::function
void invokeCallback2(std::function<void(const std::string&)> callback,const std::string& name) {
  callback(name);
}
int main() {
  invokeCallback(greet,"Nandan");
  invokeCallback2(greet,"Raj");

}