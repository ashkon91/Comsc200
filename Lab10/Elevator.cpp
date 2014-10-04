//Assignment 10B: Elevator
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor: Sublime Text 2
//Compiler: G++

#include "Elevator.h"
#include "Floor.h"

int Elevator::elevatorID = 0;
const int Elevator::IDLE = 0;
const int Elevator::UP = 1;
const int Elevator::DOWN = -1;

//create constructors
Elevator::Elevator(const int space, const int spd, const Floor& start):ID(elevatorID), capacity(space), speed(spd),toFloor(0){
	location = start.getLocation();
	direction = IDLE;
	doorOpen = true;
}

bool Elevator::isNearDestination() const
{
	double distance = (toFloor->getLocation() - location);

	if(distance < 0)
	{
		distance *= -1;
	}

	return (distance <= speed);
}

void Elevator::moveToDestinationFloor()
{
	if(hasADestination())
	{
		location = toFloor->getLocation();
	}
}

ostream& operator<<(ostream& out, const Elevator& e)
{
	out << "Elevator is located at "<< e.getLocation() << " inches from the ground.";

	if(e.isIdle()){
		out<<"\nthe Elevator is idle, ";
	}
	else if(e.isDirectionUp())
	{
		out<<"\nthe Elevator is going up, ";
	}
	else if(e.isDirectionDown())
	{
		out<<"\nthe Elevator is going down, ";
	}

	if(e.isDoorOpen())
	{
		out <<"the Door is open.\n";
	}
	else
	{
		out <<"door is closed.\n";
	}
	return out;
}

vector<Rider> Elevator::removeRidersForDestinationFloor()
{
	vector<Rider> leaving;

	if(riders.size() !=0)
	{
		vector<Rider> staying;

		for(int i=0; i<riders.size();i++)
		{
			if(toFloor==&riders[i].getDestination())
				leaving.push_back(riders[i]);
			else
				staying.push_back(riders[i]);
		}
		riders = staying;
	}
	return leaving;
}

void Elevator::addRiders(const vector<Rider>& r)
{
	vector<Rider>::const_iterator i;
	for(i=r.begin(); i != r.end(); i++)
		if(riders.size()<capacity)
			riders.push_back(*i);
}
void Elevator::setDestinationBasedOnRiders()
{
	if(!hasRiders()) return;
	//int to track the distance to the closests riders destination
	int distance =1;

	for(int i=0;i<riders.size();i++)
	{
		//caluclates the distnace
		distance = getLocation()-riders[i].getDestination().getLocation();
		//converts to abs value
		distance=abs(distance);
		if(getLocation()-riders[i].getDestination().getLocation() < 0 || getLocation()-riders[i].getDestination().getLocation()>distance)
			distance = getLocation()-riders[i].getDestination().getLocation();

		setDestination(&riders[i].getDestination());
	}
}