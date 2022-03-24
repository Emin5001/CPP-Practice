#include <iomanip>
#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

void displayMenu();
char getChoice(char);
void makeDeposit(Account&);
void withdraw(Account&);

int main()
{
    const char MAX_CHOICE = '7';
    char choice;
    Account savings;

    cout << fixed << showpoint << setprecision(2);

    do
    {
        displayMenu();
        choice = getChoice(MAX_CHOICE);
        cout << "\n";
        switch(choice)
        {
            case '1':
                cout << "The accounts balance is " << savings.getBalance() << ".\n";
                break;
            case '2':
                cout << "The number of transactions is " << savings.getTransactions() << ".\n";
                break;
            case '3':
                cout<< "The interest earned is " << savings.getInterest() << ".\n";
                break;
            case '4':   
                makeDeposit(savings);
                break;
            case '5':
                withdraw(savings);
                break;
            case '6':
                savings.getInterest();
                break;
        };
    } while (choice != MAX_CHOICE);
    
    
    return 0;
};

void displayMenu()
{
    cout << "\n\n            MENU\n\n";
    cout << "1) Display the current account balance.\n";
    cout << "2) Display the number of transactions.\n";
    cout << "3) Display interest earned in this period.\n";
    cout << "4) Make a deposit.\n";
    cout << "5) Make a withdrawl.\n";
    cout << "6) Add interest for this period.\n";
    cout << "7) Exit this program.\n";
    cout << "Enter your choice: ";
}

char getChoice(char max)
{
    char choice = cin.get();
    cin.ignore();
    while (choice < '1' || choice > max)
    {
        cout << "Choice must be between 1 and " << max << ".\n";
        cout << "Please re-enter choice: ";
        choice = cin.get();
        cin.ignore();
    }

    return choice;
};

void makeDeposit(Account& acct)
{   
    double depositAmt; 

    cout << "Deposit Amount: ";
    cin >> depositAmt;
    cin.ignore();

    acct.makeDeposit(depositAmt);
};

void withdraw(Account& acct)
{
    double withdrawAmt;

    cout << "Withdraw Amount: ";
    cin >> withdrawAmt;
    cin.ignore();

    if (!(acct.makeWithdrawl(withdrawAmt)))
        cout << "ERROR: Withdrawl amount too large.\n\n";
};