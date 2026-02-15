//
// Add functionality to Animal and Plant classes to demonstrate their purpose
//
#include <iostream>
#include <string>

class LivingBeing {
public:
    std::string name;

    void show() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "LivingBeing this: " << this << "\n";
    }
};

class Animal : virtual public LivingBeing {
public:
    int energy = 100;

    void makeSound() const {
        std::cout << name << " says: Roar!\n";
    }

    void eat(int food) {
        energy += food;
        std::cout << name << " ate, energy now: " << energy << "\n";
    }

    void show() const { // Animal-specific view
        std::cout << "\n[Animal]\n";
        LivingBeing::show();
        std::cout << "Energy: " << energy << "\n";
        std::cout << "Animal this: " << this << "\n";
    }
};

class Plant : virtual public LivingBeing {
public:
    int waterLevel = 50;

    void photosynthesize() {
        waterLevel -= 5;
        std::cout << name << " is photosynthesizing, water now: " << waterLevel << "\n";
    }

    void water(int amount) {
        waterLevel += amount;
        std::cout << name << " watered, water now: " << waterLevel << "\n";
    }

    void show() const { // Plant-specific view
        std::cout << "\n[Plant]\n";
        LivingBeing::show();
        std::cout << "WaterLevel: " << waterLevel << "\n";
        std::cout << "Plant this: " << this << "\n";
    }
};

class Hybrid : public Animal, public Plant {
public:
    void showAll() const {
        Animal::show();
        Plant::show();

        // Proves there is ONLY ONE LivingBeing (because of virtual inheritance)
        std::cout << "\n[Hybrid check]\n";
        std::cout << "LivingBeing via Hybrid: " << static_cast<const LivingBeing*>(this) << "\n";
        std::cout << "LivingBeing via Animal: " << static_cast<const LivingBeing*>(static_cast<const Animal*>(this)) << "\n";
        std::cout << "LivingBeing via Plant : " << static_cast<const LivingBeing*>(static_cast<const Plant*>(this)) << "\n";
    }
};

int main() {
    Hybrid hybrid;
    hybrid.name = "Chimera";

    hybrid.makeSound();
    hybrid.eat(20);

    hybrid.photosynthesize();
    hybrid.water(15);

    hybrid.showAll();
}
