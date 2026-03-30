//
// Created by NandanRaj on 25-03-2026.
//
#include <iostream>
#include <iomanip>

int main(int argc,char* argv[]) {
    int value=0x12345678;
    std::cout<<"int value = 0x"<<std::hex<<value<<std::dec<<std::endl;
    // Print raw bytes (shows endianness)
    std::cout << "Bytes of value: ";
    char* pchar = reinterpret_cast<char*>(&value);
    for (size_t i = 0; i < sizeof(int); ++i) {
        std::cout << "0x" << std::hex << (0xFF & pchar[i]) << " ";
    }
    std::cout << std::dec << std::endl;

    // Unsafe pointer cast between unrelated types (DO NOT DO THIS IN PRACTICE)
    int a = 42;
    double* pd = reinterpret_cast<double*>(&a);
    std::cout << "Trying to read int memory as double: *pd = " << *pd << std::endl;
    // Writing through this is even worse: *pd = 1.23; // UB
}