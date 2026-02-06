//
// Created by NandanRaj on 06-02-2026.
//
#include <iostream>
static constexpr int MAX_SPEED=100;
class Car {
    bool engineOn;
    int speed;
    int rpm;
    public:
    void start();
    void accelerate();
    void brake();
};
void Car::start() {
    engineOn = true;
    speed = 0;
    rpm = 0;
    std::cout<<"The Engine has been turned on.Tighten your seat belt"<<std::endl;
}
void Car::accelerate() {
    if (!engineOn) {
        std::cout<<"To accelerate, first start your engine"<<std::endl;
        return;
    }
    if (speed==MAX_SPEED) {
        std::cout<<"Bro! yor are already at maximum speed."<<std::endl;
        return;
    }
    speed+=20;
    rpm+=10;

    std::cout<<"Wooooohooooo! you accelerated"<<std::endl;
    if (speed>=MAX_SPEED) {
        speed=MAX_SPEED;
        std::cout<<"OMG! you reached MAXIMUM SPEED"<< std::endl;
    }
    std::cout<<"Your speed: "<<speed<<std::endl;
}
void Car::brake() {
    if (!engineOn) {
        std::cout<<"To STOP, first start your engine"<<std::endl;
        return;
    }
    speed=0;
    rpm=0;
    std::cout<<"Ooohooooo! you applied brake"<<std::endl;
}
int main() {
    Car car1;
    car1.accelerate();
    car1.brake();
    car1.start();
    car1.accelerate();
    car1.accelerate();
    car1.accelerate();
    car1.accelerate();
    car1.accelerate();
    car1.accelerate();
    car1.brake();


}

