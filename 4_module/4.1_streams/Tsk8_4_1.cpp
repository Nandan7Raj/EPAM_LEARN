//
// Created by NandanRaj on 16-02-2026.
//
#include<iostream>
#include<string>
class Person {
    std::string name;
    int age;
    public:
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
    friend std::istream& operator>>(std::istream& in, Person& person);
};
std::ostream& operator<<(std::ostream& out, const Person& person) {
    out<<"Name: "<<person.name<<", Age: "<<person.age<<"\n";
    return out;
}
std::istream& operator>>(std::istream& in,Person& person) {
    std::cout << "Input name: ";
    std::getline(in>>std::ws,person.name);
    std::cout << "Input age: ";
    in>>person.age;
    in.ignore();
    return in;
}
int main() {
    Person p1,p2,p3;
    std::cin >> p1 >> p2>>p3;
    std::cout<<p1<<p2<<p3<<std::endl;
}