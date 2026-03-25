//
// Created by NandanRaj on 18-03-2026.
//
#include<iostream>
static int counter=0;
class IntArray {
    size_t siz;
    int * arr;


public:
    IntArray(const size_t size):arr(new int[siz]),siz(size) {
        std::cout<<"CONSTRUCTOR: heap memory allocated to array @ "<<arr<<"\n";
        counter++;
        for (int i=0;i<siz;i++) arr[i]= i+1;
    }
    ~IntArray() {
        std::cout<<"DESTRUCTOR: freeing memory @ "<<arr<<std::endl;
        delete[] arr;
        counter--;
    }
    friend std::ostream& operator<<(std::ostream& out,const IntArray& intarr) {
        for (int i=0;i<intarr.siz;i++)
            out<<intarr.arr[i]<<" ";
        out<<std::endl;
        return out;
    }

    int& operator[](const size_t i) const {return arr[i];}
    [[nodiscard]] size_t getSize() const { return siz;}

};

void testEarlyReturn() {
    IntArray ar{5};
    ar[0]=23;
    std::cout<<"testEarlyReturn: value[0] = "<<ar[0]<<std::endl;
    return; // Destructor will be called automatically
}
void testException() {
    IntArray a(5);
    throw std::runtime_error("Oops! Exception triggered.");
}
int main() {
    try {
        IntArray ar1(4);
        std::cout<<"Normal usage: value[1] = "<<ar1[1]<<std::endl;
    }
    catch (...){}

    std::cout<<"Now testing Early Return\n";
    testEarlyReturn();

    std::cout<<"Now Testing Exception\n";
    try {
        testException();
    }
    catch (const std::exception& ex) {
        std::cerr<<"Exception: "<<ex.what()<<std::endl;
    }
    std::cout<<" Value of counter :"<<counter<<"\n"
    <<" if it is zero then it shows that all constructor had destructor\n";
    std::cout<<"END OF MAIN\n";

}