// This program demonstrates the declaration of an fstream
// object and the opening of a file.
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	fstream dataFile; // Declare file stream object
	char fileName[81];
	cout << "Enter the name of a file you wish to open\n";
	cout << "or create: ";
	cin.getline(fileName, 81);
	dataFile.open(fileName, ios::out);
	cout << "The file " << fileName << " was opened.\n";
}
