//
// Created by NandanRaj on 25-03-2026.
//
#include<iostream>
class Animal {
public:
    virtual ~Animal()=default;
};
class Dog:public Animal {
public:
    void DogFunc() const{
        std::cout<<"Dog Func\n";
    }
};


class Cat:public Animal {
public:
    void CatFunc() const{
        std::cout<<"Cat Func\n";
    }
};
int main() {
    Animal* ptrAc= new Cat();
    Animal* ptrAd= new Dog();
    std::cout<<"Before Casting----\n";
    std::cout<<"Type of ptr pointing to cat obj: "
    <<typeid(*ptrAc).name()<<std::endl;
    std::cout<<"Type of ptr pointing to Dog obj: "
    <<typeid(*ptrAd).name()<<std::endl;
    // ptrAc->CatFunc();// error
    // ptrAd->DogFunc();//error

    // Now doing dynamic casting
    std::cout<<"After  Casting----\n";

    Cat* ptrC=dynamic_cast<Cat *>(ptrAc);
    if (ptrC) {
        ptrC->CatFunc();
        std::cout<<"Type of ptr pointing to cat obj: "
    <<typeid(*ptrC).name()<<std::endl;
    }
    else {
        std::cout<<"Casting Failed\n";
    }

    auto ptrD=dynamic_cast<Dog *>(ptrAd);
    if (ptrD) {
        ptrD->DogFunc();
        std::cout<<"Type of ptr pointing to Dog obj: "
    <<typeid(*ptrD).name()<<std::endl;
    }
    else {
        std::cout<<"Casting Failed\n";
    }

    delete ptrAc;
    delete ptrAd;
    
}