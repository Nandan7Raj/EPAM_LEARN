//
// Created by NandanRaj on 16-02-2026.
//
#include <iostream>
#include <fstream>
#include <limits>
static void print_state(const std::istream& in) {
    std::cout<<"[State :";
    if (in.good())std::cout<<"good";
    if (in.fail())std::cout<<"fail";
    if (in.bad())std::cout<<"bad";
    if (in.fail())std::cout<<"fail";
    std::cout<<"]";
}
int main () {
    std::string filename;
    std::cout<<"Enter the name of the file to be processed: ";
    std::getline(std::cin,filename);
    std::cout<<"aa"<< std::endl;
    std::ifstream in(filename+".txt");
    if (!in) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }
    int value;
    while (true) {
        if (in>>value) {
            std::cout<<value<<"\n";
            print_state(in);
            continue;
        }
        if (in.eof()) {
            std::cout<<"\nEnd of file reached ";
            print_state(in);
            break;
        }
        if (in.bad()) {
            std::cerr<<"\nsomthing very bad happened";
            print_state(in);
            return 1;
        }
        if (in.fail()) {
            print_state(in);
            in.clear();
            in.ignore();
            continue;
        }
    }
    in.close();
}
