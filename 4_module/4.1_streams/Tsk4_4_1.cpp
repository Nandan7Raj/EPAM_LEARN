//
// Created by NandanRaj on 14-02-2026.
//
#include <iostream>
#include<fstream>
int main() {
    std::cout<<"Enter the file name to read : ";
    std::string in_file;
    std::cin>>in_file;
    if (std::cin.fail()) {
        std::cerr<<"Invalid file name\n";
        return 1;
    }
    in_file+=".txt";
    std::ifstream in(in_file);
    if (!in) {
        std::cerr << "Unable to open file to read" << std::endl;
        return 1;
    }
    std::cout<<"Enter the file name where to write : ";
    std::string out_file;
    std::cin>>out_file;
    if (std::cin.fail()) {
        std::cerr<<"Invalid file name\n";
        return 1;
    }
    out_file+=".txt";
    std::ofstream out(out_file);
    if (!out) {
        std::cerr << "Unable to open file to write" << std::endl;
        return 1;
    }
    std::string s;
    int i=0;
    while (std::getline(in,s)) {
        out<<s<<"\n";
        std::cout<<"Line "<<++i<<" copied successfully\n";
    }

}