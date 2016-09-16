#include<iostream>
#include<fstream>
#include<string.h>

#include <cstdlib> // used to exit
using namespace std;

//void transact();
class Transaction;

class Menu : public Transaction
{
protected:
    string userID; //User ID: It can be contained string characters
    int pwd; //Password: It must contain only integer numbers
    int option1;
public:
    Transaction txn;
    void selectMenu()
    {
        cout << "1 - Login \n2 - Create New Account \n3 - Quit\n";
        cin >> option1;
        switch(option1)
        {
        case 1:
            cout << "---Login---\n\n";
            cout << "Enter User ID: ";
            cin >> userID;
            cout << "\nEnter Password: ";
            cin >> pwd;
            txn.transact();
            break;
        case 2:
            cout << "---Create New Account---\n\n";
            cout << "Enter User ID: ";
            cin >> userID;
            cout << "\nEnter the password: ";
            cin >> pwd;
            cout << "\n Re-enter the password: ";
            cin >> pwd;
            txn.transact();
            break;
        case 3:
            cout << "~~Thank You! Come Again!~~\n\n";
            break;
        default:
            cout << "--INVALID INPUT!-- \n ---PLEASE CHECK AGAIN!---";
            break;
        }
    }

};

class Transaction
{
    private:
        double deposit;
        double withdraw;
        double balance;
        int option2;
    public:
        void transact()
        {
            switch (option2)
            {
            case 1:
                cout << "Enter the amount of deposit: " << deposit << endl;
                cin >> deposit;
                cout << "You have successfully deposited "<< deposit << "!\n";
                balance = balance + deposit;
                break;
            case 2:
                cout << "Enter the amount of withdraw: "<< withdraw << endl;
                cin >> withdraw;
                cout << "You have successfully withdrawn "<< withdraw << "!\n";
                balance = balance - withdraw;
                break;
            case 3:
                cout << "Your remaining balance is: " << balance << endl;
                break;
            default:
                cout << "INVALID INPUT! \n PLEASE CHECK AGAIN!"
            }
        }
};

/*int main()
{
    cout << "Hi! Welcome to ATM Machine!\n\n";
    cout << "Please select an option from the menu below: \n";
    Menu obj;
    obj.selectMenu();
    return 0;
}*/


int main()
{
    cout << "Hi! Welcome to ATM Machine!\n\n";
    cout << "Please select an option from the menu below: \n";
    Menu obj;
    obj.selectMenu();

    Transaction txn;
    txn.transact();

  /*  ifstream accInFile;
    ofstream accOutFile;

    accInFile.open("account_1.txt");

    char input;
    if (!accInFile.fail())
        {
        cout << " overwrite with the new data (y or n): ";
        cin >> input;
        if (tolower(input) == 'n')
            {
            cout << "The existing file will not be overwritten." << endl;
            exit(1);
            }
        }
        accOutFile.open("account_1.txt");


    accOutFile.open("account_1.txt");
    if (accInFile.fail())
            {
            cout << "\nThe file was not successfully opened"
            << endl;
            exit(1);
            }
            cout << "The file has been successfully opened for output."
            << endl;*/
return 0;
}
