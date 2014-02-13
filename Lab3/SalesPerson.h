//Lab3A: SalesPerson.h
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
//includes iostream and string functions we need
#ifndef SalesPerson_h
#define SalesPerson_h

//creates a class for sales person
class SalesPerson
{
  public:
        static const int monthsPerYear = 12;
        SalesPerson();
        void getSalesFromUser();
        void setSales(int, double);
        void printAnnualSales();
  private:
        double totalAnnualSales();
        double sales[monthsPerYear];
};

#endif