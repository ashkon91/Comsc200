//Term Project
//Programmer : Ashkon Honardoost
//Comsc 200
//Editor : Sublime Text 2
//Compiler : G++
#include <iostream>
using std::cout;
using std::endl;

#include <ostream>
using std::ostream;

#include <string>
using std::string;

#include <set>
using std::set;


#include <cassert>

//crates the class with the info
class Route;
class Leg;
class ShortestRoute;

class Leg
{
private:
	const string startCity;
	const string endCity;
	const double distance;
public:
	Leg(const string startLoc,const string endLoc, const double miles):startCity(startLoc),endCity(endLoc), distance(miles){};
	friend class Route;
	friend class ShortestRoute;
	void operator=(const Leg&){assert(false);}
	friend ostream& operator<<(ostream&, const Leg&);
	friend ostream& operator<<(ostream&, const Route&);

};

class Route
{
  const int count; // index for number of legs in array
  const Leg** const leg; // dynamic array of const leg pointers
  const double totald; // accumulates total distance
public:
  Route(const Leg&); // start route with a leg
  Route(const Route&, const Leg&); // add legs to route
  bool isGreaterThan(const Route&) const;
	bool operator<(const Route&) const;
  Route(const Route&); // copy constructor
  ~Route(){delete [] leg;}; // deconstructor
  friend class ShortestRoute;
  friend ostream& operator<<(ostream& out, const Route& route);
  void operator=(const Route&){ assert(false); } // should never be called
};

Route::Route(const Leg& sLeg) // start route
:leg(new const Leg*[1]), count(1), totald(sLeg.distance)
{
  leg[0]=&sLeg;
}

Route::Route(const Route& route, const Leg& addLeg) // add to route
:leg(new const Leg*[route.count+1]), count(route.count+1), totald(route.totald+addLeg.distance)
{
  // exception
  if(route.leg[count-2]->endCity != addLeg.startCity)
  {
    delete [] leg;
    throw "New starting city does not match with previous end city.";
  }

  for(int i=0; i < count-1; i++)
    leg[i]=route.leg[i];

  leg[route.count]=&addLeg;
}

Route::Route(const Route& c) // copy constructor
:leg(new const Leg*[count]), count(c.count), totald(c.totald)
{
  for(int i=0; i < c.count; i++)
    leg[i]=c.leg[i];
}



class ShortestRoute{
private:
	static const Leg legs[]; //private
	static const int length; 
public:
    static const Route getAnyRoute(const string, const string );
    static const Route getShortestRoute(const string, const string );

};

const Route ShortestRoute::getAnyRoute(const string from, const string to)
 {    
	for(int i =0; i < length ;i++){	
		if(legs[i].endCity.compare(to) == 0){
			if(legs[i].startCity.compare(from) == 0){
				return Route(legs[i]);
			}
			else {
				return Route(getAnyRoute(from, legs[i].startCity), legs[i]);
				}
			}
		}		
	}

Route const ShortestRoute::getShortestRoute(const string from, const string to)
{   

	set<Route> routes;

	for(int i =0; i < length ;i++)
	{	
		if(legs[i].endCity.compare(to) == 0)
		{
			if(legs[i].startCity.compare(from)==0)
			{
				routes.insert(Route(legs[i]));
			}
			else 
			{
				routes.insert(Route(getShortestRoute(from, legs[i].startCity), legs[i]));
			}
		}
	}		
	set<Route>::iterator it = routes.begin();
	return *it;

}	//end function



const int ShortestRoute::length = 44;
const Leg ShortestRoute::legs[] = // database
{
  	Leg ("San Francisco", "San Jose", 55.0),
	Leg ("San Jose", "Livermore", 30.8),
	Leg ("San Jose", "Stockton",60.2),
	Leg ("Livermore", "Stockton", 55.5),
	Leg ("Livermore", "Salida", 221.0),
	Leg ("Stockton", "Elko",470.2),
	Leg ("Stockton", "Fallon",244.5),
	Leg ("Salida", "Elko",259.5),
	Leg ("Salida","Fallon",485.0),
	Leg ("Elko","Salt Lake City",230.2),
	Leg ("Elko","Provo",272.3),
	Leg ("Fallon","Provo",523.2),
	Leg ("Fallon","Salt Lake City",482.2),
	Leg ("Provo","Rawlins",308.2),
	Leg ("Provo","Scottsbluff",554.3),
	Leg ("Salt Lake City","Provo",57.3),
	Leg ("Salt Lake City","Rawlins",291.2),
	Leg ("Salt Lake City","Scottsbluff",537.2),
	Leg ("Rawlins","Licoln",322.3),
	Leg ("Rawlins","Minneapolis",954.2),
	Leg ("Scottsbluff","Licoln",400.4),
	Leg ("Scottsbluff","Minneapolis",710.2),
	Leg ("Licoln","Chicago",520.1),
	Leg ("Licoln","Indianapolis",636.6),
	Leg ("Minneapolis","Chicago",409.5),
	Leg ("Minneapolis","Indianapolis",592.8),
	Leg ("Indianapolis","Columbus",176.3),
	Leg ("Indianapolis","Lexington",189.3),
	Leg ("Chicago","Columbus",356.5),
	Leg ("Chicago","Lexington",373.2),
	Leg ("Columbus","Pittsburg",185.5),
	Leg ("Columbus","Detroit",207.3),
	Leg ("Lexington","Pittsburg",371.3),
	Leg ("Lexington","Detroit",344.4),
	Leg ("Pittsburg","Philadelphia",304.9),
	Leg ("Pittsburg","New York",374.5),
	Leg ("Detroit","Philadelphia",584.3),
	Leg ("Detroit","Rochester",617.3),
	Leg ("Philadelphia","Rochester",96.7),
	Leg ("Rochester", "New York",20),
	Leg ("San Francisco", "New York", 21000),

};

int main()
{
	cout << "Term Project: ShortestRoute.cpp\n" << "Ashkon Honardoost\n" << "Comsc 200 \n" << "Editor:Sublime Text 2\n" << "Compiler:G++\n\n";

	try{
  	cout << "Any route from San Francisco to New York:" << endl;
  	cout << ShortestRoute::getAnyRoute("San Francisco", "New York");
	cout << "Shortest route from San Francisco to New York:" << endl;
  	cout << ShortestRoute::getShortestRoute("San Francisco", "New York");
	}catch(const char*ex)
	{
		cout <<"Error found: "<<ex <<endl;
	}
	cout << endl;
}
bool Route::operator<(const Route& r) const{
	if (this->isGreaterThan(r))
		return false;
	else
		return true;
}
//prints the legs
ostream& operator<<(ostream& out, const Leg& trip)
{
	out<< trip.startCity << " -> " <<trip.endCity << "is a total of  " << trip.distance << " miles." <<endl;
	return out;
}

ostream& operator<<(ostream& output, const Route& t)
{
	output<< t.leg[0]->startCity;

	for(int i = 1; i<t.count; i++)
		output << " to " << t.leg[i]->startCity;

	output << " to " << t.leg[t.count-1]->endCity;

	output << " is a total of " << t.totald << " miles " << endl;
	return output;
}

//boolean to see is isGreaterThan
bool Route::isGreaterThan(const Route& r) const
{
	if(this->totald>r.totald)
		return true;
	else
		return false;
}