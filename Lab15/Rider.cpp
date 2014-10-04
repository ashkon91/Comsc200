//Assignment 10B:Floor.CPP
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
#include "Rider.h"

class Floor;

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

const Rider& Rider::operator=(const Rider &r)
{
	if (&r !=this)
	{
		const_cast<int&>(idNumber) = r.idNumber;
		const_cast<const Floor*&>(destination) = r.destination;
	}
	return *this;
}