#include <iostream>
#include "Clock.h"
#include "Account.h"
using namespace std;

enum ACTION {
	STOP,
	BALANCE,
	DEPOSIT,
	WITHDRAW,
	SUM_DEPOSIT,
	SUM_WITHDRAW
};
ACTION menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all deposits" << endl;
	cout << "enter 5 to see the sum of all withdrawals" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (ACTION)x;
}



void checkAccount(Account bank[], int i);
void cashWithdraw(Account* bank, int size, Clock& c);
void cashDeposit(Account* bank, int size, Clock& c);
void getBalance(Account* bank, int size, Clock& c);
void printTransaction(Account a, ACTION ac, Clock& c);
int findAccount(Account* bank, int size);

using namespace std;


int main() {
	const int SIZE = 3;///להחזיר ל10
	Clock c(8, 0, 0);
	Account bank[SIZE];
	cout << "enter account number, code and email for " << SIZE << " accounts:\n";
	for (int i = 0; i < SIZE; i++) {
		try {
			cin >> bank[i];
			checkAccount(bank, i);
		}
		catch (int num)
		{
			enum check{A=1,B=2,C=3};
			
			switch (num)
			{
			case A:
				cout << "ERROR: code must be of 4 digits!" << endl;
				break;
			case B:
				cout << "ERROR: email must contain @!" << endl;
				break;
			case C:
				cout << "ERROR: email must end at .com or .co.il" << endl;
				break;
			default:
				break;
			}
		}
		catch (const char* msg) {
			cout << c << '\t' << msg;
			i--;
		}
		catch (...)
		{
			cout << "No know worng in initial acount." << endl;
		}
	}
	
	ACTION ac = menu();
	while (ac) {
		try
		{
			switch (ac) {
			case BALANCE: getBalance(bank, SIZE, c);
				break;
			case WITHDRAW:cashWithdraw(bank, SIZE, c);
				break;
			case DEPOSIT:cashDeposit(bank, SIZE, c);
				break;
			case SUM_DEPOSIT:c += 60;
				printTransaction(bank[0], SUM_DEPOSIT, c);
				break;
			case SUM_WITHDRAW:c += 60;
				printTransaction(bank[0], SUM_WITHDRAW, c);
			}
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}


		ac = menu();
	}

	return 0;
}


int findAccount(Account* bank, int size) {
	int number, code;
	cout << "please enter account number:\n";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	if (i >= size)
		throw "ERROR: no such account number\n";
	cout << "please enter the code:\n";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	throw "ERROR: wrong code!\n";
}
void printTransaction(Account a, ACTION ac, Clock& c) {
	cout << c << "\t";
	switch (ac) {
	case BALANCE: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case DEPOSIT:
	case WITHDRAW: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case SUM_DEPOSIT:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case SUM_WITHDRAW:
		cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], BALANCE, c);
}
void cashDeposit(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the deposit:\n";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], DEPOSIT, c);
}
void cashWithdraw(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw:\n";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], WITHDRAW, c);
}
void checkAccount(Account bank[], int i) {
	for (int j = 0; j < i; j++)
		if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
			throw "ERROR: account number must be unique!\n";
}

/*
enter account number, code and email for 3 accounts:

123  4444 me@gmail.com
234 5555  you@walla.co.il
345 6666  us@g.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
2
please enter account number:
234
please enter the code:
5555
enter the amount of the deposit:
 5000
08:00:30        account #: 234  new balance: 5000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
3
please enter account number:
234
please enter the code:
5555
enter the amount of money to withdraw:
1000
08:01:20        account #: 234  new balance: 4000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
1
please enter account number:
234
please enter the code:
5555
08:01:40        account #: 234  balance: 4000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
2
please enter account number:
345
please enter the code:
6666
enter the amount of the deposit:
 2000
08:02:10        account #: 345  new balance: 2000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
3
please enter account number:
345
please enter the code:
6666
enter the amount of money to withdraw:
 500
08:03:00        account #: 345  new balance: 1500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
4
08:04:00        sum of all deposits: 7000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
5
08:05:00        sum of all withdrawals: 1500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
0

C:\Users\binyamin\OneDrive - g.jct.ac.il\sadnac++\exercise\exercise1question1\Debug\exercise4question1.exe (process 932) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .



*/
/*
	while (ac) {
		switch (ac)
		{
		case BALANCE:
			try
			{
				getBalance(bank, SIZE, c);
			}
			catch (const char* str)
			{
				cout << str;
			}
			catch (...)
			{
				cout << "No know worng in Balance." << endl;
			}
			break;
		case WITHDRAW:
			try
			{
				cashWithdraw(bank, SIZE, c);
			}
			catch (const char* str)
			{
				cout << str;
			}
			catch (int num)
			{
				enum check{OVER_WITHDRWE=1,OVER_MINUS};

				switch (num)
				{
				case OVER_WITHDRWE:
					cout << "ERROR: cannot withdraw more than 2500 NIS!" << endl;
					break;
				case OVER_MINUS:
					cout << "ERROR: cannot have less than - 6000 NIS!" << endl;
					break;
				default:
					break;
				}
			}
			catch (...)
			{
				cout << "No know worng in withDrew." << endl;
			}
			break;
		case DEPOSIT:
			try
			{
				cashDeposit(bank, SIZE, c);
			}
			catch (const char* str)
			{
				cout << str;
			}
			catch (int num)
			{
				cout << "ERROR: cannot deposit more than 10000 NIS!" << endl;
			}
			catch (...)
			{
				cout << "No know worng in DEPOSIT." << endl;
			}
			break;

		case SUM_DEPOSIT:
			c += 60;
			printTransaction(bank[0], SUM_DEPOSIT, c);
			break;
		case SUM_WITHDRAW:
			c += 60;
			printTransaction(bank[0], SUM_WITHDRAW, c);
		}

		ac = menu();
	}
*/