//
// Created by NandanRaj on 05-02-2026.
//

#include <iostream>
#include "student.h"

// Setter to assign marks with validation
void Student::setMarks(int marks) {
    if (marks < 0 || marks > 100)
        std::cout << "Invalid Marks!" << std::endl;
    else
        this->marks = marks;   // Assign valid marks
}

// Setter to assign name with validation
void Student::setName(std::string name) {
    if (name == "")
        std::cout << "Invalid Name!" << std::endl;
    else
        this->name = name;   // Assign valid name
}

// Setter to assign roll number with validation
void Student::setRollNo(int rollNo) {
    if (rollNo < 0)
        std::cout << "Invalid Roll No!" << std::endl;
    else
        this->rollNo = rollNo;   // Assign valid roll number
}

// Getter to return marks
[[nodiscard]] int Student::getMarks() const {
    return marks;
}

// Getter to return name
[[nodiscard]] std::string Student::getName() const {
    return name;
}

// Getter to return roll number
[[nodiscard]] int Student::getRollNo() const {
    return rollNo;
}

int main() {

    Student s1;   // Create Student object

    // Testing validation logic
    s1.setName("");        // Invalid name
    s1.setName("Nandan");  // Valid name

    s1.setMarks(200);      // Invalid marks
    s1.setMarks(100);      // Valid marks

    s1.setRollNo(-3);      // Invalid roll number
    s1.setRollNo(10);      // Valid roll number

    s1.getName();   // Ignored return value (nodiscard warning possible)

    // Fetch student details
    std::string name = s1.getName();
    int rollNo = s1.getRollNo();
    int marks = s1.getMarks();

    // Display student details
    std::cout << "Name: " << name << std::endl;
    std::cout << "Roll No: " << rollNo << std::endl;
    std::cout << "Marks: " << marks << std::endl;
}
