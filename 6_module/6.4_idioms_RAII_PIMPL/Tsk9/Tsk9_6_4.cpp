//
// Created by NandanRaj on 20-03-2026.
//
#include"Tsk9_6_4.h"
// all heavy inclusion here
#include <map>
#include <vector>
#include<string>
#include<iostream>
struct BigData::Impl {
    std::vector<int> vec;
    std::map<std::string,int> mp;
    std::string name;

    // constructor
    Impl():vec(1e8,7),name("BIGDATA"),mp({{"First",1}}){
        std::cout << "[BigData::Impl] constructed with heavy data\n";
    }
    ~Impl() {
        std::cout << "[BigData::Impl] destroyed\n";
    }
};

BigData::BigData():impl(std::make_unique<Impl>()) {}
BigData::~BigData()=default;

void BigData::process() {
    impl->vec[0]=10;
    impl->mp["process"]=4;
    std::cout << "Processing " << impl->name << ": " << impl->vec[0] << std::endl;
}

size_t BigData::getSize() const {
    return impl->vec.size();
}