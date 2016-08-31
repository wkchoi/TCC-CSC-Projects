//Bank Account Specification
//multiple inclusion prevention
#ifndef BANKACCOUNT_DEFINED
#define BANKACCOUNT_DEFINED 1

#include <iostream>

class BankAccount
{
	public:
		BankAccount(); //default
		BankAccount(float);
		void deposit(float);
		void withdraw(float);
		float getBalance() const;
		int getTransactions() const;
		
	private:
		float Current_Balance;
		int Number_of_Transactions;	
};

#endif
