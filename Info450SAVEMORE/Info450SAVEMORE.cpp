// Info450SAVEMORE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

using namespace std;

class BankAccount {
protected:
	static int NumberGenerator;
	int accountNumber;
	double interestRate;
	double balance;
	double withdrawlAmount;
	double depositAmount;
	SYSTEMTIME openDate;
	
public:

	BankAccount(double b) {
		balance = b;
		GetLocalTime(&openDate);
 		accountNumber = NumberGenerator;
		NumberGenerator++;
	}



	virtual int withdrawl() = 0;
	virtual int deposit() = 0;
	virtual int interest() = 0;
	virtual void display() = 0;
	
};

class CheckingAccount: public BankAccount {
	char answer;
public: 
	CheckingAccount(double b) : BankAccount(b) {}
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
		char checkAnswer;
		cout << "Order checks? Y/N" << endl;
		cin >> checkAnswer;
		if (checkAnswer == 'Y' || checkAnswer == 'y')
		{
			balance -= 15;
			cout << "Checks ordered!" << endl;
		}
		else
			cout << "Ok you can order any time!" << endl;
		return 0;
	}

	void display() {
		cout << "Your checking account number is: " << accountNumber << endl;
		cout << "Your checking account balance is: " << balance << endl;
		cout << "Account created: " << openDate.wMonth  << "/";
		cout << openDate.wDay << "/" << openDate.wYear << endl << endl;
	}
	int interest() {
		cout << "Nothing to see here!" << endl;
		return 0;
	}



};

class Savings : public BankAccount {

	
public:
	
	Savings(double b) :BankAccount(b) {
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
		cout << "Your savings account number is: " << accountNumber << endl;
		cout << "Your savings account balance is: " << balance << endl;
		cout << "Your interest rate is: " << interestRate << endl << endl;
		cout << "Account created: " << openDate.wMonth << "/";
		cout << openDate.wDay << "/" << openDate.wYear << endl << endl;
	}

	int interest() {
		balance += (interestRate * balance);
		return 0;
	}




};

class CD : public BankAccount {
	int term;
public: 
	
	CD(double b) : BankAccount(b) {
		cout << "What is the term of your CD?" << endl;
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
		cout << "Your CD account number is: " << accountNumber << endl;
		cout << "Your CD account balance is: " << balance << endl;
		cout << "Your interest rate is: " << interestRate << endl << endl;
		cout << "Account created: " << openDate.wMonth << "/";
		cout << openDate.wDay << "/" << openDate.wYear << endl << endl;
	}

	int interest() {
		balance += (interestRate * balance);
		return 0;
	}



};

int BankAccount::NumberGenerator = 1;

int main()
{
	char answer;
	double startingAmount;
	cout << "Welcome new member! Members are required to have a Checking, Savings, and CD account." << endl;
	cout << "Please enter how much you would like to deposit in each. If you do not plan to use the account, enter 0." << endl <<endl;
	cout << "How much would you like to deposit in your checking account?" << endl;
	cin >> startingAmount;
	CheckingAccount newCheckingAccount(startingAmount);
	cout << "How much would you like to deposit in your Savings Account?" << endl;
	cin >> startingAmount;
	Savings newSavingsAccount(startingAmount);
	cout << "How much would you like to deposit in your CD?" << endl;
	cin >> startingAmount;
	CD newCDAccount(startingAmount);

	do
	{
		cout << "Access (C)hecking, (S)avings, or C(D)? (V)iew All or enter (Q) to quit. " << endl;
		cin >> answer;
		if (answer == 'C' || answer == 'c')
		{
			
			cout << "(D)eposit, (W)ithdrawl, (O)rder checks, or (V)iew account?" << endl;
			cin >> answer;
			if (answer == 'D' || answer == 'd')
			{
				newCheckingAccount.deposit();
			}
			else if (answer == 'W' || answer == 'w')
			{
				newCheckingAccount.withdrawl();
			}
			else if (answer == 'O' || answer == 'o')
			{
				newCheckingAccount.orderChecks();
			}
			else if (answer == 'V' || answer == 'v')
			{
				newCheckingAccount.display();
			}

		}
		else if (answer == 'S' || answer == 's')
		{
			cout << "(D)eposit, (W)ithdrawl, (I)nterest, or (V)iew account?" << endl;
			cin >> answer;

			if (answer == 'D' || answer == 'd')
			{
				newSavingsAccount.deposit();
			}
			else if (answer == 'W' || answer == 'w')
			{
				newSavingsAccount.withdrawl();
			}
			else if (answer == 'I' || answer == 'i')
			{
				newSavingsAccount.interest();
			}
			else if (answer == 'V' || answer == 'v')
			{
				newSavingsAccount.display();
			}

		}
		else if (answer == 'D' || answer == 'd')
		{
			cout << "(D)eposit, (W)ithdrawl, (I)nterest, or (V)iew account?" << endl;
			cin >> answer;

			if (answer == 'D' || answer == 'd')
			{
				newCDAccount.deposit();
			}
			else if (answer == 'W' || answer == 'w')
			{
				newCDAccount.withdrawl();
			}
			else if (answer == 'I' || answer == 'i')
			{
				newCDAccount.interest();
			}
			else if (answer == 'V' || answer == 'v')
			{
				newCDAccount.display();
			}
		}

		else if (answer == 'V' || answer == 'v')
		{
			newCheckingAccount.display();
			newSavingsAccount.display();
			newCDAccount.display();
		}

		else if (answer == 'Q' || answer == 'q')
		{
			return 0;
		}
	} while (answer != 'Q' || answer !='q');
	

    return 0;
}

