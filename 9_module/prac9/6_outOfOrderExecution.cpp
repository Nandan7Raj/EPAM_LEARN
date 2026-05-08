//
// Created by NandanRaj on 23-04-2026.
//
#include<iostream>
#include <thread>
std::atomic<int>  payload = 0;
std::atomic<bool> data_ready = false;
void producer() {
    payload.store(12,std::memory_order::release);
    data_ready = true;
}

void consumer() {
    while (!data_ready) {
        //stop and wait
    }
    std::cout << "Payload: "<<payload.load(std::memory_order::acquire)<<std::endl;
}

int main(int argc, char *argv[]) {
   std::jthread t1(producer);
    std::jthread t2(consumer);

}

