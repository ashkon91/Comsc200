//Assignment 6A:TimeDriver.cpp
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++

#include "Time.h"
#include "Time.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "Lab 6A: TimeDriver.cpp\n" << "Ashkon Honardoost\n" << "Comsc 200 \n" << "Editor:Sublime Text 2\n" << "Compiler:G++\n\n";
	Time cascade;
	cout << "Time object set to 5,25,13 without cascading"<<endl;
	cascade.setTime(5,25,13);
	cascade.printStandard();
	cout<<endl;
	cascade.printUniversal();

	//copy of the original object
	cout<<"\nTime object set to 5,20,10 with cascading"<<endl;
	cascade.setHour(5).setMinute(20).setSecond(10);

	cout <<"Hour is: " <<cascade.getHour()<<endl;
	cout<<"Min is: " <<cascade.getMinute()<<endl;
	cout<<"Seconds is: "<<cascade.getSecond()<<endl;

	cout<<"Print the copy of the function on before"<<endl;
	const Time copy = cascade;
	copy.printStandard();
	cout << endl;
	copy.printUniversal();

	cout<<"\nPrint copy after declaration"<<endl;
	Time copyCopy;
	copyCopy = cascade;
	copyCopy.printStandard();
	cout<<endl;
	copyCopy.printUniversal();

	cout<<endl;
}