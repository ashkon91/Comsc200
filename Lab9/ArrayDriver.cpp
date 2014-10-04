//Assignment 9: Array
//Ashkon Honardoost
//Comsc 200
//Editor : Sublime Text 2
//Compiler: G++

#include "Array.h"
#include "Array.h"

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "Lab 9a: ArrayDriver.cpp \nAshkon Honardoost \nComsc 200 \nEditor:Sublime Text 2 \nCompiler G++\n\n";

	istringstream sin;

	sin.str("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17");

	int val;
	sin >> val;
	cout<<val<<'\n';

	cout <<"Sin printed out and it: ";
	cout << sin.str() << '\n';
	cout << endl;
}