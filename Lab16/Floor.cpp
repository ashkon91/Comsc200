//Assignment 14: Elevator
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor: Sublime Text 2
//Compiler: G++

#include "Rider.h"
#include "Floor.h"
#include "Elevator.h"

#include <iostream>
using std::ostream;
using std::istream;

  bool Floor::isPreferredDirectionUp() const
  {
  	if(!(hasDownRiders()))
  		return true;
  	if(!(hasUpRiders()))
  		return false;
  	if(upRiders[0]<downRiders[0])
  		return true;
 	return false;
  }
  void Floor::addNewRider(const Rider& rider){
  	if(rider.getDestination().getLocation()>this->getLocation())
  	{
  		upRiders.push_back(rider);
  	}
  	else
  	{
  		downRiders.push_back(rider);
  	}
  } 

  vector<Rider> Floor::removeUpRiders(int max){
  	vector<Rider> leaving;
  	if(hasUpRiders()){
  			vector<Rider> staying;
  			for(int i=0; i<upRiders.size();i++){
  				if(leaving.size()!=max){
  					leaving.push_back(upRiders[i]);
  				}
  				else{
  					staying.push_back(upRiders[i]);	
  				}
  			}
  			//replace the upriders vector with the vector of riders remaining on the floor
  			upRiders=staying;
  		
  	}
  	//return vector of removed riders;
  	return leaving;
  } 
  vector<Rider> Floor::removeDownRiders(int max){
  	vector<Rider> leaving;
  	if(hasDownRiders()){
  			vector<Rider> staying;
  			for(int i=0; i<downRiders.size();i++){
  				if(leaving.size()!=max){
  					leaving.push_back(downRiders[i]);
  				}
  				else{
  					staying.push_back(downRiders[i]);	
  				}
  			}
  			//replace the upriders vector with the vector of riders remaining on the floor
  			downRiders=staying;
  	}
  	//return vector of removed riders;
  	return leaving;

  }
  ostream &operator<<(ostream &output, const Floor &f)
{
	output <<"Floor name is: "<<f.NAME<<"\nThe current number of up riders waiting is: "<<f.upRiders.size()<<"\nThe current number of down riders waiting is: "<<f.downRiders.size()<<"\nCurrent location is: "<<f.getLocation()<<"\n\n\n";
	return output;
}