//
// Created by NandanRaj on 03-04-2026.
//

#include<iostream>
#include<list>
#include<algorithm>

const int CACHE_CAPACITY = 6;

void accessCache(std::list<int> &cache, int value) {
    auto it = cache.begin();
    while (it != cache.end()) {
        if (*it == value) {
            cache.erase(it);
            break;
        }
        ++it;
    }
    cache.push_front(value);  // Add first
    if (cache.size() > CACHE_CAPACITY)
        cache.pop_back();
}

void printCache(const std::list<int> &cache)
{
    for (auto &x:cache)
        std::cout<<x<<" ";
    std::cout<<"\n";
}
int main() {
    std::list<int> cache;

    int value;
    while (true) {
        std::cout << "Access value: ";
        std::cin >> value;
        if (value == -1) break; // Stop input
        accessCache(cache, value);
        printCache(cache);
    }
    std::cout<<"THE END\n";

}