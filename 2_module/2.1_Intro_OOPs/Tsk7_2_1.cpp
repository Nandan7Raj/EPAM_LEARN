//
// Created by NandanRaj on 29-01-2026.
//
#include <iostream>
using namespace std;
#define SQUARE(x) x*x // macro defined -> handled during preprocessing

class Math{
public:
// inline function defined-> handled during compilation so it is type checked and scope checked
static inline int square(int x) {
    return x*x;
}
};

int main() {
    int macro_value,inline_value;
    cout<<"For simple integer say 3"<<endl;
    // first checking macro SQUARE(x)
    macro_value=SQUARE(3);
    cout<<"By using macro SQUARE(3) = "<<macro_value<<endl;
    // now inline func
    inline_value=Math::square(3);
    cout<<"By using inline function square(2+3) = "<<inline_value<<endl;
    //above macro_value = inline_value
    cout<<"Same value? "<<((macro_value == inline_value)?"YES":"NO")<<endl<<endl;


    cout<<"For Expressions say 2+3"<<endl;
    // it will not give 25 but 11 as it will work like 2+3*2+3=2+6+3=11
    macro_value=SQUARE(2+3);
    cout<<"By using macro SQUARE(2+3) = "<<macro_value<<endl;
    // Now inline function
    // compiler may replace the function call with the function body.
    // it will give correct value i.e 25 as func will get 5 i.e 2+3 as parameter
    inline_value=Math::square(2+3);
    cout<<"By using inline function square(2+3) = "<<inline_value<<endl;
    cout<<"Same value? "<<((macro_value == inline_value)?"YES":"NO")<<endl;

    //TYPE SAFETY
    //SQUARE("Hello"); not type safe as--> No error during macro expansion
    //square("Hello"); type safe --> compile-time error





}