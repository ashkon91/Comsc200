// include necesseary functions from c++ libraries
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ostream>
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cassert>

class Leg;
class Route;
class ShortestRoute;

// specification -- Leg
class Leg {
  public:
    Leg(const string sc, const string ec, const double d)
        :startingCity(sc), endingCity(ec), legDistance(d) {};
    double getLegDistance() const {return legDistance;}
    const Leg& operator=(const Leg& leg){return *this;}
    friend ostream& operator<<(ostream& out, const Leg& leg);
    friend ostream& operator<<(ostream& out, const Route& route);
    friend int cityOrderMatch(const Leg&, const Leg&);
    friend class ShortestRoute; 
  private:
    const string startingCity;
    const string endingCity;
    const double legDistance;
};

// specification -- Route
class Route {
  public:
    Route(const Leg& leg);
    Route(const Route& route, const Leg& leg);
    Route(const Route& route);
    ~Route();
    double getRouteDistance() const {return routeDistance;}
    bool isGreaterThan(const Route& route) const;
    const Route& operator=(const Route& route){return *this;}
    friend ostream& operator<<(ostream& out, const Route& route);
    friend int cityOrderMatch(const Leg&, const Leg&);
  private:
    const int nLeg;
    const Leg **legs;
    const double routeDistance;
};

// specification -- ShortestRoute
class ShortestRoute {
  public:
    // collection of LegS
    static vector<Leg> legs;

    // add leg
    static void addLeg(Leg& leg) {
      legs.push_back(leg);
    }
    
    // the first recursive fuction
    static const Route getAnyRoute(const string from, const string to) {      
      // end condition of recursion
      vector<Leg>::iterator cities;
      for (cities = legs.begin(); cities != legs.end(); cities++) {
        if ( (cities->startingCity.compare(from)==0) && (cities->endingCity.compare(to)==0) ) {
          return Route(*cities);
        }
      }
      
      // find route
      vector<Leg>::iterator end;
      for (end = legs.begin(); end != legs.end(); end++) {
        try {
          if (end->endingCity.compare(to) == 0) {
            return Route(getAnyRoute(from, end->startingCity), *end);
          }
        } catch (const char*) {
          continue;
        }
      }

      // cannot find route
      throw "\nCannot Find any Route";
      return Route(*end); // not rechaed
    }

    // the second recursive fuction
    static const Route getShortestRoute(const string from, const string to) {      
      // end condition of recursion
      vector<Leg>::iterator cities;
      for (cities = legs.begin(); cities != legs.end(); cities++) {
        if ( (cities->startingCity.compare(from)==0) && (cities->endingCity.compare(to)==0) ) {
          return Route(*cities);
        }
      }
      
      // find route
      vector<Route> routes;      
      vector<Leg>::iterator end;
      for (end = legs.begin(); end != legs.end(); end++) {
        try {
          if(end->endingCity.compare(to) == 0) {
            routes.push_back(Route(getShortestRoute(from, end->startingCity), *end));
          }
        } catch (const char*) {
          continue;
        }
      }

      // get the shortest route
      if ( !routes.empty() ) {
        int sIndex = 0;
        for (unsigned int i = 0; i < routes.size(); i++) {
          if (!routes.at(i).isGreaterThan(routes.at(sIndex))) {
            sIndex = i;
          }    
        }
        return routes.at(sIndex);
      }

      // cannot find route
      throw "\nCannot Find any Route";
      return Route(*end); // not rechaed
    }
    
  private:
};

// implementation -- Route member functions
Route::Route(const Leg& leg) 
    : nLeg(1), legs(new const Leg * [nLeg]), routeDistance(leg.getLegDistance()) {
  legs[0] = &leg;
}

Route::Route(const Route& route, const Leg& leg)
    : nLeg(route.nLeg + 1), legs(new const Leg * [route.nLeg + 1]), 
      routeDistance(route.getRouteDistance() + leg.getLegDistance()) {
  if (!cityOrderMatch(*route.legs[route.nLeg - 1], leg)) {
    throw "\nThe starting city of the Leg does not match the ending city of the Route.";          
  }  
  else {          
    for(int i = 0; i < route.nLeg;i++) {
      legs[i] = route.legs[i];
    }
    legs[nLeg - 1] = &leg;
  }
}

Route::Route(const Route& route)
    : nLeg(route.nLeg), legs(new const Leg * [nLeg]), routeDistance(route.getRouteDistance()) {
  for(int i = 0; i < route.nLeg; i++) {
    legs[i] = route.legs[i];
  }
}

Route::~Route() {
  delete [] legs;
}

bool Route::isGreaterThan(const Route& route) const {
  return (this->routeDistance > route.routeDistance);
}

// implementation -- Friend functions
ostream& operator<<(ostream& out, const Leg& leg) {
  out << leg.startingCity << " to " << leg.endingCity << ", " << leg.legDistance << " miles" << endl;
  return out;
}

ostream& operator<<(ostream& out, const Route& route) {
  // print startingCity of route  
  out << route.legs[0]->startingCity;
  // print route 
  for(int i = 0; i < route.nLeg; i++) {
    out << " to " << route.legs[i]->endingCity;
  }
  // print total distance of route  
  out << " is " << route.getRouteDistance() << " miles" << endl;

  return out;
}

int cityOrderMatch(const Leg& leg1, const Leg& leg2) {
  return (leg1.endingCity.compare(leg2.startingCity) == 0);
}

// declare static member fields
vector<Leg> ShortestRoute::legs;

// implementation -- ShortestRoute member functions
//static const Route ShortestRoute::getAnyRoute(const string from, const string to) {
//  return Route();
//}

// main 
int main() {
  // identifying output statements
  cout << "Programmer: Sung Du Kim (1288362)" << endl;
  cout << "ShortestRoute.cpp -- Term Project for CS-266" << endl << endl;

  // Leg
  Leg a("San Francisco", "Sacramento", 87.9);
  Leg b("Sacramento", "Reno", 131.9);
  Leg c("Reno", "Salt Lake City", 517.8);  
  Leg d("Salt Lake City", "Denver", 534.6);  
  Leg e("Denver", "Omaha", 538.2);
  Leg f("San Francisco", "Pleasant Hill", 27.7);
  Leg g("Denver", "Laramie", 146.1);
  Leg h("San Francisco", "Seoul",1.1);
  Leg i("Denver", "North Platte", 264.3);
  Leg j("North Platte", "Lincoln", 225.8);
  Leg k("Laramie", "Des Moines", 676.0);
  Leg l("Des Moines", "Cleveland", 663.1);
  Leg m("Des Moines", "Chicago", 333.8);  
  Leg n("Chicago", "Indiana", 177.6);  
  Leg o("Indiana", "Cincinnati", 141.7);
  Leg p("Cincinnati", "Pittsburg", 288.2);
  Leg q("Pittsburg", "Washington DC", 246.4);
  Leg r("Washington DC", "Philadelphia", 137.2);
  Leg s("Philadelphia", "New York", 93.4);
  Leg t("Pittsburg", "Philadelphia", 304.6);  
  Leg u("Chicago", "Detroit", 282.7);
  Leg v("Detroit", "Pittsburg", 285.7);
  Leg w("Chicago", "Cleveland", 345.1);  
  Leg x("Cleaveland", "Pittsburgh", 132.8);  
  Leg y("Cleveland", "Binghamton", 360.9);
  Leg z("Binghamton", "New York", 175.4);

  // ShortestRoute
  ShortestRoute::addLeg(a);
  ShortestRoute::addLeg(b);
  ShortestRoute::addLeg(c);
  ShortestRoute::addLeg(d);
  ShortestRoute::addLeg(e);
  ShortestRoute::addLeg(f);
  ShortestRoute::addLeg(g);
  ShortestRoute::addLeg(h);
  ShortestRoute::addLeg(i);
  ShortestRoute::addLeg(j);
  ShortestRoute::addLeg(k);
  ShortestRoute::addLeg(l);
  ShortestRoute::addLeg(m);
  ShortestRoute::addLeg(n);
  ShortestRoute::addLeg(o);
  ShortestRoute::addLeg(p);
  ShortestRoute::addLeg(q);
  ShortestRoute::addLeg(r);
  ShortestRoute::addLeg(s);
  ShortestRoute::addLeg(t);
  ShortestRoute::addLeg(u);
  ShortestRoute::addLeg(v);
  ShortestRoute::addLeg(w);
  ShortestRoute::addLeg(x);
  ShortestRoute::addLeg(y);
  ShortestRoute::addLeg(z);

  // print
  cout << "Any route from San Francisco to New York:" << endl;
  cout << ShortestRoute::getAnyRoute("San Francisco", "New York");
  cout << "Shortest route from San Francisco to New York:" << endl;
  cout << ShortestRoute::getShortestRoute("San Francisco", "New York");

  return 0;
} // end main