//Lab 6b: ShortestRoute1.cpp
//Programmer : Ashkon Honardoost
//Comsc 200
//Editor : Sublime Text 2
//Compiler : G++
#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

class Route;



//crates the class with the info
class Route;

class Leg
{
private:
	const char* const startCity;
	const char* const endCity;
	const double distance;
public:
	Leg(const char* const startLoc,const char* const endLoc, const double miles):startCity(startLoc),endCity(endLoc), distance(miles){};
	friend class Route;
	void friend printLeg(ostream&, const Leg&);
	void friend printRoute(ostream&, const Route&);
};

class Route
{
private:
	const Leg** leg;
	const int count;
	const double totalD;
public:
	Route(const Leg&);
	Route(const Route&, const Leg&);
	Route(const Route&);
	~Route(){delete[] leg;}
	void friend printRoute(ostream&, const Route&);
};
Route::Route(const Leg& sLeg):leg(new const Leg*[1]), count(1), totalD(sLeg.distance)
{
	leg[0]=&sLeg;
}

Route::Route(const Route& route, const Leg& addLeg):leg(new const Leg*[route.count+1]), count(route.count+1), totalD(route.totalD+addLeg.distance)
{
	for(int i = 0; i< count-1; i++)
		leg[i] = route.leg[i];

	leg[route.count]=&addLeg;
}

Route::Route(const Route& c):leg(new const Leg*[count]), count(c.count), totalD(c.totalD)
{
	for(int i=0; i<c.count+1; i++)
		leg[i]=c.leg[i];
}

void printLeg(ostream&, const Leg&);
void printRoute(ostream&, const Route&);

int main()
{
	cout << "Lab 5b: ShortestRoute2.cpp\n" << "Ashkon Honardoost\n" << "Comsc 200 \n" << "Editor:Sublime Text 2\n" << "Compiler:G++\n\n";

	//creates the legs and prints out the info
	const Leg a("San Francsico", "San Jose", 20.0);
	const Leg b ("San Jose", "Seattle", 400);
	const Leg c("Seattle", "LA", 600);
	const Leg d("LA", "San Francisco",300);
	const Leg e("San Francisco","New York", 4567);

	//create 5 routes
	const Route ra(a);
	const Route rb(ra, b);
	const Route rc(rb, c);
	const Route rd(rc, d);
	const Route re(rd, e);
	cout << endl;

	//prints legs
	printLeg(cout, a);
	printLeg(cout, b);
	printLeg(cout, c);
	printLeg(cout, d);
	printLeg(cout, e);

	printRoute(cout, re);
	cout << endl;

	{
		cout << "Test copy constructor" <<endl;
		Route rCopy = ra;
		printRoute(cout, rCopy);
		cout<<endl;
	}
	cout<<"Test original of what was copied" <<endl;
	printRoute(cout, ra);
	cout << endl;
}

//prints the legs
void printLeg(ostream& out, const Leg& trip)
{
	out<< trip.startCity << " -> " <<trip.endCity << "is a total of  " << trip.distance << " miles." <<endl;
}

void printRoute(ostream& output, const Route& t)
{
	output<< t.leg[0]->startCity;

	for(int i = 1; i<t.count; i++)
		output << " to " << t.leg[i]->startCity;

	output << " to " << t.leg[t.count-1]->endCity;

	output << " is a total of " << t.totalD << " miles " << endl;
}