//Assignment 5A: Employee.h File
//Ashkon Honardoost
//Comsc 200
//Editor:Sublime Text
//Compiler: G++
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

#include "Date.h"//include Date class def

class Employee
{
public:
	Employee(const string &, const string &, const Date &, const Date &);
	void print() const;
	~Employee(); //provide to confirm destruction order
private:
	string firstName;
	string lastName;
	const Date birthDate;
	const Date hireDate;
};

#endif