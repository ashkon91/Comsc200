//Assignment 14:Floor.h
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
#include <vector>
using std::vector;

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include "Rider.h"

#ifndef Floor_h
#define Floor_h
class Floor{
private:
	const int floorLoc; //current location
	const string NAME; //name of the floor
	vector <Rider> upRiders; //affected by add riders
	vector <Rider> downRiders; //affected by removedownriders
public:
	Floor(const int floorLoc, const char* const NAME= "unnamed"):floorLoc(floorLoc),NAME(NAME){}
	int getLocation() const{return floorLoc;} //gets the loc of the floor
	bool hasRidersWaiting() const;
	bool hasUpRiders() const{return (upRiders.size()!=0);}
	bool hasDownRiders() const{return (downRiders.size()!=0);}
	int getUpRiderCount() const{return (upRiders.size());}
	int getDownRiderCount() const{return (downRiders.size());}
	string getName() const{return NAME;}

	// non-inline functions
  bool isPreferredDirectionUp() const; // based on Rider with smallest ID
  void addNewRider(const Rider&); // add to up- or down-vector
  vector<Rider> removeUpRiders(int); // int is max #of riders...
  vector<Rider> removeDownRiders(int); //...to move onto elevator

  friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};

#endif