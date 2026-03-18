//
// Created by NandanRaj on 13-03-2026.
//
#include<iostream>
class ResourceHolder {
    int *data;
public:
    explicit ResourceHolder(int val) {
        data= new int(val);
    }
    // copy constructor
    explicit ResourceHolder(const ResourceHolder& other) {
        data=new int(*other.data);
    }
    // copy assignment operator
    ResourceHolder& operator=(const ResourceHolder& other) {
        if (this!=&other) {
            delete data;
            data=new int(*other.data);
        }
        return *this;
    }
    ~ResourceHolder() {
        delete data;
    }
    void print(int i) const {
        std::cout<<"obj no "<<i<<"--> val: "<<*data<<" at add: "<<data<<std::endl;
    }
};
int main() {
    ResourceHolder obj1(4);
    ResourceHolder obj2(obj1);
    ResourceHolder obj3(4);
    obj3=obj2;
    obj1.print(1);
    obj2.print(2);
    obj3.print(3);
    // all will have same val but diff address

}
