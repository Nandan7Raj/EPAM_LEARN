//
// Created by NandanRaj on 22-02-2026.
//
#include<iostream>
class LogSession {
    int ID;
public:
    LogSession(int ID):ID(ID) {
        std::cout<<"Session "<<ID<<" Started\n";
    }
    ~LogSession() {
        std::cout<<"Session "<<ID<<" Ended\n";
    }
};
void performDataValidation(const int& data) {
    LogSession s3(3);
    std::cout<<"[Session 3] Checking Data....\n";
    if (data<0)
        throw "Invalid Data";
    std::cout<<"[Session 3] Data Validated successfully.\n";
}
void processTransaction() {
    LogSession s2(2);
    //calling performDataValidation() with various data values
    performDataValidation(-2);
    performDataValidation(5);
    std::cout<<"[LogSession 2] transaction processed.\n";
}
void startCriticalOperation() {
    LogSession s1(1);
    processTransaction();
    std::cout<<"[LogSession] critical operation compilested.\n";
}

int main(int argc, char *argv[]) {
    std::cout<<"Starting main block.\n";
    try {
        startCriticalOperation();
    }
    catch (const char*msg) {
        std::cout<<"Inside the main Catch handler: "<<msg<<"\n";
    }
    return 0;
}
