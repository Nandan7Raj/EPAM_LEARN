//
// Created by NandanRaj on 04-02-2026.
//
#include <iostream>
//function to allocate memory at runtime
int* dynamic_memory() {
    return new int();
    // void* ptr = operator new(sizeof(int));   // allocate memory
    // int* ptr_int = static_cast<int*>(ptr);   // cast to int pointer
    // *ptr_int = int();  or *ptr_int=0;        // value initialize (sets 0)
    // return ptr_int;
}
int main() {
    auto ptr = dynamic_memory();
    // *ptr=8;
    std::cout<<"value stored at add:"<<ptr<<" is "<<*ptr<<std::endl;
    delete ptr;
    //memory is deallocated but ptr still pointing yo that memeory
    std::cout<<"After deallocation."<< std::endl;
    //*ptr=Garbage value
    std::cout<<"value stored at add:"<<ptr<<" is "<<*ptr<<std::endl;
    // now we will set ptr to nullptr to handel dangling pointer
    ptr=nullptr;
    // now ptr=0 and *ptr is nothing
    std::cout<<"After setting ptr to null."<< std::endl;
    std::cout<<"value stored at add:"<<ptr<<" is "<<*ptr<<std::endl;
    
}