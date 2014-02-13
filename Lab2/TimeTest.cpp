#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::setfill;

struct Time
{
  int hour;
  int minute;
  int second;
  void setTime(struct Time, int, int, int);
  //void setTime(int,int,int);
  void printUniversal(struct Time);
  void printStandard(struct Time);
};

int main()
{
  Time t;
  t.hour = 0;
  t.minute = 0;
  t.second = 0;
  cout<< "The initial time universal time is ";
  t.printUniversal(t);
  cout<< "\nThe initial standard time is ";
  t.printStandard(t);

  t.setTime(t,13,27,6);

  cout<<"\n\nUniversal time after setTime is ";
  t.printUniversal(t);
  cout<<"\nStandard time after setTime is ";
  t.printStandard(t);

  t.setTime(t,99,99,99);

  cout<<"\n\nAfter attempting invalid settings: " << "\nUniversal time: ";
  t.printUniversal(t);
  cout << "\nStandard Time: ";
  t.printStandard(t);
  cout<<endl;
}

void Time::setTime(Time t, int hour, int min, int second)
{
  t.hour = (hour>=0 && hour<24) ? hour : 0;
  t.minute = (min >= 0 && min<60) ? min : 0;
  t.second = (second >= 0 && second<60) ? second:0;
}

void Time::printUniversal(Time t)
{
  cout << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.minute <<":" <<setw(2) << t.second;
}
void Time::printStandard(Time t)
{
  cout << ( ( t.hour == 0 || t.hour == 12) ? 12 : t.hour % 12) << ":" << setfill('0') <<setw(2) << t.minute << ":" <<setw(2) << t.second
   << (t.hour<12 ? "AM" : "PM");
}