//
// Created by NandanRaj on 05-02-2026.
//

#include<iostream>

static constexpr double ABS_ZERO=-273.15;
// Class to handle temperature conversions
class Temperature {
    double celsius;   // Stores temperature in Celsius (private for encapsulation)

public:
    Temperature(double c = 0) {
        set_celsius(c);
    }

    // Getter function to return Celsius value
    // [[nodiscard]] warns if return value is ignored
    [[nodiscard]] double get_celsius() const {
        return celsius;
    }

    // Setter function to set Celsius value with validation
    void set_celsius(const double celsius) {

        // Check if temperature is below absolute zero
        if (celsius < ABS_ZERO) {
            std::cout << "WARNING! value less than absolute zero" << std::endl;
            return;   // Prevent invalid assignment
        }

        this->celsius = celsius;
    }

    // Converts Celsius to Fahrenheit and returns result
    [[nodiscard]] double get_Fahrenheit() const {
        double fahrenheit = (celsius * 9.0 / 5.0) + 32;   // Conversion formula
        return fahrenheit;
    }
};

int main() {

    Temperature temp;   // Create Temperature object

    temp.set_celsius(-300);   // Invalid value (below absolute zero)
    temp.set_celsius(273.15); // Valid value

    std::cout << temp.get_celsius() << std::endl;     // Display Celsius
    std::cout << temp.get_Fahrenheit() << std::endl;  // Display Fahrenheit

    // Below line will cause error as 'celsius' is private
    // std::cout << temp.celsius << std::endl;

    return 0;
}
