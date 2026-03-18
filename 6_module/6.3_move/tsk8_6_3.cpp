//
// Created by NandanRaj on 13-03-2026.
//
#include<iostream>
#include<vector>
#include<string>
class Wrapper {
public:
    std::vector<int> v;
    std::string label;

    Wrapper(std::string s,std::initializer_list<int> il):v(il),label(std::move(s)) {}
    void print(const char* tag) const {
        std::cout<<tag<<"Label: "<<(label==""?"EMPTY":label)<<" | data: ";
        if (!v.data())
            std::cout<<"EMPTY";
        else {
            for (const auto &x : v) std::cout << x << " ";
        }
        std::cout << " \n[data@ " << v.data() << "]" << std::endl;

    }
};
int main() {
    Wrapper w1("first",{1,2,3});
    w1.print("w1: ");
    Wrapper w2=w1;// copy
    w2.label = "copy";
    w2.print("w2: ");
    // Wrapper w3("third",{3,4,5});
    // w3=w2;

    Wrapper w3 = std::move(w1); // Move
    w3.label = "moved";
    w3.print("w3:");
    w1.print("w1 after move:"); // w1's data is valid but unspecified (empty/moved-from)


}