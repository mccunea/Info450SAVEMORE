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


	virtual int withdrawl() = 0;
	virtual int deposit() = 0;
	virtual void display() = 0;

};

class CheckingAccount: public BankAccount {
	char answer;
public: 
	CheckingAccount(int b) : BankAccount(b) {}
	int deposit() {
		cout << "How much would you like to deposit?" << endl;
		cin >> depositAmount;
		if (depositAmount < 0)
		{
			cout << "Cannot deposit a negative amount" << endl;
			return -1;
		}
		else
		balance += depositAmount;
		return 0;
	}

	int withdrawl() {
		cout << "How much would you like to withdrawl?" << endl;
		cin >> withdrawlAmount;
		if (withdrawlAmount > balance) {
			cout << "Withdrawl amount cannot exceed your current balance plus any additional fees." << endl;
			return -1;
		}
		else
		balance -= withdrawlAmount;
		if (balance < 500)
		{
			balance -= 5;
			cout << "A fee of five dollars has been subtracted from your account for failure to meet your account threshold." << endl;
		}
		
		return 0;
	}

	int orderChecks() {
		cout << "Order checks? Y/N" << endl;
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			balance -= 15;
			cout << "Checks ordered!" << endl;
		}
		else
			cout << "Ok you can order any time!" << endl;
		return 0;
	}

	void display() {
		cout << "Your account number is: " << accountNumber << endl;
		cout << "Your account balance is: " << balance << endl;
		
	}

};

class Savings : public BankAccount {

	
public:
	
	Savings( double b) :BankAccount( b) {
		if (balance <= 10000)
		{
			interestRate = .01;
		}
		else
		{
			interestRate = .02;
		}
		
	}

	int deposit() {
		cout << "How much would you like to deposit?" << endl;
		cin >> depositAmount;
		if (depositAmount < 0)
		{
			cout << "Cannot deposit a negative amount" << endl;
			return -1;
		}
		else
		balance += depositAmount;
		if (balance > 10000)
		{
			interestRate = .02;
		}
		return 0;
	}

	int withdrawl() {
		cout << "How much would you like to withdrawl?" << endl;
		cin >> withdrawlAmount;
		if (withdrawlAmount > balance - 2) {
			cout << "Withdrawl amount cannot exceed your current balance plus any additional fees." << endl;
			return -1;
		}
		else
		balance -= withdrawlAmount;
		
		balance -= 2;
		cout << "A 2 dollar charge has been applied to your withdrawl." << endl;
		if (balance <= 10000)
		{
			interestRate = .01;
		}
		return 0;
	}
	void display() {
		cout << "Your account number is: " << accountNumber << endl;
		cout << "Your account balance is: " << balance << endl;
		cout << "Your interest rate is: " << interestRate << endl;
	}

};

class CD : public BankAccount {
	int term;
public: 
	
	CD(double b) : BankAccount(b) {
		cout << "What is the ter of your CD?" << endl;
		cin >> term;
		if (term >= 5)
		{
			interestRate = .1;
		}
		else
		{
			interestRate = .05;
		}
	}

	int deposit() {
		cout << "How much would you like to deposit?" << endl;
		cin >> depositAmount;
		if (depositAmount < 0)
		{
			cout << "Cannot deposit a negative amount" << endl;
			return -1;
		}
		else
		balance += depositAmount;
		
		return 0;
	}

	int withdrawl() {
		cout << "How much would you like to withdrawl?" << endl;
		cin >> withdrawlAmount;
		if (withdrawlAmount > balance - (balance * .1)) {
			cout << "Withdrawl amount cannot exceed your current balance plus any additional fees." << endl;
			return -1;
		}
		else
		balance -= withdrawlAmount;
		balance -= (balance * .1);
		cout << "A 10% charge to the principal of your account has been applied to your withdrawl." << endl;
		return 0;
	}
	void display() {
		cout << "Your account number is: " << accountNumber << endl;
		cout << "Your account balance is: " << balance << endl;
		cout << "Your interest rate is: " << interestRate << endl;
	}



};

int BankAccount::NumberGenerator = 1;

int main()
{
	CD test(10000);
	test.withdrawl();
	test.display();
    return 0;
}

