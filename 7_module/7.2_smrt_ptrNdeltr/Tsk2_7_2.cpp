//
// Created by NandanRaj on 29-03-2026.
//
#include<iostream>
#include<string>
#include<chrono>
#include<memory>

class Logger {
    std::string name;
    bool isActive=true;
public:
    Logger(std::string name):name(std::move(name)) {
      std::cout << "Logger '" << this->name << "' created.\n";
    }
    void log(const std::string& msg) const {
        if (!isActive) return;
        std::cout << "[" << name << "]: " << msg << "\n";

    }
    void close() {
        if (isActive) {  // Only close if open
            isActive = false;
            std::cout << "Logger '" << name << "' closing.\n";
        }

    }

    ~Logger() {
        close();
        std::cout << "Logger '" << name << "' destroyed.\n";

    }
    std::string getName() const{
        return name;
    }
};
int main() {
    std::unique_ptr<Logger> logger= std::make_unique<Logger>("FirstLogger");
    logger->log("Msg from First Logger");

    //Reset with New Object
    logger=std::make_unique<Logger>("SecondLogger");
    logger->log("Msg from Second Logger");

    logger.reset(new Logger("TemporaryLogger"));
    logger->log("I replaced the previous logger");

    //Reset to Null
    logger.reset();
    std::cout << "Logger is now " << (logger ? "not null" : "nullptr") << "\n";

    logger=nullptr;

    logger=std::make_unique<Logger>("NewLogger");
    logger->log("Refreshed logger");

    //Move Semantics: Create a second pointer and move its ownership to the first
    std::unique_ptr<Logger> logger2=std::make_unique<Logger>("logger2");
    logger=std::move(logger2);
    logger->log("Now I own Logger2's resource");
    std::cout << "logger2 is " << (logger2 ? "not null" : "nullptr") << "\n";

    //Self-Move: Attempt to move the pointer to itself
    logger=std::move(logger);//self-assignment , will not destroy as in move assignment this!=&other will be not satisfied
    logger->log("Self-move didn't destroy me!");

}