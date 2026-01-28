//
// Created by NandanRaj on 28-01-2026.
//
#include<iostream>
using namespace std;
class Student {
    private:
    int roll_no;
    string name;
    char grade;
    public:
    //default constructor
    Student() {
        //setting default value
        roll_no = 0;
        name="Nandan";
        grade='A';
        cout<<"Default constructor called\n";
    }
    //Parametrized constructor
    Student(int roll_no, string name, char grade):roll_no(roll_no),name(name),grade(grade) {
        cout<<"Parametrized Constructor called\n";
    }
    void displayData() {

        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<roll_no<<endl;
        cout<<"Grade: "<<grade<<endl<<endl;

    }
};
int main() {
    Student stu1;//this obj will be created using default constructor
    Student stu2(1,"Rahul Raj",'B');// this obj will be created using parametrized constructor
    stu1.displayData();// will display default data
    stu2.displayData();
}