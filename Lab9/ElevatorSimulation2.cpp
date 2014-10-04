#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Floor.h" // from lab 8
#include "Elevator.h"

// TESTING THE ELEVATOR CONTROLS
// 1. Starting at the ground floor, send the elevator up for 20 seconds,
//    then let it go down until it finds and stops at the ground.
// 2. Starting at the ground floor, send the elevator down for 20 seconds,
//    then let it go up until it finds and stops at the ground.
int main()
{
  int i; // loop counter

  // create one floor and one elevator
  const Floor groundFloor(0); // the ground floor
  Elevator e(12, 5, groundFloor); // capacity 12, speed 5 in/sec
  cout << e << " (should at zero inches, idle, with the door open)\n";

  // move the elevator up for 20 seconds
  e.closeDoor();
  e.setDestination(0);
  e.setDirectionUp();
  for (i = 0; i < 20; i++)
    e.moveUp();
  e.setIdle();
  e.openDoor();
  cout << e << " (should be at 100 inches above the ground)\n";

  // move down until it reaches the upper floor -- should take 20 steps
  e.setDestination(&groundFloor);
  e.closeDoor();
  e.setDirectionDown();
  while(!e.isNearDestination())
  {
    if (e.isDirectionUp()) e.moveUp();
    else if (e.isDirectionDown()) e.moveDown();
    cout << e << endl; // this should print 19 times
  }
  e.moveToDestinationFloor();
  cout << e << " (should be at ground level)\n";

  // done
  e.openDoor();
  e.setIdle();
  cout << e << " (should be idle with the door open)\n";

  // now, move the elevator down for 20 seconds
  e.closeDoor();
  e.setDestination(0);
  e.setDirectionDown();
  for (i = 0; i < 20; i++)
    e.moveDown();
  e.setIdle();
  e.openDoor();
  cout << e << " (should be at 100 inches below the ground)\n";

  // move up to first floor until it reaches -- should take 20 steps
  e.setDestination(&groundFloor);
  e.closeDoor();
  e.setDirectionUp();
  cout << e << " (should be going up with the door closed)\n";
  while(!e.isNearDestination())
  {
    if (e.isDirectionUp()) e.moveUp();
    else if (e.isDirectionDown()) e.moveDown();
    cout << e << endl; // this should print 19 times
  }
  e.moveToDestinationFloor();
  cout << e << " (should be at ground level)\n";

  // done
  e.openDoor();
  e.setIdle();
  cout << e << " (should be idle with the door open)\n";

  // additional testing of your own, if you have any
  }