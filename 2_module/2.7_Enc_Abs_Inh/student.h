#pragma once
#include <string>

//
// Created by NandanRaj on 05-02-2026.
//

// Student class representing student details
class Student {
    std::string name;   // Stores student name (private for encapsulation)
    int rollNo;         // Stores roll number
    int marks;          // Stores marks (0–100)

public:
    void setName(std::string name);   // Setter for name
    void setRollNo(int rollNo);       // Setter for roll number
    void setMarks(int marks);         // Setter for marks

    [[nodiscard]] std::string getName() const;   // Getter for name
    [[nodiscard]] int getRollNo() const;         // Getter for roll number
    [[nodiscard]] int getMarks() const;          // Getter for marks
};
