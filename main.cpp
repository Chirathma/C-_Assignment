#include <iostream>
#include <string>
using namespace std;


class Menu
{
private:
    string userID; //User ID: It can be contained string characters
    int pwd; //Password: It must contain only integer numbers
    int option1;

    void login()
    {
        cout << "---Login---\n\n";
        cout << "Enter User ID: ";
        cin >> userID;
        cout << "\nEnter Password: ";
        cin >> pwd;
    }
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
    int option;
    string acc_no;

    void select()
    {
        cout << "1 - Login \n2 - Create New Account \n3 - Quit\n";
        cin >> option;
        switch (option)
        {
        case 1:
            login();
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


//class Account : public Menu
//class sav_acc
class Account
{
public:
    int option;
    float deposit;
    float withdraw;
    float balance=10000;


    /*void accDetails()
    {
        //string acc_no;
        cout<< "\nEnter your account number: ";
        cin>> acc_no;
    }*/

    bool anyTxn()
    {
        char response;
        cout<< "\nAny Transaction? Y / N\n";
        cin>> response;
        if(response=='Y'|response=='y')
        {
            return true;
        }
        else
        {
            cout<< "\n\"--THANK YOU, COME AGAIN!-- \"\n";
            return false;
        }
    }

    void display()
    {
        Menu menu;
        cout<< "\nEnter your requirement: "
            << "\n1 - Balance \n2 - Deposit \n3 - Withdraw \n4 - Main Menu \n\n";
        cin>> option;
        switch(option)
        {
            case 1:
                cout<< "\nYour balance is  "<<balance<< endl;
                break;

            case 2:
                cout<< "\nEnter the amount of deposit: ";
                cin>> deposit;
                balance += deposit;
                break;

            case 3:
                cout<< "\nEnter the amount of withdraw: ";
                cin>> withdraw;
                balance -= withdraw;
                break;
            case 4:
                menu.select();

            default:
                cout<< "\n--INVALID INPUT !!!--\n";
        }

            if (anyTxn())
            {
                display();
            }
            else
                cout<< "\n\"--THANK YOU, COME AGAIN!-- \"\n";

    }
    };



int main()
{
    cout << "Hi! Welcome to ATM Machine!\n\n";
    cout << "Please select an option from the menu below: \n";

    Account accHolder;
    Menu menu;
    menu.select();
    //accHolder.accDetails();
    accHolder.display();
    return 0;

}
