//
// Created by NandanRaj on 08-05-2026.
//

#include <iostream>
int main() {
    int arr[5];
    arr[10] = 100; // Write out-of-bounds!
    std::cout << "Wrote past array bounds!" << std::endl;
    return 0;
}