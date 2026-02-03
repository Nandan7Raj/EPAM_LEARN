//
// Created by NandanRaj on 02-02-2026.
//
#include <iostream>
#include "logger.h"
using namespace std;
int main() {
    LOG(1, "Critical error occurred!")
    LOG(2, "This is a warning.")
    LOG(3, "Application started successfully.")
    LOG(4, "Debugging variable x = 42.")
}