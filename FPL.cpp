/*
FPL.cpp
Won Choi 2014
Utilize arrays, structs, and files as parameters
*/
//libs
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std; //namespace

const int MAXNUMBER = 25; //global const maximum number of households

struct household
{
	string IDnumber;
	float annualIncome;
	int householdMembers;
	bool isPoor; // true if < FPL
};

//function calls
void getHouseholds (ifstream&, household[], int &);
float findAverage(const household[], int);
void printOverAverage (ostream&, const household[], int numItems, float average);
int belowPovertyLevel(const household[], int numItems);
bool belowPoverty(const household&);

int main() //main
{
	int numItems;
    float averageIncome;
    int percent;

	household houselist[MAXNUMBER];

	ifstream inData; //initialize fstream
	ofstream outData;

	inData.open("input.txt"); //input prime
	if (!inData) //input test
    {
        cout << "Failed to open input.txt" << endl;

	    return 1;
    }

    outData.open("output.txt"); //output prime
	if (!outData) //output test
    {
        cout << "Failed to open output.txt" << endl;

	    return 1;
    }

	getHouseholds (inData, houselist, numItems); //data read
	averageIncome = findAverage(houselist, numItems); //averages incomes
	printOverAverage(outData, houselist, numItems, averageIncome); //write data
	percent = belowPovertyLevel(houselist, numItems); //writes percentage of poverty

	outData << "\nPercentage below Federal Poverty Line: " << percent << "%";

	inData.close(); //close fstreams
    outData.close();

  	system ("pause");
	return 0;
}

void getHouseholds(ifstream& inData, household houselist[], int& numItems) //input data read
{
	numItems = 0;

    while(!inData.eof())
    {
    	inData >> houselist[numItems].IDnumber;
    	inData >> houselist[numItems].annualIncome;
    	inData >> houselist[numItems].householdMembers;

    	houselist[numItems].isPoor = belowPoverty(houselist[numItems]);
    	numItems++;
    }
}

float findAverage(const household houselist[], int numItems) //calculates average from total-read-loop
{
	float average = 0;

    for(int i = 0; i < numItems; i++)
    {
    	average += houselist[i].annualIncome;
    }

    return (average / numItems);
}

void printOverAverage(ostream& outData, const household houselist[], int numItems, float average) //print table
{
	outData << "Average Income: " << fixed << setprecision(2) << average << "\n\n"
		<< "ID Number   Income     Household Members" << endl; //headers

    for(int i = 0; i < numItems; i++) //print loop
    {
    	outData << houselist[i].IDnumber << "        "
			<< houselist[i].annualIncome << "         "
			<< houselist[i].householdMembers << endl;
    }
}

int belowPovertyLevel(const household houselist[], int numItems) //percentage of households below poverty
{
	int povertyTotal = 0;

    for(int i = 0; i < numItems; i++)
    {
    	if(houselist[i].isPoor)
        {
        	povertyTotal++;
        }
    }
    int percent = (float(povertyTotal) / float(numItems)) * 100;

    return percent;
}

bool belowPoverty(const household& houselist) //true if household is below poverty line
{
	int povertyLine = 11670 + (4060 * (houselist.householdMembers - 1));

    if (povertyLine < houselist.annualIncome)
    	return true;
    else
    	return false;
}

