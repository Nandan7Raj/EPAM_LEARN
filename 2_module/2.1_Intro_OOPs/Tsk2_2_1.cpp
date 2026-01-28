//
// Created by NandanRaj on 28-01-2026.
//
#include <iostream>
using namespace std;
// BankAccount class definition
class BankAccount {
private:
    int accountNumber;  // NOT accessible outside class
    double balance;     // NOT accessible outside class

    protected:
    string ownerName; //Accessible in derived class

    public:
    //constructor
    BankAccount(int accountNumber, double balance,string name) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->ownerName = name;
    }
    // func declearation
    void deposit(double amount);   // deposit money
    void withdraw(double amount); // withdraw money
    void getBalance();// check balance

};
class VIPAccount : public BankAccount {// derived class
public:
    VIPAccount(int accNo,double bal, string name):BankAccount(accNo,bal,name){}// base constructor needed to initialize
    void printOwnername() {
        //Allowed (protected member)
        cout<<"Owner of this VIP Account is : "<<ownerName<<endl;
        //NOT allowed (private members)
        // cout << accountNumber;   // ERROR
        // cout << balance;         // ERROR
    }

};
int main(int argc, char *argv[]) {
    BankAccount acc(1234,0,"Nandan");// create object of BankAccount
    VIPAccount vip(5678,0,"Ambani");// create object of VIPAccount
    // Test the functionalities
    acc.deposit(2000);
    acc.withdraw(3000);
    acc.withdraw(1000);
    acc.getBalance();
    // Accessing VIPAccount functionality to print owner name i.e. protected member
    vip.printOwnername();

    // Compilation errors (ENCAPSULATION)
    // cout << acc.balance;
    // cout << acc.accountNumber;
    // cout << acc.ownerName;


}
//deposit funct definition
void BankAccount::deposit(double amount) {
    balance += amount;
    cout<<"Deposit SUCCESSFUL"<<endl;
    cout<<"Balance after depositing : "<<balance<<endl;
}
// Withdraw func definition
void BankAccount::withdraw(double amount) {
    if (balance<amount) {// check for sufficient balance
        cout<<"Insufficient balance to withdraw."<<endl;
        return;
    }
    balance-=amount;
    cout<<"Withdraw SUCCESSFUL"<<endl;
    cout<<"Balance after withdrawning : "<<balance<<endl;
}
// getBalance func definition
void BankAccount::getBalance() {
    cout<<"Your current Balance is "<<balance<<endl;
}
