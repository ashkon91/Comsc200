//Assignment 8B:Floor.h
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
#ifndef Floor_h
#define Floor_h
class Floor{
public:
	Floor(const int floorLoc):floorLoc(floorLoc){}
	int getLocation() const{return floorLoc;} //gets the loc of the floor
private:
	const int floorLoc;

};

#endif