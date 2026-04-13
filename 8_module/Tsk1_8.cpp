//
// Created by NandanRaj on 01-04-2026.
//
#include <iostream>
#include<vector>
#include <algorithm>
int main() {
    std::vector<int> v;
    if (v.empty())
        std::cout<<"Vector is empty: true\n";
    // adding grades
    v.push_back(80);
    v.push_back(90);
    v.push_back(70);
    v.push_back(86);
    v.push_back(94);
    v.push_back(75);

    for (auto &x:v) {
        std::cout<<x<<" ";
    }
    // std::ranges::for_each(v,[](int x) {
    //     std::cout<<x<<" ";
    // });
    std::cout<<"\nSize of vector: "<<v.size()<<std::endl;

    std::cout<<"First Grade: "<<v.front()<<std::endl;
    std::cout<<"Back Grade: "<<v.back()<<std::endl;

    std::cout<<"grade at index 2 using operator[]: "<<v[2]<<std::endl;
    std::cout<<"grade at index 2 using at() : "<<v.at(2)<<std::endl;

    v[2]=93;
    std::cout<<"grade at index 2 after modification: "<<v[2]<<std::endl;


    try {
        std::cout << v.at(10);
    } catch (std::out_of_range& e) {
        std::cout << "Index out of range!\n";
    }

    v.insert(v.begin(),100);
    v.insert(v.end()-2,75);

    std::ranges::for_each(v,[](const int x) {
        std::cout<<x<<" ";
    });
    std::cout<<"\nNew size of vec: "<<v.size()<<std::endl;

    //Remove the last grade using pop_back().
    v.pop_back();
    // removing grade at specific index
    v.erase(v.begin()+1);

    std::ranges::for_each(v,[](const int x) {
        std::cout<<x<<" ";
    });
    std::cout<<"\nNew size of vec: "<<v.size()<<std::endl;

    // clearing vector
    v.clear();

    std::cout<<((v.empty())?"vector is empty":"vector is not empty")<<std::endl;





}
