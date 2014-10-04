//Assignment 8B:Floor.CPP
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++

#include "Rider.h"
//sets the int to 0
int Rider::nObjects = 0; 
//checks the condition of the operator
bool Rider::operator==(const Rider& r) const
{
  bool result = true;
  if (idNumber != r.idNumber) result = false;
  return result;
}

//checks the condition of the operator
bool Rider::operator<(const Rider& r) const 
{
  bool result = false;
  if (idNumber < r.idNumber) result = true;
  return result;
}