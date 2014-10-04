#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>
#include <ctime>

#include "Building.h"

int main()
{
  srand(time(0)); rand(); // requires cstdlib and ctime
  Building building;

  // add one rider per second for 10 seconds
  for (int i = 0; i < 10; i++)
    cout << building.step(1) << endl;

  // continue the simulation for 600 more seconds (expect all riders to be gone by then)
  for (int i = 0; i < 600; i++)
  {
    if (!(i % 10)) // pause every 10 seconds
    {
       cout << "Press ENTER to continue, X-ENTER to quit...\n";
      if (cin.get() > 31) break;
    }
    cout << building.step(0) << endl; // time-step with no riders added
  }
  cout<< "DONE: All riders should be gone, and all elevators idle\n";
}