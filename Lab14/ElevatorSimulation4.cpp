#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "Floor.h"
#include "Rider.h"
#include "Elevator.h"

int main()
{
  // create three floors
  Floor firstFloor(0, "First Floor");
  Floor secondFloor(120, "Second Floor");
  Floor basement(-120, "Basement");

  // add people to the floors (who await elevators)
  int i, count = 0;
  for (i = 0; i < 2; i++) // 2 going from 1st floor to 2nd
    firstFloor.addNewRider(Rider(secondFloor));
  for (i = 0; i < 4; i++) // 4 going from 1st floor to basement
    firstFloor.addNewRider(Rider(basement));
  for (i = 0; i < 3; i++) // 3 going from basement to 2nd floor
    basement.addNewRider(Rider(secondFloor));
  for (i = 0; i < 5; i++) // 5 going from 2nd floor to basement
    secondFloor.addNewRider(Rider(basement));
  cout << firstFloor << endl;
  cout << "The first floor: " << firstFloor << endl;
  cout << secondFloor << endl;
  cout << "The second floor: " << secondFloor << endl;
  cout << basement << endl;
  cout << "The basement: " << basement << endl;

  // check the getUpRiderCount() and getDownRiderCount() functions
  if (firstFloor.getUpRiderCount() != 2) cout << "ERROR IN " << firstFloor.getName() << "'s up-rider count\n";
  if (firstFloor.getDownRiderCount() != 4) cout << "ERROR IN " << firstFloor.getName() << "'s down-rider count\n";
  if (basement.getUpRiderCount() != 3) cout << "ERROR IN " << basement.getName() << "'s up-rider count\n";
  if (secondFloor.getDownRiderCount() != 5) cout << "ERROR IN " << secondFloor.getName() << "'s down-rider count\n";

  // create an elevator (capacity 12, speed 5 in/sec)
  Elevator e(12, 5, firstFloor);
  cout << "The elevator: " << e << endl;
  cout << "Memory address of only elevator in this test: " << &e << endl;
  // set elevator to move up; load up-riders
  int n = e.getAvailableSpace();
  vector<Rider> riders = firstFloor.removeUpRiders(n);
  e.addRiders(riders);
  cout << "Elevator should have 2 riders: " << e << endl;  
  e.setDestinationBasedOnRiders(); // this should find the 2nd floor
  cout << "Asked riders for destination: " << e << endl;
  e.setDirectionUp();
  cout << "Set direction up: " << e << endl;
  e.closeDoor();
  cout << "Closed door: " << e << endl;

  while(!e.isNearDestination())
  {
    if (e.isDirectionUp()) e.moveUp();
    else if (e.isDirectionDown()) e.moveDown();
    cout << e << endl;
    if (!(++count % 20)) {cout << "Press ENTER to continue...\n"; cin.get();}
  }
  e.moveToDestinationFloor();
  cout << "Moved to 2nd floor: " << e << endl;

  // remove riders for 2nd floor, add waiting riders, and go to basement
  riders = e.removeRidersForDestinationFloor(); // ignore returned vector
  n = e.getAvailableSpace();
  riders = secondFloor.removeDownRiders(n);
  e.addRiders(riders);
  cout << "Elevator should have 5 riders: " << e << endl;  
  cout << "Moving to basement:\n";
  e.setDestinationBasedOnRiders(); // this should find the basement
  e.setDirectionDown();
  e.closeDoor();
  cout << e << endl;
  while(!e.isNearDestination())
  {
    if (e.isDirectionUp()) e.moveUp();
    else if (e.isDirectionDown()) e.moveDown();
    cout << e << endl;
    if (!(++count % 20)) {cout << "Press ENTER to continue...\n"; cin.get();}
  }
  e.moveToDestinationFloor();
  cout << "Moved to basement (without stopping for 1st floor down-riders): " << e << endl;

  // remove riders for basement, add waiting riders, and go to 2nd floor
  riders = e.removeRidersForDestinationFloor(); // ignore returned vector
  n = e.getAvailableSpace();
  riders = basement.removeUpRiders(n);
  e.addRiders(riders);
  cout << "Elevator should have 3 riders: " << e << endl;  
  cout << "Moving to 2nd floor:\n";
  e.setDestinationBasedOnRiders(); // this should find the 2nd floor
  e.setDirectionUp();
  e.closeDoor();
  cout << e << endl;
  while(!e.isNearDestination())
  {
    if (e.isDirectionUp()) e.moveUp();
    else if (e.isDirectionDown()) e.moveDown();
    cout << e << endl;
    if (!(++count % 20)) {cout << "Press ENTER to continue...\n"; cin.get();}
  }
  e.moveToDestinationFloor();
  cout << "Moved to 2nd floor: " << e << endl;

  // done
  e.openDoor();
  riders = e.removeRidersForDestinationFloor();
  cout << "Opened door, let out " << riders.size() << " riders: " << e << endl;
  e.setIdle();

  // done
  e.openDoor();
  e.setIdle();
  cout << "Test end:\n" << e << endl;
  cout << firstFloor << " (should be 4 stranded riders) " << endl 
    << secondFloor << endl
    << basement << endl;

  // check the getUpRiderCount() and getDownRiderCount() functions
  if (firstFloor.getDownRiderCount() != 4) cout << "ERROR IN " << firstFloor.getName() << "'s down-rider count\n";

  // additional testing of your own, if you have any
  }
