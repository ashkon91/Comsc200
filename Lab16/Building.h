//Assignment 15:Building.h
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
using std::ostream;

#include <vector>
using std:: vector;

class Elevator;
class Floor;

class Building{

public:
	Building();
	int getFloorCount() const{return (floors.size());} // return #of floors in the vector of Floor*'s
	int getElevatorCount() const{return (elevators.size());} // return #of elevators in the vector of Elevator*'s
	const Floor& getFloor(int index) const{return *floors[index];} // return a reference to the "indexth" floor
	const Elevator& getElevator(int index) const{return *elevators[index];} // return a reference to the "indexth" elevator
	
	friend ostream& operator<<(ostream&, const Building&); 
	
	Building& step(int);
	void getDifferentInts(int,int&,int&);
	~Building();
private:
	int simulationTimer;
	vector<Floor*> floors;
	vector<Elevator*> elevators;
};
#endif