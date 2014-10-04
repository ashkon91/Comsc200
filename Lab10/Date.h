//Assignment 10: Date.h
//Ashkon Honardoost
//Comsc 200
//Editor : Sublime Text 2
//Compiler: G++

#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::ostream;
using std::istream;

class Date
{
	friend ostream &operator<<(ostream &, const Date &);
public:
	Date(int m=1, int d=1, int y = 1900);
	void setDate(int,int,int);
	Date &operator++();
	Date operator++(int);
	const Date &operator+=(int);
	static bool leapYear(int);
	bool endOfMonth(int) const;
private:
	int month;
	int day;
	int year;

	static const int days[];
	void helpIncrement();
};

#endif
