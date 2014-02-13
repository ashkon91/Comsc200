//Assignment 2A My Time
//Programmer: Ashkon Honardoost
//Class: Comsc 200
//Editor used: Sublime Text 2
//Compiler used: G++ via Terminal 

//includes all needed stds
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::setfill;

//creates the calsses
class Time
{
  public:
    Time(); //Constructors
    void setTime(int,int,int);
    void printUniversal();
    void printStandard();
  private:
    int hour;
    int minute;
    int second;
};

//creates a constructor to set all values to 0
Time::Time()
{
  hour = minute = second = 0;
}

//Sets the time to the values that are passed in
void Time::setTime(int h, int m, int s)
{
  hour = (h>=0 && h<24) ? h : 0;
  minute = (m >= 0 && m<60) ? m : 0;
  second = (s >= 0 && s<60) ? s:0;
}

//Prints the universal time
void Time::printUniversal()
{
  cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute <<":" <<setw(2) << second;
}

//Prints the standard time
void Time::printStandard()
{
  cout << ( ( hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setfill('0') <<setw(2) << minute << ":" <<setw(2) << second
   << (hour<12 ? "AM" : "PM");
}

int main()
{
  cout<<"Assignment 2A My Time"<<endl;
  cout<<"Programmer: Ashkon Honardoost"<<endl;
  cout<<"Class: Comsc 200"<<endl;
  cout<<"Editor used: Sublime Text 2"<<endl;
  cout<<"Compiler used: G++ via Terminal"<<endl<<endl; 
  //creates the object t.
  Time t;
  
  //prints out hte base times
  cout<< "The initial time universal time is ";
  t.printUniversal();
  cout<< "\nThe initial standard time is ";
  t.printStandard();

  //sets the time 
  t.setTime(13,27,6);

  //prints out the universal/standard time
  cout<<"\n\nUniversal time after setTime is ";
  t.printUniversal();
  cout<<"\nStandard time after setTime is ";
  t.printStandard();

  //sets the time
  t.setTime(99,99,99);

  //prints out the times again
  cout<<"\n\nAfter attempting invalid settings: " << "\nUniversal time: ";
  t.printUniversal();
  cout << "\nStandard Time: ";
  t.printStandard();
  cout<<endl;
}

