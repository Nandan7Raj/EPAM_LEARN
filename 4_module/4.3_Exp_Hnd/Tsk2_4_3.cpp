//
// Created by NandanRaj on 19-02-2026.
//
#include <iostream>
#include<stdexcept>
class SystemError:public std::exception {
    const char* msg;
public:
    SystemError(const char* msg):msg(msg){}
    virtual const char* what() const noexcept override {
        return msg;
    }
};

class NetworkError:public std::exception {
    const char* msg;
    public:
    NetworkError(const char* msg):msg(msg){}
    const char* what() const noexcept override {
        return msg;
    }
};
void complexOperation() {
    static int counter=0;
    counter++;
    if (counter==1) {
        throw SystemError("Error in System");
    }
    if (counter==2) {
        throw NetworkError("Error in Network");
    }
    if (counter==3) {
        throw -1;
    }
    if (counter==4) {
        throw "Very unexpected error!";
    }
    std::cout<<"Operation completed successfully"<<std::endl;
}
int main() {
    //1
    try {
        complexOperation();
    }
    catch (NetworkError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"Network Error caught\n";
    }
    catch (SystemError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"System Error caught\n";
    }
    catch (int errorCode) {
        std::cout<<"Generic integer error caught: "<<errorCode<<std::endl;
    }
    catch (...) {
        std::cout<<"Unknown exception caught"<<std::endl;
    }
    std::cout<<"--- End of processing ---\n" ;
    //2
    try {
        complexOperation();
    }
    catch (NetworkError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"Network Error caught\n";
    }
    catch (SystemError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"System Error caught\n";
    }
    catch (int errorCode) {
        std::cout<<"Generic integer error caught: "<<errorCode<<std::endl;
    }
    catch (...) {
        std::cout<<"Unknown exception caught"<<std::endl;
    }
    std::cout<<"--- End of processing ---\n" ;
    //3
    try {
        complexOperation();
    }
    catch (NetworkError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"Network Error caught\n";
    }
    catch (SystemError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"System Error caught\n";
    }
    catch (int errorCode) {
        std::cout<<"Generic integer error caught: "<<errorCode<<std::endl;
    }
    catch (...) {
        std::cout<<"Unknown exception caught"<<std::endl;
    }
    std::cout<<"--- End of processing ---\n" ;
    //4
    try {
        complexOperation();
    }
    catch (NetworkError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"Network Error caught\n";
    }
    catch (SystemError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"System Error caught\n";
    }
    catch (int errorCode) {
        std::cout<<"Generic integer error caught: "<<errorCode<<std::endl;
    }
    catch (...) {
        std::cout<<"Unknown exception caught"<<std::endl;
    }
    std::cout<<"--- End of processing ---\n" ;
    //5
    try {
        complexOperation();
    }
    catch (NetworkError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"Network Error caught\n";
    }
    catch (SystemError error) {
        std::cout<<error.what()<<std::endl;
        std::cout<<"System Error caught\n";
    }
    catch (int errorCode) {
        std::cout<<"Generic integer error caught: "<<errorCode<<std::endl;
    }
    catch (...) {
        std::cout<<"Unknown exception caught"<<std::endl;
    }
    std::cout<<"--- End of processing ---\n" ;

}
