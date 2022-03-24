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

/*
Method that displays the overall menu that will be 
repeated after every single user input
*/
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

/*
Gets the menu input choice from the user every single time
that they DONT pick the max variable (in this case, 7)
*/
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

/*
Method to make a deposit on the passed Account reference variable
*/
void makeDeposit(Account& acct)
{   
    double depositAmt; 

    cout << "Deposit Amount: ";
    cin >> depositAmt;
    cin.ignore();

    acct.makeDeposit(depositAmt);
};

/*
Method to withdraw a certain amount of money from the 
passed Account reference variable.
Validates if the user has enough money to withdraw, if they don't,
output an error and do nothing. 
*/
void withdraw(Account& acct)
{
    double withdrawAmt;

    cout << "Withdraw Amount: ";
    cin >> withdrawAmt;
    cin.ignore();

    if (!(acct.makeWithdrawl(withdrawAmt)))
        cout << "ERROR: Withdrawl amount too large.\n\n";
};