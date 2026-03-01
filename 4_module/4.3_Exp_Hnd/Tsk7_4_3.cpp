//
// Created by NandanRaj on 23-02-2026.
//
#include <cmath>
#include<iostream>
#include<string>
class BankAccount {
    std::string owner;
    int accountNumber;
    double balance;
public:
    BankAccount(const std::string& owner,const int& accountNumber,const double&balance):
    owner(owner),accountNumber(accountNumber),balance(balance){}

    void deposit(const double& amount) {
        if (amount<0)
            throw std::invalid_argument("Deposit amount can not be negative");
        balance+=amount;
        std::cout<<"Deposit successful\n";
    }

    void withdraw(const double& amount) {
        if (amount<0)
            throw std::invalid_argument("Withdraw amount can not be negative");
        if (amount>balance)
            throw std::runtime_error("Insufficient fund");
        balance-=amount;
        std::cout<<"Withdraw successful\n";
    }

    bool transferTo(BankAccount& targetAccount, const double& amount) noexcept{
        if (amount<0 ||amount>balance) {
            return false;
        }
        targetAccount.deposit(amount);
        return true;
    }

    [[nodiscard]]double getBalance() const{
       return balance;
    }
    void print() const {
        std::cout<<"Account Details:"
        <<"\nAccount Owner: "<<owner
        <<"\nAccount No.:"<<accountNumber
        <<"\nBalance: "<<balance<<std::endl;
    }
};
int main() {
    BankAccount Nandan("Nandan",1001,500),Abhishek("Abhishek",1002,300);
    std::cout<<"\n//////////////// First we will check deposit ////////////////\n";
    try {
        Nandan.deposit(1000);
        Nandan.print();
        Nandan.deposit(-100);
    }
    catch (const std::invalid_argument& e) {
        std::cout<<"Deposit error: "<<e.what()<<std::endl;
    }
    Nandan.print();

    std::cout<<"\n////////// Now, we will attempt Withdraw ////////////\n";
    try {
        Nandan.withdraw(500);
        Nandan.print();
        Nandan.withdraw(3000);
    }
    catch (const std::invalid_argument& e) {
        std::cout<<"Withdraw error: "<<e.what()<<std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout<<"Withdraw error: "<<e.what()<<std::endl;
    }
    Nandan.print();
    std::cout<<"\n/////////////////// Now we will try Transfer ////////////////\n";
        std::cout<<"\nBefore Transfer.........\n";
        Nandan.print();
        Abhishek.print();
        if (Nandan.transferTo(Abhishek,1000)) {
            std::cout<<"Transfer Successful.\n";
        }
        else
            std::cout<<"Transfer Unsuccessful\n";
        Nandan.print();
        Abhishek.print();
        if (Nandan.transferTo(Abhishek,-200)) {
            std::cout<<"Transfer Successful.\n";
        }
        else
            std::cout<<"Transfer Unsuccessful\n";
        Nandan.print();
        Abhishek.print();


}