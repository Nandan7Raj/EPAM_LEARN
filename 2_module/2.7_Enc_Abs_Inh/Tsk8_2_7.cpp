//
// Created by NandanRaj on 06-02-2026.
//
#include<iostream>
#include<string>
class Vehicle {
    private:
    std::string make;
    std::string model;
public:
    Vehicle(std::string make, std::string model):make(make),model(model) {
        std::cout<<"Vehicle constructor called"<<std::endl;
    };
    ~Vehicle() {
        std::cout<<"Vehicle destructor called"<<std::endl;
    }
};
class Car:public Vehicle {
private:
    int doors;
    public:
    Car(std::string make, std::string model, int doors):
    Vehicle(make,model),doors(doors) {
        std::cout<<"Car constructor called"<<std::endl;
    }
    ~Car() {
        std::cout<<"Car destructor called"<<std::endl;
    }
};
class ElectricCar:public Car {
    private:
    double batteryCapacity;
public:
    ElectricCar(std::string make, std::string model, int doors,double batteryCapacity):
    Car(make,model,doors),batteryCapacity(batteryCapacity) {
        std::cout<<"ElectricCar constructor called"<<std::endl;
    }
    ~ElectricCar() {
        std::cout<<"ElectricCar destructor called"<<std::endl;
    }
};
int main() {
    // ElectricCar elCr("2020","BYD",4,20.5);
    // first Vehicle constructor will be called , then Car constructor and then ElectricCar Constructor will be called
    Vehicle *Vptr=new ElectricCar("2020","BYD",4,20.5);
    delete Vptr; // Order of destructor call :ElectricCar->Car->Vehicel

}