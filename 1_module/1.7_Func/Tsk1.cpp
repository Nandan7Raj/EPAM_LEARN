//
// Created by NandanRaj on 25-01-2026.
#include<iostream>
using namespace std;
// Global balance (simulates a simple bank account)
static float balance = 0.0;



// Validate withdrawal amount
bool isValidWithdrawal(float amount) {
    if (amount <= 0) {
        cout << "Withdrawal amount must be greater than zero!" << endl;
        return false;
    }
    if (amount > balance) {
        cout << "Insufficient funds! Current Balance: " << balance << endl;
        return false;
    }
    return true;
}

void deposit(float amount) // Function to deposit money
{
    balance += amount; // Update balance
    cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
}

void withdraw(float amount) // Function to withdraw money
{
   if (!isValidWithdrawal(amount))
        return;

        balance -= amount; // Update balance
        cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;

}
float checkBalance() // Function to check balance
{
    return balance;
}
int main() {
    cout << "Welcome to the Bank Management System!" << endl;
    int choice;
    do { // Menu-driven interface
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nEnter your choice: ";
        cin >> choice;

        if(cin.fail()) {
            cin.clear(); // clear the fail state
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 4." << endl;
            continue;
        }
        switch(choice) {
            case 1: { // Deposit
                float amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if(cin.fail()) {
                    cin.clear(); // clear the fail state
                    cin.ignore(1000, '\n'); // discard invalid input
                    cout << "Invalid input! Please enter a valid amount." << endl;
                    break;
                }
                if(amount <= 0) // Validate deposit amount
                {
                    cout << "Deposit amount must be positive!" << endl;
                }
                else
                {
                deposit(amount);
                }
                break;
            }
            case 2: { // Withdraw
                float amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if(cin.fail()) {
                    cin.clear(); // clear the fail state
                    cin.ignore(1000, '\n'); // discard invalid input
                    cout << "Invalid input! Please enter a valid amount." << endl;
                    break;
                }

                withdraw(amount);
                break;
            }
            case 3: // Check Balance
                cout << "Current Balance: " << checkBalance() << endl;
                break;
            case 4: // Exit
                cout << "Exiting the system. Thank you!" << endl;
                break;
            default: // Invalid choice
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 4);

    return 0;
}