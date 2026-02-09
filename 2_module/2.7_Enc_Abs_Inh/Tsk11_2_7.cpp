//
// Created by NandanRaj on 06-02-2026.
//
#include<iostream>
#include<string>
class Device {
    std::string name;
    int id;
    static int count_obj;
    public:
    Device(std::string name, int id):name(name), id(id) {
        std::cout<<"Device Constructor called"<<std::endl;
        count_obj++;
    };

    [[nodiscard]] std::string get_name() const {
        return name;
    }

    [[nodiscard]] int get_id() const {
        return id;
    }
    static void print_count();
};
int Device::count_obj=0;
void Device::print_count() {
    std::cout<<"No. of Obj of Device is "<<count_obj<<std::endl;
}

class Phone : virtual public Device {
    std::string network;
    public:
    Phone(std::string name, int id,std::string network):Device(name,id),network(network) {
        std::cout<<"Phone Constructor called"<<std::endl;
    }

    [[nodiscard]] std::string get_network() const {
        return network;
    }
};
class Camera: virtual public Device {
    int megapixel;
public:
    Camera(std::string name, int id,int megapixel):Device(name,id),megapixel(megapixel) {
        std::cout<<"Camera Constructor called"<<std::endl;
    }

    [[nodiscard]] int get_megapixel() const {
        return megapixel;
    }
};
class SmartPhone:public Phone,public Camera {
public:
    SmartPhone(std::string name, int id,std::string network,int megapixel):
    Device(name,id),Phone(name,id,network),Camera(name,id,megapixel) {
        std::cout<<"SmartPhone Constructor called"<<std::endl;
    }
};
int main() {
    SmartPhone myPhone("SAMSUNG",682453,"6G",12);
    std::string name=myPhone.get_name();
    int id=myPhone.get_id();
    std::string network=myPhone.get_network();
    int megapixel=myPhone.get_megapixel();
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"ID: "<<id<<std::endl;\
    std::cout<<"Network: "<<network<<std::endl;
    std::cout<<"Megapixel: "<<megapixel<<std::endl;
    Device::print_count();//it will print 1 that showa that device initialized only once




}