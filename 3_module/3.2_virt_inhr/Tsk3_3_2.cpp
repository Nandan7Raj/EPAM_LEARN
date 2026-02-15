#include <iostream>

class Device {
    int id;
public:
    Device(int id) : id(id) {
        std::cout << "Device constructed, id = " << id << std::endl;
    }
    ~Device() {
        std::cout << "Device destructor!" << std::endl;
    }
};

class Phone : virtual public Device {
public:
    Phone(int id) : Device(id) {
        std::cout << "Phone constructor\n";
    }
    ~Phone() {
        std::cout << "Phone destructor\n";
    }
};

class Camera : virtual public Device { // Corrected to virtual
public:
    Camera(int id) : Device(id) {
        std::cout << "Camera constructor\n";
    }
    ~Camera() {
        std::cout << "Camera destructor\n";
    }
};

class SmartPhone : public Phone, public Camera {
public:
    SmartPhone(int id) : Device(id), Phone(id), Camera(id) { // Corrected initialization
        std::cout << "SmartPhone constructor\n";
    }
    ~SmartPhone() {
        std::cout << "SmartPhone destructor\n";
    }
};

int main() {
    SmartPhone sp(45);
    return 0;
}
