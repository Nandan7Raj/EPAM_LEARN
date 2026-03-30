//
// Created by NandanRaj on 30-03-2026.
//
#include<iostream>
#include<memory>
#include<string>
class LogMessage {
    std::string message_content;
public:
    LogMessage(std::string msg):message_content(msg) {
        std::cout << "LogMessage '" << message_content
        << "' created. Address: " << this << std::endl;
    }
    ~LogMessage() {
        std::cout << "LogMessage '" << message_content
        << "' destroyed. Address: " << this << std::endl;
    }

    void printContent() const {
        std::cout<<"[ "<<message_content<<" ]"<<std::endl;
    }
    void static handleLegacyLog(LogMessage* rawMessage) {
        if (rawMessage==nullptr) {
            std::cout << "Legacy system received a nullptr log.\n";
            return;
        }
        std::cout<<"Legacy system is now handling log: ";
        rawMessage->printContent();
        delete rawMessage;

        std::cout<<"Legacy system has finished processing and deleting the message\n";
    }
};

int main() {
    std::unique_ptr<LogMessage> myLog=std::make_unique<LogMessage>("System Startup Event");
    std::cout<<" unique_ptr has been created \n";
    myLog->printContent();
    LogMessage* handedOverLog=myLog.release();

    std::cout<<"myLog has released ownership.\n";
    LogMessage::handleLegacyLog(handedOverLog);

    if (!myLog) {
        std::cout << "myLog unique_ptr is now empty (nullptr) after release().\n";
    }
    else {
        std::cout << "Error: myLog unique_ptr is NOT empty after release()!\n";
    }

}