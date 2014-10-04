#include <iostream>
using std::cout;

#include "Floor.h"
#include "Rider.h"

int main()
{
  const Floor f(0); // a floor at ground level

  const Rider a(f); // a rider whose destination is "f"
  const Rider b(f); // a second rider whose destination is "f"
  if (a == b) cout << "equal (INCORRECT)\n"; else cout << "unequal (correct)\n";
  if (a < b) cout << "less (correct)\n"; else cout << "greater or equal (INCORRECT)\n";

  const Rider c(a); // a clone of the first rider
  if (a == c) cout << "equal (correct)\n"; else cout << "unequal (INCORRECT)\n";
  if (a < c) cout << "less (INCORRECT)\n"; else cout << "greater or equal (correct)\n";

  // checking the cloning of the Floor*
  if (&(a.getDestination()) == &(c.getDestination())) cout << "equal (correct)\n"; else cout << "unequal (INCORRECT)\n";

  // additional testing of your own, if you have any
  }