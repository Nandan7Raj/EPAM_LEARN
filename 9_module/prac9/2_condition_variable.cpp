//
// Created by NandanRaj on 14-04-2026.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool coffee_ready = false;
void waiter(std::string& name){
    std::unique_lock<std::mutex> lock(mtx);

    std::cout<<"Waiter: "<<name<<" got the order.\n";
    //But waiter is dependent on coffee machine to serve coffee
    cv.wait(lock,[]{return coffee_ready;});
    // now went to sleep mode to save energy (i.e cpu power) as coffee is not ready

    //after getting notified
    //Once awake, we own the lock again!
    std::cout<<"Coffee is served to customer\n";
}

void coffee_machine() {
    std::cout<<"Started the coffee machine\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate brewing

    {
        std::lock_guard<std::mutex> lock(mtx);
        coffee_ready = true;
        std::cout << "Coffee is ready!\n";
    }

    // 3. Ring the buzzer to wake up the customer
    cv.notify_one();
}

int main() {
    std::string name="Waiter1";
    std::thread t1(waiter,std::ref(name));
    std::thread t2(coffee_machine);

    t1.join();
    t2.join();
    return 0;
}
