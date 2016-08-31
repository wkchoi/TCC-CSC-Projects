//Roman Numeral specification
//w/ multiple inclusion prevention
#ifndef ROMANTYPE_DEFINED
#define ROMANTYPE_DEFINED 1

#include <iostream>
#include <string>

using namespace std;

class romanType
{
	public:
		romanType();						//constructor
		romanType(string);					//constr. w/ {roman} string parameter

		int makeDecimal() const;			//converts myRoman to myDecimal
		int getDecimal() const;				//returns the private field myDecimal;
		void setDecimal(int);				//sets the private field myDecimal;
		string getRoman() const;			//gets the private field myRoman
		void setRoman(string);				//sets the private field myRoman

	private:
		string myRoman;						//private fields for the class
		int myDecimal;						//private field converted as decimal
};

#endif
