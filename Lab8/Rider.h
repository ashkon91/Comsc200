

//Assignment 8B:Rider.h
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++

#ifndef Rider_H
#define Rider_H

class Floor;

//crates the class
class Rider
{
public:
 	Rider(const Floor& f):destination(&f), idNumber(nObjects) {++nObjects;}
	bool operator==(const Rider&) const;
	bool operator<(const Rider&) const;
	const Floor& getDestination() const{return *destination;}
private:
	const int idNumber;
	static int nObjects;
	const Floor* const destination;
};
#endif