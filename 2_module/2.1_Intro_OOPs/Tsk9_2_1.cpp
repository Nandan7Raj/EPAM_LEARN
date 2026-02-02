//
// Created by NandanRaj on 29-01-2026.
//
#include<iostream>
using namespace std;
// Logger class with mutable member
class Logger {
    // mutable member to allow modification in const method
    mutable int accessCount=0;
    string message;
public:
    // Constructor
    Logger(const string &message) {
        this->message = message;
    }
    // Const method to print message and access count
    void print_accessCount() const{
        //printing cur accesscount
        cout << "accessCount : " <<accessCount<< endl;
    }
    // Const method to print message
    void print() const {
        ++accessCount;// count incremented;
        cout<<message<<endl;
        this->print_accessCount();// calling const method

    }
};
int main() {
    Logger log("hey! Nandan");
    // Calling const method multiple times
    log.print();
    log.print();
    log.print();
    log.print();
    // Final access count
    cout<<"Final access count after multiple calls: "<<endl;
    log.print_accessCount();

}