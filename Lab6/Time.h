//Lab 4A: Time.h
//Programmer: Ashkon Honardoost
//Class: Comsc200
//Editor used: Sublime Text 2
//Compiler used: G++
#ifndef TIME_H
#define TIME_H
//creates the class
class Time
{
	//creates constructor and prototypes for methods
public:
	Time(int = 0, int = 0, int = 0);

	Time &setTime(int, int, int);
	Time &setHour(int);
	Time &setMinute(int);
	Time &setSecond(int);

	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	void printUniversal() const;
	void printStandard() const;
	//creates variables
private:
	int hour;
	int minute;
	int second;
};

#endif