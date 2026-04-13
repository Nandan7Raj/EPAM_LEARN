//
// Created by NandanRaj on 10-04-2026.
//
#include <chrono>
#include <iostream>
#include<map>
#include<unordered_map>
#include <vector>
#include<type_traits>
// --- Configuration Constants ---
const int NUM_WORDS=100000;
const int NUM_LOOKUP_TESTS=10000;
const int NUM_NONEXISTENT_WORDS=10000;

// --- Type Aliases for Readability ---
using WordVector = std::vector<std::string>;
using MilliSeconds = std::chrono::duration<double, std::milli>;

template<typename F>
double measureTime(const std::string& s,F func) {
    auto start=std::chrono::high_resolution_clock::now();
    auto end=std::chrono::high_resolution_clock::now();
    MilliSeconds duration_ms = end - start;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << " " << std::left << std::setw(35) << s + ":" << duration_ms.count() << " ms" << std::endl;
    return duration_ms.count();
}

WordVector generateWords(int count, const std::string& prefix) {
    WordVector words;
    words.reserve(count);
    for (int i = 0; i < count; ++i) {
        words.push_back(prefix + std::to_string(i));
    }
    return words;
}

template <typename MapType>
void conditionallyReserve(MapType& map, size_t count) {
    if constexpr (std::is_same_v<MapType, std::unordered_map<std::string, int>>) { // Only call reserve if it's an unordered_map
        map.reserve(count);
        std::cout << " (Reserved " << count << " buckets for unordered_map)" << std::endl;
    }
}

template<typename MapType>
void benchmarkContainer(const std::string& container_name, const WordVector& words_to_insert, const WordVector& non_existent_words) {
    MapType my_container;
    conditionallyReserve(my_container,words_to_insert);
    measureTime("Insertion", [&]() {
        for (int i = 0; i < words_to_insert.size(); ++i) {
            my_container[words_to_insert[i]] = i;
        }
    });

    // 2. Lookup Time (Existing Keys). Use volatile to prevent compiler from optimizing away the find calls entirely volatile
    int found_count = 0;
    measureTime("Lookup (Existing Keys)", [&]() {
        for (int i = 0; i < NUM_LOOKUP_TESTS; ++i) { // Using find() is crucial as operator[] would insert if not found
            auto it = my_container.find(words_to_insert[i]);
            if (it != my_container.end()) {
                found_count++; // Increment to prevent optimization
                }
        }
    }
    );

    // 3. Lookup Time (Non-Existing Keys) volatile
    int not_found_count = 0;
    measureTime("Lookup (Non-Existing Keys)", [&]() {
        for (int i = 0; i < NUM_NONEXISTENT_WORDS; ++i) {
            auto it = my_container.find(non_existent_words[i]);
            if (it == my_container.end()) {
                not_found_count++;// Increment to prevent optimization
            }
        }
    });


}
