//
// Created by NandanRaj on 06-02-2026.
//
#include <iostream>
#include <vector>

class Payment {
    public:
    virtual void processPayment(double amount)=0;

};
class CreditCardPayment:public Payment {
    public:
    void processPayment(double amount) override{
        std::cout<<"Processed the credit card payment of Rs: "<<amount<<std::endl;
    }
};
class PayPalPayment:public Payment {
    void processPayment(double amount) override{
        std::cout<<"Processed the PayPal payment of Rs: "<<amount<<std::endl;
    }
};
int main() {
    std::vector<Payment*> payments;//vector of pointers of type Payment(parent)
    payments.push_back(new CreditCardPayment{});// obj of derived class
    payments.push_back(new PayPalPayment{});// obj of derived class
    for (auto ptr:payments) {
        ptr->processPayment(100);
    }
    // here both obj is pointed by using pointer of type Payments
    //no need to know the concrete class type—only the interface.

}