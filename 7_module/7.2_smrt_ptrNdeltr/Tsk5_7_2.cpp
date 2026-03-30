//
// Created by NandanRaj on 30-03-2026.
//
#include<iostream>
#include<memory>
#include <string>

class FileHandler {
public:
    FileHandler() {
        std::cout<<"File opened\n";
    }
    ~FileHandler() {
        std::cout<<"File closed\n";
    }

    void write (const std::string& message) const{
        std::cout<<"Writing: "<<message<<std::endl;
    }
};

std::unique_ptr<FileHandler> createFileHandler() {
    auto unqPtr=std::make_unique<FileHandler>();
    return unqPtr;
}

void processFileHandler(std::unique_ptr<FileHandler> handler) {
    // handler now owns the FileHandler object
    handler->write("Message from processFileHandler");
    // Destructor called automatically when handler goes out of scope
}
int main() {
    // Step 1: Create FileHandler managed by unique_ptr
    std::unique_ptr<FileHandler> file_handler = createFileHandler();

    // Step 2: Transfer ownership to processFileHandler using std::move
    processFileHandler(std::move(file_handler));

    // Step 3: file_handler is now nullptr - cannot be used!
    // Attempting to use it will cause undefined behavior/crash
    if (file_handler == nullptr) {
        std::cout << "file_handler is now nullptr after move\n";
        std::cout << "Cannot use moved-from pointer - ownership transferred\n";
    }

    return 0;

}