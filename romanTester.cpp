/*
Won Choi - 2015
Roman Numeral Converter - main

converts strings of Roman numerals into decimal values
    using for-loops and switch cases
terminates if incorrect character
*/
//libs
#include <iomanip>
#include <iostream>
#include <fstream>

#include "romanType.cpp" //implementation

using namespace std;

int main()
{
	ofstream outData; //ofstream initialization

	outData.open("romanOutput.txt"); //output prime

	const int SIZE = 4; //string array size

	string input[SIZE] = {"MCXIV", "CCCLIX", "MDCLXVI", "MMMCMLXXXITV"}; //string array

	romanType Augustus;		//initialized constructor

	//header for console + output file
	cout<< "R O M A N   N U M E R A L   C O N V E R T E R" << endl;
	cout<< "\t\t  Won Choi" << endl;
	cout<< endl << endl;
	cout<< setw(15) <<"Numeral " << "\t\t Decimal" << endl;
	cout<< setw(15) << "= = = = =" << "\t\t";
	cout<< setw(5) << "= = = = =" << endl;

	outData<< "R O M A N   N U M E R A L   C O N V E R T E R" << endl;
	outData<< "\t\t  Won Choi" << endl;
	outData<< endl << endl;
	outData<< setw(15) <<"Numeral " << "\t\t Decimal" << endl;
	outData<< setw(15) << "= = = = =" << "\t\t";
	outData<< setw(5) << "= = = = =" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		Augustus.setRoman(input[i]);

		Augustus.setDecimal(Augustus.makeDecimal());

		cout<< setw(16) << Augustus.getRoman() << "\t";
		cout<< setw(6) << Augustus.getDecimal() << endl;

		outData<< setw(16) << Augustus.getRoman() << "\t";
		outData<< setw(6) << Augustus.getDecimal() << endl;
	}

	outData.close(); //ofstream close

	return 0;
}
