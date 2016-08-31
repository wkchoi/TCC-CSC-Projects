//Roman Numeral Implementation

#include "romanType.h"
#include <iostream>

using namespace std;

romanType::romanType()							//def. constructor
{
	myRoman = "";
	myDecimal = 0;
}
romanType::romanType(string numerals)			//parameter constructor
{
	myRoman = numerals;
	myDecimal = 0;
}
int romanType::makeDecimal() const				//string-int converter
{
	int sum = 0;								//sum for myDecimal
	char pre = ' ';

	for (int i = 0; i < (myRoman.size()); i++)
    {
        switch(myRoman[i]){

            case 'I':
                sum += 1;
                break;

            case 'V':
                if(pre == 'I')
                    sum += 3;
                else
                    sum += 5;
                break;

            case 'X':
                if(pre == 'I')
                    sum += 8;
                else
                    sum += 10;
                break;

            case 'L':
                if(pre == 'X')
                    sum += 30;
                else
                    sum += 50;
                break;

            case 'C':
                if(pre == 'X')
                    sum += 80;
                else
                    sum += 100;
                break;

            case 'D':
                if(pre == 'C')
                    sum += 300;
                else
                    sum += 500;
                break;

            case 'M':
                sum += 1000;
                break;

            default:
                sum = -1;
                i = myRoman.size();
                break;
        }
        pre = myRoman[i];
    }
    return sum;
}
int romanType::getDecimal() const				//accessor - private int
{
	return myDecimal;
}
void romanType::setDecimal(int n)				//mutator
{
	myDecimal = n;
}
string romanType::getRoman() const				//accessor - private str
{
	return myRoman;
}
void romanType::setRoman(string numerals)		//mutator
{
	myRoman = numerals;
}
