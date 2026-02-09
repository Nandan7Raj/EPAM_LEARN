//
// Created by NandanRaj on 06-02-2026.
//
#include<iostream>
class Printable {
    public:
    virtual void print() const=0;
    virtual ~Printable() = default;
};
class Savable {
public:
    virtual void save() const=0;
    virtual ~Savable() = default;
};
class Document :public Printable,public Savable {
//class Document:Printable,Savable{-->default private inheritance
public:
    void print() const override {
        std::cout<<"printing..."<<std::endl;
    }
    void save() const override {
        std::cout<<"Saving..."<<std::endl;
    }
};
int main() {
    Document doc;
    Printable* PrntPtr= &doc;
    PrntPtr->print();
   // PrntPtr->save();// Pointer is of type Printable so not aware about any func of Savable
    Savable* SvPtr= &doc;
    // SvPtr->print();// Pointer is of type Savable so no awareness of any fun of printable
    SvPtr->save();
}