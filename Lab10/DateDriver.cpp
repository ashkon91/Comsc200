//Assignment 10: DateDrive.cpp
//Ashkon Honardoost
//Comsc 200
//Editor : Sublime Text 2
//Compiler: G++
#include <iostream>
using std::cout;
using std::endl;	

#include "Date.h"
#include "Date.h"
int main()
{
	cout <<"10a:DateDrive.cpp\nAshkon Honardoost\nComsc200\nEditor:Sublime Text\nCompiler:G++\n\n";

	//creates a date
	Date t(12,12,12);
	cout << "We have created the object Date 2, It should print out 12/12/12\n";
	cout << "The date is "<<t<<endl;

	//increment date by 10
	cout <<"We are going to add 10 days to the date\n";
	t+=10;

	cout <<"The date is now " << t << endl;
	//pre and post increment
	cout <<"We will now test with pre and post increment\n";
	cout << "The date hows now changed to " <<++t << "Using pre increment. \n";
	cout <<"The date should print 24 but it will print " <<t++<<" because we are using post increment. This is because Post increment will do the command first and the increase the value.\n";


}