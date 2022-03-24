#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    private:
        double balance;
        double interestRate;
        double interest;
        int numOfTransactions;
    public:
        Account(double rate = 0.045, double bal = 0.0);
        void setBalance(double bal);
        void makeDeposit(double amt);
        void calcInterest();
        bool makeWithdrawl(double amt);
        double getBalance();
        double getInterest();
        int getTransactions();
};

//constructor
Account::Account(double rate, double bal) : interestRate(rate), balance(bal), interest(0), numOfTransactions(0) {};

void Account::makeDeposit(double amt) 
{
    balance += amt;
    numOfTransactions++;
};

void Account::calcInterest()
{
    interest = balance *interestRate;
    balance += interest;
}

bool Account::makeWithdrawl(double amt)
{
    if (balance < amt)
        return false; 
    //if enough funds, do the withdrawl
    else 
    {
        balance -= amt;
        numOfTransactions++;
        return true;
    }
};

double Account::getBalance() { return balance; };
double Account::getInterest() { Account::calcInterest(); return interest; };
int Account::getTransactions() { return numOfTransactions; };

#endif 