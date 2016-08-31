//Bank Account Implementation

#include "BankAccount.h"
#include <iostream>

using namespace std;
//default constructor
BankAccount::BankAccount()
{
    Current_Balance = 1000;
    Number_of_Transactions = 0;
}
//manual constructor
BankAccount::BankAccount(float balance)
{
    Current_Balance = balance;
    Number_of_Transactions = 0;
}

void BankAccount::deposit(float amount)
{
	Current_Balance += amount;
	
	Number_of_Transactions++;
}

void BankAccount::withdraw(float amount)
{
	if(amount > Current_Balance)
	{
		cout<<"Unable to withdraw more than total balance."<< endl;
	}
	else
	{
		Current_Balance -= amount;
		Number_of_Transactions++;
	}
}

float BankAccount::getBalance() const
{
	return Current_Balance;
}

int BankAccount::getTransactions() const
{
	return Number_of_Transactions;
}
