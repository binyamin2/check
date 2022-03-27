#pragma once
#include<iostream>
#include<string>

using namespace std;
/*oz asban 207565607
binyamin shapira 208965863
c++
homework 4 question 1
build a atm machine with class of account that enable to do actions in the account*/

class Account
{
	int accountNumber;
	int code;
	int balance;
	string email;
public:
	Account();//empty ctor
	Account(int aNum, int code, float bal, string emailAdress);//ctor
	int getAccountNumber()const;//get the account number
	int getCode()const;//get the code
	int getBalance()const;//get the balance
	string getEmail()const;//get the email
	friend istream& operator>>(istream& is, Account& a);//operator cin for account
	void withdraw(int nis);//execute a withdraw
	void deposit(int chek);//execute a deposit
	static float	sumWithdraw;//suming the withdraws
	static float 	sumDeposit;//suming the deposits
	static float  getSumWithdraw();//get the sum of withdraws
	static float  getSumDeposit();//get the sum of deposits


};

