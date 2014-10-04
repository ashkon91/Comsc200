//Assignment 8A:PhoneNumberDriver.cpp
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++

#include "PhoneNumber.h"
#include "PhoneNumber.h"

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "Lab 8a: PhoneNumberDriver.cpp\n" << "Ashkon Honardoost\n" << "Comsc 200 \n" << "Editor:Sublime Text 2\n" << "Compiler:G++\n\n";

    istringstream sin;

    sin.str ("911");

    int val;
    sin >> val;
    cout << val << '\n';
    
    cout << "Sin printed out and it: ";
    cout << sin.str() << '\n';
    cout<<endl;
}