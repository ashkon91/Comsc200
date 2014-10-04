//Lab4a: TimeDrive.cpp
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++

//includes iostream and string functions we need
#include <iostream>
using std::ios;
using std::cout;
using std::endl;
using std::cin;

#include "Time.h"
#include "Time.h" // testing ifndef

int main()
{
  cout << "Lab 4a, by Ashkon Honardoost)\n"<< "Programmer: Ashkon Honardoost\n" <<"Class: Comsc200\n" << "Editor used: Sublime Text 2\n" << "Compiler used: G++\n";
  //creates an object t
  Time t(12, 45, 30);

  //prints out the values
  cout << "getSecond : " << t.getSecond() << endl;
  cout << "getMin : " << t.getMinute() << endl;
  cout << "getHour : " << t.getHour() << endl<<endl;

  //prints out the times
  cout << "The current time is according to standard : ";
  t.printStandard();
  cout<<endl<<endl;

  cout << "The current time in universal is : ";
  t.printUniversal();
  cout << endl<<endl;

  //changes the times and prints the values
  cout << "Changing hours to 10, min to 10, sec to 10\n\n";
  t.setHour(10);
  t.setMinute(10);
  t.setSecond(10);

  cout << "New Values are " <<endl; 
  cout << "getSecond : " << t.getSecond() << endl;
  cout << "getMin : " << t.getMinute() << endl;
  cout << "getHour : " << t.getHour() << endl << endl;

  cout <<"\nDoes a copy upon declaration and prints out info"<<endl;
  const Time copy = t;
  copy.printStandard();
  cout<<endl;
  copy.printUniversal();

  cout<<"\n\nDoes a copy after declaration"<<endl;
  Time copy2;
  copy2 = t;
  copy2.printStandard();
  cout<<endl;
  copy2.printUniversal();
  cout <<endl;
}




