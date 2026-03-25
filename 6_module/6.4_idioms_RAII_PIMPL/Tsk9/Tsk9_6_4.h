//
// Created by NandanRaj on 20-03-2026.
//

#ifndef TSK9_6_4_H
#define TSK9_6_4_H
#include<memory>
#include <iostream>
class BigData {
    struct Impl; // Forward declaration only!
    std::unique_ptr<Impl> impl;
public:
    BigData();
    ~BigData();

    void process();
    size_t getSize() const;
};

#endif //TSK9_6_4_H