//
// Created by NandanRaj on 11-03-2026.
//
#include<iostream>
#include<vector>
#include<algorithm>
struct Square {
    void operator()(int&x) const {
        x*=x;
    }
};
int main() {
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{1, 2, 3, 4, 5};

    auto sqr=[](int &x) {
        x*=x;
    };

    std::for_each(v1.begin(),v1.end(),Square{});
    std::for_each(v2.begin(),v2.end(),sqr);

    std::cout << "Squared by functor: ";
    for (auto x : v1) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "Squared by lambda:  ";
    for (auto x : v2) std::cout << x << " ";
    std::cout << std::endl;

    // Discussion:
    // - Lambdas are more concise and local for one-off operations.
    // - Functors allow reusability, state, and can be more explicit, possibly benefiting inlining/optimization.
    // - In most modern C++ code, lambdas are preferred for clarity and brevity unless stateful or reusable logic is needed.
}