//
// Created by NandanRaj on 16-03-2026.
//
#include <cstring>
#include<iostream>
class Base {
    int* baseData;
public:
    Base(const int n):baseData(new int(n)) {
        std::cout<<"constructor: @ "<<baseData<<std::endl;
    }
    //copy constructor
    Base(const Base& other):baseData(new int(*(other.baseData))) {
        std::cout<<"copy constructor: from @ "<<other.baseData<<" to @ "<<baseData<<std::endl;
    }
    // copy assignment operator
    Base& operator=(const Base& other) {
        if (this!=&other) {
            delete baseData;
            baseData=new int(*(other.baseData));
            std::cout<<"copy assignment: from @ "<<other.baseData<<" to @ "<<baseData<<std::endl;
        }
        return *this;
        }
    // move constructor
    Base(Base&&other) noexcept:baseData(other.baseData) {
        other.baseData=nullptr;
        std::cout<<"Move constructor: transfer of ownership of value: "
                 <<*baseData<< " @ "<<baseData<<std::endl;
    }
    // move assignment operator
    Base& operator=(Base&& other) noexcept {
        if (this!=&other) {
            delete baseData;
            baseData=other.baseData;
            other.baseData=nullptr;
            std::cout<<"Move assignment operator: transfer of ownership of value: "
                 <<*baseData<< " @ "<<baseData<<std::endl;
        }
        return *this;
    }
    virtual ~Base() {
        std::cout<<"Freeing memory @ "<<baseData<<std::endl;
        delete baseData;
    }

    virtual void print(const char* tag) const {
        std::cout<<tag<<" Base data: "<< baseData << " (" << (baseData ? *baseData : 0) << ")\n";
    }
};
class Derived: public Base {
    char* derivedData;
public:
    Derived(int n,const char* str):Base(n),derivedData(new char[std::strlen(str)+1]) {
        std::strcpy(derivedData,str);
        std::cout<<" Derived class constructor: derivedData : "
        <<derivedData<< " created @ "<<static_cast<const void*>(derivedData)
        <<std::endl;
    }
    // copy constructor
    Derived(const Derived& other):Base(other),derivedData(new char[std::strlen(other.derivedData)+1])
    {
        std::strcpy(derivedData,other.derivedData);
        std::cout<<" Derived copy constructor: string: "
        <<derivedData<<" copied from @ "<<static_cast<const void*>(other.derivedData)
        <<" to @ "<<static_cast<const void*>(derivedData)<<std::endl;
    }
    // copy assignment operator
    Derived& operator=(const Derived& other) {
        if (this!=&other) {
            delete [] derivedData;
            Base::operator=(other);
            derivedData = new char[strlen(other.derivedData)+1];
            strcpy(derivedData, other.derivedData);
            std::cout<<"Derived copy assign: string: "
        <<derivedData<<" copied from @ "<<static_cast<const void*>(other.derivedData)
        <<" to @ "<<static_cast<const void*>(derivedData)<<std::endl;
        }
        return *this;
    }
    // move constructor
    Derived(Derived&& other) noexcept: Base(other),derivedData(other.derivedData) {
        other.derivedData=nullptr;
        std::cout<<"Derived Move constructor: transfer of ownership of value: "
                 <<derivedData<< " @ "<<static_cast<const void*>(derivedData)<<std::endl;
    }
    // move assignment operator
    Derived& operator=(Derived&& other) {
        if (this!=&other) {
            Base::operator=(std::move(other));
            delete [] derivedData;
            derivedData=other.derivedData;
            other.derivedData=nullptr;
            std::cout<<"Derived Move Assignment: transfer of ownership of value: "
                 <<derivedData<< " @ "<<static_cast<const void*>(derivedData)<<std::endl;

        }
        return *this;
    }
    ~Derived() override {
        std::cout << "Derived dtor: " << static_cast<void*>(derivedData) << "\n";
        delete[] derivedData;
    }
    void print(const char* lbl) const override {
        Base::print(lbl);
        std::cout << lbl << " Derived data: " << static_cast<const void*>(derivedData)
                  << " (" << (derivedData ? derivedData : "null") << ")\n";
    }
};

int main() {
    std::cout<<"----Base test----\n";
    Base b1(7);
    Base b2=b1;// copy
    Base b3(8);
    b3=b1; // move

    std::cout<<"----Derived test----\n";
    Derived d1(9,"Nandan");
    Derived d2=d1; // copy
    Derived d3(3,"Temp");
    d3=std::move(d1);

     std::cout<<"----Slicing Demo----\n";
    Base slic1= d2; // Slicing (loses Derived-specific data)
    slic1.print("Sliced: ");
    d2.print("d2: ");

    std::cout << "--- Polymorphic deletion ---\n";
    Base* poly = new Derived(7,"Dhoni");
    delete poly;        // Should call both destructors safely

}