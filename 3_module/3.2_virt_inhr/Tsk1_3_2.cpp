//
// Created by NandanRaj on 12-02-2026.
//
#include <iostream>
class Device {
public:
    int id=7;
    void showId() {
        std::cout << "ID: " << id << std::endl;
    }
};
class Phone:public Device {
//body
};
class Camera:public Device {
//body
};
class SmartPhone:public Phone,public Camera {
//body
};

int main(int argc, char *argv[]) {
    SmartPhone sp;
    // sp.id=6;
    sp.Phone::id=6;
    sp.Camera::id=8;
    // below two fun call will work as we specified using :: that through which subobj we are calling showId()
    sp.Phone::showId();
    sp.Camera::showId();
    // below one will lead to error as compiler is not sure through which subobject ( Phone or camera ) it have to call showId()
    // sp.showId();
    std::cout << &sp<<std::endl;
    std::cout<<static_cast<Phone*>(&sp)<<std::endl;
    std::cout<<static_cast<Camera*>(&sp)<<std::endl;
    // Demonstrating that  Phone and Camera share the diff. Device subobject
    std::cout << "Address of Device subobject from Phone: " << (void*)&sp.Phone::id << std::endl;
    std::cout << "Address of Device subobject from Camera: " << (void*)&sp.Camera::id << std::endl;
    // std::cout << "Address of Device subobject from SmartPhone: " << (void*)&sp.id << std::endl;

}
