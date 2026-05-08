#include <iostream>
#include <thread>
#include <atomic>

std::atomic<bool> ready{false}; // synchronization flag
int data = 0;                   // shared non-atomic data

// Producer thread
void producer() {
    data = 42; // write shared data

    std::cout << "[Producer] Data set to 42\n";

    // release ensures all previous writes (data=42)
    // are visible before ready becomes true
    ready.store(true, std::memory_order::release);
}

// Consumer thread
void consumer() {

    std::cout << "[Consumer] Waiting for data...\n";

    // acquire ensures that once ready == true,
    // all writes before release are visible here
    while (!ready.load(std::memory_order::acquire)) {
        // spin-wait
    }

    // safe to read data after acquire
    std::cout << "[Consumer] Data observed: " << data << "\n";
}

int main() {
    std::jthread t1(producer);
    std::jthread t2(consumer);

    // jthread automatically joins
    return 0;
}
