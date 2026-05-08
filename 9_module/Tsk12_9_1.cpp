//
// Created by NandanRaj on 17-04-2026.
//
#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>
#include <numeric>

const int N=1e3;
typedef unsigned long long ull;
std::mutex mtx;

std::vector<int> data(1e6);
std::vector<ull> result;
void worker(int beg,int end) {
    ull sum=0;
    for (int i=beg;i<=end&&i<data.size();i++) {
        sum+= 1LL*data[i];
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        result.push_back(sum);
    }
}

int main() {
    data.reserve(1e6);
    std::iota(data.begin(),data.end(),0);

    int i=0;
    std::vector<std::jthread> Threads;
    while (i<data.size()) {
        int beg=i;
        int end=i+N-1;
        Threads.emplace_back(worker,beg,end);
        i+=N;
    }
    // for (auto&thd:Threads) {
    //     thd.join();
    // }

    std::cout<<"Done with chunk sum calculation\n";

    ull sum = std::accumulate(result.begin(),result.end(),0);
    std::cout << "Final Sum: "<<sum<<std::endl;
}