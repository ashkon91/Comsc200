//Lab 3A: SalesPerson.cpp
//Programmer: Ashkon Honardoost
// Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
//includes iostream and string functions we need#include "SalesPerson.h"
 #include "SalesPerson.h"

#include <iostream>
using std::ios;
using std::cout;
using std::endl;
using std::cin;

#include <string>;
using std::getline;
using std::string;

#include <iomanip>
using std::setprecision;

//Construct
SalesPerson::SalesPerson()
{
        for(int i = 0; i<monthsPerYear; i++)
                sales[i] = 0.0;
}

//gets the values for the sales info
void SalesPerson::getSalesFromUser()
{
        double salesFigure;
        string buf;

        for(int i=1; i <= monthsPerYear; i++)
        {

                cout << "Enter sales amount for month " << i << ": ";
                cin >> buf;
                salesFigure = atof(buf.c_str());
                setSales(i, salesFigure);
        }
}

//sets the values for sales info
void SalesPerson::setSales(int month, double amount)
{
        if(month >= 1 && month <= monthsPerYear  && amount > 0)
                sales[month - 1] = amount;
        else
                cout << "Invalid month or sales figure" << endl;
}

//prints the sales info
void SalesPerson::printAnnualSales()
{
        cout.setf(ios::fixed|ios::showpoint);
        cout << setprecision(2) << "\nThe total annual sales are: $" << totalAnnualSales() << endl;
}

//prints out the total
double SalesPerson::totalAnnualSales()
{
        double total = 0.0;

        for(int i = 0; i < monthsPerYear; i++)
                total += sales[i];

        return total;
}