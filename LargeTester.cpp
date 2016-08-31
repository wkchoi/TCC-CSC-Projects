/*
Won Choi - 2015
Use vectors instead of long ints to sum large values
Mirror print to console and output txt
*/

#include <iostream>	//basic lib
#include <vector>	//vector lib
#include <fstream>	//i/o lib
#include <iomanip>  //i/o manip lib

using namespace std;    //std namespace

vector<int> convertAndSum(istream&);//file read/sum
void print(ostream&, vector<int>);	//print func

int main()
{
	ifstream inF;   //fstream init
	ofstream outF;
	inF.open("Big26.in.txt");   //input prime
    outF.open("Big26.out.txt");  //output prime

    if (!inF) //input test
    {
        cout << "Failed to open Big26.in.txt" << endl;
	    return 1;
    }

    print(outF, convertAndSum(inF)); //call print func

    inF.close(); //fstream close
    outF.close();

    return 0;
}

vector<int> convertAndSum(istream& inF) //converts string input and sums
{
	string input; //string init
	int convert; //int for converting

	vector<int> vec; //vector init
	vector<int> sum; //sum vector to be returned

	bool sumCheck = false; //check for empty sum

	while(inF >> input) //pulls ints as strings as EoF condition
	{
        int count = 0; //vector value iterator in sum and reset
        int carry = 0; //checks overlapping digits

		for(int i = input.length() - 1; i >= 0; i--) //loop through input
        {
            convert = input[i] - '0'; // converted int
            vec.push_back(convert);
        }

        if (!sumCheck)  //fills empty sum
            sum = vec;
        else
        {
            if(sum.size() > vec.size())   //for when sum vector is larger
            {
                while(sum.size() > vec.size())
                    vec.push_back(0);
            }
            else
            {
                while(vec.size() > sum.size())
                    sum.push_back(0);
            }

            for(int i = 0; i < sum.size(); i++) //sums up once vec is filled
            {
                if(sum.at(i) + vec.at(i) + carry > 9)   //loop for carry
                {
                    sum[i] = sum.at(i) + vec.at(i) - 10 + carry;
                    carry = 1;
                }
                else    //loop for normal
                {
                    sum[i] = sum.at(i) + vec.at(i) + carry;
                    carry = 0;
                }
            }
        }
        vec.clear(); //clears vector
        sumCheck = true; //declares sum vector filled
	}
	return sum;
}

void print(ostream& outF, vector<int> sum) //prints header and sum
{
    outF << "L A R G E  I N T E G E R  M A N I P U L A T O R"
        << endl << endl << setw(29) << "By Won Choi" << endl << endl << endl;
    outF << "Sum of large integers is: " << endl << endl;

    cout << "L A R G E  I N T E G E R  M A N I P U L A T O R"
        << endl << endl << setw(29) << "By Won Choi" << endl << endl << endl;
    cout << "Sum of large integers is: " << endl << endl;

    for(int i = sum.size() - 1; i > 0; i--) //prints through vector
    {
        outF << sum.at(i);
        cout << sum.at(i);
    }
}
