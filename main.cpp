#include <iostream>
#include <fstream>
#include <string.h>
//#include <string>
#include <cstdlib> // used to exit
#include <limits>
#include <vector>
#include <sstream>
using namespace std;

//account details and
class Account {
private:
    string userId;
    double balance;
    string password;

public:
    Account(string id, double balanceValue, string pwd)
    {
        userId = id;
        balance = balanceValue;
        password = pwd;
    }
    string getpassword()
    {
        return password;
    }
    string getUserId()
    {
        return userId;
    }
    double getBalance()
    {
        return balance;
    }
    void deposit(double amount)
    {
        balance += amount;
    }

    bool withdraw(double amount)
    {
        if (amount < balance) {
            balance -= amount;
            return true;
        }
        else {
            return false;
        }
    }
};

class DataHandler {
public:
    bool createUserFile(string userName, string password)
    {
        string temp = userName + "#" + password + "#0";
        if (std::ifstream(userName.c_str())) {
            return false;
        }
        else {
            ofstream myfile;
            myfile.open(userName.c_str());
            myfile << temp;
            myfile.close();
            return true;
        }
    }

    string readFile(string userName)
    {
        string line;
        ifstream myfile(userName.c_str());

        if (!myfile) {
            return "";
        }
        else if (myfile.is_open()) {
            getline(myfile, line);
            myfile.close();
            return line;
        }
        return "";
    }

    void updateFile(string userId, string pwd, string balance)
    {
        string line = userId + "#" + pwd + "#" + balance;
        ofstream fout(userId.c_str());
        fout << line;
    }
};

//selecting main menu
class Menu {
private:
    //double withdrawValue;
    //double depositValue;
    //double balance;

    Account* login()
    {
        string userID;
        string info;
        string password;

        string pwd;
        cout << "---Login---\n\n";
        cout << "Enter ID: ";
        cin >> userID;
        cout << "\nEnter Password: ";
        cin >> pwd;
        DataHandler datahandler;
        info = datahandler.readFile(userID);

        Account* account = NULL;
        if (info == "") {
            return NULL;
        }
        else {
            vector<string> tokens = splitString(info, "#");
            string userId = tokens.at(0);
            double balance = atof(tokens.at(2).c_str());
            password = tokens.at(1);
            if (pwd == password) {
                account = new Account(userID, balance, password);
            }
            else {
                account = NULL;
            }
        }
        return account;
    }

    vector<string> splitString(string input, string delimiter)
    {
        vector<string> output;
        char* pch;

        char* str = strdup(input.c_str());

        pch = strtok(str, delimiter.c_str());

        while (pch != NULL) {
            output.push_back(pch);

            pch = strtok(NULL, delimiter.c_str());
        }

        free(str);

        return output;
    }

    bool createAcc()
    {
        string userID;
        string pwd, pwd2;
        cout << "---Create New Account---\n\n";
        cout << "Enter User ID: ";
        cin >> userID;
        do {
        cout << "\nEnter the password: ";
        cin >> pwd;
        cout << "\n Re-enter the password: ";
        cin >> pwd2;
        if(pwd!=pwd2) {
            cout<<"Passwords don't match! Enter Again!\n";
        }
        } while(pwd!=pwd2);

        DataHandler datahandler;
        return datahandler.createUserFile(userID, pwd);
    }

    void quitAcc()
    {
        cout << "~~Thank You! Come Again!~~\n\n";
    }

    void transact(Account* account)
    {
        int option;
        double balance,depositValue,withdrawValue;
        cout << "\nEnter your requirement: "
             << "\nBalance-'1'\t Deposit-'2'\t Withdraw-'3'\t Exit -'4' \n";
        cin >> option;
        while (!cin || option < 1 || option > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "--INVALID INPUT!-- \n ---PLEASE ENTER AGAIN!---\n";
            cout << "\nBalance-'1'\t Deposit-'2'\t Withdraw-'3'\t Exit -'4' \n";
            cin >> option;
        }

        switch (option) {
        case 1:
            balance = account->getBalance();
            cout << "\nYour balance is  " << balance << endl;
            transact(account);
            break;

        case 2:
            cout << "\nEnter the amount of deposit: ";
            cin >> depositValue;
            //account->deposit(depositValue);
            deposit(account, depositValue);
            cout << "\nYour balance is  " << account->getBalance() << endl;
            transact(account);
            break;

        case 3:
            cout << "\nEnter the amount of withdraw: ";
            cin >> withdrawValue;
            //account->withdraw(withdrawValue);
            withdraw(account, withdrawValue);
            cout << "\nYour balance is  " << account->getBalance() << endl;
            transact(account);
            break;
        case 4:
            selectMenu();
            break;
        }
    }

    void withdraw(Account* account, double withdrawValue)
    {
        account->withdraw(withdrawValue);
        string userId = account->getUserId();
        string pwd = account->getpassword();

        ostringstream strs;
        strs << account->getBalance();
        string balance = strs.str();
        /*string line = userId + "#" + pwd + "#" + balance;

        ofstream fout(userId.c_str());
        fout<<line;*/
        DataHandler datahandler;
        datahandler.updateFile(userId, pwd, balance);
    }

    void deposit(Account* account, double depositValue)
    {
        account->deposit(depositValue);
        string userId = account->getUserId();
        string pwd = account->getpassword();

        ostringstream strs;
        strs << account->getBalance();
        string balance = strs.str();
        /*string line = userId + "#" + pwd + "#" + balance;
        cout<<line;

        ofstream fout(userId.c_str());
        fout<<line;*/
        DataHandler datahandler;
        datahandler.updateFile(userId, pwd, balance);
    }

public:
    void selectMenu()
    {
        cout << "1 - Login \n2 - Create New Account \n3 - Quit\n";
        int option1;
        cin >> option1;
        while (!cin || option1 < 1 || option1 > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "--INVALID INPUT!-- \n ---PLEASE ENTER AGAIN!---\n";
            cout << "1 - Login \n2 - Create New Account \n3 - Quit\n";
            cin >> option1;
        }
        switch (option1) {
        case 1: {
            Account* account = login();
            if (account != NULL) {
                transact(account);
                delete account; //to free the memory allocated for account object
            }
            else {
                cout << "Wrong username or password!\n";
                selectMenu();
            }
        } break;

        case 2:
            if(!createAcc()) {
                cout << "User name exists!\n";
            } else {
                 cout << "Account creation successful!\n";
            };
            selectMenu();
            break;

        case 3:
            quitAcc();
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
