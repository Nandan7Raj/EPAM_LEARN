//
// Created by NandanRaj on 20-04-2026.
//
#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<queue>
#include<optional>

int spin_count=0;
template<typename T>
class MutexQueue {
    std::queue<T> q;
    mutable std::mutex mtx; //'mutable' allows locking in const functions

public:
    MutexQueue()=default;
    // push item in the queue
    void push(T item) {
        std::lock_guard<std::mutex> lock(mtx);
        q.push(std::move(item));
    }//mutex automatically unlocks here

    // Attempt to pop an item
    // Returns std::nullopt if the queue is empty
    std::optional<T> try_pop() {
        std::lock_guard<std::mutex> lock(mtx);
        if (q.empty())
            return std::nullopt;
        T res=std::move(q.front());
        q.pop();
        return res;
    }

    // check if empty
    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return q.empty();
    }
};

void producer(MutexQueue<int>& q) {
    // Producer is slow: it waits 2 seconds before giving the first item
    std::this_thread::sleep_for(std::chrono::seconds(2));
    q.push(42);
    std::cout << "[Producer] Finally pushed the data!\n";
}

void consumer(MutexQueue<int>& q) {

    unsigned long long spin_count = 0;

    std::cout << "[Consumer] Started spinning...\n";

    while (true) {
        auto item = q.try_pop();
        if (item) {
            std::cout << "[Consumer] Got it! Value: " << *item << "\n";
            std::cout << "[Consumer] I wasted " << spin_count << " loops checking for this.\n";
            break;
        }
        // NO SLEEP HERE! This is the "Spinning"
        spin_count++;
    }

}

int main() {
    MutexQueue<int> q;
    std::thread t1(producer, std::ref(q));
    std::thread t2(consumer, std::ref(q));

    t1.join();
    t2.join();

    if (q.empty())
        std::cout<<"Queue is empty now\n";

    return 0;
}

