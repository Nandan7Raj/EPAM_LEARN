//
// Created by NandanRaj on 19-02-2026.
//
#include <complex>
#include <iomanip>
#include <iostream>
#include <set>

#include<string>
static std::set<std::string> AccountDataBase;
    class InsufficientFundsException: public std::runtime_error {
        std::string accountNumber;
        double currentBalance;
        double requestedAmount;
        std::string msg;
    public:
        InsufficientFundsException(const std::string& accountNumber, const double& currentBalance, const double& requestedAmount):
            std::runtime_error("Insufficient Fund"),msg(build_msg(accountNumber,currentBalance,requestedAmount)),
            accountNumber(accountNumber), currentBalance(currentBalance),requestedAmount(requestedAmount){}

        static std::string build_msg(const std::string& accountNumber, double currentBalance, double requestedAmount) {
            return "Insufficient fund in "+accountNumber+".\nCurrent Balance: "+ std::to_string(currentBalance)+"\nRequired Balance: "+std::to_string(requestedAmount);
        }
        [[nodiscard]] const char* what() const noexcept override  {
            return msg.c_str();
        }
    };
class InvalidAmountException: public std::invalid_argument {
    double amount;
    std::string operation;
    std::string msg;
    public:
    InvalidAmountException(const std::string& operation, const double& amount):
    std::invalid_argument("Invalid amount"),msg(build_msg(operation,amount)), operation(operation), amount(amount){}

    static std::string build_msg(const std::string& operation, const double& amount) {
        return "Can't do "+operation+" for amount "+std::to_string(amount);
    }
    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }

};

class AccountNotFoundException: public std::out_of_range {
    std::string accountNumber;
    std::string msg;
public:
    explicit AccountNotFoundException(const std::string& accountNumber):
    std::out_of_range("Account Not Found"),msg(build_msg(accountNumber)),accountNumber(accountNumber){}
    static std::string build_msg(const std::string& accountNumber) {
        return "Account No. "+accountNumber+" is not found";
    }
    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }
};

class TransectionLimitExceededException:public std::logic_error {
    double amount;
    double limit;
    std::string msg;
public:
    explicit TransectionLimitExceededException(const double& amount , const double& limit):
    std::logic_error("Tranction limit Exceeded"),msg(build_msg(amount ,limit)),amount(amount),limit(limit){}
    static std::string build_msg(const double& amount,const double& limit) {
        return "Can not do transection of amount "+std::to_string(amount)+" as daily limit "+std::to_string(limit)+" reached";
    }
    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }
};

class BankSystemException:public std::runtime_error {
    std::string component;
    std::string error;
    std::string msg;
public:
    BankSystemException(const std::string& component,const std::string& error):std::runtime_error("Bank System  Error"),
    component(component),error(error),msg(build_str(component,error)){}
    static std::string build_str(const std::string& component,const std::string& error) {
        return "Error: "+error+" in component "+component;
    }
    const char* what() const noexcept override {
        return msg.c_str();

    }

};

//BankAccount Class
class BankAccount {
    std::string accountNumber;
    std::string holderName;
    double balance;
    double dailyWithdrawlLimit;
    double dailyWithdrawlAmount=0;
    void validateAmount(double amount, const std::string& operation) const {
        if (amount<0)
            throw InvalidAmountException(operation,amount);
        if (std::isnan(amount)|| std::isinf(amount))
            throw std::invalid_argument("Invalid amount type");
    }
public:
    BankAccount(){};// non parametrized constructor

    BankAccount(const std::string& accountNumber,const std::string& holderName,const double& balance,const double& dailyWithdrawlLimit ):
    accountNumber(accountNumber),holderName(holderName),balance(balance),dailyWithdrawlLimit(dailyWithdrawlLimit)
    {
        if (AccountDataBase.find(accountNumber)!=AccountDataBase.end()) {
            throw std::logic_error("Account No "+accountNumber+" is not available. Already Used");
        }
        if (balance<0)
            throw InvalidAmountException("Creating Account",balance);
        if (accountNumber.empty()|| holderName.empty())
            throw std::invalid_argument("account no. or holder name is empty");
        AccountDataBase.insert(accountNumber);
        std::cout<<"A Bank account created successfully.\n";
    }
    void deposit(double amount) {
        validateAmount(amount , "deposit");
        if (amount>1000000)
            throw BankSystemException("deposit machine","Very Very large amount");
        balance+=amount;
        std::cout<<"Deposit successful for "+holderName+"\n";
    }

    void withdraw(const double&amount) {
        validateAmount(amount,"withdraw");
        if (amount>balance) {
            throw InsufficientFundsException(accountNumber,balance,amount);
        }
        if (dailyWithdrawlAmount+amount>dailyWithdrawlLimit) {
            throw TransectionLimitExceededException(amount,dailyWithdrawlLimit);
        }
        if (amount>100000) {
            throw BankSystemException("withdraw process","Fraud Detection");
        }
        balance-=amount;
        dailyWithdrawlAmount+=amount;
        std::cout<<"Withdraw successful for "+holderName+"\n";
    }

    void  transferTo(BankAccount& recipient,const double&amount) {
        if (AccountDataBase.find(accountNumber)==AccountDataBase.end())
            throw AccountNotFoundException(recipient.getAccountNumber());
        validateAmount(amount,"transfer");
        if (recipient.accountNumber==this->accountNumber)
            throw std::logic_error("Error due to self transfer");
        if (amount>balance) {
            throw InsufficientFundsException(accountNumber,balance,amount);
        }
        recipient.deposit(amount);
        balance-=amount;
        std::cout<<"Transfer successful from "+holderName+" to "+recipient.getHolderName()+"\n";
    }
    //Getters
    [[nodiscard]]std::string getAccountNumber() const {
        return accountNumber;
    }
    [[nodiscard]] std::string getHolderName() const {
        return holderName;
    }
    [[nodiscard]] double getBalance() const {
        return balance;
    }
    [[nodiscard]] double getDailyWithdrawLimit() const {
        return dailyWithdrawlLimit;
    }
    [[nodiscard]] double getDailyWithdrawn() const {
        return dailyWithdrawlAmount;
    }
    void printAccountInfo() const {
        std::cout<<"Account info:\n";
        std::cout<<"Account holder Name: "<<holderName<<"\n"
        <<"Balance: "<<balance<<"\n"
        <<"Daily withdraw Limit: "<<dailyWithdrawlLimit<<"\n"
        <<"Already Withdrawn amount per the day: "<<dailyWithdrawlLimit-dailyWithdrawlAmount<<"\n"
        <<"Available withdrawable amount per the day: "<<dailyWithdrawlAmount<<"\n";
    }

};

int main(int argc, char *argv[]) {
    try {
        BankAccount customer1{"1234","Nandan",0,50000};
        BankAccount customer2{"2345","Abhijeet",0,50000};
        customer1.deposit(70000);
        customer1.withdraw(20000);
        // customer1.transferTo( {"2345","Abhijeet",0,50000},500);// it will  work when func will have && to accept rvalue but we have & only so l value
        customer1.transferTo(customer2,5000);

        // Duplicate account creation (logic_error)
        BankAccount customer3("1234","Govind",0,50000);
        //Insufficient funds (InsufficientFundsException)
        customer1.withdraw(80000);

        //Invalid amount (InvalidAmountException)
        customer1.deposit(-7000);

        //print info
        customer1.printAccountInfo();

        //Account not found (AccountNotFoundException)
        BankAccount customer4;
        customer1.transferTo(customer4,200);

        //Transaction limit exceeded
        customer1.withdraw(40000);

        //System errors (BankSystemException for large transactions)
        customer1.deposit(1000400);

    }
    catch (const InsufficientFundsException&e) {
        std::cout<<e.what()<<std::endl;
    }
    catch (const InvalidAmountException& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (const AccountNotFoundException& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (const TransectionLimitExceededException& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (const BankSystemException& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (const std::logic_error& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    catch (...) // Catch-all last
    {
        std::cout<<"Unknown Exception"<<std::endl;
    }

}
