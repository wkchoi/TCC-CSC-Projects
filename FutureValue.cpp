/*
FutureValue.cpp
Won Choi - 2014
Create tables showing future values of investments


Notes:
    checks against incorrect inputs
    stringstream to read/take data,
	fixed for setprecision,
	tabs/newlines for required format
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream> //for getData read

using namespace std; //namespace

void getData (ifstream & inData, float & principle, int & years, float & rate); //function calls
void printTable (ostream & outData, float principle, int years, float rate);
float getCurrentInterest (float principle, float rate);

int main() //main
{
	float principle = 0; //initialize variables
	float rate = 0;
	int years = 0;

	ifstream inData; //initialize fstream
    ofstream outData;

    inData.open("input.txt"); //input prime
    outData.open("output.txt"); //output prime

	if (not inData) //input test
    {
        cout << "Failed to open input.txt" << endl;
        return 1;
    }

    while(!inData.eof())
    {
    	getData(inData, principle, years, rate); //data collection
		printTable(outData, principle, years, rate); //prints off table
	}

	inData.close(); //closes fstreams
    outData.close();

    system ("pause");
    return 0;
}
// reads data, uses low-level I/O for principle
void getData(ifstream & inData, float & principle, int & years, float & rate)
{
	string str1;
	stringstream str2;
    char ch;

    str2.clear(); //string sum reset

	getline(inData, str1); //reads line

    for (int i = 0; i <= str1.length(); i++)
	{
    	if (isdigit(str1[i]) || str1[i] == ' ') //tests if digit
    	{
    		ch = str1[i];
            str2 << ch; //adds for full string
    	}
    }
    str2 >> principle >> rate >> years; //read as P, Y, R

}
// prints table of accumulted values
void printTable(ostream & outData, float principle, int years, float rate)
{
	//header print
	outData << "Original Principle" << "\t" << fixed << setprecision(2) << principle << " \t"
		<< "Interest Rate" << "\t" << fixed << setprecision(2) << rate << "\n\n";
	outData << "Current Year" << "\t\t" << "Interest" << "\t"
		<< "Accumulation" << "\n\n";

	//data print
	for (int i = 0; i < years; i++)
	{
		outData << "        " << i + 1 << "\t\t" << fixed << setprecision(2)
			<< getCurrentInterest(principle, rate) << "\t\t" << setprecision(2)
			<< (principle + getCurrentInterest(principle, rate)) << endl;

		principle += getCurrentInterest(principle, rate); //adds concurrent principle

		outData << endl; //spacing
	}

	outData << endl; //spacing
}
// finds principle for current year (rate is 1)
float getCurrentInterest(float principle, float rate)
{
	float interest = principle * (rate / 100) * 1; //1 for current year

	return interest;
}
