#include<iostream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>

template<typename T>
class MutexQueue {
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cv;

public:
    void push(T item) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            q.push(std::move(item));
        }
        cv.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !q.empty(); });
        
        T res = std::move(q.front());
        q.pop();
        return res;
    }

    bool isEmpty() {
        std::lock_guard<std::mutex> lock(mtx);
        return q.empty();
    }
};

void producer(MutexQueue<int>& q) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    q.push(84);
}

void consumer(MutexQueue<int>& q) {
    std::cout << "[Consumer] Waiting for data (Efficiently sleeping...)\n";
    int item = q.pop(); 
    std::cout << "[Consumer] Got it! Value: " << item << "\n";
}

int main() {
    MutexQueue<int> q;
    std::thread t1(producer, std::ref(q));
    std::thread t2(consumer, std::ref(q));
    std::thread t3(consumer, std::ref(q));
    t1.join();
    t2.join();
    t3.detach();


    std::cout<<"Main Ends\n";
    return 0;
}