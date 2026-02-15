//
// Created by NandanRaj on 12-02-2026.
//
#include <iostream>
#include <string>
class Logger {
    public:
    virtual void log(const std::string& message) const=0;
    virtual ~Logger() {
        std::cout<<"Logger Destructor"<<std::endl;
    }
};
class FileLogger : public Logger {
    public:
    void log(const std::string& message) const override{
        std::cout<<"File log: "<<message<<std::endl;
    }
    ~FileLogger() override{
        std::cout<<"FileLogger Destructor"<<std::endl;
    }
};

class ConsolLogger : public Logger {
public:
    void log(const std::string& message) const override{
        std::cout<<"Consol log: "<<message<<std::endl;
    }
    ~ConsolLogger() override{
        std::cout<<"ConsolLogger Destructor"<<std::endl;
    }
};
int main() {
    const Logger* logger1=new FileLogger();
    const Logger* logger2=new ConsolLogger();
    logger1->log("logs are in file");
    logger2->log("logs are in Consol");
    delete logger1;
    logger1=nullptr;
    delete logger2;
    logger1=nullptr;
}