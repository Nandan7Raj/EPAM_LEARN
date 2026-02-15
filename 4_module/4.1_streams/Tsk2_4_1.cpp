#include <iostream>
#include <iomanip>

int main() {

    std::string Itm_name[] = {"Apple","Banana","Mango","Guava"};
    double Itm_price[] = {30.34,35.50,70.999,40.333};

    const int nameWidth = 15;
    const int priceWidth = 10;

    // Header
    std::cout << std::left  << std::setw(nameWidth)  << "ITEM"
              << std::right << std::setw(priceWidth) << "PRICE" << "\n";

    std::cout << std::string(nameWidth + priceWidth, '-') << "\n";

    // Set formatting once
    std::cout << std::fixed << std::setprecision(2);

    // Data rows
    for(int i = 0; i < 4; i++) {
        std::cout << std::left  << std::setw(nameWidth)  << Itm_name[i]
                  << std::right << std::setw(priceWidth) << Itm_price[i]
                  << "\n";
    }

    return 0;
}
