//
// Created by NandanRaj on 09-02-2026.
//
#include <iostream>
#include <string>
#include <vector>

class Employee {
    std::string name;
    int id;
    public:
    Employee():name("unnamed") ,id(0) {
        std::cout<<"Employee constructor"<<std::endl;
    }
    void set_name(const std::string&name) {
        if (name.empty())
            std::cout<<"Invalid name(Empty)"<<std::endl;
        else
            this->name=name;
    }
    void set_id(const int& id) {
        if (id<=0)
            std::cout<<"Invalid id(ZERO or NEGATIVE)"<<std::endl;
        else
            this->id=id;
    }
    std::string get_name() const {
        return name;
    }
    int get_id() const {
        return id;
    }
    virtual double calculatePay() const=0;
    virtual void display() const =0;
    virtual ~Employee() =default;
};
class SalariedEmployee: public Employee {
    double salary;
    public:
    SalariedEmployee():salary(0) {
        std::cout<<"SalariedEmployee constructor"<<std::endl;
    }
    void set_salary(const double& salary) {
        if (salary<=0)
            std::cout<<"Invalid salary(NEGATIVE)"<<std::endl;
        else
            this->salary=salary;
    }
    double calculatePay() const {
        return salary;
    }
    void display() const {
        std::cout<<"SalariedEmployee"<<std::endl;
        std::cout<<"Name: "<<get_name()<<", ID: "<<get_id()
        <<", Salary: "<<salary<<std::endl;

    }
};
class HourlyEmployee: public Employee {
    double hourlyRate;
    double hourlyWorked;
    public:
    HourlyEmployee():hourlyRate(0) ,hourlyWorked(0) {
        std::cout<<"HourlyEmployee constructor"<<std::endl;
    }
    void set_hourlyRate(const double& hourlyRate) {
        if (hourlyRate<0)
            std::cout<<"Invalid hourly Rate(Negative)"<<std::endl;
        else
            this->hourlyRate=hourlyRate;
    }
    void set_hourlyWorked(const double& hourlyWorked) {
        if (hourlyWorked<0)
            std::cout<<"Invalid hourly Worked(Negative)"<<std::endl;
        else {
            this->hourlyWorked=hourlyWorked;
            this->hourlyRate=hourlyRate;
        }
    }
    double calculatePay() const override {
        return hourlyRate*hourlyWorked;
    }
    void display() const override {
        std::cout<<"HourlyEmployee"<<std::endl;
        std::cout<<"Name: "<<get_name()<<", ID: "<<get_id()
        <<", Salary: "<<calculatePay()<<std::endl;
    }
};
int main() {
    SalariedEmployee se;
    HourlyEmployee he;

    std::vector<Employee*>  employees;
    employees.push_back(&se);
    employees.push_back(&he);
    //default values
    for (const Employee* employee: employees) {
        std::cout<<"Employee pay "<<employee->calculatePay()<<std::endl;
        employee->display();
        std::cout<<std::endl;
    }

    se.set_name("");//invalid name
    se.set_name("Nandan");//valid Name
    se.set_id(-2);//invalid id
    se.set_id(1);//valid id
    se.set_salary(-1);// invalid salary
    se.set_salary(70000);

    he.set_name("Raj");
    he.set_id(2);
    he.set_hourlyRate(-1);//invalid
    he.set_hourlyWorked(-1);//invalid
    he.set_hourlyRate(800);//invalid
    he.set_hourlyWorked(160);//invalid

    // now values after initializing
    std::cout<<"\nEmployee Info"<<std::endl;
    for (const Employee* employee: employees) {
        std::cout<<"Employee pay "<<employee->calculatePay()<<std::endl;
        employee->display();
        std::cout<<std::endl;
    }
}