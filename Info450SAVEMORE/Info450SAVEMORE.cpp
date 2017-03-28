// Info450SAVEMORE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class BankAccount {
protected:
	static int NumberGenerator;
	int accountNumber;
	int interestRate;
	int balance;
	int withdrawlAmount;
	int depositAmount;

public:

	BankAccount(int a, int b) {
		accountNumber = a;
		balance = b;
		accountNumber = NumberGenerator;
		NumberGenerator++;
	}


	virtual int withdrawl() = 0;
	virtual int deposit() = 0;
	virtual void display() = 0;

};

class CheckingAccount: public BankAccount {
	char answer;
public: 
	
	int deposit() {
		cout << "How much would you like to deposit?" << endl;
		cin >> depositAmount;
		balance += depositAmount;

		return balance;
	}

	int withdrawl() {
		cout << "How much would you like to withdrawl?" << endl;
		cin >> withdrawlAmount;
		balance -= withdrawlAmount;
		if (balance < 500)
		{
			balance -= 5;
			cout << "A fee of five dollars has been subtracted from your account for failure to meet your account threshold." << endl;
		}
		return balance;
	}

	int orderChecks() {
		cout << "Order checks? Y/N" << endl;
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			balance -= 15;
			cout << "Checks ordered!" << endl;
		}
		return balance;
	}

	void display() {
		cout << "Your account number is: " << accountNumber << endl;
		cout << "Your account balance is: " << balance << endl;
		
	}

};

class Savings : public BankAccount {

	int *interestPointer = &interestRate;
public:
	Savings(int a, int b, int i) :BankAccount(a, b) {
		if (balance <= 10000)
		{
			i = .01;
		}
		else
		{
			i = .02;
		}
		interestRate = i;
	}

	int deposit(*interestPointer) {
		cout << "How much would you like to deposit?" << endl;
		cin >> depositAmount;
		balance += depositAmount;
		if (balance > 10000)
			(*interestRate) = .02; // this may need to be made static for the update to happen since this is not returned from the function. 
		return balance;
	}


};

int main()
{
	
    return 0;
}

