//Assignment 4A:Time.cpp
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++

//includes needed to run program
#include <iostream>
using std::ios;
using std::cout;
using std::endl;
using std::cin;

#include <iomanip>
using std::setprecision;

#include "Time.h"

//sets the time for constructor
Time::Time(int hour, int minute, int second)
{
	setTime(hour, minute, second);
}

//the setter methods
void Time::setTime(int hour, int minute, int second)
{
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}

//sets hour
void Time::setHour(int h)
{
	hour = (h >= 0 && h < 24) ? h:0;

}

//sets the min
void Time::setMinute(int m)
{
	minute = ( m>= 0 && m < 60) ? m : 0;

}

//sets the second
void Time::setSecond(int s)
{
	second = (s >= 0 && s<60) ? s : 0;

}

//gets the hour
int Time::getHour() const
{
	return hour;
}

//gets the min
int Time::getMinute() const
{
	return minute;
}

//gets the second
int Time::getSecond() const
{
	return second;
}


//prints the Universal time
void Time::printUniversal() const
{
	cout.setf(ios::fixed|ios::showpoint);
	cout << setprecision(2) << hour << " : "  << minute << " : "  << second;
}

//prints standard time
void Time::printStandard() const
{
	cout.setf(ios::fixed|ios::showpoint);
	cout << ((hour == 0|| hour == 12)? 12 : hour % 12 ) << " : " << setprecision(2) << minute << " : " << second << (hour < 12 ? "AM" : " PM");
}



