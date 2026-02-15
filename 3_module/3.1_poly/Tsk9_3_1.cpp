//
// Created by NandanRaj on 10-02-2026.
//
#include <iostream>
class BaseLogger {
public:
    BaseLogger() {
        std::cout<<"BaseLogger obj created"<<std::endl;
    }
    virtual ~BaseLogger() {
        std::cout<<"BaseLogger obj destroyed"<<std::endl;
    }
};
class FileLogger : public BaseLogger {
    public:
    FileLogger() {
        std::cout<<"FileLogger obj created"<<std::endl;
    }
    ~FileLogger() override  {
        std::cout<<"FileLogger obj destroyed"<<std::endl;
    }
};
class ConsoleLogger : public BaseLogger {
    public:
    ConsoleLogger() {
        std::cout<<"ConsoleLogger obj created"<<std::endl;
    }
    ~ConsoleLogger() override  {
        std::cout<<"ConsoleLogger obj destroyed"<<std::endl;
    }
};

int main(int argc, char *argv[]) {
    const BaseLogger* base_ptr1=new FileLogger();
    const BaseLogger* base_ptr2=new ConsoleLogger();

    std::cout<<"Now Deletion------------------------\n";
    delete base_ptr1;
    base_ptr1=nullptr;
    delete base_ptr2;
    base_ptr1=nullptr;
}

