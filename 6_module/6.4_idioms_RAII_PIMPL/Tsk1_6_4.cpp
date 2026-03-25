//
// Created by NandanRaj on 18-03-2026.
//
#include<iostream>
#include<fstream>
class FileWrapper {
    std::ofstream out;
public:
    FileWrapper(const std::string& name):out(name+".txt") {
        if (!out) throw std::runtime_error("Failed to open the file");
        std::cout<<"File: "<<name<<" is open\n";
    }
    void write(const std::string& content) {
        out<<content;
        std::cout<<" WRITE SUCCESFULL\n";
    }
    ~FileWrapper() {
        if (out.is_open()) {
            out.close();
            std::cout << "File closed automatically.\n";
        }
    }
};
int main() {
    try {
        FileWrapper file("Tsk1");
        file.write("This is Task 1 of module 6.4\n");
        // throw std::runtime_error("Simulated crash!");// to check closing even in case of exception
        file.write("In this Task we are implementing RAII\n");


    }
    catch (const std::exception& e) {
        std::cerr<<"Exception: "<<e.what()<<std::endl;
    }
    std::cout<<"Now out of try catch block so FileWrapper is out of scope now\n";

}