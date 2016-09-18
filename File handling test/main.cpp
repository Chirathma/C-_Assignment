#include <iostream>
#include <fstream>
#include <cstdlib> // used to exit

using namespace std;

int main()
{
    ifstream accInFile;
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
            << endl;
return 0;
}

