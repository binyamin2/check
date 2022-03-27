/*
binyamin shapira 208965863.

course : cadna c++.
exercise 4 question 1.
the file is definition of methods of class "Clock.h"
*/
#include <iostream>
#include "Clock.h"
using namespace std;



void check_second(int second)
//help function to check second.
{
	if (second < 0)
	{
		throw 1;
	}
	if (second > 59)
	{
		throw 2;
	}
	return;
}

void check_minute(int mintue)
//help function to check minute.
{
	if (mintue < 0)
	{
		throw 3;
	}
	if (mintue > 59)
	{
		throw 4;
	}
	return;

}

void check_hours(int hours)
//help function to check hours.
{
	if (hours < 0)
	{
		throw 5;
	}
	if (hours > 23)
	{
		throw 6;
	}
	return;
}

Clock::Clock(int hours, int minute, int second)
{
	check_second(second);//check second
	check_minute(minute);//check mintue
	check_hours(hours);//check hours

	//if not have throw the values inside to this-> clock

	this->second = second;
	this->minute = minute;
	this->hours = hours;

}

void Clock::set_hours(int hours)
{
	check_hours(hours);
	//if not have throw the value inside to this-> clock
	this->hours = hours;
	return;
}

void Clock::set_minute(int minute)
{
	check_minute(minute);
	//if not have throw the value inside to this-> clock
	this->minute = minute;
	return;
}
void Clock::set_second(int second)
{
	check_second(second);
	//if not have throw the value inside to this-> clock
	this->second = second;
	return;
}

Clock& Clock::operator+=(const int second)
{
	if (this->second + second >59)//if the second > 59
	{
		this->second = (this->second + second) - 60;//the rest of second after pass mintue
		
		if (this -> minute + 1 > 59 )//if the minute > 59
		{
			this->minute = 0;
			if (this->hours + 1 > 23)//if the hours > 23
			{
				this->hours = 0;
			}
			else//hours < 23
			{
				this->hours += 1;
			}
		}
		else//minute < 59
		{
			this->minute += 1;
		}
	}
	else //(this->second + second) < 60
	{
		this->second = (this->second + second);
	}


	return *this;
}



ostream& operator<<(ostream& os, const Clock& c1)
{
	//all the condation make to check if we need to add digit "0" 
	if (c1.hours < 10)
	{
		os << 0 << c1.hours << ":";
	}
	else
	{
		os << c1.hours << ":";
	}
	if (c1.minute < 10)
	{
		os << 0 << c1.minute << ":";
	}
	else
	{
		os << c1.minute << ":";
	}
	if (c1.second < 10)
	{
		os << 0 << c1.second;
	}
	else
	{
		os << c1.second;
	}

	return os;
}

istream& operator>>(istream& is, Clock& c1)
{
	int tsecond, tminute, thours;
	char tch;
	is >> thours >> tch >> tminute >> tch >> tsecond;

	check_second(tsecond);
	check_minute(tminute);
	check_hours(thours);

	//if not have throw the values inside to this-> clock
	c1.set_hours(thours);
	c1.set_minute(tminute);
	c1.set_second(tsecond);
	return is;

	
}