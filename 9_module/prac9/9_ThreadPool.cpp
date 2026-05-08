//
// Created by NandanRaj on 04-05-2026.
//

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>

class ThreadPool {
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;

public:
    ThreadPool(int n) {
        //below code is as same as we used to do in main func(previously)
        /*
         *for(int i=0;i<n;i++)
         *{
         *threads.emplace_back(funcName);
         *}
         */
        for (int i = 0; i < n; i++) {
            workers.emplace_back([this]() {// below code is part of lambda don't get confused
                //below code is callable that thread will do
                while (true) {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(mtx);
                        cv.wait(lock, [this]() {
                            return stop || !tasks.empty();
                        });

                        if (stop && tasks.empty()) return; // it means all task are done

                        task = std::move(tasks.front());
                        tasks.pop();
                    }

                    task(); // execute
                }
            });
        }
    }

    void enqueue(std::function<void()> task) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(task);
        }
        cv.notify_one();
    }

    ~ThreadPool() {
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true; // indicates that done with all push in queue , so if now any thread finds queue empty
                         // then it means all tasks are done
        }
        cv.notify_all();

        for (auto &t : workers)
            t.join();
    }
};

int main() {
    ThreadPool pool(3);

    for (int i = 0; i < 5; i++) {
        pool.enqueue([i]() {
            std::cout << "Task " << i << " running\n";
        });
    }
}
