//
// Created by NandanRaj on 17-02-2026.
//
#include<iostream>
#include<string>
class Student {
    std::string name;
    int marks;
    public:
    Student(std::string name, int marks) : name(name), marks(marks) {};
    friend class Result;
};
class Result {
public:
    void display(const Student& student) {
        std::cout<<"Name: "<<student.name<<std::endl;
        std::cout<<"Marks: "<<student.marks<<std::endl;
        if (student.marks < 30)
            std::cout<<"FAIL!\n";
        else
            std::cout<<"PASS\n";
    }
};
int main() {
    Student s1("Alice",72);
    Student s2("Bob",23);
    Result result;
    result.display(s1);
    result.display(s2);
}