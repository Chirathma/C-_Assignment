#include<iostream>
#include<fstream>
#include<string.h>
#include <cstdlib> // used to exit
using namespace std;

class Account
{
private:
    string userId;
    double balance;
public:
    Account(string id, double balanceValue)
    {
        userId = id;
        balance = balanceValue;
    }
    double getBalance ()
    {
        return balance;
    }
    void deposit(double amount)
    {
        balance += amount;
    }

    bool withdraw(double amount)
    {
        if(amount < balance)
        {
            balance -= amount;
            return true;
        }
        else
        {
            return false;
        }
    }
};

//selecting main menu
class Menu
{
private:
    string userID; //User ID: It can be contained string characters
    int pwd; //Password: It must contain only integer numbers
    int option, option1; //used as the switch-case operator
    double withdrawValue;
    double depositValue;
    double balance;

    Account* login()
    {
        cout << "---Login---\n\n";
        cout << "Enter ID: ";
        cin >> userID;
        cout << "\nEnter Password: ";
        cin >> pwd;

        //Read the file named userID
        //Match password
        //If password is correct, create an Account object
        double balance = 1500;
        Account account(userID, balance);
        return &account;
    }

    /*void transact(Account* account)
    {
        cout<< "\nEnter your requirement: "
            << "\nBalance-'1'\t Deposit-'2'\t Withdraw-'3'\n";
        cin>> option;
        switch(option)
        {
            case 1:
                balance = account->getBalance();
                cout<< "\nYour balance is  "<<balance<< endl;
                break;

            case 2:
                cout<< "\nEnter the amount of deposit: ";
                cin>> depositValue;
                account->deposit(depositValue);
                break;

            case 3:
                cout<< "\nEnter the amount of withdraw: ";
                cin>> withdrawValue;
                account->withdraw(withdrawValue);
                break;

            default:
                cout<< "\n--INVALID INPUT !!!--\n";
        }
    }*/

    void createAcc()
    {
        cout << "---Create New Account---\n\n";
        cout << "Enter User ID: ";
        cin >> userID;
        cout << "\nEnter the password: ";
        cin >> pwd;
        cout << "\n Re-enter the password: ";
        cin >> pwd;
    }

    void quitAcc()
    {
        cout << "~~Thank You! Come Again!~~\n\n";
    }

public:
    void selectMenu()
    {
        cout << "1 - Login \n2 - Create New Account \n3 - Quit\n";
        cin >> option1;
        //Account* accountPointer;//=login();
        int option;
        switch (option1)
        {
        case 1:
        {
            Account* accountPointer= login();
            cout << accountPointer->getBalance();
            if(accountPointer != NULL)
            {
                cout<< "\nEnter your requirement: "
                    << "\nBalance-'1'\t Deposit-'2'\t Withdraw-'3'\n";
                cin>> option;
                switch(option)
                {
                case 1:
                {
                    balance = accountPointer->getBalance();
                    cout<< "\nYour balance is  "<<balance<< endl;
                }
                break;

                case 2:
                    cout<< "\nEnter the amount of deposit: ";
                    cin>> depositValue;
                    accountPointer->deposit(depositValue);
                    break;

                case 3:
                    cout<< "\nEnter the amount of withdraw: ";
                    cin>> withdrawValue;
                    accountPointer->withdraw(withdrawValue);
                    break;

                default:
                    cout<< "\n--INVALID INPUT !!!--\n";
                }
            }
        }
        break;

        case 2:
            createAcc();
            break;

        case 3:
            quitAcc();
            break;

        default:
            cout << "--INVALID INPUT!-- \n ---PLEASE CHECK AGAIN!---";
            break;
        }
    }
};

int main()
{
    cout << "Hi! Welcome to ATM Machine!\n\n";
    cout << "Please select an option from the menu below: \n";
    Menu obj;
    obj.selectMenu();

    return 0;
}
