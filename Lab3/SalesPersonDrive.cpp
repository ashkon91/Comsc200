//Lab3a: SalesPersonDriver.cpp
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
//includes iostream and string functions we need
#include <iostream>
using std::ios;
using std::cout;
using std::endl;
using std::cin;

#include "SalesPerson.h"
#include "SalesPerson.h" // testing ifndef

int main()
{
  cout << "Lab 3a, by Ashkon Honardoost)\n"<< "Programmer: Ashkon Honardoost\n" <<"Class: Comsc200\n" << "Editor used: Sublime Text 2\n" << "Compiler used: G++\n";
  //Creates the object
  SalesPerson salesPerson;

  //Prompts user to enter certain infp
  cout<< "Please enter the information for 12 months of sales" << endl;
  cout<< "Use this information: 700 500 300 200 100 600 800 900 400 200 300 100"<<endl;
  salesPerson.getSalesFromUser();

  //Gives expected and prints values
  cout<< "The expected total is $5100" << endl;
  salesPerson.printAnnualSales();

  //Changes some values and then prints ita gain
  salesPerson.setSales(1,900);
  salesPerson.setSales(2,700);
  cout<<"The values for months 1 and 2 have been increased by 200 the new expected value is $5500"<<endl;
  cout<<"The new total is: " <<endl;
  salesPerson.printAnnualSales();
  // object copy testing, with assignment UPON declaration
  {
    //Prints a copy
    SalesPerson copy = salesPerson;
    cout<< "The values have been copied and the expected copy value is: ";
    copy.printAnnualSales();
    cout<<endl;
  }

  // object copy testing, with assignment AFTER declaration
  {
    SalesPerson copy; copy = salesPerson;
    //...use getters to confirm that copy's contents match salesPerson's
    cout<<"The values have been copied and the expected copy value is: ";
    copy.printAnnualSales();
    cout<<endl;

  }
}