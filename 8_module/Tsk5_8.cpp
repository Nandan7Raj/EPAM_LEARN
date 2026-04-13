//
// Created by NandanRaj on 02-04-2026.
//
#include <algorithm>
#include<iostream>
#include<vector>
#include<string>
int main() {
    std::vector<std::string> students;
    students.emplace_back("Alice");
    students.emplace_back("Bob");
    students.emplace_back("Charlie");
    students.emplace_back("Diana");
    students.emplace_back("Eve");

    for (auto &s:students)
        std::cout<<s<<" | ";
    std::cout<<"\n";
    auto it=std::ranges::find(students,"Charlie");

    if (it!=students.end()) {
        students.erase(it);
        std::cout<<"List is updated\n";
    }

    it=std::ranges::find(students,"Eve");
    if (it!=students.end()) {
        std::cout<<"Eve is enrolled ? : Yes\n";
    }
    std::ranges::sort(students);

    students.clear();

    std::cout<<"Size of vector after clear: "<<students.size()<<std::endl;
    std::cout<<"Is the vector empty? "<<(students.empty()?"Yes":"No")<<std::endl;




}