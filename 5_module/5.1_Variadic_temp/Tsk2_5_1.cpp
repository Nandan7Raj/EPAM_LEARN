//
// Created by NandanRaj on 27-02-2026.
//
#include<iostream>
#include <tuple>
#include <string>
template<typename...Args>
class MyTuple{
    std::tuple<Args...> data;
    template<std::size_t N>
    void printHelper() const {
        if constexpr  (N<sizeof...(Args)) {// why constexpr
            std::cout<<std::get<N>(data)<<" "; // for templet function the its construction is done at compile time and at compile time
                                               // if statement is doesn't cared but if constexpr mentioned then checked at compile time
            printHelper<N+1>();
        }
    }
public:
    //constructor
    MyTuple(Args...args):data(args...){}
     void print() const {
        printHelper<0>();
        std::cout<<std::endl;
    }
};
int main() {
    MyTuple<int,double,std::string> t(2,2.34,"Nandan");
    t.print();
}