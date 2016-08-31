/*
Won Choi
BankAccountMain.cpp
Utilizes specification/implementation files
Creates bank account, allowing for withdraw/deposit
*/
//specification
#include "BankAccount.cpp"
//libraries
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inData; //fstream initialization
    ofstream outData;

    inData.open("input.txt"); //input prime

	if (not inData) //input test
    {
        cout << "Failed to open input.txt" << endl;
	    return 1;
    }

    outData.open("output.txt"); //output prime

    float initial_balance;
    int amount;
    char option;

    cout<<"Please enter initial balance: $";
    cin>>initial_balance;

    BankAccount account(initial_balance);

    while(inData>>option>>amount) //data read (option read as EOF test)
    {
    	switch(option)
		{
    		case 'w':
                account.withdraw(amount);
                break;
            case 'd':
                account.deposit(amount);
                break;
            default:
            	outData<<"Improper selection!"<<endl;
                break;
    	}
    }

    outData<<"Current balance: $"<<account.getBalance()<<endl;
    outData<<"Number of transactions: "<<account.getTransactions()<<endl;

    inData.close(); //fstream close
    outData.close();

    return 0;
}
