//
// Created by NandanRaj on 15-04-2026.
//
#include<iostream>
#include<thread>
#include<queue>
#include<condition_variable>
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
bool complete =false;
void producer() {
    for (int i=1;i<=20;i++) {
            {
                std::unique_lock<std::mutex> lock(mtx);
                buffer.push(i);
                std::cout << "Produced: " << i << "\n";
            }
            cv.notify_one(); // notify consumer
        }

        // signal completion
        {
            std::unique_lock<std::mutex> lock(mtx);
            std::cout<<"Done with the production\n";
            complete = true;
        }
        cv.notify_one(); // wake consumer if waiting

}
void consumer(){

    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[] {
            return !buffer.empty() || complete;
        });
        if (buffer.empty() && complete) {
            break; // Exit if producer finished and buffer is empty
        }
        int value=buffer.front();
        buffer.pop();
        std::cout<<"Consumed "<<value<<"\n";
    }
    std::cout<<"\n";
}
int main(){
    std::thread prd_t(producer);
    std::thread con_t(consumer);
    prd_t.join();
    con_t.join();
    std::cout<<"MAIN ENDS\n";
}

