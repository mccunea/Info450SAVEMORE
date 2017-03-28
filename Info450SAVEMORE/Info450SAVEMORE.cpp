// Info450SAVEMORE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
char answer;
class BankAccount {
protected:
	static int NumberGenerator;
	int accountNumber;
	double interestRate;
	double balance;
	double withdrawlAmount;
	double depositAmount;

public:

	BankAccount(double b) {
		balance = b;
		accountNumber = NumberGenerator;
		NumberGenerator++;
	}


	virtual double withdrawl() = 0;
	virtual double deposit() = 0;
	virtual void display() = 0;

};

class CheckingAccount: public BankAccount {
	char answer;
public: 
	CheckingAccount(int b) : BankAccount(b) {}
	double deposit() {
		cout << "How much would you like to deposit?" << endl;
		cin >> depositAmount;
		balance += depositAmount;

		return balance;
	}

	double withdrawl() {
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

	double orderChecks() {
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

	
public:
	
	Savings( double b, double i) :BankAccount( b) {
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

	double deposit() {
		cout << "How much would you like to deposit?" << endl;
		cin >> depositAmount;
		balance += depositAmount;
		if (balance > 10000)
			interestRate = .02; 
		return balance;
	}

	double withdrawl() {}
	void display() {}

};

int BankAccount::NumberGenerator = 1;

int main()
{


    return 0;
}

