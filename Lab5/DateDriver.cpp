//Assignment 5A: DateDrive.cpp
//Ashkon Honardoost
//Comsc 200
//Editor:Sublime Text
//Compiler: G++

#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"
#include "Date.h"
int main()
{
	//prints my info
	cout<<"Assignment 5A: DateDrive.cpp" <<endl;
	cout<<"Ashkon Honardoost"<<endl;
	cout<<"Comsc 200"<<endl;
	cout<<"Editor:Sublime Text"<<endl;
	cout<<"Compiler: G++"<<endl;
	//"create date object"
	Date a(12,11,1994); 
	Date h(15,15,15);

	//tests a valid date
	cout << "Test the print function on a valid date A"<<endl;
	a.print();
	cout<<endl;

	//Tests an invalid date
	cout <<"Test the print function on an invalid date"<<endl;
	h.print();
	cout<<endl;
	{
	//creates a copy and tests it
	const Date copy = a;

	cout << "Testing the copy of the date object A";
	copy.print();
	cout <<endl;
	}
}