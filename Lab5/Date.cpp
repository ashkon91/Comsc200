//Assignment 5A: Date.cpp File
//Ashkon Honardoost
//Comsc 200
//Editor:Sublime Text
//Compiler: G++
#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

Date::Date(int mn, int dy, int yr)
{
	if(mn > 0 && mn <= monthsPerYear)
		month = mn;
	else
	{
		month =1;
		cout<<"Invalid month (" << mn << ") set to 1.\n";
	}
	year = yr;
	day = checkDay(dy);

	//output date object to show when its constructor is called
	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

//print Date object in form month/day/year
void Date::print() const
{
	cout << month << '/' << day << '/' << year;
}

//output Date object to show when its destructor is called
Date::~Date()
{
	cout<< "Date object destructor for date ";
	print();
	cout << endl;
}

//utility function to confrim proper day value on month and year
int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[monthsPerYear + 1] = {0,31,28,31,30,31,30,31,30,31,30,31};

	//determine wether testDay is valid for specificmonth
	if(testDay>0 && testDay <= daysPerMonth[month])
		return testDay;

	//Feb 29 check for leap year
	if( month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 00 && year % 100 != 0 )))
		return testDay;

	cout <<"Invalid Day(" << testDay << ") set to 1. \n";
	return 1;
}