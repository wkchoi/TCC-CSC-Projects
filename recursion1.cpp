/*
Won Choi - 2015
Simple program to test recursion
*/

#include <iostream>

using namespace std;

int fact(int num);
int adder(int num);

int main()
{
    cout <<"Factorial of 6 = " << fact(6) << endl;
    cout <<"Factorial of 10 = " << fact(10) << endl;
    cout <<"Sum of 1 to 100 = " << adder(100) << endl;
    return 0;
}

int fact(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
        return num * fact(num - 1);
}

int adder(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
        return num + adder(num - 1);
}
