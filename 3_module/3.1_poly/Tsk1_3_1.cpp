#include <iostream>
#include <string>

class Calculator {
public:
    // Add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Add two doubles
    double add(double a, double b) {
        return a + b;
    }

    // Concatenate two strings
    std::string add(const std::string& a, const std::string& b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    // Calling overloaded functions
    std::cout << "Integer Add: " << calc.add(2, 3) << std::endl;
    std::cout << "Double Add: " << calc.add(2.5, 3.7) << std::endl;
    std::cout << "String Add: " << calc.add("Nandan, ", "Raj") << std::endl;

    return 0;
}
