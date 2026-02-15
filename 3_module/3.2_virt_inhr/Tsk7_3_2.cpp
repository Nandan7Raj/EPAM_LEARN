//
// Created by NandanRaj on 12-02-2026.
//
#include <iostream>
#include <string>
class Person {
    protected:
    std::string name;
    int age;
    public:
    Person( std::string name, int age):name(std::move(name)),age(age){
        std::cout<<"Person obj created"<<std::endl;
    }
    virtual void displayInfo() const=0;
    virtual ~Person()=default;

};
class Student : virtual public Person {
    protected:
    int rollNo;
    public:
    Student(const std::string& name,int age,int rollNo):Person(name,age),rollNo(rollNo) {
        std::cout<<"Student obj created"<<std::endl;
    }
    void displayInfo() const override {
        std::cout<<"\nInfo. of Student"<<std::endl;
        std::cout<<"Name: "<<name<<std::endl;
        std::cout<<"Age: "<<age<<std::endl;
        std::cout<<"Roll No: "<<rollNo<<std::endl;
    }

};
class Employee : virtual public Person {
    protected:
    double salary;
    public:
    Employee(const std::string& name,int age,double salary):Person(name,age),salary(salary) {
        std::cout<<"Employee obj created"<<std::endl;
    }
    void displayInfo() const override {
        std::cout<<"\nInfo. of Employee"<<std::endl;
        std::cout<<"Name: "<<name<<std::endl;
        std::cout<<"Age: "<<age<<std::endl;
        std::cout<<"Salary: "<<salary<<std::endl;
    }
};
class TeachingAssistant : public Student, public Employee {
    public:
    TeachingAssistant(const std::string& s,const int age,const double salary,const int rollNo):Person(s,age),
    Student(s,age,rollNo),Employee(s,age,salary) {
        std::cout<<"TeachingAssistant obj created"<<std::endl;
    }
    void displayInfo() const override {
        std::cout<<"\nInfo. of TeachingAssistant"<<std::endl;
        std::cout<<"Name: "<<name<<std::endl;
        std::cout<<"Age: "<<age<<std::endl;
        std::cout<<"Roll No: "<<rollNo<<std::endl;
        std::cout<<"Salary: "<<salary<<std::endl;
    }

};
int main() {
    std::string name="Nandan";
    TeachingAssistant ta(name,23,30000,68);
    ta.displayInfo();
    ta.Employee::displayInfo();
    ta.Student::displayInfo();

    std::cout<<"\naddress of the underlying Person subobject via both base paths:"<<std::endl;
    std::cout << static_cast<Person *>(static_cast<Student *>(&ta)) <<std::endl;
    std::cout << static_cast<Person *>(static_cast<Employee *>(&ta)) <<std::endl;
    std::cout<<"see both are same"<<std::endl;



}