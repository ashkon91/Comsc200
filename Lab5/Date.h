//Assignment 5A: Date.h File
//Ashkon Honardoost
//Comsc 200
//Editor:Sublime Text
//Compiler: G++

#ifndef DATE_H
#define DATE_H

class Date
{
public:
	static const int monthsPerYear = 12;
	Date(int = 1, int = 1, int = 1900); //construct
	void print() const; //prints date
	~Date();
private:
	int month;
	int day;
	int year;

	//checks proper day
	int checkDay(int) const;

};

#endif