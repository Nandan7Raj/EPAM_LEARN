//
// Created by NandanRaj on 13-03-2026.
//
#include <cstring>
#include<iostream>
class Buffer {
    int* data;
    size_t size;
public:
    explicit Buffer(const size_t size):size(size) {
        data=new int[size];
        for (int i=0;i<size;i++) {
            data[i]=i+1;
        }
        std::cout<<"Constructor: memory for data allocated at: "<<data<<std::endl;
    }

    // copy constructor
    Buffer(const Buffer& other):size(other.size) {
        data = new int[size];
        std::memcpy(data,other.data,size*sizeof(int));
        std::cout<<"Copy constructor: other's data from "<<other.data<<" copied to memory : "<<data<<std::endl;
    }

    // copy assignment operator
    Buffer& operator=(const Buffer& other){
        if (this!=&other) {
            delete [] data;
            data=new int[size];
            size=other.size;
            std::memcpy(data,other.data,size*sizeof(int));
            std::cout<<"Copy assignment operator: other's data copied to memory: "<<data<<std::endl;
        }
        return *this;
    }

    // move constructor
    Buffer(Buffer&& other) noexcept:data(other.data),size(other.size)  {
        other.data= nullptr;
        other.size=0;
        std::cout<<"Move constructor: Ownership transfer of add: "<<data<<std::endl;
    }

    // move assignment operator
    Buffer& operator=(Buffer&& other) noexcept{
        if (this!=&other) {
            delete [] data;
            size=other.size;
            other.size=0;
            data=other.data;
            other.data=nullptr;
            std::cout<<"Move assignment operator : Ownership transfer of add: "<<data<<std::endl;
        }
        return *this;
    }

    // destructor
    ~Buffer() {
        std::cout<<"Destructor: freeing add: "<<data<<std::endl;
        delete[] data;
    }

    // print info
    void print(const int label) const{
        std::cout<<"buf "<<label<<" --> Data@ "<<data<<" of size: "<<size<<std::endl;
        for (int i=0;i<size;i++) {
            std::cout<<*(data+i)<<" ";
        }
    }

};
int main() {
    Buffer buf1(3);// regular
    Buffer buf2=buf1;// copy constructor ( implicit conversion)
    Buffer buf3(2);
    buf3=buf1; // copy assignment

    Buffer buf4 = std::move(buf1); // move constructor (implicit conversion)
    Buffer buf5(1);
    buf5=buf3; // move assignment

    buf2.print(2);
    buf4.print(4);
    buf5.print(5);
    return 0;
}
