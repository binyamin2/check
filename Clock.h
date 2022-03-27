/*
 binyamin shapira 208965863.

course : cadna c++.
exercise 4 question 1.
the file is definition of class "Clock.h"
and declaration of is methods.
*/

#pragma once

#include <iostream>
using namespace std;

class Clock
{
private:
	int hours = 0;
	int minute = 0;
	int second = 0;

public:

	Clock(int hours, int mintue, int second);//constractor.

	Clock() : hours(0), minute(0), second(0){};//defalt constractor.

	int get_hours() { return hours; };
	int get_minute() { return minute; };
	int get_second() { return second; };

	void set_hours(int hours);
	void set_minute(int minute);
	void set_second(int second);

	Clock& operator += (int second);//operator+=

	friend ostream& operator<<(ostream& os, const Clock& c1);//cin
	friend istream& operator>>(istream& is, Clock& c1);//cout
};


/*
checking Clock
int main()
{
	Clock c;
	try
	{
		cin >> c;
	}
	catch (int num)
	{
		enum check{A=1,B,C,D,E,F};

		switch (num)
		{
		case A:
			cout << "Invalid time - negative number of seconds." << endl;
			break;
		case B:
			cout << "Invalid time - more than 60 seconds." << endl;
			break;
		case C:
			cout << "Invalid time - negative number of minutes." << endl;
			break;
		case D:
			cout << "Invalid time - more than 60 minutes." << endl;
			break;
		case E:
			cout << "Invalid time - negative number of hours." << endl;
			break;
		case F:
			cout << "Invalid time - more than 24 hours." << endl;
			break;
		default:
			break;
		}
	}
	catch (...)
	{
		cout << "Wrong time format." << endl;
	}

	cout << c;
	for (int i = 0; i < 4; i++)
	{
		c += 50;

	cout << c;
	}


	return 0;
}
*/