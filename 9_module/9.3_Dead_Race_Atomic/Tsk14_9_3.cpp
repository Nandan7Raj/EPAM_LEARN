//
// Created by NandanRaj on 04-05-2026.
//

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>
#include<queue>
#include<functional>

class ThreadPool {

    std::vector<std::thread> workers;
    std::queue<std::function<void()>> task_queue;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop=false;

public:
    ThreadPool(int n) {
        for (int i=0;i<n;i++) {
            workers.emplace_back([this] {

                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(mtx);
                       cv.wait(lock,[this] {
                          return stop || !task_queue.empty();
                       });

                       if (stop && task_queue.empty()) return;

                        task = std::move(task_queue.front());
                        task_queue.pop();
                    }
                    //Run the task outside the lock
                    task();
                }
            });
        }
    }

    void submit(std::function<void()> task) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            task_queue.push(std::move(task));
        }
        cv.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(mtx);
            stop = true;
        }
        cv.notify_all();
        for (std::thread &t:workers)
            t.join();
    }

};

int main(int argc, char *argv[]) {
    ThreadPool pool(4); // Create 4 worker threads

    for (int i = 1; i <= 8; ++i) {
        pool.submit([i] {
            std::cout << "Task " << i << " is being processed by thread "
                      << std::this_thread::get_id() << std::endl;
        });
    }

    return 0;
}
