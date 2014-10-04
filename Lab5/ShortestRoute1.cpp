//Lab 5b: ShortestRoute1.cpp
//Programmer : Ashkon Honardoost
//Comsc 200
//Editor : Sublime Text 2
//Compiler : G++

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

//crates the class with the info
class Leg
{
private:
	const char* const startCity;
	const char* const endCity;
	const double distance;
public:
	Leg(const char* const startLoc,const char* const endLoc, const double miles):startCity(startLoc),endCity(endLoc), distance(miles){};
	friend void printLeg(ostream&, const Leg&);
};

void printLeg(ostream&, const Leg&);

int main()
{
	cout << "Lab 5b: ShortestRoute1.cpp\n" << "Ashkon Honardoost\n" << "Comsc 200 \n" << "Editor:Sublime Text 2\n" << "Compiler:G++\n\n";

	//creates the legs and prints out the info
	Leg a("San Francsico", "San Jose", 20.0);
	printLeg(cout, a);
	Leg b ("San Jose", "Seattle", 400);
	printLeg(cout,b);
	Leg c("Seattle", "LA", 600);
	printLeg(cout,c);
	Leg d("LA", "San Francisco",300);
	printLeg(cout,d);
	Leg e("San Francisco","New York", 4567);
	printLeg(cout,e); 

	cout << endl;
}

//prints the legs
void printLeg(ostream& out, const Leg& trip)
{
	out<< trip.startCity << " -> " <<trip.endCity << ", " << trip.distance << " miles." <<endl;
}