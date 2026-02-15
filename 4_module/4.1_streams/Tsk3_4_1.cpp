//
// Created by NandanRaj on 13-02-2026.
//
#include <iostream>
#include<fstream>
int main() {
    std::string file_name;
    std::cout<<"Enter the name of your file: ";
    // std::cin>>file_name;
    std::getline(std::cin,file_name);
    file_name+=".txt";
    std::ofstream out(file_name);
    if (!out) {
        std::cerr<<"Unable to open file";
        return 1;
    }
    std::cout<<"Enter content of file: ";
    std::string line;
    // std::cin.ignore();
    std::getline(std::cin,line);
    // or we better use
    // std::getline(std::cin>>std::ws,line);
    out<<line;
    out.close();
    std::ifstream in(file_name);
    if (!in) {
        std::cerr<<"Unable to open file";
        return 1;
    }
    std::cout<<" content of file : ";
    std::string line2;
    while (std::getline(in,line2)) {
        std::cout<<line2<<"\n";
    }
}