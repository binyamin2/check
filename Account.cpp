#include"Account.h"
#include<iostream>
#include<string>

using namespace std;
/*oz asban 207565607
binyamin shapira 208965863
c++
homework 4 question 1
build a atm machine with class of account that enable to do actions in the account*/

float Account::sumDeposit = 0;
float Account::sumWithdraw = 0;

Account::Account()//empty ctor
{
	accountNumber = 0;
	code = 0;
	balance = 0;
	email = '\0';
}

Account::Account(int aNum, int code, float bal, string emailAdress)//ctor
{
	if (aNum < 1000 || aNum>9999)//throw error if ilegal code
	{
		throw "ERROR: code must be of 4 digits!";
	}
	else if (email.find('@') == -1)//check if @ is in the email
	{
		throw"ERROR: email must contain @!";
	}
	else if (email.find(".com") == -1 && email.find(".co.il") == -1)//check if .com/.co.il is in th mail
	{
		throw"ERROR: email must end at .com or .co.il!";
	}
	else//if everything legal
	{
		accountNumber = aNum;
		this->code = code;
		balance = bal;
		email = emailAdress;
	}
}
int Account::getAccountNumber()const//get the account number
{
	return accountNumber;
}
int Account::getCode()const//get the code
{
	return code;
}
int Account::getBalance()const//get the balance
{
	return balance;
}
string Account::getEmail()const//get the email
{
	return email;
}
istream& operator>>(istream& is, Account& a)//operator cin for account
{
	is >> a.accountNumber;
	is >> a.code;
	is >> a.email;
	if (a.code < 1000 || a.code>9999)//throw error if ilegal code
	{
		throw "ERROR: code must be of 4 digits! ";
	}
	else if (a.email.find('@') == -1)//check if @ is in the email
	{
		throw"ERROR: email must contain @!";
	}
	else if (a.email.find(".com") == -1 && a.email.find(".co.il") == -1)//check if .com/.co.il is in th mail
	{
		throw"ERROR: email must end at .com or .co.il!";
	}
	else//if everything fine
		return is;
}
void Account::withdraw(int nis)//function to withdrow money
{
	if (balance - nis < -6000)//check if the balance is becoming under -6000
	{
		throw "ERROR: cannot have less than - 6000 NIS!";
	}
	else if (nis > 2500)//make shur that the withdraw wont pass the 2500 nis
	{
		throw"ERROR: cannot withdraw more than 2500 NIS!";
	}
	else//execute the withdraw
	{
		balance -= nis;
		sumWithdraw += nis;
	}
}
void Account::deposit(int chek)
{
	if (chek > 10000)//check that the deposit is not more then 10000
	{
		throw "ERROR: cannot deposit more than 10000 NIS!";
	}
	else//execute the deposit
	{
		balance += chek;
		sumDeposit += chek;
	}
}
float Account::getSumWithdraw()//get tha sum of withdraws
{
	return Account::sumWithdraw;
}
float Account::getSumDeposit()//get the sum of th deposits
{
	return Account::sumDeposit;
}