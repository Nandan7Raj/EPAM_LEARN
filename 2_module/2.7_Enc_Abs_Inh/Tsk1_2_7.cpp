//
// Created by NandanRaj on 05-02-2026.
//

#include <iostream>

// BankAccount class representing a simple bank account
class BankAccount {
    int account_number;     // Stores account number (private for encapsulation)
    double balance = 0;     // Stores account balance (default = 0)

public:
    // Constructor to initialize account number
    BankAccount(int acc_no) {
        account_number = acc_no;
    }

    void deposit(double amount);   // Function to deposit money
    void withdraw(double amount);  // Function to withdraw money
    void getBalance() const;       // Displays current balance (does not modify object)
};

// Deposit money into account
void BankAccount::deposit(double amount) {
    if (amount <= 0)
        std::cout << "Deposited unsuccessful! \nHow can you deposit non-positive amount\n";
    else {
        balance += amount;   // Add amount to balance
        std::cout << "Deposited successful " << amount << "\n";
    }
}

// Withdraw money from account
void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Withdraw unsuccessful! \nHow can you withdraw non-positive amount\n";
    }
    else if (balance <= amount) {   // Check if enough balance is available
        std::cout << "Withdraw unsuccessful! \n Insufficient Balance\n" << amount << "\n";
    }
    else {
        balance -= amount;   // Deduct amount from balance
        std::cout << "Withdraw successful " << amount << "\n";
    }
}

// Display account balance (const ensures no modification)
void BankAccount::getBalance() const {
    std::cout << "Account Balance: " << balance << "\n";
}

int main(int argc, char const *argv[]) {

    BankAccount b1(1234);   // Create bank account object

    b1.deposit(1000);       // Deposit money
    b1.getBalance();        // Display balance

    b1.withdraw(100);       // Withdraw money
    b1.getBalance();

    b1.deposit(-2300);      // Invalid deposit
    b1.getBalance();

    b1.withdraw(0);         // Invalid withdrawal
    b1.getBalance();

    // Below lines will cause error because members are private
    // std::cout << b1.account_number << std::endl;
    // std::cout << b1.balance = 2000 << std::endl;
}
