//Assignment 15:Building.cpp
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
#include "Building.h"
#include "Rider.h"
#include "Floor.h"
#include "Elevator.h"

#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

Building::Building() : simulationTimer(0)
{
	Floor* sb = new Floor(-200, "Sub-Basement");//lowest floor
	floors.push_back(sb);
	Floor* b = new Floor(-100, "Basement");
	floors.push_back(b);
	Floor* m = new Floor(0,"Main Floor"); //ground floor
	floors.push_back(m);
	Floor* l1 = new Floor(100, "Second Floor");//second level
	floors.push_back(l1);
	Floor* l2 = new Floor(200,"Third Floor"); //third level
	floors.push_back(l2);
	Floor* l3 = new Floor(300,"Fourth Floor"); //fourth level
	floors.push_back(l3);
	Floor* l4 = new Floor(400,"Fifth Floor"); //fifth level
	floors.push_back(l4);

	Elevator* e1 = new Elevator(5,5, *floors[1]);//first elevator
	elevators.push_back(e1);
	Elevator* e2 = new Elevator(5,5, *floors[6]); //second elevator
	elevators.push_back(e2);	
}

Building& Building::step(int max)
{
  for(int i = 0; i < max; i++)
  {
    int topFloor = getFloorCount();
    int firstFloor; // starting floor int
    int lastFloor; // ending floor int
    getDifferentInts(topFloor, firstFloor, lastFloor); // call getDifferentInts creates 2 random ints that are not equal to one another
    floors[firstFloor]->addNewRider(Rider(*floors[lastFloor])); // rider loop 
  }
  // ELEVATOR ACTIONS [3]  
  for(int i = 0; i < getElevatorCount(); i++){// tell each elevator to perform an action [3]
    if(getElevator(i).isDoorOpen() == false){ // if elevator door is closed
      if(getElevator(i).isNearDestination() == false){ // if not near enough to destination to reach it in this time step, continue moving [3]
        if(getElevator(i).isDirectionUp() == true){ // if elevator direction is up, move up [3]
          elevators[i]->moveUp();
        }
        else{ // otherwise, move down [3]
          elevators[i]->moveDown();
        }
      }

      else{ // otherwise it's near enough to destination to reach it in this time step... [4]
        elevators[i]->moveToDestinationFloor(); // tell elevator to move to its destination floor [4]
        elevators[i]->openDoor(); // tell elevator to open its door [4]
        elevators[i]->removeRidersForDestinationFloor(); // tell elevator to remove riders for its destination floor -- ignore returned vector of removed riders [4]   
        // get a non-const pointer to the elevator's destination floor (using const_cast) [5]
        Floor* ncp;
        const_cast<const Floor*&>(ncp) = &getElevator(i).getDestination();
         
        if(getElevator(i).getRiderCount() == 0){ // if elevator is empty
          //choose a direction based on longest-waiting rider (the one with the smallest ID) on the floor: [5]
          if(ncp->isPreferredDirectionUp() == true) // if the floor's chosen direction is up [5]
            elevators[i]->setDirectionUp(); // tell elevator to set its direction to up [5]
          else // otherwise [5]
            elevators[i]->setDirectionDown(); // tell elevator to set its direction to down [5]        
        }
        
        if(getElevator(i).getAvailableSpace() > 0 && elevators[i]->isDoorOpen() == true){ // if there is space in the elevator after letting off riders
          // board new ones [6]
          if(getElevator(i).isDirectionUp() == true){ // if elevator direction is up, board up-riders (if any)... [6]
            elevators[i]->addRiders(ncp->removeUpRiders(elevators[i]->getAvailableSpace()));
        }
          else{ // otherwise, board down-riders (if any) [6]
            elevators[i]->addRiders(ncp->removeDownRiders(elevators[i]->getAvailableSpace()));
        	}
        }
        
        elevators[i]->setDestinationBasedOnRiders();  // reassess elevator destination based on its riders [8]
        
      }

   
    }

    else{ // otherwise (then it already let off riders, or is in its initial state) [7]
      if(getElevator(i).hasRiders() == true){ // if elevator has any riders
        elevators[i]->closeDoor(); // tell elevator to close its door [7]      
      	}
      else{
        elevators[i]->setIdle();
    	}
    }
    
  }
  
  // FLOOR ACTIONS [2]
  // check each floor (for waiting riders) [2]
  for(int i = 0; i < getFloorCount();i++){
    if(getFloor(i).hasRidersWaiting() == false){ // if there are no riders waiting on this floor, continue with next floor [2]
      continue;
    }
    for(int j = 0; j < getElevatorCount(); j++){  
      
      int currentLoc = elevators[j]->getLocation() - floors[i]->getLocation(); // get elevator's relative location
      
      if(getElevator(j).isIdle() == true){ // look at each elevator to see if it needs to be sent here [2]
        
        if(currentLoc >= 0){ // elevator is above if positive
          elevators[j]->setDirectionDown(); // set elevator direction to down [2]
          elevators[j]->setDestination(floors[i]);// set elevator's destination to this floor [2]  
          elevators[j]->closeDoor(); // tell elevator to close its door [2]
        }
        
        else{
          elevators[j]->setDirectionUp();// set elevator direction to up [2]
          elevators[j]->setDestination(floors[i]); // set elevator's destination to this floor [2]  
          elevators[j]->closeDoor(); // tell elevator to close its door [2] 
        }
      } 
      
      // else if there are riders on this floor waiting to go up, and the elevator is going up... [10]
      else if(getFloor(i).hasUpRiders() == true && getElevator(j).isDirectionUp() == true){
        // get distance from elevator's destination floor to this floor (positive if elevator destination is above this floor) [10]
        double DistancetoFloor = getElevator(j).getDestination().getLocation() - getFloor(i).getLocation();
        if (DistancetoFloor > 0 && currentLoc < 0){ // if elevator is below floor and elevator destination is above this floor [10]
          elevators[j]->setDestination(&(getFloor(i))); // set elevator's destination to this floor [10]
        }
      }
      
      else if(getFloor(i).hasUpRiders() == true && getElevator(j).isDirectionUp() == true){
        // get distance from elevator's destination floor to this floor (negative if elevator destination is below this floor) [10]
        double DistancetoFloor = getElevator(j).getDestination().getLocation() - getFloor(i).getLocation();
        if (DistancetoFloor < 0 && currentLoc > 0){ // if elevator is above floor and elevator destination is below this floor [10]
          elevators[j]->setDestination(&(getFloor(i))); // set elevator's destination to this floor [10]
        }
      }
          
    }
  }
  
  simulationTimer++;
  return *this;
}
//destrucotr
Building::~Building()
{
	for(int i=0; i<getFloorCount();i++)
		delete floors[i];
	for(int i=0; i<getElevatorCount(); i++)
		delete elevators[i];
}
//rand numbers
void Building::getDifferentInts(int max, int&x, int& y)
{
	do
	{
		x = rand() % max;
		y = rand() % max;
	}
	while(x==y);
}
//printing function
ostream& operator<<(ostream& out, const Building& x)
{
	out<< "Time in seconds is: " << x.simulationTimer << endl;

	for(int i = 0; i < x.elevators.size();i++){
		out <<"Elevator #" << i << *x.elevators[i] <<endl;
	}
	for(int i = 0; i< x.floors.size(); i++){
		out<< *x.floors[i];
		}
	return out;


}