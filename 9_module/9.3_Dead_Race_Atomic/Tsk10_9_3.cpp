#include<iostream>
#include<thread>
#include<atomic>

std::atomic<int> value{10};

void add() {
    int before = value.load();
    int prev = value.fetch_add(5); // returns old value
    std::cout << "fetch_add: before=" << before
              << " prev=" << prev
              << " after=" << value.load() << "\n";
}

void sub() {
    int before = value.load();
    int prev = value.fetch_sub(3);
    std::cout << "fetch_sub: before=" << before
              << " prev=" << prev
              << " after=" << value.load() << "\n";
}

int main() {
    std::thread t1(add);
    std::thread t2(sub);

    t1.join();
    t2.join();

    int before = value.load();
    int prev = value.exchange(42);
    std::cout << "exchange: before=" << before
              << " prev=" << prev
              << " after=" << value.load() << "\n";
}
