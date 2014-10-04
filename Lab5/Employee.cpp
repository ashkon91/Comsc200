//Assignment 5A: EMployee.cpp File
//Ashkon Honardoost
//Comsc 200
//Editor:Sublime Text
//Compiler: G++

#include <iostream>
using std::cout;
using std::endl;

#include "Employee.h"

#include "Date.h"
//construcor
Employee::Employee(const string &first, const string &last, const Date &dateOfBirth, const Date &dateOfHire) : firstName(first), lastName(last), birthDate(dateOfBirth), hireDate(dateOfHire)
{
	cout << "Employee object constructor: " << firstName << ' ' << lastName << endl;
}
//prints out info
void Employee::print() const
{
	cout << lastName << ", " << firstName << " Hired: ";
	hireDate.print();
	cout <<" Birthday: ";
	birthDate.print();
	cout << endl;
}

//destructor
Employee::~Employee()
{
	cout<<"Employee object destructor: "<< lastName<< ", "<< firstName<< endl;
}