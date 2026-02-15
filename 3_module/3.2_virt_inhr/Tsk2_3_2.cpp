#include <iostream>

class Device {
public:
    int id = 7;
    void showId() {
        std::cout << "ID: " << id << std::endl;
    }
};

class Phone : virtual public Device {
    // body
};

class Camera : virtual public Device {
    // body
};

class SmartPhone : public Phone, public Camera {
    // body
};

int main() {
    SmartPhone sp;
    sp.id = 6; // Set id directly
    std::cout << "After setting id to 6: ";
    sp.showId(); // Should print ID: 6

    sp.Phone::id = 7; // Set id through Phone
    std::cout << "After setting id through Phone to 7: ";
    sp.showId(); // Should print ID: 7

    sp.Camera::id = 8; // Set id through Camera
    std::cout << "After setting id through Camera to 8: ";
    sp.showId(); // Should print ID: 8

    // Demonstrating that both Phone and Camera share the same Device subobject
    std::cout << "Address of Device subobject from Phone: " << (void*)&sp.Phone::id << std::endl;
    std::cout << "Address of Device subobject from Camera: " << (void*)&sp.Camera::id << std::endl;
    std::cout << "Address of Device subobject from SmartPhone: " << (void*)&sp.id << std::endl;

    // Explanation of the output
    std::cout << "All addresses should be the same, proving only one Device base object exists." << std::endl;

    return 0;
}
