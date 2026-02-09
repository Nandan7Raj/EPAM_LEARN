//
// Created by NandanRaj on 06-02-2026.
//
#include<iostream>
#include<string>
class Person {
protected:
    std::string name;
    int age;
    public:
    void setName(std::string name) {
        this->name=name;
    }
    void setAge(int age) {
        this->age=age;
    }
    std::string getName() {
        return this->name;
    }
    int getAge() {
        return this->age;
    }
};
class Student :public Person {
    int rollNo;
    char grade;
    public:
    void setRollNo(int rollNo) {
        this->rollNo=rollNo;
    }
    void setGrade(char grade) {
        this->grade=grade;
    }
    int getRollNo() {
        return this->rollNo;
    }
    char getGrade() {
        return this->grade;
    }
};
class Teacher:public Person {
    std::string subject;
    double salary;
public:
    void setSubject(std::string subject) {
        this->subject=subject;
    }
    void setSalary(double salary) {
        this->salary=salary;
    }
    std::string getSubject() {
        return this->subject;
    }
    double getSalary() {
        return this->salary;
    }
};
int main() {
    Student s;
    s.setName("Nandan");
    s.setAge(20);
    s.setRollNo(10);
    s.setGrade('A');
    std::cout<<"Data of Student."<< std::endl;
    std::cout<<"Name: "<<s.getName()<<std::endl;
    std::cout<<"Age: "<<s.getAge()<<std::endl;
    std::cout<<"Roll No: "<<s.getRollNo()<<std::endl;
    std::cout<<"Grade: "<<s.getGrade()<<std::endl;
    std::cout<<std::endl;
    Teacher t;
    t.setName("Santosh Narendra");
    t.setAge(20);
    t.setSubject("C++");
    t.setSalary(200000);
    std::cout<<"Data of Teacher."<< std::endl;
    std::cout<<"Name: "<<t.getName()<<std::endl;
    std::cout<<"Age: "<<t.getAge()<<std::endl;
    std::cout<<"Subject: "<<t.getSubject()<<std::endl;
    std::cout<<"Salary: "<<t.getSalary()<<std::endl;

}