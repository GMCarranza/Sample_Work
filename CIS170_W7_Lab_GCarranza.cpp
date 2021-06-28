// ---------------------------------------------------------------
// Programming Assignment:	LAB7
// Developer:			    Gwendolyn M Carranza
// Date Written:			April 14, 2018
// Purpose:				    An Address Data Base
// ---------------------------------------------------------------

//Specification: Append and display records in a address database 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void menu(void);
void writeData(void);
void readData(void);
string * split(string, char);

const char FileName[] = "d:/her/devry/cis 170/lab cis170c/week 7 lab Gwendolyn Carranza/TestAddress2.txt";




int main() {
	menu();
	return 0;
} //end main

void menu(void) {
	char userChoice = ' ';
	//allow user to choose to append records, display records or exit the program
	cout << "(A)ppend Records, (S)how Records, (E)xit" << endl;
	cin >> userChoice;

	while (userChoice != 'e')

		switch (userChoice)
		{
		case 'A':
		case 'a': // append records
		{
			writeData();
		}
		break;

		case 'S':
		case 's': // read records
		{
			readData();
		}
		break;

		default:
			cout << "Invalid Choice" << endl;
			break;

		}

}//end menu

void writeData(void) {

	string name = " ";
	string address = " ";
	string city = " ";
	string state = " ";
	string zip = " ";
	char response = 'Y';

	ofstream outMyAddress("c://TestAddress.txt", ios::app);

	outMyAddress.is_open();

	do {
		cout << endl;
		getline(cin, name);
		cout << "Enter Name: ";
		getline(cin, name);

		cout << "Enter Address: ";
		getline(cin, address);

		cout << "Enter City: ";
		getline(cin, city);

		cout << "Enter State: ";
		getline(cin, state);

		cout << "Enter Zip: ";
		getline(cin, zip);

		outMyAddress << name << "," << address << "," << city << "," << state << "," << zip << endl;

		cout << "\n Enter another record? (Y/N) ";
		cin >> response;

	} while (response == 'y' || response == 'Y');

		outMyAddress.close();

	menu();


	//Write the Address Info to a file

}//end write data

void readData(void) {
	//read data from a file
	//use the split function to break a
	//deliminated line of text into fields

	int recordCount = 0;
	string lineBuffer;

	ifstream inMyAddress;
	inMyAddress.open(FileName);

	inMyAddress.is_open(); // tests to see if file is open

	getline(inMyAddress, lineBuffer);

	while (!inMyAddress.eof());
	{
		for (int counter = 0; counter > 0; counter++)
		{
			recordCount++;
		}
		cout << "\n Record No. " << recordCount;

		string * theFields = split(lineBuffer, ',');

		cout << endl;

		cout << "Name.........." << theFields[0] << endl;
		cout << "Address.........." << theFields[1] << endl;
		cout << "City.........." << theFields[2] << endl;
		cout << "State.........." << theFields[3] << endl;
		cout << "Zip.........." << theFields[4] << endl;
		cout << "___________________________________________" << endl;

		getline(inMyAddress, lineBuffer);
	}

	inMyAddress.close();
	cout << endl;

	menu();

}//end read data

string * split(string theLine, char theDeliminator) {
	//Break theline into fields and save the fields to an array.
	//Each field will occupy one element in a character array.
	//theLine is a string with fields separated with theDeliminator character.
	//Assumes the last field in the string is terminated with a newline.
	//Useage: string *theFields = split(lineBuffer, ',');

	//determine how many splits there will be so we can size our array
	int splitCount = 0;
	for (int i = 0; i < theLine.size(); i++) 
	{
		if (theLine[i] == theDeliminator)
			splitCount++;
	}
	splitCount++; //add one more to the count because there is not an ending comma 

				  //create an array to hold the fields
	string* theFieldArray;
	theFieldArray = new string[splitCount];

	//split the string into seperate fields
	string theField = "";
	int commaCount = 0;

	for (int i = 0; i < theLine.size(); i++) 
	{ //read each character and look for the deliminator
		if (theLine[i] != theDeliminator) 
		{
			theField += theLine[i]; //build the field
		}
		else { //the deliminator was hit so save to the field to the array
			theFieldArray[commaCount] = theField; //save the field to the array
			theField = "";
			commaCount++;
		}
	}
	theFieldArray[commaCount] = theField; //the last field is not marked with a comma...

	return theFieldArray;
} //end split
